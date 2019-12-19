//THE DINO GAME

#include "global_variables.h"
#include "dino.h"
#include "messages.h"
#include "debounce.h"
#include "eepromActions.h"
#include "settings.h"

void setup(){
  Serial.begin(9600);
//  for(int i = 0 ; i < 3; ++i){
//    strcpy(theHS.hs[i].na, "AAAA");
//    theHS.hs[i].sc = 0;
//  }
//  EEPROM_writeAnything(0, theHS);
  EEPROM_readAnything(0, theHS);
  
  strcpy(nameDino1, "AAAA");
  strcpy(nameDino2, "BBBB");
  srand(time(NULL));
  
  
  lcd.begin(16, 2);
  lcd.createChar(0, heart);
  print_intro();
  //delay(5000);

  pinMode(lcdLed, OUTPUT);
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(xPin2, INPUT);
  pinMode(yPin2, INPUT);
  pinMode(swPin, INPUT_PULLUP);
  pinMode(swPin2, INPUT_PULLUP);
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

  digitalWrite(lcdLed, lcdLedValue);
  xValue = analogRead(xPin);
  yValue = analogRead(yPin);
  xValue2 = analogRead(xPin2);
  yValue2 = analogRead(yPin2);
  int swValue = digitalRead(swPin);
  int swValue2 = digitalRead(swPin2);
  
  debounceButton(digitalRead(buttonPin));
  debounceDino1(swValue);
  debounceDino2(swValue2);

  if(buttonState == 1 && checkButton == 0){
    lcd.clear();
    print_intro();
    checkButton = 1;
    lcdState = 0;
  }

  if(buttonState == 0 && checkButton == 1){
    checkButton = 0;
    swState = 1;
    lcdState = 0;    
  }

  if(lcdState == 0 && buttonState == 0){
    print_main_menu();
    lcd.setCursor(0, 0);
    lcd.print(">");
    cursorPosition = 1;
    lcdState = 1;
    swState = 1;
    swState2 = 1;
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

  if(swState == 0 && cursorPosition == 2 && lcdState == 1){
    // enter settings screen
    lcdState = 5;
    check5 = 1;
    lineScroll = 0;
    letter = 0;
    check5_1 = 0;
  }
  //settings h
  if(lcdState == 5){
    settings();
  }
  

  if(swState == 0 && cursorPosition == 4 && lcdState == 1){
    // enter info screen
    lcdState = 4;
    check4 = 1;
    lineScroll = 0;
  }

  if(lcdState == 4){
    if(check4 == 1){
      check4 = 0;
      printCreaterName();
    }
    if(yValue < minThreshold && joyMoved == false){
      if(lineScroll <= 0){
        lineScroll = 2;
      }
      else{
        lineScroll--;
      }
      joyMoved = true;
      check4_1 = 0;
    }
    if(yValue > maxThreshold && joyMoved == false){
      if(lineScroll >= 2){
        lineScroll = 0;
      }
      else{
        lineScroll++;
      }
      joyMoved = true;
      check4_1 = 0;
    }
    
    if (xValue >= minThreshold && xValue <= maxThreshold && yValue >= minThreshold && yValue <= maxThreshold) {
      joyMoved= false;
    }

    if(lineScroll == 0){
      if(check4_1 == 0){
        check4_1 = 1;
        printCreaterName();
      }
    }
    if(lineScroll == 1){
      if(check4_1 == 0){
        check4_1 = 1;
        printGithub();
      }
    }
    if(lineScroll == 2){
      if(check4_1 == 0){
        check4_1 = 1;
        printGameName();
      }
    }
    if(swState == 1){
      lcdState = 0;
    }
  }

  if(swState == 0 && cursorPosition == 3 && lcdState == 1){
    //enter the highscore screen
    lcdState = 3;
    check3 = 0;
    lineScroll = 0;
  }

  if(lcdState == 3){
    // in the HighScore Tab
    if(check3 == 0){
      check3 = 1;
      printHighScoreFirstScreen();
    }
    
    if(lineScroll == 0){
      if(check3_1 == 0){
        printHighScoreFirstScreen();
        check3_1 = 1;
      }
    }
    else{
      if(check3_1 == 0){
        printHighScoreSecondScreen();
        check3_1 = 1;
      }
    }
    
    if(yValue < minThreshold && joyMoved == false){
      if(lineScroll == 0){
        lineScroll = 1;
      }
      else{
        lineScroll = 0;
      }
      joyMoved = true;
      check3_1 = 0;
    }
    if(yValue > maxThreshold && joyMoved == false){
      if(lineScroll == 0){
        lineScroll = 1;
      }
      else{
        lineScroll = 0;
      }
      joyMoved = true;
      check3_1 = 0;
    }
    
    if (xValue >= minThreshold && xValue <= maxThreshold && yValue >= minThreshold && yValue <= maxThreshold) {
      joyMoved= false;
    }
    if(swState == 1){
      lcdState = 0;
    }
  }

  if(swState == 0 && cursorPosition == 1 && lcdState == 1 || swState2 == 0 && cursorPosition == 1 && lcdState == 1){
    lcdState = 10;
    check10 = 1;
    canTheGameStart = 1;
  }

  if(lcdState == 10){
    if(check10 == 1){
      printReadyPlayersJS();
      check10 = 0;
    }
    if(swState == 0 && swState2 == 0){
      lcdState = 2;
      printPlay();
    }
  }

  if(lcdState == 2){
    // start the game
    if(canTheGameStart == 1){
      lcd.clear();
      lcd.setCursor(5, 0);
      lcd.print("READY?");
      lcd.setCursor(4, 1);
      lcd.print("START!!");
      delay(2000);
      init_ground();
      poz_dino(dino1);
      poz_dino(dino2);
      idx1 = 0;
      idx2 = 0;
      scoreDino1 = 0;
      scoreDino2 = 0;
      livesDino1 = 5;
      livesDino2 = 5;
      printPlay();
      lifeGainCounter1 = 0;
      lifeGainCounter2 = 0;
      gameSpeed = 9000;
      startTime = millis();
      scoreTime1 = millis();
      scoreTime2 = millis();
      speedTimer = millis();
      canTheGameStart = 0;
    }
    inGame();
    
    if(millis() - speedTimer >= 6000){
      gameSpeed += 300;
      speedTimer = millis();
    }
    if(swState == 1 || swState2 == 1){
      lcdState = 9;
    }
  }

  if(lcdState == 9){
    if(check9 == 1){
      printPause();
      check9 = 0;
      swState = 0;
      swState2 = 0;
    }
    if(swState == 1 || swState2 == 1){
      printPlay();
      swState = 0;
      swState2 = 0;
      scoreTime1 = millis();
      scoreTime2 = millis();
      startTime = millis();
      speedTimer = millis();

      if(attackCheck == 1){
        attackTime = millis();
      }
      if(attackCheck2 == 1){
        attackTime2 = millis();
      }
      check9 = 1;
      lcdState = 2;
    }
  }

  if(lcdState == 6){
    if(check6 == 1){
      printEndMessage();
      check6 = 0;
    }
    if(swState == 1 || swState2 == 1){
      lcdState = 8;
      update_highscore();
      EEPROM_writeAnything(0, theHS);
      swState = 0;
      swState2 = 0;
    }
  }
  if(lcdState == 8){ // this lcdState is more like 6.1 state than 8 -- sorry --

    if(beatHS != 0){
      print_new_hs();
      beatHS = 0;
    }
    if(swState == 1 || swState2 == 1){
      swState = 0;
      swState2 = 0;
      check7 = 1;
      lcdState = 7;
      againCursor = 1;
    }
  }

  if(lcdState == 7){
    if(check7 == 1){
      printPlayAgain();
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
      swState2 = 1;
      canTheGameStart = 1;
      lcdState = 10;
      printReadyPlayersJS();
    }
    if(swState == 1 && againCursor == 2){
      lcdState = 0;
      swState2 = 1;
      canTheGameStart = 1;
    }
  }
}
