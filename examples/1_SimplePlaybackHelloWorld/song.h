// Required by the 1_SimplePlaybackHelloWorld.ino example sketch.


#include <TonePlayer.h>


// Song title: Hello World by Alan Walker ft. Torine
const PROGMEM uint8_t SONG[] = {
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
