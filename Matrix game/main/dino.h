#pragma once
#include "global_variables.h"
#include "attack.h"
#include "obstacles.h"
#include "collisions.h"
#include "check_highscore.h"


void initGround(){
  /*
   * This function sets the ground for the game.
   */
  for (int i = 0; i < 8; ++i){
    lc.setRow(0, i, B00000000);
  }

  for (int i = 0; i < 8; ++i){
    lc.setLed(0, 0, i, true);
    lc.setLed(0, 7, i, true);
  }
}

dino pozDino(dino d){
  /*
   * Whatever the coordinates of the dino in that moment
   * this function lights up only those leds on the matrix.
   */
  lc.setLed(0, d.fp.x, d.fp.y, true);
  lc.setLed(0, d.sp.x, d.sp.y, true);
}

// first dino jump ///

void dinoJump(){
  /*
   * This function controls the jump for the first dino.
   * Depending on the time that has passed since the y coordinate passed the threshold
   * the dino's coordinates change.
   */
  if (downCheck == 1){
    var += 10000;
    downCheck = 0;
  }
  jumpInterval = (20000000/(20000*var));
  if (2*(jumpInterval) > millis() - upTime && millis() - upTime >= 1*(jumpInterval)){first = 0; sec = 1; third = 0; four = 0;}
  if (3*(jumpInterval) > millis() - upTime && millis() - upTime >= 2*(jumpInterval)){first = 0; sec = 0; third = 1; four = 0;}
  if (millis() - upTime >= 3*(jumpInterval)){first = 0; sec = 0; third = 0; four = 1;}
  if (first == 1){
    dino1.fp.x = 5;
    dino1.fp.y = 1;
    dino1.sp.x = 4;
    dino1.sp.y = 1;
    lc.setLed(0, 3, 1, false);
    lc.setLed(0, 4, 1, true);
    lc.setLed(0, 5, 1, true);
    lc.setLed(0, 6, 1, false);
    first = 0;
  }
  if (sec == 1){
    dino1.fp.x = 4;
    dino1.fp.y = 1;
    dino1.sp.x = 3;
    dino1.sp.y = 1;
    lc.setLed(0, 3, 1, true);
    lc.setLed(0, 4, 1, true);
    lc.setLed(0, 5, 1, false);
    //lc.setLed(0, 6, 1, false);
    sec = 0;
  }
  if (third == 1){
    dino1.fp.x = 5;
    dino1.fp.y = 1;
    dino1.sp.x = 4;
    dino1.sp.y = 1;
    lc.setLed(0, 3, 1, false);
    lc.setLed(0, 4, 1, true);
    lc.setLed(0, 5, 1, true);
    //lc.setLed(0, 6, 1, false);
    third = 0;
  }
  if (four == 1){
    dino1.fp.x = 6;
    dino1.fp.y = 1;
    dino1.sp.x = 5;
    dino1.sp.y = 1;
    lc.setLed(0, 3, 1, false);
    lc.setLed(0, 4, 1, false);
    lc.setLed(0, 5, 1, true);
    lc.setLed(0, 6, 1, true);
    four = 0;
  }
}

// end first dino jump ///

// second dino jump ///

void dinoJump2(){
  /*
   * Similar to the first dino jump but changes the coordinates of the second dino
   */
  if (downCheck2 == 1){
    var += 10000;
    downCheck2 = 0;
  }
  jumpInterval2 = (20000000/(20000*var));
  if (2*(jumpInterval2) > millis() - upTime2 && millis() - upTime2 >= 1*(jumpInterval2)){first2 = 0; sec2 = 1; third2 = 0; four2 = 0;}
  if (3*(jumpInterval2) > millis() - upTime2 && millis() - upTime2 >= 2*(jumpInterval2)){first2 = 0; sec2 = 0; third2 = 1; four2 = 0;}
  if (millis() - upTime2 >= 3*(jumpInterval2)){first2 = 0; sec2 = 0; third2 = 0; four2 = 1;}
  if (first2 == 1){
    dino2.fp.x = 2;
    dino2.fp.y = 6;
    dino2.sp.x = 3;
    dino2.sp.y = 6;
    lc.setLed(0, 1, 6, false);
    lc.setLed(0, 2, 6, true);
    lc.setLed(0, 3, 6, true);
    //lc.setLed(0, 4, 6, false);
    first2 = 0;
  }
  if (sec2 == 1){
    dino2.fp.x = 3;
    dino2.fp.y = 6;
    dino2.sp.x = 4;
    dino2.sp.y = 6;
    //lc.setLed(0, 1, 6, false);
    lc.setLed(0, 2, 6, false);
    lc.setLed(0, 3, 6, true);
    lc.setLed(0, 4, 6, true);
    sec2 = 0;
  }
  if (third2 == 1){
    dino2.fp.x = 2;
    dino2.fp.y = 6;
    dino2.sp.x = 3;
    dino2.sp.y = 6;
    //lc.setLed(0, 1, 6, false);
    lc.setLed(0, 2, 6, true);
    lc.setLed(0, 3, 6, true);
    lc.setLed(0, 4, 6, false);
    third2 = 0;
  }
  if (four2 == 1){
    dino2.fp.x = 1;
    dino2.fp.y = 6;
    dino2.sp.x = 2;
    dino2.sp.y = 6;
    lc.setLed(0, 1, 6, true);
    lc.setLed(0, 2, 6, true);
    lc.setLed(0, 3, 6, false);
    lc.setLed(0, 4, 6, false);
    four2 = 0;
  }
}

