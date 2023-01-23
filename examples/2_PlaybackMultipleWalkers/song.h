// Required by the 2_PlaybackMultipleWalkers.ino example sketch.


#include <TonePlayer.h>


/*****************************************************************************************/
// Song 1: Catch Me If You Can by Alan Walker ft. Sorana
const PROGMEM uint8_t SONG_1[] = {
  NA6, 0, 3, 2, NAIS6, 0, 3, 2, NG6, 0, 3, 2, NA6, 0, 3, 2,
  
  // Address 16
  NA5, 3,
  // Address 18
  NF6, 3, NE6, 3, NF6, 6, NAIS5, 2,
  NF6, 3, NE6, 3, NF6, 6, NB5,   2,
  NF6, 3, NE6, 3, NF6, 6, NA5,   2,
  REPEAT, 16, 0, 24, 0,   NG6,   2,
  NF6, 3, NE6, 3, NG6, 3, NF6,   6, NE6, 1,

  REPEAT, 16, 0, 43, 0,
  
  // Address 64
  NA6, 3, ND6, 6, NAIS6, 2, NAIS6, 6, NA6,   6, NG6,   2, REST, 4,
  NG6, 3, NF6, 6, NA6,   2, NA6,   6, NA6,   6, NA6,   6, NG6,  6, NF6, 2, REST, 4,
  NA6, 3, NC7, 6, NAIS6, 2, NAIS6, 6, NAIS6, 6, NAIS6, 6, NA6,  6, NG6, 2, REST, 10,
  // Address 114
  NA6, 6, NG6, 6, NA6,   6, NG6,   6, NA6,   3, NA6,   6, NA6,  6, NF7, 6, NE7,  3, ND7, 2,
  
  // Address 134
  NG6, 6, NA6, 6, NF7,   6, NE7,   3, ND7,   2,
  NG6, 6, NA6, 6, NAIS6, 6, NC7,   3, NAIS6, 2,
  NF6, 6, NG6, 6, NA6,   6, NAIS6, 3, NA6,   3, NAIS6, 6, NA6, 3,
  NA6, 6, NA6, 6, NF7,   6, NE7,   3, ND7,   2,
  
  REPEAT, 134, 0, 44, 0,
  
  REPEAT, 16, 0, 43, 0,

  REPEAT, 64, 0, 119, 0,
  
  // Address 193
  NA6, 3,
  // Address 195
  ND6, 3, ND6, 3, NG6, 6, NF6, 6, NE6, 3,
  REPEAT, 195, 0, 10, 0,
  REPEAT, 193, 0, 12, 0,
  ND7, 3, ND7, 3,
  
  REPEAT, 193, 0, 26, 0,
  
  REPEAT, 64, 0, 119, 0,
  
  REPEAT, 134, 0, 30, 0,

  REPEAT, 114, 0, 20, 0
};


