#include "LedControl.h" //  need the library
#include <time.h>
LedControl lc = LedControl(12, 11, 10, 1); //DIN, CLK, LOAD, No. DRIVER
 
// pin 12 is connected to the MAX7219 pin 1
// pin 11 is connected to the CLK pin 13
// pin 10 is connected to LOAD pin 12
// 1 as we are only using 1 MAX7219

unsigned char A[] = {B00000000,B00111100,B01100110,B01100110,B01111110,B01100110,B01100110,B01100110};
unsigned char B[] = {B01111000,B01001000,B01001000,B01110000,B01001000,B01000100,B01000100,B01111100};
unsigned char C[] = {B00000000,B00011110,B00100000,B01000000,B01000000,B01000000,B00100000,B00011110};
unsigned char D[] = {B00000000,B00111000,B00100100,B00100010,B00100010,B00100100,B00111000,B00000000};
unsigned char E[] = {B00000000,B00111100,B00100000,B00111000,B00100000,B00100000,B00111100,B00000000};
unsigned char F[] = {B00000000,B00111100,B00100000,B00111000,B00100000,B00100000,B00100000,B00000000};
unsigned char G[] = {B00000000,B00111110,B00100000,B00100000,B00101110,B00100010,B00111110,B00000000};
unsigned char H[] = {B00000000,B00100100,B00100100,B00111100,B00100100,B00100100,B00100100,B00000000};
unsigned char I[] = {B00000000,B00111000,B00010000,B00010000,B00010000,B00010000,B00111000,B00000000};
unsigned char J[] = {B00000000,B00011100,B00001000,B00001000,B00001000,B00101000,B00111000,B00000000};
unsigned char K[] = {B00000000,B00100100,B00101000,B00110000,B00101000,B00100100,B00100100,B00000000};
unsigned char L[] = {B00000000,B00100000,B00100000,B00100000,B00100000,B00100000,B00111100,B00000000};
unsigned char M[] = {B00000000,B00000000,B01000100,B10101010,B10010010,B10000010,B10000010,B00000000};
unsigned char N[] = {B00000000,B00100010,B00110010,B00101010,B00100110,B00100010,B00000000,B00000000};
unsigned char O[] = {B00000000,B00111100,B01000010,B01000010,B01000010,B01000010,B00111100,B00000000};
unsigned char P[] = {B00000000,B00111000,B00100100,B00100100,B00111000,B00100000,B00100000,B00000000};
unsigned char Q[] = {B00000000,B00111100,B01000010,B01000010,B01000010,B01000110,B00111110,B00000001};
unsigned char R[] = {B00000000,B00111000,B00100100,B00100100,B00111000,B00100100,B00100100,B00000000};
unsigned char S[] = {B00000000,B00111100,B00100000,B00111100,B00000100,B00000100,B00111100,B00000000};
unsigned char T[] = {B00000000,B01111100,B00010000,B00010000,B00010000,B00010000,B00010000,B00000000};
unsigned char U[] = {B00000000,B01000010,B01000010,B01000010,B01000010,B00100100,B00011000,B00000000};
unsigned char V[] = {B00000000,B00100010,B00100010,B00100010,B00010100,B00010100,B00001000,B00000000};
unsigned char W[] = {B00000000,B10000010,B10010010,B01010100,B01010100,B00101000,B00000000,B00000000};
unsigned char X[] = {B00000000,B01000010,B00100100,B00011000,B00011000,B00100100,B01000010,B00000000};
unsigned char Y[] = {B00000000,B01000100,B00101000,B00010000,B00010000,B00010000,B00010000,B00000000};
unsigned char Z[] = {B00000000,B00111100,B00000100,B00001000,B00010000,B00100000,B00111100,B00000000};

const int swPin = 9;
const int xPin = A0;
const int yPin = A1;

struct cursorPoz{
  int x, y;
};

unsigned long lastPrint = 0;
unsigned long lastDebounceTime = 0;
int debounceDelay = 50;
int buttonState= 0;
int lastButtonState = 0;
const int minThreshold = 400;
const int maxThreshold = 600;
int xValue;
int yValue;
int swState;
bool joyMoved = false;
cursorPoz cp;
cursorPoz cpPrev;
cursorPoz walls[30];

void debounce(bool reading){
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;

      if (buttonState == HIGH) {
        swState = !swState;
      }
    }
  }
  lastButtonState = reading;
}

cursorPoz init_cursor_poz(){
  cursorPoz a;
  a.x = 0;
  a.y = 0;
  return a;
}



void init_walls(cursorPoz *walls){

  int ct = 0;
  for(int l = 0; l <= rand()%4; ++l){
    for (int i = rand()%3 + 1; i < rand()%3 + 4; ++i){
      for (int j = 0; j < rand()%4; ++j){
        walls[ct].x = i;
        walls[ct].y = j; 
        lc.setLed(0, walls[ct].x, walls[ct].y, true);
        ct++;
      }
    }
  }
}

void setup()
{
  srand(time(NULL));
  
  Serial.begin(9600);
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(swPin, INPUT);
  // the zero refers to the MAX7219 number, it is zero for 1 chip
  lc.shutdown(0, false); // turn off power saving, enables display
  lc.setIntensity(0, 6); // sets brightness (0~15 possible values)
  lc.clearDisplay(0);// clear screen
  init_walls(walls);
  
  cp = init_cursor_poz();
  
}

void print_dead(){
  for(int row = 0; row < 8; ++row){
    lc.setRow(0, row, D[row]);
  }
  delay(1000);
  for(int row = 0; row < 8; ++row){
    lc.setRow(0, row, E[row]);
  }
  delay(1000);
  for(int row = 0; row < 8; ++row){
    lc.setRow(0, row, A[row]);
  }
  delay(1000);
  for(int row = 0; row < 8; ++row){
    lc.setRow(0, row, D[row]);
  }
  delay(1000);
}

void loop()
{
  xValue = analogRead(xPin);
  yValue = analogRead(yPin);
  int swValue = digitalRead(swPin);
  debounce(swValue);
  Serial.println(cp.x);
  Serial.println(cp.y);
//  Serial.println(swState);
  
  if (xValue > maxThreshold && joyMoved == false && swState == 0) {
    cpPrev = cp;
    if(cp.x <= 0){
      cp.x = 7;
    }
    else{
      cp.x--;
    }
    joyMoved = true;
  }
  if (xValue < minThreshold && joyMoved == false && swState == 0) {
    cpPrev = cp;
    if(cp.x >= 7){
      cp.x = 0;
    }
    else{
      cp.x++;
    }
    joyMoved = true;
  }
  if (yValue > maxThreshold && joyMoved == false && swState == 0) {
    cpPrev = cp;
    if(cp.y >= 7){
      cp.y = 0;
    }
    else{
      cp.y++;
    }
    joyMoved = true;
  }
  if (yValue < minThreshold && joyMoved == false && swState == 0) {
    cpPrev = cp;
    if(cp.y <= 0){
      cp.y = 7;
    }
    else{
      cp.y--;
    }
    joyMoved = true;
  }
  
  if (xValue >= minThreshold && xValue <= maxThreshold && yValue >= minThreshold && yValue <= maxThreshold) {
    joyMoved= false;
  }

  for(int i = 0; i < 30; ++i){
    if(walls[i].x == cp.x && walls[i].y == cp.y){
      //print_dead();
      cp = init_cursor_poz();
      init_walls(walls);
    }
  }

  lc.setLed(0, cp.x, cp.y, true);
  lc.setLed(0, cpPrev.x, cpPrev.y, false);
  
}
