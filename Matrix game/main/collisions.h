#pragma once
#include "global_variables.h"

void check_collisinos(){
  /*
   * First dino collision
   * When the first dinos coordinates coincide with the frame of an obstacle that passes through those coordinates
   * then a collision is happening.
   */
  if (idx1 == 1 && frame1 == 8 || idx1 == 2 && frame1 == 7 || idx1 == 2 && frame1 == 8 || idx1 == 3 && frame1 == 7){
    if (heightObstacle1 == dino1.fp.x || heightObstacle1 == dino1.sp.x){
      dino1Collision = 1;
    }
  }
  if (idx1 == 3 && frame1 == 8 || idx1 == 3 && frame1 == 12 || idx1 == 4 && frame1 == 8 || idx1 == 4 && frame1 == 12){
   if (heightObstacle1 == dino1.fp.x || heightObstacle1 == dino1.sp.x){
      dino1Collision = 1;
    }
  }

  /*
   * If an attack is ongoing then it checks if the other dino intersects it
   */

  if (attackCheck2 == 1){
    if (attackFrame2 == 7){
      if (attackHeight2 == dino1.fp.x || attackHeight2 == dino1.sp.x){
        dino1Collision = 1;
      }
    }
  }

  /*
   * Similar for the second dino collision
   */

  if (idx2 == 1 && frame2 == 1 || idx2 == 2 && frame2 == 1 || idx2 == 2 && frame2 == 1 || idx2 == 2 && frame2 == 0){
    if (heightObstacle2 == dino2.fp.x || heightObstacle2 == dino2.sp.x){
      dino2Collision = 1;
    }
  }
  if (idx2 == 3 && frame2 == 1 || idx2 == 3 && frame2 == 5 || idx2 == 4 && frame2 == 1 || idx2 == 4 && frame2 == 5){
    if (heightObstacle2 == dino2.fp.x || heightObstacle2 == dino2.sp.x){
      dino2Collision = 1;
    }
  }

  if (attackCheck == 1){
    if (attackFrame == 2){
      if (attackHeight == dino2.fp.x || attackHeight == dino2.sp.x){
        dino2Collision = 1;
      }
    }
  }  
}
