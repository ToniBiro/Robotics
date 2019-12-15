#pragma once
#include "global_variables.h"

void set_obstacle(){
  if((frame1+1) * (gameSpeed/nObstacle) > millis() - startTime && millis() - startTime >= frame1*(gameSpeed/nObstacle) && here == 1){
      lc.setRow(0, heightObstacle1, obstacle[idx1][frame1]);
      lc.setRow(0, heightObstacle2, obstacle[idx2][frame2]);
      here = 0;
      frame1++;
      frame2--;
  }
  if(frame1 * (gameSpeed/nObstacle) <= millis() - startTime){
    here = 1;
  }
}

void choose_obstacle(){

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
