#pragma once
#include "global_variables.h"


void print_intro(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("THE DINO GAME!");
  lcd.setCursor(0, 1);
  lcd.print("Press the button");
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
