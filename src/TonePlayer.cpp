/*
 * TonePlayer.cpp
 * 
 * A library for playing melody in background process using the builtin tone() function.
 * No needed for delay() function to waste the MCU processing power.
 * It parses melodic tones from PROGMEM to conserve the SRAM.
 * The frequency of each tone is computed instead of being stored as constant values.
 * Supports repeat to a specified number of tones till five levels of stack.
 * 
 * By ZulNs, @Gorontalo, December 2022
 */

#include "Arduino.h"
#include "TonePlayer.h"

void (*TonePlayer::onEndOfSongCallback)(void);
void (*TonePlayer::onToneCallback)(uint16_t freq);
void (*TonePlayer::onMuteCallback)(void);

TonePlayer::TonePlayer(uint8_t speaker_pin) {
	speakerPin = speaker_pin;
}

void TonePlayer::setSong(const uint8_t* ptr_song_buffer, uint16_t tone_size) {
  if (isPlaying) {
    stop();
  }
  songBuffer = ptr_song_buffer;
  toneSize = tone_size;
}

void TonePlayer::setTempo(uint16_t current_tempo) {
  tempo = (current_tempo == 0) ? 1000 : current_tempo;
}

void TonePlayer::setRestFactor(uint8_t rest_factor) {
  restFactor = (rest_factor > 100) ? rest_factor % 100 : rest_factor;
}

void TonePlayer::setToneShift(int8_t tone_shift) {
  toneShift = (tone_shift != 0) ? toneShift + tone_shift : 0;
}

void TonePlayer::play(uint16_t start_from_address) {
  tonePointer = start_from_address;
  stackPointer = 0;
  toneCode = FETCH;
  isPlaying = true;
}

void TonePlayer::pause() {
  if (isBuzzing) {
    muteSpeaker();
  }
  isPlaying = false;
}

void TonePlayer:: cont() {
  if (tonePointer > 0) {
    isPlaying = true;
  }
}

void TonePlayer::stop() {
  if (isBuzzing) {
    muteSpeaker();
  }
  isPlaying = false;
}

