//THE DINO GAME

#include "global_variables.h"
#include "dino.h"
#include "messages.h"
#include "debounce.h"


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



//###### end menu code##################

//######debounce code##################


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
  strcpy(nameDino2, "BBBB");
  srand(time(NULL));
  
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.createChar(0, heart);
  print_intro();
  //delay(5000);
  
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
  
  xValue = analogRead(xPin);
  yValue = analogRead(yPin);
  xValue2 = analogRead(xPin2);
  yValue2 = analogRead(yPin2);
  int swValue = digitalRead(swPin);
  int swValue2 = digitalRead(swPin2);
  
  debounceButton(digitalRead(buttonPin));
  debounceDino1(swValue);
  debounceDino2(swValue2);
  Serial.println(swState2);

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
      idx1 = 0;
      idx2 = 0;
      scoreDino1 = 0;
      scoreDino2 = 0;
      livesDino1 = 5;
      livesDino2 = 5;
      printPlay();
      lifeGainCounter1 = 0;
      lifeGainCounter2 = 0;
      gameSpeed = 7000;
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
      swState = 0;
      swState2 = 0;
    }
  }
  if(lcdState == 8){ // this lcdState is more like 6.1 state than 8 -- sorry --
    if(beatHS != 0){
      print_new_hs();
      // memoreaza in eeprom hs-ul
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
