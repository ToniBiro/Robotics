//THE DINO GAME

#include "global_variables.h"
#include "dino.h"


//###### EEPROM code##################

template <class T> int EEPROM_writeAnything(int ee, const T& value)
{
    const byte* p = (const byte*)(const void*)&value;
    unsigned int i;
    for (i = 0; i < sizeof(value); i++)
          EEPROM.write(ee++, *p++);
    return i;
}

template <class T> int EEPROM_readAnything(int ee, T& value)
{
    byte* p = (byte*)(void*)&value;
    unsigned int i;
    for (i = 0; i < sizeof(value); i++)
          *p++ = EEPROM.read(ee++);
    return i;
}

//###### end EEPROM code##################

//###### menu code##################

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

void print_intro(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("THE DINO GAME!");
  lcd.setCursor(0, 1);
  lcd.print("PRESS THE BUTTON");
}

void print_main_menu(){
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Start");
  lcd.setCursor(8, 0); 
  lcd.print("Settings");
  lcd.setCursor(1, 1);
  lcd.print("HighScore");
  lcd.setCursor(12, 1);
  lcd.print("Info"); 
}

void print_play(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.write(byte(0));
  lcd.setCursor(15, 0);
  lcd.write(byte(0));
  lcd.setCursor(7, 1);
  lcd.print("::");
  lcd.setCursor(1, 0);
  lcd.print(livesDino1);
  lcd.setCursor(14, 0);
  lcd.print(livesDino2);
  lcd.setCursor(0, 1);
  lcd.print(scoreDino1);
  lcd.setCursor(9, 1);
  lcd.print(scoreDino2);
}

void print_end_message(){
  lcd.clear();
  if(scoreDino1 > scoreDino2){
    lcd.setCursor(0, 0);
    lcd.print(nameDino1);
    lcd.setCursor(4, 0);
    lcd.print(" WON");
  }
  else{
    if(scoreDino1 < scoreDino2){
      lcd.setCursor(0, 0);
      lcd.print(nameDino2);
      lcd.setCursor(4, 0);
      lcd.print(" WON");
    }
    else{
      lcd.setCursor(0, 0);
      lcd.print("IT IS A TIE!");
    }
  }

  lcd.setCursor(0, 1);
  lcd.print("D1:");
  lcd.setCursor(3, 1);
  lcd.print(scoreDino1);
  lcd.setCursor(8, 1);
  lcd.print("D2:");
  lcd.setCursor(11, 1);
  lcd.print(scoreDino2);
}

void print_new_hs(){
  lcd.clear();
  if(beatHS == 1){
    lcd.setCursor(0, 0);
    lcd.print("New HighScore:");
    lcd.setCursor(0, 1);
    lcd.print(nameDino1);
    lcd.setCursor(4, 1);
    lcd.print(":");
    lcd.setCursor(5, 1);
    lcd.print(scoreDino1);
  }
  if(beatHS == 2){
    lcd.setCursor(0, 0);
    lcd.print("New HighScore:");
    lcd.setCursor(0, 1);
    lcd.print(nameDino2);
    lcd.setCursor(4, 1);
    lcd.print(":");
    lcd.setCursor(5, 1);
    lcd.print(scoreDino2);
  }
}

void print_play_again(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(">");
  lcd.setCursor(1, 0);
  lcd.print("Play again?");
  lcd.setCursor(1, 1);
  lcd.print("Back to Main Menu");
}

//###### end menu code##################

//######debounce code##################

void debounce(bool reading){
  if (reading != lastSwState) {
    lastSwDebounceTime = millis();
  }

  if ((millis() - lastSwDebounceTime) > debounceDelay) {
    if (reading != pushSwState) {
      pushSwState = reading;

      if (pushSwState == HIGH) {
        swState = !swState;
      }
    }
  }
  lastSwState = reading;
}

void debounceButton(bool reading){
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != pushButtonState) {
      pushButtonState = reading;

      if (pushButtonState == HIGH){
        buttonState = !buttonState;
      }
    }
  }
  lastButtonState = reading;
}

//######end debounce code##################

//###### dino 1 code##################

//######end dino 1 code##################

//###### obstacle code###################

//######end obstacle code##################

//###### collisinons code##################

//###### end collisinons code##################

//###### attack code##################

//###### end attack code##################


//###### in game code##################

//###### end in game code##################

