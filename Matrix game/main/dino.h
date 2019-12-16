#pragma once
#include "global_variables.h"
#include "attack.h"
#include "obstacles.h"
#include "collisions.h"
#include "check_highscore.h"


void init_ground(){
  lc.setLed(0, 0, 0, true);
  for (int i = 0; i < 8; ++i){
    lc.setLed(0, 0, i, true);
    lc.setLed(0, 7, i, true);
  }
}

dino poz_dino(dino d){
  lc.setLed(0, d.fp.x, d.fp.y, true);
  lc.setLed(0, d.sp.x, d.sp.y, true);
}

// first dino jump ///

void dinoJump(){
  if(downCheck == 1){
    var += 10000;
    downCheck = 0;
  }
  jumpInterval = (20000000/(gameSpeed*var));
  if(2*(jumpInterval) > millis() - upTime && millis() - upTime >= 1*(jumpInterval)){first = 0; sec = 1; third = 0; four = 0;}
  if(3*(jumpInterval) > millis() - upTime && millis() - upTime >= 2*(jumpInterval)){first = 0; sec = 0; third = 1; four = 0;}
  if(millis() - upTime >= 3*(jumpInterval)){first = 0; sec = 0; third = 0; four = 1;}
  if(first == 1){
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
  if(sec == 1){
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
  if(third == 1){
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
  if(four == 1){
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
  if(downCheck2 == 1){
    var += 10000;
    downCheck2 = 0;
  }
  jumpInterval2 = (20000000/(gameSpeed*var));
  if(2*(jumpInterval2) > millis() - upTime2 && millis() - upTime2 >= 1*(jumpInterval2)){first2 = 0; sec2 = 1; third2 = 0; four2 = 0;}
  if(3*(jumpInterval2) > millis() - upTime2 && millis() - upTime2 >= 2*(jumpInterval2)){first2 = 0; sec2 = 0; third2 = 1; four2 = 0;}
  if(millis() - upTime2 >= 3*(jumpInterval2)){first2 = 0; sec2 = 0; third2 = 0; four2 = 1;}
  if(first2 == 1){
    dino2.fp.x = 2;
    dino2.fp.y = 6;
    dino2.sp.x = 3;
    dino2.sp.y = 6;
    lc.setLed(0, 1, 6, false);
    lc.setLed(0, 2, 6, true);
    lc.setLed(0, 3, 6, true);
    lc.setLed(0, 4, 6, false);
    first2 = 0;
  }
  if(sec2 == 1){
    dino2.fp.x = 3;
    dino2.fp.y = 6;
    dino2.sp.x = 4;
    dino2.sp.y = 6;
    lc.setLed(0, 1, 6, false);
    lc.setLed(0, 2, 6, false);
    lc.setLed(0, 3, 6, true);
    lc.setLed(0, 4, 6, true);
    sec2 = 0;
  }
  if(third2 == 1){
    dino2.fp.x = 2;
    dino2.fp.y = 6;
    dino2.sp.x = 3;
    dino2.sp.y = 6;
    lc.setLed(0, 1, 6, false);
    lc.setLed(0, 2, 6, true);
    lc.setLed(0, 3, 6, true);
    lc.setLed(0, 4, 6, false);
    third2 = 0;
  }
  if(four2 == 1){
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
  if(yValue < minThreshold){
    dino1.fp.x = 6;
    dino1.fp.y = 1;
    dino1.sp.x = 6;
    dino1.sp.y = 1;
    if(done == 1){
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
  if(yValue2 < minThreshold){
    dino2.fp.x = 1;
    dino2.fp.y = 6;
    dino2.sp.x = 1;
    dino2.sp.y = 6;
    if(done2 == 1){
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
  // first joystick //
  if (xValue < minThreshold && joyMoved == false && swState == 0) {
    if(attackCheck == 0){
      attackCheck = 1;
      attackTime = millis();
      attackHeight = dino1.sp.x;
    }
    joyMoved = true;
  }
  if (yValue > maxThreshold && joyMoved == false && swState == 0) {
    if(upCheck == 0){
      upCheck = 1;
      upTime = millis();
    }
    joyMoved = true;
  }
  if (yValue < minThreshold && joyMoved == false && swState == 0) {
    if(downCheck == 0){
      downCheck = 1;
      downTime = millis();
    }
    joyMoved = true;
  }
  
  if (xValue >= minThreshold && xValue <= maxThreshold && yValue >= minThreshold && yValue <= maxThreshold) {
    joyMoved = false;
  }
  
  if(upCheck == 1){
    dinoJump();
  }
  else{
    if(downCheck == 1){
      dinoBend();
    }
  }

  if(dino1.fp.x == 6 && dino1.fp.y == 1 && dino1.sp.x == 5 && dino1.sp.y == 1){
    upCheck = 0;
    downCheck = 0;
    first = 1;
    var = 4;
  }

  if(attackCheck == 1){
    attack();
  }
  if(attackFrame == -1){
    attackCheck = 0;
    auxFrame = 0;
    attackFrame = nObstacle-7;
    auxHere = 1;
  }

  // end first joystick //

  // second joystick //

  if (xValue2 < minThreshold && joyMoved2 == false && swState2 == 0) {
    if(attackCheck2 == 0){
      attackCheck2 = 1;
      attackTime2 = millis();
      attackHeight2 = dino2.sp.x;
    }
    joyMoved2 = true;
  }

  if (yValue2 > maxThreshold && joyMoved2 == false && swState2 == 0) {
    if(upCheck2 == 0){
      upCheck2 = 1;
      upTime2 = millis();
    }
    joyMoved2 = true;
  }
  if (yValue2 < minThreshold && joyMoved2 == false && swState2 == 0) {
    if(downCheck2 == 0){
      downCheck2 = 1;
      downTime2 = millis();
    }
    joyMoved2 = true;
  }

  if (xValue2 >= minThreshold && xValue2 <= maxThreshold && yValue2 >= minThreshold && yValue2 <= maxThreshold) {
    joyMoved2 = false;
  }

  if(upCheck2 == 1){
    dinoJump2();
  }
  else{
    if(downCheck2 == 1){
      dinoBend2();
    }
  }

  if(dino2.fp.x == 1 && dino2.fp.y == 6 && dino2.sp.x == 2 && dino2.sp.y == 6){
    upCheck2 = 0;
    downCheck2 = 0;
    first2 = 1;
    var = 4;
  }

  if(attackCheck2 == 1){
    attack2();
  }
  if(attackFrame2 == 10){
    attackCheck2 = 0;
    attackFrame2 = 0;
    auxHere2 = 1;
  }

  // end second joystick //

  setObstacle();
  chooseObstacle();
  
  poz_dino(dino1);
  poz_dino(dino2);

  check_collisinos(); // check all collisions for both dinos
  
  if(dino1Collision == 0){
    colFlag1 = 0;
  }

  if(dino1Collision == 1 && colFlag1 == 0){
    colFlag1 = 1;
    livesDino1 -= 1;
    scoreDino1 -= 10;
  }
  
  if(dino1Collision == 1){
    dino1Collision = 0;
    tone(buzzer, 1000);
    noTone(buzzer);
  }

  if(dino2Collision == 0){
    colFlag2 = 0;
  }

  if(dino2Collision == 1 && colFlag2 == 0){
    colFlag2 = 1;
    livesDino2 -= 1;
    scoreDino2 -= 10;
  }
  
  if(dino2Collision == 1){
    dino2Collision = 0;
    tone(buzzer, 500);
    noTone(buzzer);
  }

  if(livesDino1 <= 0 || livesDino2 <= 0){
    lcdState = 6;
    check6 = 1;
  }

  if(colFlag1 == 0){
    if(millis() - scoreTime1 >= 500){
      scoreDino1 += 1;
      scoreTime1 = millis();
    }
  }

  if(colFlag2 == 0){
    if(millis() - scoreTime2 >= 500){
      scoreDino2 += 1;
      scoreTime2 = millis();
    }
  }

  update_highscore();
  print_realtime_game_data();
  
  if(lifeGainCounter1 >= 5){
    livesDino1 += 1;
    lifeGainCounter1 = 0;
  }
  if(lifeGainCounter2 >= 5){
    livesDino2 += 1;
    lifeGainCounter2 = 0;
  }
  
}
