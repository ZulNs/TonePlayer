// Required by the 3_RainbowLightsOfTheSpectre.ino example sketch.


#include <TonePlayer.h>


// Song title: The Spectre by Alan Walker
const PROGMEM uint8_t SONG[] = {
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

#define LOWEST_TONE  NB5
#define HIGHEST_TONE NGIS7