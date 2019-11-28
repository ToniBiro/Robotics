// 1088AS
// Lighting up an LED

                 //R1 R2  R3 R4 R5 R6 R7  R8  - cathodes
const int row[] = {6, 11, A5, 9, 5, A4, 4, A2};

                 //C1 C2 C3 C4  C5 C6  C7  C8 - anodes
const int col[] = {10, 3, 2, 7, A3, 8, 12, 13};

const int xJoy = A1;
const int yJoy = A0;

int i;

void setup() {
  Serial.begin(9600);
  pinMode(xJoy, INPUT);
  pinMode(yJoy, INPUT);
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
  digitalWrite(row[7], LOW); // turn on an led
  digitalWrite(col[3], HIGH);
}

int prevX = 3, prevY = 3, posX = 3, posY = 3;
int valX, valY;
boolean movedX = false, movedY = false;

void loop() {
  valX = analogRead(xJoy);
  valY = analogRead(yJoy);
if (valY > 600)
  {
    if (movedY == false)
    {
      prevY = posY;
      posY--;
      movedY = true;
    }
  }
  else
  {
    if (valY < 400)
    {
      if (movedY == false)
      {
        prevY = posY;
        posY++;
        movedY = true;
      }
    }
    else movedY = false;
  }

  if (valX < 400)
  {
    if (movedX == false)
    {
      prevX = posX;
      posX--;
      movedX = true;
    }
  }
  else
  {
    if (valX > 600)
    {
      if (movedX == false)
      {
        prevX = posX;
        posX++;
        movedX = true;
      }
    }
    else movedX = false;
  }

  // for wall collision
  if (posY == 8) posY = 0;
  if (posY == -1) posY = 7;

  if (posX == 8) posX = 0;
  if (posX == -1) posX = 7;

  digitalWrite(row[prevY], HIGH); // turn off the previous one
  digitalWrite(col[prevX], LOW);

  digitalWrite(row[posY], LOW); // light up the current one
  digitalWrite(col[posX], HIGH);
 
}
