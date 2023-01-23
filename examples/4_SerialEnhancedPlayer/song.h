// Required by the 4_SerialEnhancedPlayer.ino example sketch.


#include <TonePlayer.h>

#define NUMBER_OF_SONG 11
// Song  1: Pirates of The Carribean by Alan Walker
// Song  2: Ignite by K-391 ft. Alan Walker, Julie Bergan, & Seungri
// Song  3: Hark The Herald Angels Sing
// Song  4: Phantom by Dimitri Vangelis & Wyman
// Song  5: Monody (Radio Edit) by TheFatRat ft. Laura Brehm
// Song  6: He's a Pirate - Live performance by D. Garrett (Composed By H. Zimmer & K. Badelt)
// Song  7: Hello World by Alan Walker ft. Torine
// Song  8: Catch Me If You Can by Alan Walker ft. Sorana
// Song  9: Lovesick by Alan Walker ft. Sophie Simmons
// Song 10: Unity by Alan Walker ft. The Walkers
// Song 11: The Spectre by Alan Walker


/*****************************************************************************************/
// Song 1: Pirates of The Carribean by Alan Walker
const PROGMEM uint8_t SONG_1[] = {
  REST_FACTOR, 50,
  ND6, 0, 7, 50, NG6, 0, 7, 50,
  // Address 10
  NA6, 0, 21, 25, NAIS6, 0, 21, 25, LOOP, NA6, 0, 7, 25, 4, NG6, 0, 21, 25,
  REST_FACTOR, 0,
  SEQUENCE_TONE, ND4, NA6, 1, 0, 7, 50,
  
  // Address 37
  REST_FACTOR, 50,
  // Address 39
  REPEAT, 10, 0, 18, 0,
  NG6, 0, 21, 25, NF6,   0, 21, 25, NE6, 0, 7, 25, NF6, 0, 7, 25, NE6, 0, 7, 25, ND6, 0, 21, 25, REST, 0, 7, 25,
  
  REPEAT, 39, 0, 33, 0,
  
  // Address 77
  ND5,   0, 21, 50, NF5,   0, 7, 50,
  NA5,   0,  7, 25, NA5,   0, 7, 25, NA5, 0, 7, 25, NF5, 0, 7, 25,
  NAIS5, 0,  7, 25, NAIS5, 0, 7, 25, NA5, 0, 7, 25, NG5, 0, 7, 25, NA5, 0, 21, 25,
  REPEAT, 77, 0, 24, 0,
  NG5,   0,  7, 25, NF5,   0, 7, 25, NE5, 0, 7, 25, NF5, 0, 7, 25, ND5, 0, 21, 25,
  
  REPEAT, 77, 0, 24, 0,
  REPEAT, 77, 0, 24, 0,
  REPEAT, 77, 0, 16, 0,
  REPEAT, 77, 0, 16, 0,
  
  // Address 166
  REPEAT, 77, 0, 69, 0,
  
  REPEAT, 77, 0, 44, 0,
  NG5, 0, 21, 50, NG5, 0,  7, 50, NG5, 0, 7, 25, NA5, 0, 7, 25, NF5, 0,  7, 25,
  NF5, 0,  7, 50, NG5, 0,  7, 50, NF5, 0, 7, 25, ND5, 0, 7, 25, NE5, 0,  7, 25,
  NE5, 0,  7, 50, NE5, 0,  7, 50, NF5, 0, 7, 25, NE5, 0, 7, 25, ND5, 0, 21, 25,
  
  REPEAT, 166, 0, 70, 0,
  
  REPEAT, 39, 0, 38, 0,
  
  REPEAT, 39, 0, 202, 0,
  REST_FACTOR, 20,
};


