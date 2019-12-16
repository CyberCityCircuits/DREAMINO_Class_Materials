#include "keyboard.h"
#include <Keypad.h>

Keypad buttons = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

int play_length = 250;

void setup() {
  pinMode(speaker, OUTPUT);
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(led_3, OUTPUT);
}

void loop() {
  char key = buttons.getKey();

  if (key){
    if (key == '0'){playNote(notes[0]); }
    if (key == '1'){playNote(notes[1]); }
    if (key == '2'){playNote(notes[2]); }
    if (key == '3'){playNote(notes[3]); }
    if (key == '4'){playNote(notes[4]); }
    if (key == '5'){playNote(notes[5]); }
    if (key == '6'){playNote(notes[6]); }
    if (key == '7'){playNote(notes[7]); }
    if (key == '8'){playNote(notes[8]); }
    if (key == '9'){playNote(notes[9]); }
    if (key == 'a'){playNote(notes[10]);}
    if (key == 'b'){playNote(notes[11]);}

    //Function 1
    if (key == 'c'){playMary();}
    //Function 2
    if (key == 'd'){}
    //Function 3
    if (key == 'e'){}
    //Function 4
    if (key == 'f'){}
  }
}

void playNote(int note){
  digitalWrite(led_2, HIGH);
  tone(speaker, note, play_length);
  delay(play_length);
  digitalWrite(led_2, LOW);  
}

void playMary(){
  playNote(GS); delay(100);
  playNote(FS); delay(100);
  playNote(E); delay(100);
  playNote(FS); delay(100);
  playNote(GS); delay(100);
  playNote(GS); delay(100);
  playNote(GS); delay(100);
  playNote(FS); delay(100);
  playNote(FS); delay(100);
  playNote(FS); delay(100);
  playNote(GS); delay(100);
  playNote(B); delay(100);
  playNote(B); delay(100);
  playNote(GS); delay(100);
  playNote(FS); delay(100);
  playNote(FS); delay(100);
  playNote(GS); delay(100);
  playNote(FS); delay(100);
  playNote(E); delay(100);
  
}
