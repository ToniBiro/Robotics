//#pragma once
//
//void inGame(){
//  if (xValue < minThreshold && joyMoved == false && swState == 0) {
//    if(attackCheck == 0){
//      attackCheck = 1;
//      attackTime = millis();
//      attackHeight = dino1.sp.x;
//    }
//    joyMoved = true;
//  }
//  if (yValue > maxThreshold && joyMoved == false && swState == 0) {
//    if(upCheck == 0){
//      upCheck = 1;
//      upTime = millis();
//    }
//    joyMoved = true;
//  }
//  if (yValue < minThreshold && joyMoved == false && swState == 0) {
//    if(downCheck == 0){
//      downCheck = 1;
//      downTime = millis();
//    }
//    joyMoved = true;
//  }
//  
//  if (xValue >= minThreshold && xValue <= maxThreshold && yValue >= minThreshold && yValue <= maxThreshold) {
//    joyMoved= false;
//  }
//  
//  if(upCheck == 1){
//    dino_jump();
//  }
//  else{
//    if(downCheck == 1){
//      dino_bend();
//    }
//  }
//
//  if(dino1.fp.x == 6 && dino1.fp.y == 1 && dino1.sp.x == 5 && dino1.sp.y == 1){
//    upCheck = 0;
//    downCheck = 0;
//    first = 1;
//    var = 4;
//  }
//
//  if(attackCheck == 1){
//    attack();
//  }
//  if(attackFrame == -1){
//    attackCheck = 0;
//    auxFrame = 0;
//    attackFrame = nObstacle-7;
//    auxHere = 1;
//  }
//
//  check_collisinos();
//  set_obstacle();
//  choose_obstacle();
//  
//  poz_dino(dino1);
//  
//  if(dino1Collision == 1){
//    dino1Collision = 0;
//    livesDino1 -= 1;
//    tone(buzzer, 1000);
//    noTone(buzzer);
//   
//    lcd.setCursor(1, 0);
//    lcd.print(livesDino1);
//  }
//
//  if(dino2Collision == 1){
//    dino2Collision = 0;
//    livesDino2 -= 1;
//    tone(buzzer, 1000);
//    noTone(buzzer);
//    
//    lcd.setCursor(1, 0);
//    lcd.print(livesDino2);
//  }
//
//  if(livesDino1 <= 0 || livesDino2 <= 0){
//    lcdState == 6;
//  }
//  
//}