/*****************************************************************************************/
// Song 2: Ignite by K-391 ft. Alan Walker, Julie Bergan, & Seungri
const PROGMEM uint8_t SONG_2[] = {
  REST_FACTOR, 50,
  LOOP, NGIS6, 0, 2, 3, 4,
  LOOP, NFIS6, 0, 2, 3, 4,
  LOOP, NE6,   0, 2, 3, 4,
  LOOP, NGIS6, 0, 2, 3, 4, REST, 6,
  REST_FACTOR, 20,
  
  // Address 30
  NGIS6, 5, NAIS6, 5, NB6,   2, REST,  2,
  NB6,   5, NAIS6, 5, NGIS6, 5, NB6,   5, NAIS6, 2, NFIS6, 2, REST, 2,
  NCIS7, 5, NB6,   5, NAIS6, 5, NGIS6, 5, NB6,   2, REST,  2,
  NCIS7, 5, NB6,   5, NAIS6, 5, NGIS6, 5, NB6,   2, NB6,   5, NAIS6, 2, REST, 4,
  
  REPEAT, 30, 0, 50, 0,
  
  // Address 85
  NGIS6, 6, NAIS6, 6, NB6,   3, NB6,   3, NAIS6, 3, NAIS6, 3,
  LOOP, NGIS6, 6, 3,  NGIS6, 3, REST,  6,
  NGIS6, 6, NFIS6, 6, NGIS6, 3, NGIS6, 3, NAIS6, 3, NAIS6, 3,
  LOOP, NB6,   6, 3,  NB6,   3, REST,  6,
  // Address 125
  REPEAT, 85, 0, 20, 0,
  // Address 130
  NDIS7, 3, NCIS7, 3, NB6,   3, NAIS6, 3, NFIS6, 3, NGIS6, 3, REST, 3,
  
  REPEAT, 85, 0, 59, 0,
  
  // Address 149
  NFIS6, 6, NGIS6, 6, NAIS6, 6,
  REST_FACTOR, 50,
  NB6,   3, NB6,   3, NAIS6, 3, NAIS6, 3, NGIS6, 3, NGIS6, 3, REST, 3,
  REST_FACTOR, 20,
  NGIS6, 6, NFIS6, 6,
  REST_FACTOR, 50,
  NGIS6, 3, NGIS6, 3, NAIS6, 3, NAIS6, 3, NB6,   3, NB6,   3, REST, 3,
  REST_FACTOR, 20,
  REPEAT, 149, 0, 22, 0,
  REPEAT, 130, 0, 14, 0,
  REST_FACTOR, 20,
  
  REPEAT, 149, 0, 58, 0,
  
  REPEAT, 30, 0, 182, 0,
  
  // Address 217
  NB5, 4, REST, 3,
  LOOP, NB5, 4, 4, REST, 3,
  NGIS5, 4, NAIS5, 4, NB5, 4, NAIS5, 4, REST, 3,
  NAIS5, 4, NAIS5, 4, NB5, 4, NAIS5, 4, REST, 3,
  NFIS5, 4, NGIS5, 4, REST, 3,
  LOOP, NGIS5, 4, 4, REST, 3,
  NDIS5, 4, NE5, 4, NFIS5, 4, NGIS5, 4, REST, 3,
  NGIS5, 4, NAIS5, 4, NB5, 4, NAIS5, 4, REST, 3,
  
  // Address 279
  NGIS5, 4, NAIS5, 4, NB5, 4, REST, 3,
  LOOP, NB5, 4, 4, REST, 3,
  NAIS5, 4, NAIS5, 4, NB5, 4, NDIS6, 4, REST, 3,
  NAIS5, 4, NAIS5, 4, NB5, 4, NAIS5, 4, REST, 3,
  NGIS5, 4, NAIS5, 4, NB5, 4, REST, 3,
  NGIS5, 4, NFIS5, 4, NGIS5, 4, REST, 3,
  NGIS5, 4, NAIS5, 4, NB5, 4, REST, 3,
  NB5, 4, REST, 4, NAIS5, 4, REST, 4,
  
  // Address 345
  NGIS5, 6, NAIS5, 6, NB5,   3, NB5,   3, NAIS5, 3, NAIS5, 3,
  LOOP, NGIS5, 6, 3,  NGIS5, 3, REST,  6,
  NGIS5, 6, NFIS5, 6, NGIS5, 3, NGIS5, 3, NAIS5, 3, NAIS5, 3,
  LOOP, NB5,   6, 3,  NB5,   3, REST,  6,
  REPEAT, 89, 1, 20, 0,
  NDIS6, 3, NCIS6, 3, NB5,   3, NAIS5, 3, NFIS5, 3, NGIS5, 2, REST, 3,
  
  // Address 404
  NB5,   4, NCIS6, 4, NDIS6, 4, REST, 5,
  NDIS6, 4, REST,  5, NDIS6, 4, REST, 5, NDIS6, 4, REST, 5, NE6,   4, REST, 2,
  NE6,   4, NDIS6, 4, NCIS6, 4, REST, 5,
  NCIS6, 4, REST,  5, NCIS6, 4, REST, 5, NB5,   4, REST, 5, NDIS6, 4, REST, 6,
  NFIS6, 6, REPEAT, 125, 0, 19, 0,
  
  REPEAT, 149, 0, 56, 0,
  NAIS6, 3, NB6,   3, NB6,   3, NAIS6, 3, NFIS6, 3, NGIS6, 3, REST, 3,
  NAIS6, 3, NB6,   3, NB6,   3, NCIS7, 3, NB6,   3, NDIS7, 3, REST, 3,
  NDIS7, 3, NDIS7, 3, NDIS7, 3, NCIS7, 3, NAIS6, 3, NB6,   3, REST, 3,
  REPEAT, 130, 0, 14, 0,
  REST_FACTOR, 20
};