/*****************************************************************************************/
// Song 2: Lovesick by Alan Walker ft. Sophie Simmons
const PROGMEM uint8_t SONG_2[] = {
  // Address 0
  ND6, 4, NE6, 0, 3, 4, NA6, 4, NC7, 0, 3, 4, NA6, 4, NGIS6, 0, 3, 4, NB6, 4, NA6, 0, 3, 4,
  // Address 24
  NE6, 4, NF6, 0, 3, 4, ND6, 4, NE6, 0, 3, 4, NC6, 4, NB5, 0, 3, 4, NG5, 4, NA5, 0, 3, 4,
  
  // Address 48
  NC6, 4, NF6, 4, NF6, 4, NE6, 4, NC6, 4, ND6, 4, ND6, 4, ND6, 4,
  NB5, 4, NC6, 4, NC6, 4, NB5, 4, NC6, 4, NB5, 4, NA5, 4, NA5, 4,
  REPEAT, 48, 0, 24, 0,           NG5, 4, NA5, 0, 3, 4,
  REPEAT, 48, 0, 32, 0,
  NC6, 4, NF6, 4, NF6, 4, NF6, 4, NG6, 4, NF6, 4, NE6, 4, NE6, 4,
  NA5, 4, NC6, 4, NC6, 4, NB5, 4, NG5, 4, NA5, 0, 3, 4,
  
  // Address 126
  REPEAT, 0, 0, 24, 0,
  REPEAT, 24, 0, 18, 0,                                             ND6, 4, NC6, 0, 3, 4,
  NE6, 4, REPEAT, 2, 0, 22, 0,
  // Address 149
  NE7, 4, NF7, 0, 3, 4, ND7, 4, NE7, 0, 3, 4, NC7, 4, NB6, 0, 3, 4, NG6, 4, NA6, 0, 3, 4,
  // Address 173
  NF7, 1, NE7, 1, NB6, 1, NC7, 1,
  NF7, 1, NE7, 4, NF7, 4, NE7, 4, ND7, 4, NC7, 4, NB6, 1,
  
  REPEAT, 48, 0, 43, 0,
  
  NG6, 4,
  NC7, 2, NC7, 0, 3, 4,
  // Address 208
  NC7, 4, NB6, 4, NA6, 4, NG6, 4, NG6, 4,
  ND7, 2, ND7, 0, 3, 4,
  REPEAT, 208, 0, 10, 0,
  NE7, 2, NE7, 0, 3, 4,
  NE7, 4, NF7, 4, NE7, 4, ND7, 4, NC7, 4, NB6, 0, 3, 4, REST, 0, 3, 4,
  
  REPEAT, 126, 0, 47, 0,
  
  // Address 258
  REPEAT, 0, 0, 24, 0,
  NF6, 1, NE6, 1, NB5, 1, NA5, 1,
  
  REPEAT, 2, 1, 13, 0,

  REPEAT, 2, 1, 13, 0,
  
  REPEAT, 0, 0, 24, 0,
  REPEAT, 149, 0, 24, 0,

  REPEAT, 126, 0, 47, 0
};


/*****************************************************************************************/
// Song 3: Unity by Alan Walker ft. The Walkers
const PROGMEM uint8_t SONG_3[] = {
  NB6, 0, 3, 2, NGIS6, 0, 3, 2, NE7, 4, REST, 4, NDIS7, 0, 3, 2, NAIS6, 0, 3, 2,
  
  // Address 20
  NDIS6, 4, NB6,   2, NAIS6, 4, NGIS6, 2, NFIS6, 4, NGIS6, 2, NFIS6, 4, NDIS6, 2,
  NDIS6, 4, NFIS6, 2, NDIS6, 4, NCIS6, 2, NB5,   4, NCIS6, 2, NB5,   4, NGIS5, 2,
  REPEAT, 20, 0, 18, 0,
            NB6,   2, NAIS6, 4, NAIS6, 2, NGIS6, 4, NB6,   2, NAIS6, 4, NGIS6, 2,
  
  // Address 71
  LOOP, NGIS6, 5, 4,
  NGIS6, 0, 2, 5, NFIS6, 0, 2, 5, NB5, 0, 2, 5, NFIS6, 0, 2, 5, NFIS6, 0, 4, 5,
  NDIS6, 5, NDIS6, 5, NDIS6, 5, NDIS6, 5,           NCIS6, 0, 2, 5,
  NCIS6, 5, NCIS6, 5, NE6,   5, NDIS6, 5, NB5,   5, NGIS5, 0, 2, 5, REST, 5,
  
  REPEAT, 71, 0, 46, 0,                             NGIS6, 0, 2, 5, REST, 5,
  
  // Address 134
  NB6,   5, NAIS6, 5, NGIS6, 5, NFIS6, 5, NGIS6, 0, 4, 5,
  NFIS6, 5, NE6,   5, NDIS6, 5, NCIS6, 5, NDIS6, 0, 3, 5,
  NDIS6, 5, NDIS6, 0, 2, 5, NFIS6, 5, NFIS6, 0, 2, 5,
  NAIS5, 5, NB5,   5, NCIS6, 5, NB5,   5, NGIS5, 0, 3, 5,
  
  REPEAT, 134, 0, 36, 0,
  NAIS6, 5, NB6,   5, NCIS7, 5, NB6,   5, NGIS6, 0, 3, 5
};