void setup()
{
  for(int i = 0; i < 3; ++i){
    strcpy(theHS.hs[i].na, "AAAA");
    theHS.hs[i].sc = 0;
  }
  
  strcpy(nameDino1, "AAAA");
  strcpy(nameDino2, "AAAA");
  srand(time(NULL));
  
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.createChar(0, heart);
  print_intro();
  //delay(5000);
  
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(swPin, INPUT_PULLUP);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
  // the zero refers to the MAX7219 number, it is zero for 1 chip
  lc.shutdown(0, false); // turn off power saving, enables display
  lc.setIntensity(0, 15); // sets brightness (0~15 possible values)
  lc.clearDisplay(0);// clear screen
  
  init_ground();
  poz_dino(dino1);
  poz_dino(dino2);
}

void loop(){
  
  xValue = analogRead(xPin);
  yValue = analogRead(yPin);
  int swValue = digitalRead(swPin);
  debounceButton(digitalRead(buttonPin));
  debounce(swValue);

  if(buttonState == 1 && checkButton == 0){
    print_intro();
    checkButton = 1;
  }

  if(buttonState == 0 && checkButton == 1){
    checkButton = 0;
    swState = 1;
    lcdState = 0;
  }

  if(swState == 1 && lcdState == 0 && buttonState == 0){
    print_main_menu();
    lcd.setCursor(0, 0);
    lcd.print(">");
    cursorPosition = 1;
    lcdState = 1;
  }
  
  if (xValue > maxThreshold && joyMoved == false && swState == 1 && lcdState == 1) {
    if(cursorPosition >= 4)
      cursorPosition = 1;
    else
      cursorPosition++;
    print_main_menu();
    if(cursorPosition == 1){
      lcd.setCursor(0, 0);
      lcd.print(">");
    }
    else{
      if(cursorPosition == 2){
        lcd.setCursor(7, 0);
        lcd.print(">");
      }
      else{
        if(cursorPosition == 3){
          lcd.setCursor(0, 1);
          lcd.print(">");
        }
        else{
          lcd.setCursor(11, 1);
          lcd.print(">");
        }
          
      }
    }
    joyMoved = true;
  }

  if (xValue >= minThreshold && xValue <= maxThreshold && yValue >= minThreshold && yValue <= maxThreshold) {
    joyMoved= false;
  }

  if(swState == 0 && cursorPosition == 1 && lcdState == 1){
    lcdState = 2;
    canTheGameStart = 1;
  }

  if(lcdState == 2){
    // start the game
    if(canTheGameStart == 1){
      lcd.clear();
      lcd.setCursor(8, 0);
      lcd.print("READY?");
      lcd.setCursor(7, 1);
      lcd.print("START!!");
      delay(2000);
      print_play();
      scoreDino1 = 0;
      scoreDino2 = 0;
      livesDino1 = 3;
      livesDino2 = 3;
      startTime = millis();
      canTheGameStart = 0;
    }
    inGame();
  }

  if(lcdState == 6){
    if(check6 == 1){
      print_end_message();
      check6 = 0;
    }
    
    if(beatHS != 0){
      print_new_hs();
      
      beatHS = 0;
    }
    lcdState = 7;
    if(swState == 1){
      check7 = 1;
      lcdState = 7;
    }
    
  }

  if(lcdState == 7){
    if(check7 == 1){
      print_play_again();
      check7 = 0;
    }
    if (xValue > maxThreshold && joyMoved == false){
      if(againCursor == 1){
        againCursor = 2;
        lcd.setCursor(0, 0);
        lcd.print(" ");
        lcd.setCursor(0, 1);
        lcd.print(">");
      }
      else{
          if(againCursor == 2){
            againCursor = 1;
            lcd.setCursor(0, 1);
            lcd.print(" ");
            lcd.setCursor(0, 0);
            lcd.print(">");
          }
      }
      joyMoved = true;
    }
    if (xValue < minThreshold && joyMoved == false){
      if(againCursor == 1){
        againCursor = 2;
        lcd.setCursor(0, 0);
        lcd.print(" ");
        lcd.setCursor(0, 1);
        lcd.print(">");
      }
      else{
          if(againCursor == 2){
            againCursor = 1;
            lcd.setCursor(0, 1);
            lcd.print(" ");
            lcd.setCursor(0, 0);
            lcd.print(">");
          }
      }
      joyMoved = true;
    }
    if (xValue >= minThreshold && xValue <= maxThreshold && yValue >= minThreshold && yValue <= maxThreshold) {
      joyMoved= false;
    }
    if(swState == 1 && againCursor == 1){
      swState = 0;
      canTheGameStart = 1;
      lcdState = 2;
    }
    if(swState == 1 && againCursor == 2){
      lcdState = 0;
      canTheGameStart = 1;
    }
  }
}
