/*
 * 2_PlaybackMultipleWalkers.ino
 * 
 * Demonstrates the use of .setOnEndOfSongCallback(function_name_to_callback) function.
 * This function helps to realize melody playback of more than one song
 * (three songs exactly in this example).
 * 
 * Those three songs of Walker are:
 * Song 1: Catch Me If You Can by Alan Walker ft. Sorana
 * Song 2: Lovesick by Alan Walker ft. Sophie Simmons
 * Song 3: Unity by Alan Walker ft. The Walkers
 * 
 * By ZulNs, @Gorontalo, January 2023
*/


#include <TonePlayer.h>
#include "song.h"

TonePlayer top;  // If omitted, pin 13 is the default pin the passive buzzer connected to.
//TonePlayer top(13);  // This line has same effect with above line.

void setup() {
  top.setOnEndOfSongCallback(onEndOfSong);  // The onEndOfSong() function will be
                                           // called everytime the end of song has reached.
  onEndOfSong();  // Call this function once to begin playback the first song.
}

void loop() {
  top.loop();  // Call this line inside the loop() function to keep the song playing.
}

void onEndOfSong() {
  static int songCounter;
  const uint8_t * songBuffer;
  uint16_t songSize;
  uint16_t songBPM;
  if (songCounter == 0) {
    songBuffer = SONG_1;
    songSize = sizeof(SONG_1);
    songBPM = SONG_1_BPM;
  }
  else if (songCounter == 1) {
    songBuffer = SONG_2;
    songSize = sizeof(SONG_2);
    songBPM = SONG_2_BPM;
  }
  else {
    songBuffer = SONG_3;
    songSize = sizeof(SONG_3);
    songBPM = SONG_3_BPM;
  }
  // SONG_1, SONG_2, & SONG_3 are declared in file "song.h"
  top.setSong(songBuffer, songSize, songBPM);
  top.play();
  songCounter = (songCounter + 1) % 3;
}
