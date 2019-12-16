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

void dino_jump(){
  if(downCheck == 1){
    var += 10000;
    downCheck = 0;
  }
  jumpInterval = (20000000/(gameSpeed*var));
  Serial.println(gameSpeed/jumpConst);
  if(2*(jumpInterval) > millis() - upTime && millis() - upTime >= 1*(jumpInterval)){first = 0; sec = 1; third = 0; four = 0;}
  if(3*(jumpInterval) > millis() - upTime && millis() - upTime >= 2*(jumpInterval)){first = 0; sec = 0; third = 1; four = 0;}
  if(millis() - upTime >= 3*(jumpInterval)){first = 0; sec = 0; third = 0; four = 1;}
  if(first == 1){
    dino1.fp.x = 5;
    dino1.fp.y = 1;
    dino1.sp.x = 4;
    dino1.sp.y = 1;
    lc.setLed(0, 6, 1, false);
    lc.setLed(0, 4, 1, true);
    first = 0;
  }
  if(sec == 1){
    dino1.fp.x = 4;
    dino1.fp.y = 1;
    dino1.sp.x = 3;
    dino1.sp.y = 1;
    lc.setLed(0, 5, 1, false);
    lc.setLed(0, 3, 1, true); 
    sec = 0;
  }
  if(third == 1){
    dino1.fp.x = 5;
    dino1.fp.y = 1;
    dino1.sp.x = 4;
    dino1.sp.y = 1;
    lc.setLed(0, 3, 1, false);
    lc.setLed(0, 5, 1, true); 
    third = 0;
  }
  if(four == 1){
    dino1.fp.x = 6;
    dino1.fp.y = 1;
    dino1.sp.x = 5;
    dino1.sp.y = 1;
    lc.setLed(0, 4, 1, false);
    lc.setLed(0, 6, 1, true);
    four = 0;
  }
}

void dino_bend(){
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
    joyMoved= false;
  }
  
  if(upCheck == 1){
    dino_jump();
  }
  else{
    if(downCheck == 1){
      dino_bend();
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

  // end second joystick //

  
  set_obstacle();
  choose_obstacle();

//  set_obstacle2();
//  choose_obstacle2();
  
  poz_dino(dino1);
  poz_dino(dino2);

  check_collisinos(); // check all collisions for both dinos
  
  if(dino1Collision == 0){
    colFlag1 = 0;
  }

  if(dino1Collision == 1 && colFlag1 == 0){
    colFlag1 = 1;
    livesDino1 -= 1;
    scoreDino1 -= gameSpeed/(scoreDino1*100);
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
    scoreDino2 -= gameSpeed/(scoreDino2*10);
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
    scoreDino1 += 0.005;
  }

  if(colFlag2 == 0){
    scoreDino2 += 0.005;
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
