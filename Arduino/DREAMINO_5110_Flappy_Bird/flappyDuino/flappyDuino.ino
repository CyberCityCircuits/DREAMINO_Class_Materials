//This is a port of the Flappy Bird on Arduino Project
//found at https://hackaday.io/project/3981-flappy-bird-on-arduino
//Author: https://hackaday.io/huy
//Ported to the DREAMINO 5110 Gamer Set 04/11/2019

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

//Assign Pins for DREAMINO 5110 Gamer
#define SW_01       7
#define SW_02       6
#define SW_03       9
#define SW_04       5
#define SW_05       8
#define SW_06       2
#define SW_07       0
#define SW_08       3
#define SW_09       4
#define SW_10       1
#define light_1    12
#define light_2    11
#define light_3    10
#define speakerPin 13
#define BL         14
#define CLK        15
#define DIN        16
#define DC         17
#define CS         18
#define RST        19

Adafruit_PCD8544 display = Adafruit_PCD8544(CLK, DIN, DC, CS, RST); 

#include "Sprite.h"
#include "Chym.h"
#include "Bar.h"

Chym player;
Bar bar; Bar bar2;
int gameScore = 0;

boolean clicked = false;

void loop(){}

void resetGame() {
  player.respawn();
  bar.setPos(0, 20);
  bar2.setPos(50, 30);
  gameScore = 0;
}

void setup() {
  Serial.begin(9600);

  display.begin();
  display.setContrast(50);
  display.clearDisplay();
  display.display();

  pinMode(SW_01,   INPUT_PULLUP);
  pinMode(BL, OUTPUT);
  digitalWrite(BL, LOW);
  
  resetGame();
  
  while(1) {
    getInput();
    player.update();
    bar.update(); bar2.update();
    drawLCD();
  }
}

void getInput() {
  int knock = digitalRead(SW_01);
  if (knock == 0) { // push down
    clicked = true;
  } 
  else {
    clicked = false;
  }
}

void drawLCD() {
  display.clearDisplay();

  if (!player.isDead()) {
    int ht1 = bar.hitTest(player.getX(), player.getY());
    int ht2 = bar2.hitTest(player.getX(), player.getY());
    int die = ht1 + ht2;
    if (die == 1) {
        // game over
        player.die();
    }

    if (clicked) {
      player.flyUp();
    } 
    else {
      player.cancelJump();
    }
    player.render();	
    
    bar.render(); bar2.render(); 
  } 
  else {
    display.setCursor(0, 0);
    display.setTextSize(2);
    display.println("Game   Over!!!");
    if (clicked) {
      resetGame();
    }
  }

  display.display();
}