// end second dino jump ///

// first dino bend ///

void dinoBend(){
  /*
   * This function controls the bend for the first dino.
   * While the y value passes the according threshold, the coordinates of the dino are set to be the same pixel
   * the lower one
   */
  if (yValue < minThreshold){
    dino1.fp.x = 6;
    dino1.fp.y = 1;
    dino1.sp.x = 6;
    dino1.sp.y = 1;
    if (done == 1){
      lc.setLed(0, 5, 1, false);
      lc.setLed(0, 6, 1, true);  
      done = 0;
    }
  }
  else{
    dino1.fp.x = 6;
    dino1.fp.y = 1;
    dino1.sp.x = 5;
    dino1.sp.y = 1;
    lc.setLed(0, 5, 1, true);
    lc.setLed(0, 6, 1, true);
    done = 1;
  }
}

// end first dino bend ///

// second dino bend ///

void dinoBend2(){
  /*
   * Similar to the bend function for the first dino
   */
  if (yValue2 < minThreshold){
    dino2.fp.x = 1;
    dino2.fp.y = 6;
    dino2.sp.x = 1;
    dino2.sp.y = 6;
    if (done2 == 1){
      lc.setLed(0, 2, 6, false);
      lc.setLed(0, 1, 6, true);  
      done2 = 0;
    }
  }
  else{
    dino2.fp.x = 1;
    dino2.fp.y = 6;
    dino2.sp.x = 2;
    dino2.sp.y = 6;
    lc.setLed(0, 1, 6, true);
    lc.setLed(0, 2, 6, true);
    done2 = 1;
  }
}

// end second dino bend ///

