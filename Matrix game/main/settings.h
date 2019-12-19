#pragma once
#include "global_variables.h"

void settings(){ 
  
  if(lineScroll == 0 && swState == 0){
    if(check5_1 == 0){
      check5_1 = 1;
      printChooseName();
      lcd.setCursor(0, 0);
      lcd.print(">");
      lcd.setCursor(0, 1);
      lcd.print(" ");
      caret = 0;
      blinkTime = millis();
      check5 = 0;
    }
    blinkCaret(caret, 0);
  }
  if(lineScroll == 1 && swState == 0){
    if(check5_1 == 0){
      check5_1 = 1;
      printChooseName();
      lcd.setCursor(0, 0);
      lcd.print(" ");
      lcd.setCursor(0, 1);
      lcd.print(">");
      caret = 0;
      blinkTime = millis();
      check5 = 0;
    }
    blinkCaret(caret, 1);
  }
  if(lineScroll == 2){
    if(check5_1 == 0){
      check5_1 = 1;
      printLcdControl();
      lcd.setCursor(0, 0);
      lcd.print(">");
      lcd.setCursor(0, 1);
      lcd.print(" ");
    }
  }
  if(lineScroll == 3){
    if(check5_1 == 0){
      check5_1 = 1;
      printLcdControl();
      lcd.setCursor(0, 0);
      lcd.print(" ");
      lcd.setCursor(0, 1);
      lcd.print(">");
    }
    if(swState == 1){
      lcdState = 0;
    }
  }
  if(lineScroll == 0 && swState == 1){
    if(check5 == 0){
      printLetters();
      check5 = 1;
    }
    blinkLetter(letter%16, letter>15);
  }
  if(lineScroll == 1 && swState == 1){
    if(check5 == 0){
      printLetters();
      check5 = 1;
    }
    blinkLetter(letter%16, letter>15);
  }

  if(lineScroll == 0 && check5 == 1 && swState == 0){
    nameDino1[caret] = letters[letter>=15][letter%16];
    check5_1 = 0;
  }
  if(lineScroll == 1 && check5 == 1 && swState == 0){
    nameDino2[caret] = letters[letter>=15][letter%16];
    check5_1 = 0;
  }
  
  if(xValue < minThreshold && joyMoved == false){
    if(swState == 0){
      if(caret <= 0){
        caret = 3;
      }
      else{
        caret--;
      }
    }
    if((lineScroll == 0 || lineScroll == 1) && swState == 1 ){
      if(letter <= 0){
        letter = 25;
      }
      else{
        letter--;
      }
    }
    if(lineScroll == 2){
      strcpy(lcdLedControl, "OFF");
      lcdLedValue = 0;
      printLcdControl();
    }
    joyMoved = true;
    check5 = 0;
  }
  if(xValue > maxThreshold && joyMoved == false){
    if(swState == 0){
      if(caret >= 3){
        caret = 0;
      }
      else{
        caret++;
      }
    }
    if((lineScroll == 0 || lineScroll == 1) && swState == 1){
      if(letter >= 25){
        letter = 0;
      }
      else{
        letter++;
      }
    }
    if(lineScroll == 2){
      strcpy(lcdLedControl, "ON");
      lcdLedValue = 1;
      printLcdControl();
    }
    joyMoved = true;
    check5 = 0;
  }
  if(yValue < minThreshold && joyMoved == false && swState == 0){
    if(lineScroll <= 0){
      lineScroll = 3;
    }
    else{
      lineScroll--;
    }
    joyMoved = true;
    check5_1 = 0;
  }
  if(yValue > maxThreshold && joyMoved == false && swState == 0){
    if(lineScroll >= 4){
      lineScroll = 0;
    }
    else{
      lineScroll++;
    }
    joyMoved = true;
    check5_1 = 0;
  }
}