/*****************************************************************************************/
// Song 3: Hark The Herald Angels Sing
const PROGMEM uint8_t SONG_3[] = {
  NC7, 0, 2, 3,
  NC7, 3, NC7, 3, ND7,   3, NC7,   3, NAIS6, 3, NA6,  3, NAIS6, 0, 2, 3,
  NG6, 3, NA6, 3, NC7,   3, NAIS6, 3, NA6,   3, NG6,  3, NA6,   0, 2, 3,
  NF6, 3, NG6, 3, NAIS6, 3, NA6,   3, NG6,   3, NF6,  3, NG6,   0, 2, 3,
  NG6, 3, NF6, 3, NE6,   1, ND6,   3, NC6,   0, 4, 3, NF6, 0, 2, 3, NG6, 0, 2, 3,
  NA6, 0, 2, 3, NAIS6, 0, 2, 3, NA6, 0, 4, 3, NG6, 0, 4, 3, NF6,  0, 4, 3, REST, 0, 2, 3,
  
  // Address 96
  NC6,  0, 2, 3, NF6, 0, 2, 3, NF6, 1, NE6,   3, NF6,   0, 2, 3, NA6, 0, 2, 3, NA6, 0, 2, 3, NG6, 0, 2, 3,
  NC7,  0, 2, 3, NC7, 0, 2, 3, NC7, 1, NAIS6, 3, NA6,   0, 2, 3, NG6, 0, 2, 3, NA6, 1, REST, 3,
  REPEAT, 96, 0, 28, 0,
  NC7,  0, 2, 3, NG6, 0, 2, 3, NG6, 1, NF6,   3, NE6,   0, 2, 3, ND6, 0, 2, 3, NC6, 1, REST, 3,
  // Address 177
  NC7,  0, 2, 3, NC7, 0, 2, 3, NC7, 1, NF6,   3, NAIS6, 0, 2, 3, NA6, 0, 2, 3, NA6, 0, 2, 3, NG6, 0, 2, 3,
  REPEAT, 177, 0, 28, 0,
  // Address 210
  ND7, 1, ND7, 3, ND7, 0, 2, 3, NC7, 0, 2, 3, NAIS6, 0, 2, 3, NA6, 0, 2, 3, NAIS6, 1, REST, 3,
  NG6, 0, 2, 3, NA6, 0, 2, 3, NC7, 1, NF6, 3, NF6,   0, 2, 3, NG6, 0, 2, 3, NA6,   1, REST, 3,
  REPEAT, 210, 0, 44, 0,                                                       NF6,   1, REST, 3,
  
  REPEAT, 0, 0, 96, 0,
  
  REPEAT, 0, 0, 96, 0,
  
  REPEAT, 96, 0, 77, 0,
  NC6, 3, NC6, 3, NF6, 3, NA6, 3,
  REPEAT, 177, 0, 90, 0,
};


/*****************************************************************************************/
// Song 4: Phantom by Dimitri Vangelis & Wyman
const PROGMEM uint8_t SONG_4[] = {
  REST_FACTOR, 0,
  NC7, 0, 4, 3, NCIS7, 4, NC7, 4, NAIS6, 4, NGIS6, 1, REST, 6,
  
  // Address 16
  REST_FACTOR, 40,
  // Address 18
  SWING_CENTER, NGIS6, 3, 25, 3, SWING_CENTER, NGIS6, 3, 25, 3, SWING_CENTER, NGIS6, 3, 25, 3,
  REST_FACTOR,  20, SWING_CENTER, NG6, 6, 25, 3, SWING_CENTER, NF6, 6, 25, 3,
  REST_FACTOR,  40, SWING_CENTER, NF6, 3, 25, 3,
  // Address 52
  SWING_CENTER, NAIS6, 3, 25, 3, SWING_CENTER, NAIS6, 3, 25, 3, SWING_CENTER, NAIS6, 3, 25, 3,
  REST_FACTOR, 20, SWING_CENTER, NF6, 6, 25, 3, SWING_CENTER, NCIS7, 6, 25, 3,
  REST_FACTOR, 40,
  // Address 81
  SWING_CENTER, NC7, 3, 25, 3,
  SWING_CENTER, NC7, 3, 25, 3, REPEAT, 81, 0, 10, 0,
  REST_FACTOR, 20, SWING_CENTER, NGIS6, 6, 25, 3, SWING_CENTER, NAIS6, 6, 25, 3,
  REST_FACTOR, 40,
  SWING_CENTER, NDIS7, 3, 25, 3,
  REPEAT, 52, 0, 10, 0,
  // Address 120
  SWING_CENTER, NGIS6, 3, 25, 3, SWING_CENTER, NG6, 3, 25, 3, SWING_CENTER, NGIS6, 3, 25, 3,
  
  REPEAT, 18, 0, 97, 0,
  REPEAT, 81, 0, 10, 0, SHIFT_TONE, 12, REPEAT, 120, 0, 15, 0, SHIFT_TONE, -12,
  
  SHIFT_TONE, -12,
  REPEAT, 18, 0, 136, 0,
  
  SHIFT_TONE, -12,
  REPEAT, 18, 0, 136, 0,
  
  SHIFT_TONE, 12,
  REPEAT, 18, 0, 136, 0,
  
  SHIFT_TONE, 12,
  REPEAT, 18, 0, 136, 0,
  
  // Address 182
  NGIS6, 3, NGIS6, 3, NGIS6, 3, REST_FACTOR, 20, NG6,   6, NF6,   6, REST_FACTOR, 40, NF6,   3,
  NAIS6, 3, NAIS6, 3, NAIS6, 3, REST_FACTOR, 20, NF6,   6, NCIS7, 6, REST_FACTOR, 40, NC7,   3,
  NC7,   3, NC7,   3, NC7,   3, REST_FACTOR, 20, NGIS6, 6, NAIS6, 6, REST_FACTOR, 40, NDIS7, 3,
  NAIS6, 3, NAIS6, 3, NGIS6, 3, NG6,          3, NGIS6, 3,
  
  REPEAT, 182, 0, 48, 0,
  NC7,   3, NC7,   3, NGIS7, 3, NG7,          3, NGIS7, 3,
  
  SHIFT_TONE, -12,
  REPEAT, 182, 0, 73, 0,
  
  SHIFT_TONE,  12,
  REPEAT, 182, 0, 71, 0,
  REST_FACTOR, 20,
  NGIS7, 0, 2, 1
};


