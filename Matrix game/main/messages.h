#pragma once
#include "global_variables.h"

/*
 * All the messages that are printed through out the game on the LCD
 * are pozDino as a function here.
 */

void printIntro(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("THE DINO GAME!");
  lcd.setCursor(0, 1);
  lcd.print("Press the button");
}

void printMainMenu(){
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

void printPlay(){
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print(livesDino2);
  lcd.setCursor(11, 0);
  lcd.print(livesDino1);
  lcd.setCursor(0, 1);
  lcd.print(scoreDino2);
  lcd.setCursor(9, 1);
  lcd.print(scoreDino1);
  lcd.setCursor(7, 1);
  lcd.print("::");
  lcd.setCursor(0, 0);
  lcd.write(byte(0));
  lcd.setCursor(15, 0);
  lcd.write(byte(0));
}

void printEndMessage(){
  lcd.clear();
  if (scoreDino1 > scoreDino2){
    lcd.setCursor(0, 0);
    lcd.print(nameDino1);
    lcd.setCursor(4, 0);
    lcd.print(" WON");
  }
  else{
    if (scoreDino1 < scoreDino2){
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

void printNewHs(){
  lcd.clear();
  if (beatHS == 1){
    lcd.setCursor(0, 0);
    lcd.print("New HighScore:");
    lcd.setCursor(0, 1);
    lcd.print(nameDino1);
    lcd.setCursor(4, 1);
    lcd.print(":");
    lcd.setCursor(5, 1);
    lcd.print(scoreDino1);
  }
  if (beatHS == 2){
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

void printPlayAgain(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(">");
  lcd.setCursor(1, 0);
  lcd.print("Play again?");
  lcd.setCursor(1, 1);
  lcd.print("Back to Menu");
}

void printPause(){
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("PAUSE...");
  lcd.setCursor(9, 0);
  lcd.print("Press");
  lcd.setCursor(0, 1);
  lcd.print("any JS to resume");
}

void printReadyPlayersJS(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("To start press");
  lcd.setCursor(0, 1);
  lcd.print("both of the JS's");
}

printHighScoreFirstScreen(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("1.");
  lcd.setCursor(2, 0);
  lcd.print(theHS.hs[0].na);
  lcd.setCursor(6, 0);
  lcd.print(":");
  lcd.setCursor(7, 0);
  lcd.print(theHS.hs[0].sc);
  lcd.setCursor(0, 1);
  lcd.print("2.");
  lcd.setCursor(2, 1);
  lcd.print(theHS.hs[1].na);
  lcd.setCursor(6, 1);
  lcd.print(":");
  lcd.setCursor(7, 1);
  lcd.print(theHS.hs[1].sc);
}

printHighScoreSecondScreen(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("3.");
  lcd.setCursor(2, 0);
  lcd.print(theHS.hs[2].na);
  lcd.setCursor(6, 0);
  lcd.print(":");
  lcd.setCursor(7, 0);
  lcd.print(theHS.hs[2].sc);
}

void printCreaterName(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Biro Balan");
  lcd.setCursor(0, 1);
  lcd.print("Antonia");  
}

void printGithub(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("github.com/ToniB");
  lcd.setCursor(0, 1);
  lcd.print("iro/Robotics"); 
}

void printGameName(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("The Dino Game");
  lcd.setCursor(0, 1);
  lcd.print("@UnibucRobotics");
}

void printChooseName(){
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Dino1 Name:");
  lcd.setCursor(12, 0);
  lcd.print(nameDino1);
  
  lcd.setCursor(1, 1);
  lcd.print("Dino2 Name:");
  lcd.setCursor(12, 1);
  lcd.print(nameDino2);
}

void printLcdControl(){
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("LCD led:");
  lcd.setCursor(10, 0);
  lcd.print(lcdLedControl);
  lcd.setCursor(1, 1);
  lcd.print("Back to menu");
}

void printLetters(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("ABCDEFGHIJKLMNOP");
  lcd.setCursor(0, 1);
  lcd.print("QRSTUVWXYZ");
}

void blinkCaret(int i, int line){
  if (1000 >= millis() -  blinkTime && millis() -  blinkTime >= 500){
    lcd.setCursor(12+i, line);
    lcd.print(" ");
  }
  if (millis() -  blinkTime > 1000){
    lcd.setCursor(12, line);
    if (line == 0){
      lcd.print(nameDino1);
    }
    else{
      lcd.print(nameDino2);
    }
    blinkTime = millis();
  }
}

void blinkLetter(int i, int line){
  if (1000 >= millis() -  blinkTime && millis() -  blinkTime >= 500){
    lcd.setCursor(i, line);
    lcd.print(" ");
  }
  if (millis() -  blinkTime > 1000){
    lcd.setCursor(i, line);
    lcd.print(letters[line][i]);
    blinkTime = millis();
  }
}