void TonePlayer::loop() {
  static uint16_t rest, freqFrom, currentFreq, eachToneDuration, eachRestDuration;
  static uint8_t  repetition, stepCount, stepCtr, freqStep;
  static int8_t   toneFrom, toneStep, currentTone;
  uint16_t freq, freqTo, freqRange, duration, toneCtr, toneSz;
  uint8_t  swingStrength, swingStep;
  int8_t toneTo;
  uint32_t val;
  if (isPlaying && millis() - toneTimer >= toneDuration) {
    switch (toneCode) {
      case FETCH:
        if (tonePointer >= toneSize) {
          if (stackPointer) {
            val = stackBuffer[--stackPointer];
            toneSize    = val & 0xFFFF;
            tonePointer = val >> 16;
          }
          else {
            isPlaying = false;
            if (onEndOfSongCallback) {
              onEndOfSongCallback();
            }
          }
        }
        else {
          toneCode = pgm_read_byte_near(songBuffer + tonePointer++);
          switch (toneCode) {
            case NC1 ... NB8:
              freq     = getFreqShift(toneCode);
              duration = getDuration();
              rest     = (uint32_t)duration * restFactor / 100;
              soundSpeaker(freq, duration - rest);
              break;
            case REST:
              rest = getDuration();
              muteSpeaker(rest);
              toneCode = FETCH;
              break;
            case REST_FACTOR:
              restFactor = pgm_read_byte_near(songBuffer + tonePointer++);
              if (restFactor > 100) {
                restFactor %= 100;
              }
              toneCode = FETCH;
              toneDuration = 0;
              break;
            case SHIFT_TONE:
              toneShift += pgm_read_byte_near(songBuffer + tonePointer++);
              toneCode = FETCH;
              toneDuration = 0;
              break;
            case RESET_TONE_SHIFT:
              toneShift = 0;
              toneCode = FETCH;
              toneDuration = 0;
              break;
            case REPEAT:
              toneCtr  =           pgm_read_byte_near(songBuffer + tonePointer++);
              toneCtr += (uint16_t)pgm_read_byte_near(songBuffer + tonePointer++) << 8;
              toneSz   =           pgm_read_byte_near(songBuffer + tonePointer++);
              toneSz  += (uint16_t)pgm_read_byte_near(songBuffer + tonePointer++) << 8;
              toneSz  += toneCtr;
              if (stackPointer < STACK_LEVEL_LIMIT) {
                stackBuffer[stackPointer++] = ((uint32_t)tonePointer << 16) + toneSize;
                tonePointer = toneCtr;
                toneSize    = toneSz;
              }
              toneCode = FETCH;
              toneDuration = 0;
              break;
            case LOOP:
              currentFreq = getFreqShift(pgm_read_byte_near(songBuffer + tonePointer++));
              duration    = getDuration();
              repetition  =              pgm_read_byte_near(songBuffer + tonePointer++);
              eachRestDuration = (uint32_t)duration * restFactor / 100;
              eachToneDuration = duration - eachRestDuration;
              soundSpeaker(currentFreq, eachToneDuration);
              break;
            case SEQUENCE_TONE:
              toneFrom   = pgm_read_byte_near(songBuffer + tonePointer++);
              toneTo     = pgm_read_byte_near(songBuffer + tonePointer++);
              toneStep   = pgm_read_byte_near(songBuffer + tonePointer++);
              duration   = getDuration();
              rest = (uint32_t)duration * restFactor / 100;
              eachToneDuration = duration - rest;
              if (toneStep != 0) {
                if (toneStep < 0) {
                  toneStep = -toneStep;
                }
                stepCount = (toneFrom > toneTo) ? toneFrom - toneTo : toneTo - toneFrom;
                stepCount++;
                stepCount /= toneStep;
                if (toneFrom > toneTo) {
                  toneStep = -toneStep;
                }
                currentTone = toneFrom;
                stepCtr = stepCount;
                eachRestDuration = rest;
              }
              else {
                toneCode = toneFrom;  // converts to regular tone
              }
              soundSpeaker(getFreqShift(currentTone), eachToneDuration);
              break;
            case SWING_CENTER:
              currentTone   = pgm_read_byte_near(songBuffer + tonePointer++);
              duration = getDuration();
              swingStrength = pgm_read_byte_near(songBuffer + tonePointer++);
              stepCount     = pgm_read_byte_near(songBuffer + tonePointer++);
              rest = (uint32_t)duration * restFactor / 100;
              eachToneDuration = duration - rest;
              freq = getFreqShift(currentTone);
              if (stepCount > 1 && swingStrength > 0) {
                if (swingStrength > 100) {
                  swingStrength %= 100;
                }
                freqRange = (uint32_t)(getFreqShift(currentTone + 1) - freq) * swingStrength / 50;
                currentFreq = freqFrom = freq - freqRange / 2;
                freqTo   = freqFrom + freqRange;
                freqStep = freqRange / (stepCount - 1);
                eachToneDuration /= stepCount;
                if (eachToneDuration > 0 && freqStep > 0) {
                  rest = duration - eachToneDuration * stepCount;
                  stepCtr = stepCount;
                }
                else {
                  currentFreq = freq;
                  toneCode = currentTone;  // converts to regular tone
                  eachToneDuration = duration - rest;
                }
              }
              else {
                currentFreq = freq;
                toneCode = currentTone;  // converts to regular tone
              }
              soundSpeaker(currentFreq, eachToneDuration);
              break;
          }
        }
        break;
      case NC1 ... NB8:
        muteSpeaker(rest);
        toneCode = FETCH;
        break;
      case LOOP:
        if (!isBuzzing || eachRestDuration == 0) {
          if (--repetition == 0) {
            if (isBuzzing) {
              muteSpeaker();
            }
            toneCode = FETCH;
          }
          else {
            soundSpeaker(currentFreq, eachToneDuration);
          }
        }
        else {
          muteSpeaker(eachRestDuration);
        }
        break;
      case SEQUENCE_TONE:
        if (!isBuzzing || eachRestDuration == 0) {
          if (--stepCtr == 0) {
            if (isBuzzing) {
              muteSpeaker();
            }
            toneCode = FETCH;
            break;
          }
          else {
            currentTone += toneStep;
            soundSpeaker(getFreqShift(currentTone), eachToneDuration);
          }
        }
        else {
          muteSpeaker(eachRestDuration);
        }
        break;
      case SWING_CENTER:
        if (--stepCtr == 0) {
          muteSpeaker(rest);
          toneCode = FETCH;
        }
        else {
          currentFreq += freqStep;
          soundSpeaker(currentFreq, eachToneDuration);
        }
        break;
    }
  }
}

uint16_t TonePlayer::getFreq(int8_t pitch) {
  float freq = pow(1.059463, (float)pitch - 45.0) * 440.0;
  return (uint16_t)(freq + 0.5);
}

uint16_t TonePlayer::getFreqShift(int8_t pitch) {
  return getFreq(pitch + toneShift);
}

uint16_t TonePlayer::getDuration(void) {
  uint16_t duration;
  uint8_t  div, mul = 1;
  div = pgm_read_byte_near(songBuffer + tonePointer++);
  if (div == 0) {
    mul = pgm_read_byte_near(songBuffer + tonePointer++);
    div = pgm_read_byte_near(songBuffer + tonePointer++);
    if (div == 0) {
      div = 255;
    }
  }
  duration = (uint32_t)tempo * mul / div;
  return duration;
}

void TonePlayer::soundSpeaker(uint16_t freq, uint16_t duration) {
  if (isBuzzing) {
    noTone(speakerPin);
  }
  tone(speakerPin, freq, duration);
  toneTimer = millis();
  toneDuration = duration;
  isBuzzing = true;
  if (onToneCallback) {
    onToneCallback(freq);
  }
}

void TonePlayer::muteSpeaker(uint16_t duration) {
  noTone(speakerPin);
  toneTimer = millis();
  toneDuration = duration;
  isBuzzing = false;
  if (onMuteCallback) {
    onMuteCallback();
  }
}
