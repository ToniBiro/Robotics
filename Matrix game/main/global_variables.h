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
const int swPin2 = 3;
const int xPin2 = A2;
const int yPin2 = A3;
const int buttonPin = A5;
const int buzzer = A4;
const int lcdLed = 13;

int checkButton = 0;

struct cursorPoz{
  int x, y;
};

struct dino{
  cursorPoz fp, sp;
};

// for debounces

unsigned long lastPrint = 0;
unsigned long lastSwDebounceTime = 0;
unsigned long lastSwDebounceTime2 = 0;
unsigned long lastDebounceTime = 0;
int debounceDelay = 50;
int pushSwState = 0;
int pushSwState2 = 0;
int pushButtonState = 1;

int lastButtonState = 1;
int lastSwState = 0;
int lastSwState2 = 0;
const int minThreshold = 400;
const int maxThreshold = 600;
int xValue;
int yValue;
int xValue2;
int yValue2;

int buttonState = 1;
int swState;
int swState2;

// for the dinos movements

int canTheGameStart = 0;
bool joyMoved = false;
bool joyMoved2 = false;
dino dino1 = {6, 1, 5, 1};  // the initial dino positions
dino dino2 = {2, 6, 1, 6};
int upCheck = 0, downCheck = 0, upCheck2 = 0, downCheck2 = 0;
double gameSpeed = 9000;
const double speedConst = 2500000;
const double jumpConst = 2500;
unsigned long speedTimer;
unsigned long downTime, upTime, downTime2, upTime2;
double var = 8;
double jumpInterval = (20000000/(20000*var));
double jumpInterval2 = (20000000/(20000*var));

// for the highScore

struct highScore{
  char na[5];
  int sc;
}; 

struct highScores{
  highScore hs[3];
};

highScores theHS;
int beatHS = 0;

char nameDino1[5], nameDino2[5];
int scoreDino1 = 0, scoreDino2 = 0;
int livesDino1 = 3, livesDino2 = 3;
unsigned long scoreTime1, scoreTime2;
int lifeGainCounter1 = 0, lifeGainCounter2 = 0;

int first = 1, sec, third, four;
int first2 = 1, sec2, third2, four2;
int done = 1, done2 = 1;

// for the obstacles 

int nObstacle = 14;
unsigned long startTime = 0;


unsigned char obstacle[][14] = {
  {B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000},
  {B00000000, B00000001, B00000010, B00000100, B00001000, B00010000, B00100000, B01000000, B10000000, B00000000, B00000000, B00000000, B00000000, B00000000},
  {B00000000, B00000011, B00000110, B00001100, B00011000, B00110000, B01100000, B11000000, B10000000, B00000000, B00000000, B00000000, B00000000, B00000000},
  {B00000000, B00000011, B00000110, B00001100, B00011000, B00110001, B01100010, B11000100, B10001000, B00010000, B00100000, B01000000, B10000000, B00000000},
  {B00000000, B00000001, B00000010, B00000100, B00001000, B00010001, B00100010, B01000100, B10001000, B00010000, B00100000, B01000000, B10000000, B00000000}
};

unsigned char initMatrix[]{
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000
};

byte heart[] = {
  B00000,
  B01010,
  B11111,
  B11111,
  B11111,
  B11111,
  B01110,
  B00100
};

// for attack

int here = 1;
int heightObstacle1 = 6, heightObstacle2 = 1;
int idx1, idx2;
int frame1 = 0, frame2 = 0;

int attackFrame = 14 - 7;
int attackFrame2 = 2;
int auxFrame = 0;
int auxFrame2 = 0;
int auxHere = 1, auxHere2 = 1;
int attackHeight;
unsigned long attackTime;
int attackCheck = 0;
int attackHeight2;
unsigned long attackTime2;
int attackCheck2 = 0;

// for collisions

int dino1Collision = 0;
int dino2Collision = 0;
int colFlag1 = 0;
int colFlag2 = 0;


int lcdState = 0;
int cursorPosition = 0;

int againCursor = 1;
int check7;

int check6 = 1;
int check10 = 1;
int check9 = 1;

int check3 = 1;
int check3_1 = 0;

int check4 = 1;
int check4_1 = 0;

int check5 = 1;
int check5_1 = 0;

// for the settings

int lineScroll = 0;
int letter = 0;
char lcdLedControl[4] = "ON";

unsigned long blinkTime;

char letters[][17] = {
  {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P'},
  {'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z'}
};

int caret = 0;
int lcdLedValue = 1;
