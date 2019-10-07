#include "pitches.h"
#include <Keypad.h>

int speaker = 13;

#define led_1   10
#define led_2   11
#define led_3   12

#define play_length 250
#define rest_length 100

#define wait   100

int row_1 = 8;
int row_2 = 9;
int row_3 = 3;
int row_4 = 5;

int col_1 = 7;
int col_2 = 4;
int col_3 = 2;
int col_4 = 6;

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns


char keys[ROWS][COLS] = {
{'0','4','8','c'},
{'1','5','9','d'},
{'2','6','a','e'},
{'3','7','b','f'}
};

byte rowPins[ROWS] = {row_1, row_2, row_3, row_4}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {col_1, col_2, col_3, col_4}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

int octave = 4;

int notes[] = {};

//int notes[] = {
//   C4, CS4,  D4, DS4,
//   E4,  F4, FS4,  G4,
//  GS4,  A4, AS4,  B4
//};

void setup() {
  //Serial.begin(115200);
  //Serial.println("Starting...");
  pinMode(speaker, OUTPUT);
  pinMode(led_1,   OUTPUT);
  pinMode(led_2,   OUTPUT);
  pinMode(led_3,   OUTPUT);
}

void loop() {
  char key = keypad.getKey();

    int notes[12] = {
       C4, CS4,  D4, DS4,
       E4,  F4, FS4,  G4,
      GS4,  A4, AS4,  B4
    };

  if (octave == 3){
    int notes[12] = {
       C3, CS3,  D3, DS3,
       E3,  F3, FS3,  G3,
      GS3,  A3, AS3,  B3
    };
  }

  if (octave == 4){
    int notes[12] = {
       C4, CS4,  D4, DS4,
       E4,  F4, FS4,  G4,
      GS4,  A4, AS4,  B4
    };
  }

  if (octave == 5){
    int notes[12] = {
       C5, CS5,  D5, DS5,
       E5,  F5, FS5,  G5,
      GS5,  A5, AS5,  B5
    };
  }


  if (key){
    if (key=='0'){playNote(notes[0],  play_length, rest_length);}
    if (key=='1'){playNote(notes[1], play_length, rest_length);}
    if (key=='2'){playNote(notes[2],  play_length, rest_length);}
    if (key=='3'){playNote(notes[3], play_length, rest_length);}
    if (key=='4'){playNote(notes[4],  play_length, rest_length);}
    if (key=='5'){playNote(notes[5],  play_length, rest_length);}
    if (key=='6'){playNote(notes[6], play_length, rest_length);}
    if (key=='7'){playNote(notes[7],  play_length, rest_length);}
    if (key=='8'){playNote(notes[8], play_length, rest_length);}
    if (key=='9'){playNote(notes[9],  play_length, rest_length);}
    if (key=='a'){playNote(notes[10], play_length, rest_length);}
    if (key=='b'){playNote(notes[11],  play_length, rest_length);}
    
    //FUNCT1
    if (key=='c'){playNote(C3,  play_length, rest_length);}
    //FUNCT2
    if (key=='d'){playNote(C4,  play_length, rest_length);}
    //FUNCT3
    if (key=='e'){playNote(C5,  play_length, rest_length);}
    //FUNT4
    if (key=='f'){playNote(C6,  play_length, rest_length);}
   
  }

}

void playNote(int note, int duration, int rest) {
  digitalWrite(led_2, HIGH);
  tone(speaker, note, duration);
  delay(rest);
  digitalWrite(led_2, LOW);
}
