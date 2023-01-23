/*
 * TonePlayer.h
 * 
 * A library for playing melody in background process using the builtin tone() function.
 * No needed for delay() function to waste the MCU processing power.
 * It parses melodic tones from PROGMEM to conserve the SRAM.
 * The frequency of each tone is computed instead of being stored as constant values.
 * Supports repeat to a specified number of tones till five levels of stack.
 * 
 * By ZulNs, @Gorontalo, December 2022
 */

#ifndef ARDUINO_TONE_PLAYER_H
#define ARDUINO_TONE_PLAYER_H

#include "Arduino.h"

#define DEFAULT_TEMPO       1000   // in milliseconds
#define DEFAULT_REST_FACTOR   20   // of 100
#define STACK_LEVEL_LIMIT      5   // used by REPEAT command
#define DEFAULT_SPEAKER_PIN LED_BUILTIN

enum NOTES {
  NC1, NCIS1, ND1, NDIS1, NE1, NF1, NFIS1, NG1, NGIS1, NA1, NAIS1, NB1,
  NC2, NCIS2, ND2, NDIS2, NE2, NF2, NFIS2, NG2, NGIS2, NA2, NAIS2, NB2,
  NC3, NCIS3, ND3, NDIS3, NE3, NF3, NFIS3, NG3, NGIS3, NA3, NAIS3, NB3,
  NC4, NCIS4, ND4, NDIS4, NE4, NF4, NFIS4, NG4, NGIS4, NA4, NAIS4, NB4,
  NC5, NCIS5, ND5, NDIS5, NE5, NF5, NFIS5, NG5, NGIS5, NA5, NAIS5, NB5,
  NC6, NCIS6, ND6, NDIS6, NE6, NF6, NFIS6, NG6, NGIS6, NA6, NAIS6, NB6,
  NC7, NCIS7, ND7, NDIS7, NE7, NF7, NFIS7, NG7, NGIS7, NA7, NAIS7, NB7,
  NC8, NCIS8, ND8, NDIS8, NE8, NF8, NFIS8, NG8, NGIS8, NA8, NAIS8, NB8,
  REST,              // (also tone NC1...NB8) followed by duration*
  REST_FACTOR,       // followed by value (0 - 100)
  SHIFT_TONE,        // followed by tone difference value
  RESET_TONE_SHIFT,
  REPEAT,            // followed by lowByte(address), highByte(address), lowByte(size), highByte(size)
  LOOP,              // followed by tone, duration*, & repetition
  SEQUENCE_TONE,     // followed by initial tone, destination tone, tone shift, & duration*
  SWING_CENTER,      // followed by tone to swing, swing strength (1 - 100), number of step
  FETCH,             // internal code
};                   //
                     // *duration consists of one or three bytes.
                     // It expressed in 1/d seconds. If you want any value other than 1/d seconds,
                     // for example 3/4 seconds,SWING_CENTER then you can enter 0, 3, 4, respectively.

class TonePlayer {
public:
  TonePlayer(uint8_t speaker_pin = DEFAULT_SPEAKER_PIN);
  void setSong(const uint8_t * ptr_song_buffer, uint16_t tone_size);
  void setSpeakerPin(uint8_t gpio_pin = DEFAULT_SPEAKER_PIN) { speakerPin = gpio_pin; }
  void setOnEndOfSongCallback(void (*funct)(void)) { onEndOfSongCallback = funct; }
  void setOnToneCallback(void (*funct)(uint16_t freq)) { onToneCallback = funct; }
  void setOnMuteCallback(void (*funct)(void)) { onMuteCallback = funct; }
  void setTonePointer(uint16_t tone_pointer) { tonePointer = tone_pointer; }
  void setTempo(uint16_t current_tempo = DEFAULT_TEMPO);
  void setRestFactor(uint8_t rest_factor = DEFAULT_REST_FACTOR);
  void setToneShift(int8_t tone_shift = 0);
  void play(uint16_t start_from_address = 0);
  void pause(void);
  void cont(void);
  void stop(void);
  void loop(void);
  uint16_t getFreq(int8_t pitch);
  uint16_t getFreqShift(int8_t pitch);

private:
  static void (*onEndOfSongCallback)(void);
  static void (*onToneCallback)(uint16_t freq);
  static void (*onMuteCallback)(void);
  
  uint16_t getDuration(void);
  void soundSpeaker(uint16_t freq, uint16_t duration);
  void muteSpeaker(uint16_t duration);

  bool     isPlaying, isBuzzing;
  uint8_t  speakerPin, stackPointer, toneCode;
  const uint8_t * songBuffer;
  int8_t   toneShift;
  uint16_t toneSize, tonePointer, toneDuration, tempo = DEFAULT_TEMPO, restFactor = DEFAULT_REST_FACTOR;
  uint32_t toneTimer;
  uint32_t stackBuffer[STACK_LEVEL_LIMIT];
};

#endif   // ARDUINO_TONE_PLAYER_H