# Arduino TonePlayer Library

## Overview
A library for playing melody in background process using the builtin `tone()` function. No needed for `delay()` function to waste the MCU processing power. It parses melodic tones from `PROGMEM` to conserve the SRAM. The frequency of each tone is computed instead of being stored as constant values. Supports repeat to a specified number of tones till five levels of stack.

## Example
```c
#include <TonePlayer.h>

const PROGMEM uint8_t SONG[] = {
  NFIS6, 5, NFIS6, 5, ND6,   5, NB5,   5, REST,  5, NB5,   5, REST,  5, NE6,   5,
  REST,  5, NE6,   5, REST,  5, NE6,   5, NGIS6, 5, NGIS6, 5, NA6,   5, NB6,   5,
  NA6,   5, NA6,   5, NA6,   5, NE6,   5, REST,  5, ND6,   5, REST,  5, NFIS6, 5,
  REST,  5, NFIS6, 5, REST,  5, NFIS6, 5, NE6,   5, NE6,   5, NFIS6, 5, NE6,   5,
  REPEAT, 0, 0, 64, 0,
};

TonePlayer top;
//TonePlayer tp(13);  // This line has same effect with above line.

void setup() {
  top.setSong(SONG, sizeof(SONG));  // Set the song data, note: it must be in PROGMEM area.
  top.play();  // Begins playback a song.
}

void loop() {
  top.loop();  // Call this line inside the loop() function to keep the song playing.
}
```


&nbsp;

&nbsp;

---
#### Created by ZulNs
##### @Gorontalo, Indonesia, January 2023
---
