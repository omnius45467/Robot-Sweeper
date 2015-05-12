
//speaker
// TONES  ==========================================
// Start by defining the relationship between 
//       note, period, &  frequency. 
#define  c     3830    // 261 Hz 
#define  d     3400    // 294 Hz 
#define  e     3038    // 329 Hz 
#define  f     2864    // 349 Hz 
#define  g     2550    // 392 Hz 
#define  a     2272    // 440 Hz 
#define  b     2028    // 493 Hz 
#define  C     1912    // 523 Hz 
// Define a special note, 'R', to represent a rest
#define  R     0

//// SETUP ============================================
//// Set up speaker on a PWM pin (digital 9, 10 or 11)
int speakerGnd = 15;
int speakerOut = 14;
//random number
//long randNumber;
//// Do we want debugging on serial out? 1 for yes, 0 for no
int DEBUG = 1;

void speakerSetup() { 
  pinMode(speakerGnd, OUTPUT);
  pinMode(speakerOut, OUTPUT);
  if (DEBUG) { 
    Serial.begin(9600); // Set serial out if we want debugging
  } 
}

// MELODY and TIMING  =======================================
//  melody[] is an array of notes, accompanied by beats[], 
//  which sets each note's relative length (higher #, longer note) 
int melody[] = {  C,  b,  g,  C,  b,   e,  R,  C,  c,  g, a, C };
int beats[]  = { 16, 32, 3,  20,  8,  16, 32, 6, 6, 16, 8, 8 }; 
int MAX_COUNT = sizeof(melody) / 2; // Melody length, for looping.

// Set overall tempo
long tempo = 1000;
// Set length of pause between notes
int pause = 10;
// Loop variable to increase Rest length
int rest_count = 100; //<-BLETCHEROUS HACK; See NOTES

// Initialize core variables
int tone_ = 0;
int beat = 0;
long duration  = 0;

// PLAY TONE  ==============================================
// Pulse the speaker to play a tone for a particular duration
void playTone() {
//  int melody[] = {  C,  b,  g,  C,  b,   e,  R,  C,  c,  g, a, C };
//int beats[]  = { 16, 16, 16,  8,  8,  16, 32, 16, 16, 16, 8, 8 }; 
//int MAX_COUNT = sizeof(melody) / 2; // Melody length, for looping.
  long elapsed_time = 0;
  if (tone_ > 0) { // if this isn't a Rest beat, while the tone has 
    //  played less long than 'duration', pulse speaker HIGH and LOW
    while (elapsed_time < duration) {

      digitalWrite(speakerOut,HIGH);
      delayMicroseconds(tone_ / 200);

      // DOWN
      digitalWrite(speakerOut, LOW);
      delayMicroseconds(tone_ / 10);

      // Keep track of how long we pulsed
      elapsed_time += (tone_);
    } 
  }
  else { // Rest beat; loop times delay
    for (int j = 0; j < rest_count; j++) { // See NOTE on rest_count
      delayMicroseconds(duration);  
    }                                
  }                                 
}

// PLAY TONE  ==============================================
// Pulse the speaker to play a tone for a particular duration
void dangerTone() {
//  int melody[] = {  C,  b,  g,  C,  b,   e,  R,  C,  c,  g, a, C };
//int beats[]  = { 16, 16, 16,  8,  8,  16, 32, 16, 16, 16, 8, 8 }; 
//int MAX_COUNT = sizeof(melody) / 2; // Melody length, for looping.
  long elapsed_time = 0;
  if (tone_ > 0) { // if this isn't a Rest beat, while the tone has 
    //  played less long than 'duration', pulse speaker HIGH and LOW
    while (elapsed_time < duration) {

      digitalWrite(speakerOut,HIGH);
      delayMicroseconds(tone_ /200);

      // DOWN
      digitalWrite(speakerOut, LOW);
      delayMicroseconds(tone_ / 3.14);

      // Keep track of how long we pulsed
      elapsed_time += (tone_);
    } 
  }
  else { // Rest beat; loop times delay
    for (int j = 0; j < rest_count; j++) { // See NOTE on rest_count
      delayMicroseconds(duration);  
    }                                
  }                                 
}


