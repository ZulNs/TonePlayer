/*
 * 3_RainbowLightsOfTheSpectre.ino
 * 
 * Demonstrates the use of:
 *    -  .setOnToneCallback(function_name_to_callback) function.
 *       The callback function must provide one parameter as the
 *        frequency of the recently sounded tone.
 *    -  .setOnMuteCallback(function_name_to_callback) function.
 * 
 * The above two functions, together with the hardware of an RGB LED
 * driven by three PWM pins, realize the light indicator in the rainbow
 * light spectrum corresponding to the frequency of sounding tone.
 * The lower the frequency, the more towards the red color of the
 * rainbow spectrum the light is.Converselly, the higher the frequency,
 * the more towards the purple color the light is.
 * 
 * The song title: The Spectre by Alan Walker
 * 
 * By ZulNs, @Gorontalo, January 2023
*/


#include <TonePlayer.h>
#include "song.h"

// These below pins must be support PWM output (3, 5, 6, 9, 10, and 11 on UNO board).
// Avoid using pins 3 and 11 on boards other than the Mega since the use of tone() function
// (which used in this library) will interfere with PWM output on both pins.
const uint8_t  RGB_RED_PIN   = 10;
const uint8_t  RGB_GREEN_PIN = 9;
const uint8_t  RGB_BLUE_PIN  = 6;

TonePlayer top;  // If omitted, pin 13 is the default pin the passive buzzer connected to.
//TonePlayer top(13);  // This line has same effect with above line.

uint16_t lowestFreq, highestFreq, freqRange;

void setup() {
  lowestFreq  = top.getFreq(LOWEST_TONE);
  highestFreq = top.getFreq(HIGHEST_TONE);
  // Both LOWEST_TONE & HIGHEST_TONE are defined in file "song.h"
  freqRange = highestFreq - lowestFreq;
  top.setOnToneCallback(onTone);         // The onTone() function will be called everytime a tone begins to sound.
  top.setOnMuteCallback(onMute);         // While the onMute() function wiil be called when the buzzer begins to be muted. 
  top.setSong(SONG, sizeof(SONG), BPM);  // Set the song data, note: it must be in PROGMEM area.
                                         // Song buffer SONG is declared in file "song.h"
  top.play();  // Begins playback a song.
}

void loop() {
  top.loop();  // Call this line inside the loop() function to keep the song playing.
}

void onTone(uint16_t freq) {  // This function will be called by TonePlayer object with one
							                // argument as the frequency of the recently sounded tone.
  uint16_t norm;
  uint8_t  val, red, green, blue, grade;
  if (freq < lowestFreq) {
    freq = lowestFreq;
  }
  else if (freq > highestFreq) {
    freq = highestFreq;
  }
  freq -= lowestFreq;
  norm = (float)freq / freqRange * 5.0 * 255.0;
  // Uses 5.0 value instead of 6.0 to put the violet lights on top of the rainbow spectrum
  val = norm / 255;
  grade = norm % 255;
  red = green = blue = 0;
  if (bitRead(val, 0)) {
    grade = 255 - grade;
  }
  switch (val) {
    case 0:
      red   = 255;
      green = grade;
      break;
    case 1:
      red   = grade;
      green = 255;
      break;
    case 2:
      green = 255;
      blue  = grade;
      break;
    case 3:
      green = grade;
      blue  = 255;
      break;
    case 4:
      blue  = 255;
      red   = grade;
      break;
    case 5:
      blue  = grade;
      red   = 255;
      break;
  }
  analogWrite(RGB_RED_PIN,   red);
  analogWrite(RGB_GREEN_PIN, green);
  analogWrite(RGB_BLUE_PIN,  blue);
}

void onMute() {
  analogWrite(RGB_RED_PIN,   0);
  analogWrite(RGB_GREEN_PIN, 0);
  analogWrite(RGB_BLUE_PIN,  0);
}
