// 1088AS
// Lighting up an LED

                 //R1 R2  R3 R4 R5 R6 R7  R8  - cathodes
const int row[] = {A2, 4, A4, 5, 9, A5, 11, 6};

                 //C1 C2 C3 C4  C5 C6  C7  C8 - anodes
const int col[] = {13, 12, 8, A3, 7, 2, 3, 10};



int i;

void setup() {
  Serial.begin(9600);
  for (i = 0; i < 8; i++)
  {
    pinMode(row[i], OUTPUT);
    pinMode(col[i], OUTPUT);
  }
  for (i = 0; i < 8; i++) // so no leds are on
  {
    digitalWrite(col[i], LOW);
    digitalWrite(row[i], HIGH);
  }
}

byte smile_1[8][8] = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 1, 0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0, 1, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 1, 0, 0, 0, 0, 1, 0},
  {0, 0, 1, 1, 1, 1, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
};

byte smile_2[8][8] = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 1, 0, 0, 1, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 1, 1, 1, 1, 1, 1, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
};


byte smile_3[8][8] = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {1, 1, 1, 0, 0, 1, 1, 1},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 1, 0, 0, 0, 0, 0, 0},
  {0, 0, 1, 1, 1, 1, 0, 0},
  {0, 1, 0, 0, 0, 0, 1, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
};

byte heart[8][8] = {
  {0, 1, 1, 0, 0, 1, 1, 0},
  {0, 1, 1, 1, 1, 1, 1, 0},
  {1, 1, 1, 1, 1, 0, 1, 1},
  {1, 1, 1, 1, 1, 0, 1, 1},
  {1, 1, 1, 1, 1, 1, 1, 1},
  {0, 1, 1, 1, 1, 1, 1, 0},
  {0, 0, 1, 1, 1, 1, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0}
};

unsigned long entryTime = millis();
int face = 1;

void loop() {

  int i, j;
  if(face == 1){
    for(i = 0; i < 8; ++i){
      for(j = 0; j < 8; ++j){
        digitalWrite(col[j], smile_1[i][j]);
      }
      digitalWrite(row[i], LOW);
      delay(2);
      digitalWrite(row[i], HIGH);
    }
    if(millis() - entryTime >= 1000){
      face = 2;
      entryTime = millis();
    }
  }
  else{
    if(face == 2){
     
      for(i = 0; i < 8; ++i){
        for(j = 0; j < 8; ++j){
          digitalWrite(col[j], smile_2[i][j]);
        }
        digitalWrite(row[i], LOW);
        delay(2);
        digitalWrite(row[i], HIGH);
       }
     
       if(millis() - entryTime >= 1000){
        face = 3;
        entryTime = millis();
      }
   }
   else{
    if(face == 3){
      for(i = 0; i < 8; ++i){
        for(j = 0; j < 8; ++j){
          digitalWrite(col[j], smile_3[i][j]);
        }
        digitalWrite(row[i], LOW);
        delay(2);
        digitalWrite(row[i], HIGH);
       }
     
       if(millis() - entryTime >= 1000){
        face = 1;
        entryTime = millis();
      }
    }
   }
  }
  
}