/*****************************************************************************************/
// Song 5: Monody (Radio_Edit) by TheFatRat ft. Laura Brehm
const PROGMEM uint8_t SONG_5[] = {
  // Address 0
  NGIS6, 2, NB6,   2, NCIS7, 1,
  NCIS7, 2, NB6,   2, NGIS6, 1,
  NFIS6, 2, NE6,   2, NFIS6, 1,
  NFIS6, 2, NE6,   2, NCIS6, 1,
  NB5,   2, NCIS6, 2, NE6,   1,
  NFIS6, 2, NGIS6, 2, NA6,   1,
  NGIS6, 2, NE6,   2, NFIS6, 1, REST, 1,
  
  REPEAT, 0, 0, 34, 0,   NFIS6, 1,
  NE6,   2, NDIS6, 2, NE6,   1, REST, 2,
  
  // Address 59
  NFIS6, 7, NCIS6, 0, 2, 7, REST,  7,
  NCIS6, 7, NE6,   0, 2, 7, NFIS6, 0, 2, 7, NCIS6, 0, 2, 7, REST, 7,
  NCIS6, 7, NE6,   0, 2, 7, NFIS6, 0, 2, 7, NGIS6, 0, 2, 7,
  NGIS6, 0, 2, 7, NFIS6, 0, 2, 7, NE6,   7, NGIS6, 7, NFIS6, 0, 2, 7, REST,  0, 2, 7,
  
  REPEAT, 59, 0, 30, 0,
                            NCIS7, 0, 2, 7, NB6,   0, 2, 7,
  NB6,   0, 2, 7, NGIS6, 0, 2, 7, NGIS6, 7, NE6,   7, NFIS6, 0, 2, 7, REST,  0, 2, 7,
  
  REPEAT, 59, 0, 91, 0,
  
  // Address 155
  NGIS6, 0, 2, 7, NB6,   0, 2, 7, NCIS7, 0, 3, 7, NDIS7, 7,
  NCIS7, 0, 2, 7, NB6,   0, 2, 7, NGIS6, 0, 4, 7,
  NFIS6, 0, 2, 7, NE6,   0, 2, 7, NFIS6, 0, 3, 7, NGIS6, 7,
  NFIS6, 0, 2, 7, NE6,   0, 2, 7, NCIS6, 0, 4, 7,
  NB5,   0, 2, 7, NCIS6, 0, 2, 7, NE6,   0, 4, 7,
  NFIS6, 0, 2, 7, NGIS6, 0, 2, 7, NA6,   0, 4, 7,
  NGIS6, 0, 2, 7, NE6,   0, 2, 7, NFIS6, 1,       REST, 2,
  
  REPEAT, 155, 0, 72, 0,
                                  NFIS6, 0, 4, 7,
  NE6,   0, 2, 7, NDIS6, 0, 2, 7, NE6,   1,       REST, 2,
  
  REPEAT, 59, 0, 91, 0,
  
  REPEAT, 59, 0, 91, 0
};


