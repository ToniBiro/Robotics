#pragma once
#include "LedControl.h" //  need the library
# include <LiquidCrystal.h>
# include <EEPROM.h>
# include <string.h>
#include <time.h>
#include <Arduino.h>  // for type definitions

LedControl lc = LedControl(12, 11, 10, 1); //DIN, CLK, LOAD, No. DRIVER
int addr = 0;
const int RS = 9;
const int enable = 8;
const int d4 = 7;
const int d5 = 6;
const int d6 = 5;
const int d7 = 4;
LiquidCrystal lcd(RS, enable, d4, d5, d6, d7);

const int swPin = 2;
const int xPin = A1;
const int yPin = A0;
const int buttonPin = A5;
const int buzzer = A4;

int checkButton = 0;

struct cursorPoz{
  int x, y;
};

struct dino{
  cursorPoz fp, sp;
};

unsigned long lastPrint = 0;
unsigned long lastSwDebounceTime = 0;
unsigned long lastDebounceTime = 0;
int debounceDelay = 50;
int pushSwState = 0;
int pushButtonState = 1;
int buttonState = 1;
int lastButtonState = 1;
int lastSwState = 0;
const int minThreshold = 400;
const int maxThreshold = 600;
int xValue;
int yValue;
int swState;
bool joyMoved = false;
cursorPoz cp = {1, 0};
cursorPoz cpPrev;
dino dino1 = {6, 1, 5, 1};
dino dino2 = {2, 6, 1, 6};
int upCheck = 0, downCheck = 0;
double gameSpeed = 5000;
const double speedConst = 2500000;
const double jumpConst = 2500;
unsigned long speedTimer;
unsigned long downTime, upTime;
int var = 4;
double jumpInterval = gameSpeed/2/var;


struct highScore{
  char na[5];
  double sc;
}; 

struct highScores{
  highScore hs[3];
};

highScores theHS;

int beatHS = 0;
char nameDino1[5], nameDino2[5];
double scoreDino1 = 0, scoreDino2 = 0;
int livesDino1 = 3, livesDino2 = 3;

int first = 1, sec, third, four;
int done = 1;

int nObstacle = 14;
unsigned long startTime = 0;


unsigned char obstacle[][14] = {
  {B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000},
  {B00000000, B00000001, B00000010, B00000100, B00001000, B00010000, B00100000, B01000000, B10000000, B00000000, B00000000, B00000000, B00000000, B00000000},
  {B00000000, B00000011, B00000110, B00001100, B00011000, B00110000, B01100000, B11000000, B10000000, B00000000, B00000000, B00000000, B00000000, B00000000},
  {B00000000, B00000011, B00000110, B00001100, B00011000, B00110001, B01100010, B11000100, B10001000, B00010000, B00100000, B01000000, B10000000, B00000000},
  {B00000000, B00000001, B00000010, B00000100, B00001000, B00010001, B00100010, B01000100, B10001000, B00010000, B00100000, B01000000, B10000000, B00000000}
};

int here = 1;
int heightObstacle1 = 6, heightObstacle2 = 1;
int idx1, idx2;
int frame1 = 0, frame2 = 0;

int dino1Collision = 0;
int dino2Collision = 0;
int colFlag1 = 0;
int colFlag2 = 0;

int attackFrame = 14 - 7;
int auxFrame = 0;
int auxHere = 1;
int attackHeight;
unsigned long attackTime;
int attackCheck = 0;


int lcdState = 0;
int cursorPosition = 0;

int againCursor = 1;
int check7;
int canTheGameStart = 0;

int check6 = 1;

int lifeGainCounter1 = 0, lifeGainCounter2 = 0;
