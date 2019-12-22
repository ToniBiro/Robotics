#pragma once
#include "global_variables.h"

void setObstacle(){
  /*
   * Depending on the game speed this code prints to the matrix the frame of the choosen obstacle
   * for both the first and the second player.
   * Also, it checks if there was a collision on this obstacle.
   */
  if ((frame1+1) * (speedConst/gameSpeed) > millis() - startTime && millis() - startTime >= frame1*(speedConst/gameSpeed) && here == 1){
      lc.setRow(0, heightObstacle1, obstacle[idx1][frame1]);
      lc.setRow(0, heightObstacle2, obstacle[idx2][frame2]);
      here = 0;
      frame1++;
      if (frame1 == nObstacle && dino1Collision != 1){
        lifeGainCounter1 += 1;
      }
      frame2--;
      if (frame2 == 0 && dino2Collision != 1){
        lifeGainCounter2 += 1;
      }
  }
  if (frame1 * (speedConst/gameSpeed) <= millis() - startTime){
    here = 1;
  }
}

void chooseObstacle(){
  /*
   * The obstacles are memorised as a 5 by 14 matrix.
   * The index of the obstacle to use is pickes randomly out of the last 4,
   * the first obstacle is blank and used to reset the row when needed
   * (for example, when the game is paused and a collison is happening at the same time,
   * so that not more than one collision is read)
   * 
   * This code makes sure that only the second obstacle is used when the height is
   * equivalent with the head of the dino (to look like the bird from the original game)
   */
  if (frame1 >= nObstacle){
    idx1 = rand()%4 + 1;
    idx2 = rand()%4 + 1;
    heightObstacle1 = rand()%2 + 5;
    heightObstacle2 = rand()%2 + 1;
    if (heightObstacle1 == 5){idx1 = 1;}
    if (heightObstacle2 == 2){idx2 = 1;}
    frame1 = 0;
    frame2 = nObstacle-1;
    startTime = millis();
    here = 1;
  }
}