/*****************************************************************************************/
// Song 6: He's a Pirate - Live performance by D. Garrett (Composed By H. Zimmer & K. Badelt)
const PROGMEM uint8_t SONG_6[] = {
  NE6, 2, NG6, 2, NA6, 0, 2,   1, NC6, 1, ND6, 0, 2,   1,
  NE6, 2, NF6, 0, 2,   1, NE6, 1, ND6, 0, 2,   1,
  NE6, 2, NF6, 0, 2,   1, NF6, 2, NG6, 0, 2,   1, ND6, 2, NA6, 0, 3, 1,
  
  // Address 44
  NA5, 5, NC6, 5, ND6, 10, ND6, 10, REST, 5,
  // Address 54
  ND6, 5, NE6, 5, NF6, 10, NF6, 10, REST, 5,
  // Address 64
  NF6, 5, NG6, 5, NE6, 10, NE6, 10, REST, 5,
  NE6, 5, ND6, 5, NC6, 10, ND6, 10, REST, 5,
  
  REPEAT, 44, 0, 32, 0,
          NC6, 5, ND6, 5, REST, 5,
  
  REPEAT, 44, 0, 12, 0,
          NF6, 5, NG6,   10, NG6,   10, REST, 5,
  NG6, 5, NA6, 5, NAIS6, 10, NAIS6, 10, REST, 5,
  NA6, 5, NG6, 5, NA6,   10, ND6,   10, REST, 5,
  
  // Address 128
  ND6, 5, NE6, 5, NF6, 5, REST, 10, NF6, 10, NG6, 5, NA6, 5, ND6, 5, REST, 5,
  ND6, 5, NF6, 5, NE6, 5, REST, 10, NE6, 10, NF6, 5, ND6, 5, NE6, 5, REST, 5,
  
  REPEAT, 44, 0, 114, 0,                             NE6, 5, ND6, 5, REST, 5,
  
  // Address 175
  NF6, 6, NG6, 6, LOOP, NA6, 3, 3, NAIS6, 6, NA6, 6, REST, 3,
  LOOP, NG6, 3, 3, NG6, 6, NA6, 6, REST, 3,
  REPEAT, 179, 0, 10, 0,
  NG6, 3, NF6, 3, NE6, 3, ND6, 3, REST, 3,
  
  REPEAT, 175, 0, 39, 0,
  
  // Address 219
  NA5, 5, NC6, 5, ND6, 10, ND6, 10, REST, 5, NF6,  5, REST, 20, NF6, 5, REST, 5,
  ND6, 5, NE6, 5, NF6, 10, NF6, 10, REST, 5, NG6,  4, REST, 20, NG6, 5, REST, 5,
  NF6, 5, NG6, 5, NE6, 10, NE6, 10, REST, 5, NE6,  4, REST, 20, NE6, 5, REST, 5,
  ND6, 5, NC6, 5, NC6, 10, ND6, 10, REST, 5, ND6, 10, NE6,  10, ND6, 10, NC6, 10, ND6, 10, REST, 5,
  
  REPEAT, 219, 0, 54, 0,
  NA6, 5, NA6, 5, NAIS6, 10, NG6, 10, NA6, 10, REST, 5,
  
  REPEAT, 44, 0, 131, 0,
  
  // Address 317
  NA6, 10, NC7, 5, REST, 10,
  NC7, 10, NB6, 5, REST, 10,
  NC7, 10, NA6, 5, REST, 10,
  NC7, 10, NB6, 5, REST, 10,
  NG6, 10, NC7, 5, REST, 10,
  NC7, 10, NB6, 5, REST, 10,
  NG6, 10, NA6, 5, REST, 10,
  NF6, 10, ND6, 5, REST, 10,
  
  REPEAT, 61, 1, 44, 0,
           NA6, 5, REST, 10,
  
  REPEAT, 61, 1, 36, 0,
  NG6, 5, NF6, 5, NA6, 5, NF6, 5, NG6,5, NF6, 5, NE6, 5, NC6, 5, ND6, 5, REST, 1,
  
  REPEAT, 44, 0, 127, 0,
  ND6,    5, REST,  5, ND6, 5, REST, 5, NE6, 5, REST, 5, NF6, 5, REST, 5,
  NF6,    5, REST,  5, NG6, 5, REST, 5, NA6, 5, REST, 0, 2,   5,
  NF6,   10, NE6,  10, ND6, 5, REST, 0, 2,   5,
  NAIS6,  5, REST,  0, 2,   5,
  NG6,   10, NF6,  10, NE6, 5, REST, 0, 2,   5,
  NG6,    5, REST,  5, NF6, 5, REST, 5, NE6, 5, REST, 0, 2,   5,
  REPEAT, 175, 0, 39, 0,
  
  NF6, 6, NG6, 6, NA6, 3, REST, 3,
  NAIS6, 3, REST, 3,
  // Address 491
  LOOP, NA6, 3,    3, NA6, 6, NG6,  6, REST, 3,
  NG6,  3,   REST, 3, NF6, 3, REST, 3,
  NE6,  3,   NF6,  3, NE6, 3, NE6,  6, ND6,  6, REST, 6,
  
  NF6, 6, NE6, 6, ND6, 6, REST, 6, NA6,   3, REST, 6,
  ND6, 6, NE6, 6, NF6, 6, REST, 6, NAIS6, 3, REST, 6,
  ND6, 6, NE6, 6, NF6, 6, REST, 6,
  REPEAT, 235, 1, 10, 0,
  REST_FACTOR, 50,
  // Address 560
  ND4, 3, NE4, 3, NF4, 3, NG4, 3, NA4, 3, NAIS4, 3, NC5, 3,
  SHIFT_TONE, 12, REPEAT, 48, 2, 14, 0,
  SHIFT_TONE, 12, REPEAT, 48, 2, 8, 0,
  SHIFT_TONE, -24, REST_FACTOR, 20,
  NA6, 3, REST, 3, NAIS6, 3, REST, 3,
  NA6, 3, REST, 12, NG6, 3, REST, 12, NF6, 3, REST, 12,
  NF6, 6, NE6, 6, ND6, 3, REST, 3,
  NA5, 3, REST, 12, NG5, 3, REST, 12, NF5, 6, NE5, 6, ND5, 0, 3, 1, ND7, 3, REST, 3
};


