#pragma once
#include "global_variables.h"
#include "messages.h"

void update_highscore(){
  /*
   * This code runs only if the lcdState is 6 (if one of the playes has died).
   * It checks if the highScore is beaten and updates the ranking.
   * It memorises the first 3 highScores together with the names of the players
   * in the custom structure "theHS".
   */
  if (scoreDino1 >= theHS.hs[0].sc){
    theHS.hs[2] = theHS.hs[1];
    theHS.hs[1] = theHS.hs[0];
    strcpy(theHS.hs[0].na, nameDino1);
    theHS.hs[0].sc = scoreDino1;
    beatHS = 1;
  }
  else{
    if (scoreDino1 >= theHS.hs[1].sc){
      theHS.hs[2] = theHS.hs[1];
      strcpy(theHS.hs[1].na, nameDino1);
      theHS.hs[1].sc = scoreDino1;
    }
    else{
      if (scoreDino1 >= theHS.hs[2].sc){
        strcpy(theHS.hs[2].na, nameDino1);
        theHS.hs[2].sc = scoreDino1;
      }
    }
  }

  if (scoreDino2 >= theHS.hs[0].sc){
    theHS.hs[2] = theHS.hs[1];
    theHS.hs[1] = theHS.hs[0];
    strcpy(theHS.hs[0].na, nameDino2);
    theHS.hs[0].sc = scoreDino2;
    beatHS = 2;
  }
  else{
    if (scoreDino2 >= theHS.hs[1].sc){
      theHS.hs[2] = theHS.hs[1];
      strcpy(theHS.hs[1].na, nameDino2);
      theHS.hs[1].sc = scoreDino2;
    }
    else{
      if (scoreDino2 >= theHS.hs[2].sc){
        strcpy(theHS.hs[2].na, nameDino2);
        theHS.hs[2].sc = scoreDino2;
      }
    }
  }
}

void printRealtimeGameData(){
  /*
   * Updates in real-time the score and the number of lives of the players.
   */
  if (scoreDino1+1 % 10 == 0 || scoreDino2+1 % 10 == 0){
    lcd.clear();
    printPlay();
  }
  lcd.setCursor(0, 1);
  lcd.print(scoreDino2);
  lcd.setCursor(9, 1);
  lcd.print(scoreDino1);
  lcd.setCursor(1, 0);
  lcd.print(livesDino2);
  lcd.setCursor(11, 0);
  lcd.print(livesDino1);
}