// PLAY TONE  ==============================================
// Pulse the speaker to play a tone for a particular duration
void happyTone() {
//  int melody[] = {  C,  b,  g,  C,  b,   e,  R,  C,  c,  g, a, C };
//int beats[]  = { 16, 16, 16,  8,  8,  16, 32, 16, 16, 16, 8, 8 }; 
//int MAX_COUNT = sizeof(melody) / 2; // Melody length, for looping.
  long elapsed_time = 0;
  if (tone_ > 0) { // if this isn't a Rest beat, while the tone has 
    //  played less long than 'duration', pulse speaker HIGH and LOW
    while (elapsed_time < duration) {
  
  long randNumber;
  randNumber = random(1, 4);
  
      digitalWrite(speakerOut,HIGH);
      delayMicroseconds(tone_ / 200);

      // DOWN
      digitalWrite(speakerOut, LOW);
      delayMicroseconds(tone_ /4);

      // Keep track of how long we pulsed
      elapsed_time += (tone_);
    } 
  }
  else { // Rest beat; loop times delay
    for (int j = 0; j < rest_count; j++) { // See NOTE on rest_count
      delayMicroseconds(duration);  
    }                                
  }                                 
}

// PLAY TONE  ==============================================
// Pulse the speaker to play a tone for a particular duration
void happy2Tone() {
//  int melody[] = {  C,  b,  g,  C,  b,   e,  R,  C,  c,  g, a, C };
//int beats[]  = { 16, 16, 16,  8,  8,  16, 32, 16, 16, 16, 8, 8 }; 
//int MAX_COUNT = sizeof(melody) / 2; // Melody length, for looping.
  long elapsed_time = 0;
  if (tone_ > 0) { // if this isn't a Rest beat, while the tone has 
    //  played less long than 'duration', pulse speaker HIGH and LOW
    while (elapsed_time < duration) {
  
  long randNumber;
  randNumber = random(1, 4);
  
      digitalWrite(speakerOut,HIGH);
      delayMicroseconds(tone_ /20000 + randNumber);

      // DOWN
      digitalWrite(speakerOut, LOW);
      delayMicroseconds(tone_ /4);
      
        
      digitalWrite(speakerOut,HIGH);
      delayMicroseconds(tone_ /20000 + randNumber + 1000);

      // DOWN
      digitalWrite(speakerOut, LOW);
      delayMicroseconds(tone_ /4);

      // Keep track of how long we pulsed
      elapsed_time += (tone_);
    } 
  }
  else { // Rest beat; loop times delay
    for (int j = 0; j < rest_count; j++) { // See NOTE on rest_count
      delayMicroseconds(duration);  
    }                                
  }                                 
}
// PLAY TONE  ==============================================
// Pulse the speaker to play a tone for a particular duration
void warningTone() {
  
  long randNumber;
  randNumber = random(1, 4);
  
  long elapsed_time = 0;
  if (tone_ > 0) { // if this isn't a Rest beat, while the tone has 
    //  played less long than 'duration', pulse speaker HIGH and LOW
    while (elapsed_time < duration) {

      digitalWrite(speakerOut,HIGH);
      delayMicroseconds(tone_ / 20);

      // DOWN
      digitalWrite(speakerOut, LOW);
      delayMicroseconds(tone_ / 10 );

      // Keep track of how long we pulsed
      elapsed_time += (tone_);
    } 
  }
  else { // Rest beat; loop times delay
    for (int j = 0; j < rest_count; j++) { // See NOTE on rest_count
      delayMicroseconds(40);  
    }                                
  }                                 
}

