#pragma once
#include "global_variables.h"

void check_collisinos(){
  if(idx == 0 && frame == 8 || idx == 1 && frame == 7 || idx == 1 && frame == 8 || idx == 2 && frame == 7){
    if(heightObstacle == dino1.fp.x || heightObstacle == dino1.sp.x){
      dino1Collision = 1;
    }
  }
  if(idx == 2 && frame == 8 || idx == 2 && frame == 12 || idx == 3 && frame == 8 || idx == 3 && frame == 12){
   if(heightObstacle == dino1.fp.x || heightObstacle == dino1.sp.x){
      dino1Collision = 1;
    }
  }

  if(attackCheck == 1){
    
  }
}
