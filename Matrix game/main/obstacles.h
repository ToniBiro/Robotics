#pragma once
#include "global_variables.h"

void set_obstacle(){
  if((frame+1) * (gameSpeed/nObstacle) > millis() - startTime && millis() - startTime >= frame*(gameSpeed/nObstacle) && here == 1){
      lc.setRow(0, heightObstacle, obstacle[idx][frame]);
      here = 0;
      frame++;
  }
  if(frame * (gameSpeed/nObstacle) <= millis() - startTime){
    here = 1;
  }
}

void choose_obstacle(){

  if(frame >= nObstacle){
    idx = rand()%4;
    heightObstacle = rand()%2 + 5;
    if(heightObstacle == 5){idx = 0;}
    frame = 0;
    startTime = millis();
    here = 1;
  }
}
