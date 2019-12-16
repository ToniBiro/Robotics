#include "global_variables.h"

void update_highscore(){
  if(scoreDino1 > theHS.hs[0].sc){
    strcpy(theHS.hs[0].na, nameDino1);
    theHS.hs[0].sc = scoreDino1;
    beatHS = 1;
  }
  else{
    if(scoreDino1 > theHS.hs[1].sc){
      strcpy(theHS.hs[1].na, nameDino1);
      theHS.hs[1].sc = scoreDino1;
    }
    else{
      if(scoreDino1 > theHS.hs[2].sc){
        strcpy(theHS.hs[2].na, nameDino1);
        theHS.hs[2].sc = scoreDino1;
      }
    }
  }

  if(scoreDino2 > theHS.hs[0].sc){
    strcpy(theHS.hs[0].na, nameDino2);
    theHS.hs[0].sc = scoreDino2;
    beatHS = 2;
  }
  else{
    if(scoreDino2 > theHS.hs[1].sc){
      strcpy(theHS.hs[1].na, nameDino2);
      theHS.hs[1].sc = scoreDino2;
    }
    else{
      if(scoreDino2 > theHS.hs[2].sc){
        strcpy(theHS.hs[2].na, nameDino2);
        theHS.hs[2].sc = scoreDino2;
      }
    }
  }
}

void print_realtime_game_data(){
  lcd.setCursor(0, 1);
  lcd.print(scoreDino2);
  lcd.setCursor(9, 1);
  lcd.print(scoreDino1);
  lcd.setCursor(1, 0);
  lcd.print(livesDino2);
  lcd.setCursor(11, 0);
  lcd.print(livesDino1);
}
