# include "pitches.h"

int melody[] = {A6, FS6, G6, A6, FS6, G6, A6, A5, B5, CS6, D6, E6, FS6, G6, FS6, D6, E6, FS6, FS5, G5, A5, B5, A5, G5, A5, FS5, G5, A5, G5, B5, A5, G5, FS5, E5, FS5, E5, D5, E5, FS5, G5, A5, B5, G5, B5, A5, B5, CS6, D6, A5, B5, CS6, D6, E6, FS6, G6, A6};

//int melody[] = {'A6', 'FS6', 'G6', 'A6', 'FS6', 'G6', 'A6', 'A5', 'B5', 'CS6', 'D6', 'ES6', 'FS6', 'G6', 'FS6', 'D6', 'E6', 'FS6', 'FS5', 'G5', 'A5', 'B5', 'A5', 'G5', 'A5', 'FS5', 'G5', 'A5', 'G5', 'B5', 'A5', 'G5', 'FS5', 'E5', 'FS5', 'E5', 'D5', 'E5', 'FS5', 'G5', 'A5', 'B5', 'G5', 'B5', 'A5', 'B5', 'CS6', 'D6', 'A5', 'B5', 'CS6', 'D6', 'E6', 'FS6', 'G6', 'A6'};

int noteDurations[] = {8, 16, 16, 8, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 8, 16, 16, 8, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 8, 16, 16, 8, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 8, 16, 16, 8, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16};

#define speakerPin 13

void setup() {
  // iterate over the notes of the melody:
  pinMode (speakerPin, OUTPUT);
}

void loop() {

  for (int i = 0; i < 56; i++) {

    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 2500 / noteDurations[i];
    tone(speakerPin, melody[i], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
  }
  
}
