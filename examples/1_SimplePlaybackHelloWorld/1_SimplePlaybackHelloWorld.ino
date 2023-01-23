/*
 * 1_SimplePlaybackHelloWorld.ino
 * 
 * Demonstrates how simple it is to playback the melody of a song.
 * 
 * The song title: Hello World by Alan Walker ft. Torine
 * 
 * By ZulNs, @Gorontalo, January 2023
*/


#include <TonePlayer.h>
#include "song.h"

TonePlayer top;  // If omitted, pin 13 is the default pin the passive buzzer connected to.
//TonePlayer top(13);  // This line has same effect with above line.

void setup() {
  top.setSong(SONG, sizeof(SONG));  // Set the song data, note: it must be in PROGMEM area.
                                   // Song buffer SONG is declared in file "song.h"
  top.play();  // Begins playback a song.
}

void loop() {
  top.loop();  // Call this line inside the loop() function to keep the song playing.
}