/*****************************************************************************************/
// Song 7: Hello World by Alan Walker ft. Torine
const PROGMEM uint8_t SONG_7[] = {
  NAIS6, 8, NC7,   8, REST,  8, NCIS7, 2,
  // Address 8
  NAIS6, 8, REST,  8, NCIS7, 4, NDIS7, 8, REST, 8, NC7,   2,
  NAIS6, 8, NGIS6, 8, REST,  8, NAIS6, 2,
  NGIS6, 8, REST,  8, NAIS6, 4, NCIS6, 8, REST, 8, NF6,   2,
  NDIS6, 8, NCIS6, 8, REST,  8, NFIS6, 2,
  NDIS6, 8, REST,  8, NFIS6, 4, NGIS6, 8, REST, 8, NF6,   2,
  NDIS6, 8, NCIS6, 8, REST,  8, NDIS6, 2,
  NCIS6, 8, REST,  8, NDIS6, 4, NGIS5, 8, REST, 8, NAIS5, 2,
  REST,  2,
  
  // Address 82
  NAIS5,   4, NF6,    4, REST, 8, NF6,   0, 3, 4,
  NDIS6,   4, NCIS6,  4, REST, 8,
  // Address 98
  NFIS6,   4, NFIS6,  4, REST, 8,
  NGIS6,   4, NAIS6,  4, REST, 8, NF6,   0, 3, 4,
  REPEAT, 98, 0,     16, 0,
  NDIS6,   4, NCIS6,  4, REST, 8, NDIS6, 0, 3, 4, REST, 1,
  
  REPEAT, 82, 0, 49, 0,
  
  // Address 136
  NAIS6,  4, NC7,   5, REST, 8, NCIS7, 2,
  NAIS6,  4, NCIS7, 5, REST, 8, NC7,   2,
  NAIS6,  4, NC7,   5, REST, 8, NAIS6, 2,
  NGIS6,  4, NFIS6, 5, REST, 8, NF6,   2, REST, 2,
  NFIS6,  2,
  NDIS6,  4, NFIS6, 5, REST, 8, NF6,   2,
  // Address 180
  NDIS7, 16, NCIS6, 0, 3,   16, NCIS6, 5, REST, 8, NDIS6, 2,
  NCIS6,  4, NC6,   5, REST, 8, NAIS5, 2, REST, 2,
  
  REPEAT, 142, 0, 60, 0,
  
  // Address 207
  NF6,   8,
  REPEAT, 4, 0, 76, 0,
  
  // Address 214
  //NAIS5, 8, NCIS6, 8, NF6, 8, NAIS6, 8, NC7, 8, NCIS7, 8,
  NAIS5, 8, NC6, 8, NCIS6, 8, NAIS6, 8, NC7, 8, NCIS7, 8,
  REPEAT, 8, 0, 74, 0,
  
  // Address 231
  NAIS5, 4, NAIS5, 2, REST,  4,
  NC6,   4, NC6,   2, REST,  4,
  NCIS6, 4, NCIS6, 4, NDIS6, 8, NF6,   2, REST, 4,
  NCIS6, 4, NFIS6, 4, NFIS6, 4,
  NF6,   4, NFIS6, 4, NF6,   3,
  NDIS6, 8, NCIS6, 4, NCIS6, 4, NDIS6, 2,
  NCIS6, 4, NC6,   4, NAIS5, 2,
  
  REPEAT, 214, 0, 12, 0,
  REPEAT, 231, 0, 48, 0,
  
  REPEAT, 80, 0, 56, 0,
  
  // Address 294
  NAIS6, 4, NC7,   4, NCIS7, 4, NC7,   4, NAIS6, 6, NAIS6, 3, REST, 2,
  NDIS6, 3, REST,  3, NCIS6, 3, REST,  2,
  NDIS6, 3, NCIS6, 3, NCIS6, 3, NCIS6, 3, NDIS6, 6, NF6,   2, REST, 3,
  NDIS6, 3, NCIS6, 3, NCIS6, 3, NFIS6, 3, NGIS6, 6, NF6,   2, REST, 3,
  NF7,   3, NDIS7, 3, NCIS7, 3, NCIS7, 3, NC7,   6, NAIS6, 2, REST, 3,
  
  REPEAT, 136, 0, 95, 0,
  
  REPEAT, 80, 0, 56, 0
};


