#pragma once
#include "global_variables.h"


void attack(){
  /*
   * Once the x coordinate has passed the threshold an attack is launched and depending on how much time
   * has passed an appropriate frame if picked on the x axis (on which the head of the dino was when
   * the attack happend)
   */
  if ((auxFrame+1) * (speedConst/gameSpeed) > millis() - attackTime && millis() - attackTime >= auxFrame*(speedConst/gameSpeed) && auxHere == 1){
      lc.setRow(0, attackHeight, obstacle[1][attackFrame]);
      auxHere = 0;
      auxFrame++;
      attackFrame--;
  }
  if (auxFrame * (speedConst/gameSpeed) <= millis() - attackTime){
    auxHere = 1;
  }
}

void attack2(){
  /*
   * Similar for the second dino attack
   */
  if ((auxFrame2+1) * (speedConst/gameSpeed) > millis() - attackTime2 && millis() - attackTime2 >= auxFrame2*(speedConst/gameSpeed) && auxHere2 == 1){
      lc.setRow(0, attackHeight2, obstacle[1][attackFrame2]);
      auxHere2 = 0;
      auxFrame2++;;
      attackFrame2++;
  }
  if (auxFrame2 * (speedConst/gameSpeed) <= millis() - attackTime2){
    auxHere2 = 1;
  }
}
