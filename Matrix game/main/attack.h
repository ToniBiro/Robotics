#pragma once
#include "global_variables.h"


void attack(){
  if((auxFrame+1) * (speedConst/gameSpeed) > millis() - attackTime && millis() - attackTime >= auxFrame*(speedConst/gameSpeed) && auxHere == 1){
      lc.setRow(0, attackHeight, obstacle[1][attackFrame]);
      auxHere = 0;
      auxFrame++;
      attackFrame--;
  }
  if(auxFrame * (speedConst/gameSpeed) <= millis() - attackTime){
    auxHere = 1;
  }
}
