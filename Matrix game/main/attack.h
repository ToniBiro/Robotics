#pragma once
#include "global_variables.h"


void attack(){
  if((auxFrame+1) * (gameSpeed/nObstacle) > millis() - attackTime && millis() - attackTime >= auxFrame*(gameSpeed/nObstacle) && auxHere == 1){
      lc.setRow(0, attackHeight, obstacle[1][attackFrame]);
      auxHere = 0;
      auxFrame++;
      attackFrame--;
  }
  if(auxFrame * (gameSpeed/nObstacle) <= millis() - attackTime){
    auxHere = 1;
  }
}