// LET THE WILD RUMPUS BEGIN =============================
void playToneInit() {
  long randNumber;
  // Set up a counter to pull from melody[] and beats[]
  for (int i=0; i< MAX_COUNT; i++) {
    tone_ = melody[i];
    beat = beats[i];

    randNumber = random(10, 20);
    duration = beat * tempo * randNumber; // Set up timing

    playTone(); 
    // A pause between notes...
    delayMicroseconds(pause);

    if (DEBUG) { // If debugging, report loop, tone, beat, and duration
      Serial.print(i);
      Serial.print(":");
      Serial.print(beat);
      Serial.print(" ");    
      Serial.print(tone_);
      Serial.print(" ");
      Serial.println(duration);
    }
  }
}

// LET THE WILD RUMPUS BEGIN =============================
void warningInit() {
  long randNumber;
  // Set up a counter to pull from melody[] and beats[]
  for (int i=0; i<MAX_COUNT; i++) {
    tone_ = melody[i];
    beat = beats[i];

    randNumber = random(1, 20);
    duration = beat * tempo * randNumber; // Set up timing

    warningTone(); 
    // A pause between notes...
    delayMicroseconds(pause);

    if (DEBUG) { // If debugging, report loop, tone, beat, and duration
      Serial.print(i);
      Serial.print(":");
      Serial.print(beat);
      Serial.print(" ");    
      Serial.print(tone_);
      Serial.print(" ");
      Serial.println(duration);
    }
  }
}


// LET THE WILD RUMPUS BEGIN =============================
void dangerInit() {
  long randNumber;
  // Set up a counter to pull from melody[] and beats[]
  for (int i=0; i<MAX_COUNT; i++) {
    tone_ = melody[i];
    beat = beats[i];

    randNumber = random(1, 7);
    duration = beat * tempo * randNumber / 3.14; // Set up timing

    dangerTone(); 
    // A pause between notes...
    delayMicroseconds(pause);

    if (DEBUG) { // If debugging, report loop, tone, beat, and duration
      Serial.print(i);
      Serial.print(":");
      Serial.print(beat);
      Serial.print(" ");    
      Serial.print(tone_);
      Serial.print(" ");
      Serial.println(duration);
    }
  }
}

// LET THE WILD RUMPUS BEGIN =============================
void happyInit() {
  long randNumber;
  // Set up a counter to pull from melody[] and beats[]
  for (int i=0; i<MAX_COUNT; i++) {
    tone_ = melody[i];
    beat = beats[i];

    randNumber = random(1, 7);
    duration = beat * tempo * randNumber; // Set up timing

    happyTone(); 
    happy2Tone();
    // A pause between notes...
    delayMicroseconds(pause);

    if (DEBUG) { // If debugging, report loop, tone, beat, and duration
      Serial.print(i);
      Serial.print(":");
      Serial.print(beat);
      Serial.print(" ");    
      Serial.print(tone_);
      Serial.print(" ");
      Serial.println(duration);
    }
  }
}

//
///*
// * NOTES
// * The program purports to hold a tone for 'duration' microseconds.
// *  Lies lies lies! It holds for at least 'duration' microseconds, _plus_
// *  any overhead created by incremeting elapsed_time (could be in excess of 
// *  3K microseconds) _plus_ overhead of looping and two digitalWrites()
// *  
// * As a result, a tone of 'duration' plays much more slowly than a rest
// *  of 'duration.' rest_count creates a loop variable to bring 'rest' beats 
// *  in line with 'tone' beats of the same length. 
// * 
// * rest_count will be affected by chip architecture and speed, as well as 
// *  overhead from any program mods. Past behavior is no guarantee of future 
// *  performance. Your mileage may vary. Light fuse and get away.
// *  
// * This could use a number of enhancements:
// * ADD code to let the programmer specify how many times the melody should
// *     loop before stopping
// * ADD another octave
// * MOVE tempo, pause, and rest_count to #define statements
// * RE-WRITE to include volume, using analogWrite, as with the second program at
// *          http://www.arduino.cc/en/Tutorial/PlayMelody
// * ADD code to make the tempo settable by pot or other input device
// * ADD code to take tempo or volume settable by serial communication 
// *          (Requires 0005 or higher.)
// * ADD code to create a tone offset (higer or lower) through pot etc
// * REPLACE random melody with opening bars to 'Smoke on the Water'
// */