/*****************************************************************************************/
// Song 8: Catch Me If You Can by Alan Walker ft. Sorana
const PROGMEM uint8_t SONG_8[] = {
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
// Song 9: Lovesick by Alan Walker ft. Sophie Simmons
const PROGMEM uint8_t SONG_9[] = {
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
// Song 10: Unity by Alan Walker ft. The Walkers
const PROGMEM uint8_t SONG_10[] = {
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


/*****************************************************************************************/
// Song 11: The Spectre by Alan Walker
const PROGMEM uint8_t SONG_11[] = {
  NE6,   2, NGIS6, 2, NE7,   1, NB6,   2, NCIS7, 2, NGIS6, 1,
  NE6,   2, NFIS6, 2, NDIS6, 1, NCIS6, 2, NE6,   2, NCIS6, 1,
  
  // Address 24
  NGIS6, 4, NGIS6, 4, NB6, 4, NCIS7, 0, 3, 4, NCIS7, 2, NB6, 2, NGIS6, 0, 3, 4, NFIS6, 0, 3, 4,
  NDIS6, 2, NDIS6, 4, NCIS6, 2, NB5, 2, NGIS5, 0, 3, 4,
  REPEAT, 24, 0, 22, 0,
  NCIS6, 4, NDIS6, 2, NDIS6, 4, NFIS6, 2, NDIS6, 4, NE6, 0, 3, 4,
  
  // Address 77
  NGIS6, 4, NE7, 4, NDIS7, 4, NCIS7, 4, NB6, 4,
  NCIS7, 1, NB6, 0, 3, 4, NGIS6, 1,
  NGIS6, 4, NFIS6, 2, NFIS6, 4, NA6,   2, NFIS6, 4, NGIS6, 0, 3, 4,
  REPEAT, 77, 0, 22, 0,
  // Address 114
                      NE6,   4, NDIS6, 2, NB5,   4, NCIS6, 0, 3, 4,
  
  // Address 124
  LOOP, NGIS6, 4, 3, NGIS6, 2,
                      NFIS6, 4, NE6,   2, NB6,   4, NB6,   0, 3, 4,
  NE6,   4, NFIS6, 2, NE6,   4, NFIS6, 2, NA6,   4, NGIS6, 0, 3, 4,
  REPEAT, 124, 0, 16, 0,
  // Address 159
  NGIS6, 4, NFIS6, 2, REPEAT, 114, 0, 10, 0,
  
  // Address 168
  NB5,   4, NCIS6, 2,
  NE6,   4, NGIS6, 4, NE7,   2,
  NE7,   8, NDIS7, 8, NB6,   4, NCIS7, 2,
  NE7,   4, NCIS7, 4, NA6,   1,
  NGIS6, 2,
  NGIS6, 4, NFIS6, 4, NE6,   2,
  NCIS7, 8, NA6,   8, NGIS6, 8, NE6,   8, NFIS6, 2,
  NE6,   4, NFIS6, 4, NDIS6, 0, 3, 4,
  
  REPEAT, 168, 0, 42, 0,
  REST_FACTOR, 50,
  LOOP, NFIS6, 3, 3, NGIS6, 3, NE6, 3, NE6, 3, NDIS6, 3, NDIS6, 3, NCIS6, 0, 2, 3,
  REST_FACTOR, 20,
  
  REPEAT, 168, 0, 50, 0,
  
  REPEAT, 168, 0, 50, 0,
  
  REPEAT, 24, 0, 100, 0,
  
  REST_FACTOR, 50,
  // Address 262
  LOOP, NGIS6, 4, 5, NFIS6, 4, NE6, 4, NE6, 4, LOOP, NB6, 4, 4,
  NE6, 4, NFIS6, 4, NFIS6, 4, NE6, 4, NFIS6, 4, NFIS6, 4, NA6, 4, LOOP, NGIS6, 4, 3,
  REPEAT, 6, 1, 14, 0,
  REST_FACTOR, 20,
  REPEAT, 159, 0, 59, 0,
  REPEAT, 168, 0, 42, 0,
  REPEAT, 114, 0, 10, 0,
  REPEAT, 168, 0, 10, 0,
  REPEAT, 168, 0, 10, 0,
  // Address 326
  REPEAT, 172, 0, 6, 0,
  REPEAT, 172, 0, 6, 0,
  REPEAT, 172, 0, 6, 0,
  REPEAT, 70, 1, 10, 0,
  // Address 346
  NGIS6, 4, NE7,   2,
  NGIS6, 4, NE7,   2,
  NGIS6, 4, NE7,   2,
  REPEAT, 90, 1, 8, 0,
  
  REPEAT, 168, 0, 50, 0,
  
  REPEAT, 168, 0, 50, 0,

  NE6, 4, NDIS7, 4, NB6, 4, NCIS7, 2,
  // Address 381
  NB6, 4, NGIS6, 4, NGIS7, 2,
  NB6, 8, NGIS6, 8, NB6, 8, NGIS6, 8, NE7, 2,
  NE7, 4, NFIS7, 4, NCIS7, 1,
  NB6, 2,
  NE7, 4, NFIS7, 4, NDIS7, 2,
  NGIS7, 8, NFIS7, 8, NE7, 8, NDIS7, 8, NE7, 2,
  NE7, 4, NFIS7, 4, NDIS7, 0, 3, 4,
  
  REPEAT, 125, 1, 44, 0, NDIS7, 0, 2, 1
};


const PROGMEM uint8_t * const SONG_BUFFER[] = {
  SONG_1,
  SONG_2,
  SONG_3,
  SONG_4,
  SONG_5,
  SONG_6,
  SONG_7,
  SONG_8,
  SONG_9,
  SONG_10,
  SONG_11
};


const PROGMEM uint16_t SONG_SIZE[] = {
  sizeof(SONG_1),
  sizeof(SONG_2),
  sizeof(SONG_3),
  sizeof(SONG_4),
  sizeof(SONG_5),
  sizeof(SONG_6),
  sizeof(SONG_7),
  sizeof(SONG_8),
  sizeof(SONG_9),
  sizeof(SONG_10),
  sizeof(SONG_11)
};


const PROGMEM char SONG_1_TITLE [] = { "Pirates of The Carribean by Alan Walker" };
const PROGMEM char SONG_2_TITLE [] = { "Ignite by K-391 ft. Alan Walker, Julie Bergan, & Seungri" };
const PROGMEM char SONG_3_TITLE [] = { "Hark The Herald Angels Sing" };
const PROGMEM char SONG_4_TITLE [] = { "Phantom by Dimitri Vangelis & Wyman" };
const PROGMEM char SONG_5_TITLE [] = { "Monody (Radio Edit) by TheFatRat ft. Laura Brehm" };
const PROGMEM char SONG_6_TITLE [] = { "He's a Pirate - Live performance by D. Garrett (Composed By H. Zimmer & K. Badelt)" };
const PROGMEM char SONG_7_TITLE [] = { "Hello World by Alan Walker ft. Torine" };
const PROGMEM char SONG_8_TITLE [] = { "Catch Me If You Can by Alan Walker ft. Sorana" };
const PROGMEM char SONG_9_TITLE [] = { "Lovesick by Alan Walker ft. Sophie Simmons" };
const PROGMEM char SONG_10_TITLE[] = { "Unity by Alan Walker ft. The Walkers" };
const PROGMEM char SONG_11_TITLE[] = { "The Spectre by Alan Walker" };


const PROGMEM char * const SONG_TITLE[] = {
  SONG_1_TITLE,
  SONG_2_TITLE,
  SONG_3_TITLE,
  SONG_4_TITLE,
  SONG_5_TITLE,
  SONG_6_TITLE,
  SONG_7_TITLE,
  SONG_8_TITLE,
  SONG_9_TITLE,
  SONG_10_TITLE,
  SONG_11_TITLE
};


const PROGMEM uint8_t TONE_RANGE[] = {
  ND5,   NAIS6,  // Song  1
  NDIS5, NDIS7,  // Song  2
  NC6,   ND7,    // Song  3
  NF4,   NGIS7,  // Song  4
  NB5,   NDIS7,  // Song  5
  NA5,   ND7,    // Song  6
  NGIS5, NF7,    // Song  7
  ND6,   NF7,    // Song  8
  NG5,   NF7,    // Song  9
  NGIS5, NE7,    // Song 10
  NB5,   NGIS7   // Song 11
};  // lowest tone, highest tone
