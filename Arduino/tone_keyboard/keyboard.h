//Assign pins for buttons
int row_1 = 8;
int row_2 = 9;
int row_3 = 3;
int row_4 = 5;
int col_1 = 7;
int col_2 = 4;
int col_3 = 2;
int col_4 = 6;

//Assign pins for LEDs
int led_1 = 10;
int led_2 = 11;
int led_3 = 12;

//Assign pins for Speaker
int speaker = 13;

//how many columns and rows do we have
const byte ROWS = 4;
const byte COLS = 4;

//Connect row and col pins to keypad
byte rowPins[ROWS] = {row_1, row_2, row_3, row_4};
byte colPins[COLS] = {col_1, col_2, col_3, col_4};

//Name the different buttons for the keypad
char keys[ROWS][COLS] = {
  {'0', '4', '8', 'c'},
  {'1', '5', '9', 'd'},
  {'2', '6', 'a', 'e'},
  {'3', '7', 'b', 'f'}
};

//Assign tone values
int C  = 262;
int CS = 277;
int D  = 294;
int DS = 311;
int E  = 330;
int F  = 349;
int FS = 370;
int G  = 392;
int GS = 415;
int A  = 440;
int AS = 466;
int B  = 494;

//list of notes
int notes[12] = {
   C, CS,  D, DS,
   E,  F, FS,  G,
  GS,  A, AS,  B
};
