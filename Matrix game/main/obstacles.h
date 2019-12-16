#pragma once
#include "global_variables.h"

void setObstacle(){
  if((frame1+1) * (speedConst/gameSpeed) > millis() - startTime && millis() - startTime >= frame1*(speedConst/gameSpeed) && here == 1){
      lc.setRow(0, heightObstacle1, obstacle[idx1][frame1]);
      lc.setRow(0, heightObstacle2, obstacle[idx2][frame2]);
      here = 0;
      frame1++;
      if(frame1 == nObstacle && dino1Collision != 1){
        lifeGainCounter1 += 1;
      }
      frame2--;
      if(frame2 == 0 && dino2Collision != 1){
        lifeGainCounter2 += 1;
      }
  }
  if(frame1 * (speedConst/gameSpeed) <= millis() - startTime){
    here = 1;
  }
}

void chooseObstacle(){

  if(frame1 >= nObstacle){
    idx1 = rand()%4 + 1;
    idx2 = rand()%4 + 1;
    heightObstacle1 = rand()%2 + 5;
    heightObstacle2 = rand()%2 + 1;
    if(heightObstacle1 == 5){idx1 = 1;}
    if(heightObstacle2 == 2){idx2 = 1;}
    frame1 = 0;
    frame2 = nObstacle-1;
    startTime = millis();
    here = 1;
  }
}