void inGame(){
  /*
   * This function is called every time the lcdState is set to 2
   * When the players are in this function they have control over the movements for the dinos.
   * 
   * Depending on how the joysticks are managed by the players, certin global variables are set to 0 or 1 
   * and based on those variables according functions are called.
   * It does this for the first joystick and then for the second one.
   * 
   * Here we also set randomly what obstacles to send to each player, and detect if any collisions happend
   * 
   * 
   * They can exit this function if:
   *  - one of them dies
   *  - one of them pushes the swich button and pauses the game
   *  - the reset button is pushed
   *  
   */
  // first joystick //
  if (xValue < minThreshold && joyMoved == false && swState == 0) {
    if (attackCheck == 0){
      attackCheck = 1;
      attackTime = millis();
      attackHeight = dino1.sp.x;
    }
    joyMoved = true;
  }
  if (yValue > maxThreshold && joyMoved == false && swState == 0) {
    if (upCheck == 0){
      upCheck = 1;
      upTime = millis();
    }
    joyMoved = true;
  }
  if (yValue < minThreshold && joyMoved == false && swState == 0) {
    if (downCheck == 0){
      downCheck = 1;
      downTime = millis();
    }
    joyMoved = true;
  }
  
  if (xValue >= minThreshold && xValue <= maxThreshold && yValue >= minThreshold && yValue <= maxThreshold) {
    joyMoved = false;
  }
  
  if (upCheck == 1){
    dinoJump();
  }
  else{
    if (downCheck == 1){
      dinoBend();
    }
  }

  /*
   * Resets the global variables for the jump and bend
   * when the dino ends up at the initial coordinates
   */

  if (dino1.fp.x == 6 && dino1.fp.y == 1 && dino1.sp.x == 5 && dino1.sp.y == 1){
    upCheck = 0;
    downCheck = 0;
    first = 1;
    var = 4;
  }

  if (attackCheck == 1){
    attack();
  }

  /*
   * Resests the attack global variables when the attack has ended
   */
  
  if (attackFrame == -1){
    attackCheck = 0;
    auxFrame = 0;
    attackFrame = nObstacle-7;
    auxHere = 1;
  }

  // end first joystick //

  // second joystick //

  if (xValue2 < minThreshold && joyMoved2 == false && swState2 == 0) {
    if (attackCheck2 == 0){
      attackCheck2 = 1;
      attackTime2 = millis();
      auxFrame2 = 0;
      attackHeight2 = dino2.sp.x;
    }
    joyMoved2 = true;
  }

  if (yValue2 > maxThreshold && joyMoved2 == false && swState2 == 0) {
    if (upCheck2 == 0){
      upCheck2 = 1;
      upTime2 = millis();
    }
    joyMoved2 = true;
  }
  if (yValue2 < minThreshold && joyMoved2 == false && swState2 == 0) {
    if (downCheck2 == 0){
      downCheck2 = 1;
      downTime2 = millis();
    }
    joyMoved2 = true;
  }

  if (xValue2 >= minThreshold && xValue2 <= maxThreshold && yValue2 >= minThreshold && yValue2 <= maxThreshold) {
    joyMoved2 = false;
  }

  if (upCheck2 == 1){
    dinoJump2();
  }
  else{
    if (downCheck2 == 1){
      dinoBend2();
    }
  }

  if (dino2.fp.x == 1 && dino2.fp.y == 6 && dino2.sp.x == 2 && dino2.sp.y == 6){
    upCheck2 = 0;
    downCheck2 = 0;
    first2 = 1;
    var = 4;
  }

  if (attackCheck2 == 1){
    attack2();
  }
  
  if (attackFrame2 == 10){
    attackCheck2 = 0;
    attackFrame2 = 2;
    auxFrame2 = 0;
    auxHere2 = 1;
  }

  // end second joystick //

  /*
   * Randomly selects the obstacles
   */
  setObstacle();
  chooseObstacle();

  /*
   * Makes sure the position of the dino on the matrix is the same as the position in the code
   */
  pozDino(dino1);
  pozDino(dino2);

  /*
   * Check for any collisions for both dinos
   */
  check_collisinos();
  
  if (dino1Collision == 0){
    colFlag1 = 0;
  }

  /*
   * If a collison is detected then decrese a life from the player
   * and 10 points from the score
   */

  if (dino1Collision == 1 && colFlag1 == 0){
    colFlag1 = 1;
    livesDino1 -= 1;
    scoreDino1 -= 10;
  }

  /*
   * Activates the buzzer while the collision is taking place.
   */
  
  if (dino1Collision == 1){
    dino1Collision = 0;
    tone(buzzer, 1000);
    noTone(buzzer);
  }

  /*
   * Similar for the second dino
   */

  if (dino2Collision == 0){
    colFlag2 = 0;
  }

  if (dino2Collision == 1 && colFlag2 == 0){
    colFlag2 = 1;
    livesDino2 -= 1;
    scoreDino2 -= 10;
  }
  
  if (dino2Collision == 1){
    dino2Collision = 0;
    tone(buzzer, 500);
    noTone(buzzer);
  }

  /*
   * If any of the playes have died the lcdState changes to 6
   */

  if (livesDino1 <= 0 || livesDino2 <= 0){
    lcdState = 6;
    check6 = 1;
  }

  if (colFlag1 == 0){
    if (millis() - scoreTime1 >= 500){
      scoreDino1 += 1;
      scoreTime1 = millis();
    }
  }

  if (colFlag2 == 0){
    if (millis() - scoreTime2 >= 500){
      scoreDino2 += 1;
      scoreTime2 = millis();
    }
  }

  /*
   * Updates the score and lives screen on the LCD
   */
  printRealtimeGameData();

  /*
   * This code makes sure that if the playes have passed 5 obstacles
   * without being hit they will recive an extra life
   */
  if (lifeGainCounter1 >= 5){
    livesDino1 += 1;
    lifeGainCounter1 = 0;
  }
  if (lifeGainCounter2 >= 5){
    livesDino2 += 1;
    lifeGainCounter2 = 0;
  }
  
}
