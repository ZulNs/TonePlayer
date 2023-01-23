/*
 * 4_SerialEnhancedPlayer.ino
 * 
 * Exposes the capabilities of this library, from the callback functions
 * like in the previous example sketches, standard media player functions
 * (play, pause, continue, next track, previous track, and stop),
 * playback mode (single track, contionuous, and repeat), till the function
 * to changes the playback speed, also the function to shift the tone.
 * 
 * Single character command set (send via Serial panel):
 *    =  : Playback the current song
 *    ,  : Pause/continue play
 *    .  : Stops playback
 *    >  : Playback the next song
 *    <  : Playback the previous song
 *    +  : Increases the playback speed (max 2.00x)
 *    -  : Decreases the playback speed (min 0.50x)
 *    ]  : Increases the tone shift by one pitch
 *    [  : Decreases the tone shift by one pitch
 *    *  : Toggles RGB LED indicator on/off
 *    c  : Toggles continous playback mode on/off
 *    r  : Toggles repeat playback mode on/off
 *    l  : Prints the playlist
 *    s  : Prints the all current states
 *    ?  or  h  : Prints help
 * 
 * Playlist:
 * Song  1: Pirates of The Carribean by Alan Walker
 * Song  2: Ignite by K-391 ft. Alan Walker, Julie Bergan, & Seungri
 * Song  3: Hark The Herald Angels Sing
 * Song  4: Phantom by Dimitri Vangelis & Wyman
 * Song  5: Monody (Radio Edit) by TheFatRat ft. Laura Brehm
 * Song  6: He's a Pirate - Live performance by D. Garrett (Composed By H. Zimmer & K. Badelt)
 * Song  7: Hello World by Alan Walker ft. Torine
 * Song  8: Catch Me If You Can by Alan Walker ft. Sorana
 * Song  9: Lovesick by Alan Walker ft. Sophie Simmons
 * Song 10: Unity by Alan Walker ft. The Walkers
 * Song 11: The Spectre by Alan Walker
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

const PROGMEM char SKETCH_TITLE[] = {
  "*************************************\n"
  "*                                   *\n"
  "*  Serial Advanced Player by ZulNs  *\n"
  "*                                   *\n"
  "*************************************\n"
};

const PROGMEM char HELP[] = {
  "\n"
  "Single character command set (send via Serial panel):\n"
  " =  : Plays the current song\n"
  " ,  : Pause/continue play\n"
  " .  : Stops playback\n"
  " >  : Playback the next song\n"
  " <  : Playback the previous song\n"
  " +  : Increases the playback speed (max 2.00x)\n"
  " -  : Decreases the playback speed (min 0.50x)\n"
  " ]  : Increases the tone shift by one pitch\n"
  " [  : Decreases the tone shift by one pitch\n"
  " *  : Toggles RGB LED indicator on/off\n"
  " c  : Toggles continous playback mode on/off\n"
  " r  : Toggles repeat playback mode on/off\n"
  " l  : Prints the playlist\n"
  " s  : Prints the all current states\n"
  " ?  or  h  : Prints help (this page)\n"
};

TonePlayer top;  // If omitted, pin 13 is the default pin the passive buzzer connected to.
//TonePlayer top(13);  // This line has same effect with above line.

uint16_t lowestFreq, highestFreq, freqRange;
uint16_t currentSpeed = 1000;
int8_t currentSong, toneShift;
bool isPlaying, isPaused, isContinousMode, isRepeatMode, isDisplayIndicator;

void setup() {
  Serial.begin(9600);
  while (!Serial);

  top.setOnToneCallback(onTone);
  // The onTone() function will be called everytime a tone begins to sound.
  top.setOnMuteCallback(onMute);
  // While the onMute() function wiil be called when the buzzer begins to be muted. 
  top.setOnEndOfSongCallback(onEndOfSong);
  // The onEndOfSong() function will be called everytime the end of song has reached.
  Serial.println((const __FlashStringHelper *)SKETCH_TITLE);
  delay(1000);
  printHelp();
  delay(2000);
  printPlaylist();
  delay(2000);
  isDisplayIndicator = true;
  playSong();
  printStatus();
}

void loop() {
  top.loop();  // Call this line inside the loop() function to keep the song playing.
  checkSerialInput();
}

void onTone(uint16_t freq) {  // This function will be called by TonePlayer object with one
							                // argument as the frequency of the recently sounded tone.
  if (!isDisplayIndicator) {
    return;
  }
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
  if (!isDisplayIndicator) {
    return;
  }
  analogWrite(RGB_RED_PIN,   0);
  analogWrite(RGB_GREEN_PIN, 0);
  analogWrite(RGB_BLUE_PIN,  0);
}

void onEndOfSong() {
  isPlaying = false;
  if (isContinousMode && (isRepeatMode || currentSong < NUMBER_OF_SONG - 1)) {
    currentSong = (currentSong + 1) % NUMBER_OF_SONG;
    playSong();
  }
  else if (isRepeatMode) {
    playSong();
  }
}

void playSong() {
  const uint8_t * songBuf = (const uint8_t *)pgm_read_word_near(SONG_BUFFER + currentSong);
  uint16_t noteSz = pgm_read_word_near(SONG_SIZE + currentSong);
  top.setSong(songBuf, noteSz);
  top.setRestFactor(20);  // Set to default rest factor
  top.play();
  initIndicator();
  isPlaying = true;
  isPaused = false;
  Serial.print(F("Playback "));
  printSongTitle(currentSong);
}

void initIndicator() {
  lowestFreq  = top.getFreqShift(pgm_read_byte_near(TONE_RANGE + currentSong * 2));
  highestFreq = top.getFreqShift(pgm_read_byte_near(TONE_RANGE + currentSong * 2 + 1));
  freqRange = highestFreq - lowestFreq;
}

void checkSerialInput() {
  uint8_t  chr;
  while (Serial.available()) {
    chr = Serial.read();
    if (isUpperCase(chr)) {
      chr += 0x20;  // Converts to lower case
    }
    switch (chr) {
      case '=':  // play
        if (!isPlaying) {
          playSong();
        }
        else if (isPaused) {
          top.cont();
          isPaused = false;
          printPauseCont();
        }
        break;
      case '.':  // stop
        top.stop();
        isPlaying = false;
        Serial.println(F("Stopped..."));
        break;
      case ',': // pause/continue
        if (isPlaying) {
          if (isPaused) {
            top.cont();
          }
          else {
            top.pause();
          }
          isPaused = !isPaused;
          printPauseCont();
        }
        break;
      case '>':
        currentSong = (currentSong + 1) % NUMBER_OF_SONG;
        playSong();
        break;
      case '<':
        currentSong = (currentSong - 1 + NUMBER_OF_SONG) % NUMBER_OF_SONG;
        playSong();
        break;
      case '+':
        if (currentSpeed > 500) {
          currentSpeed -= (currentSpeed >= 1000) ? 100 : 50;
          top.setTempo(currentSpeed);
          printSpeed();
        }
        break;
      case '-':
        if (currentSpeed < 2000) {
          currentSpeed += (currentSpeed >= 1000) ? 100 : 50;
          top.setTempo(currentSpeed);
          printSpeed();
        }
        break;
      case '*':
        if (isDisplayIndicator) {
          onMute();
        }
        isDisplayIndicator = !isDisplayIndicator;
        printDisplayIndicatorStatus();
        break;
      case ']':
        top.setToneShift(1);
        toneShift++;
        initIndicator();
        printToneShift();
        break;
      case '[':
        top.setToneShift(-1);
        toneShift--;
        initIndicator();
        printToneShift();
        break;
      case 'c':
        isContinousMode = !isContinousMode;
        printContinousModeStatus();
        break;
      case 'r':
        isRepeatMode = !isRepeatMode;
        printRepeatModeStatus();
        break;
      case 's':
        Serial.println();
        if (isPlaying) {
          if (isPaused) {
            Serial.print(F("Paused "));
          }
          else {
            Serial.print(F("Playback "));
          }
        }
        printSongTitle(currentSong);
        printStatus();
        break;
      case 'l':
        printPlaylist();
        break;
      case '?':
      case 'h':
        printHelp();
        break;
    }
  }
}

void printHelp() {
  Serial.println((const __FlashStringHelper *)HELP);
}

void printStatus() {
  printContinousModeStatus();
  printRepeatModeStatus();
  printDisplayIndicatorStatus();
  printSpeed();
  printToneShift();
  Serial.println();
}

void printPlaylist() {
  Serial.println();
  Serial.println(F("Playlist:"));
  for (int8_t idx = 0; idx < NUMBER_OF_SONG; ++idx) {
    printSongTitle(idx);
  }
  Serial.println();
}

void printSongTitle(uint8_t songIdx) {
  Serial.print(F("Song "));
  Serial.print(songIdx + 1);
  Serial.print(F(": "));
  Serial.println((const __FlashStringHelper *)pgm_read_word_near(SONG_TITLE  + songIdx));
}

void printPauseCont() {
  if (isPaused) {
    Serial.println(F("Paused..."));
  }
  else {
    Serial.print(F("Continue playback "));
    printSongTitle(currentSong);
  }
}

void printSpeed() {
  Serial.print(F("Playback speed: "));
  Serial.print(1000.0 / currentSpeed);
  Serial.println(F("x"));
}

void printToneShift() {
  Serial.print(F("Tone shift: "));
  Serial.println(toneShift);
}

void printContinousModeStatus() {
  printOnOffStatus(F("Continous playback mode"), isContinousMode);
}

void printRepeatModeStatus() {
  printOnOffStatus(F("Repeat playback mode"), isRepeatMode);
}

void printDisplayIndicatorStatus() {
  printOnOffStatus(F("Display indicator"), isDisplayIndicator);
}

void printOnOffStatus(const __FlashStringHelper * fstr, bool status) {
  Serial.print(fstr);
  Serial.print(F(": "));
  Serial.println(status ? F("ON") : F("OFF"));
}