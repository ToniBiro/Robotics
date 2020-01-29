#include <Stepper.h>
// Define number of steps per rotation:
const int stepsPerRevolution = 2048;

const int stepperPin1 = 8;
const int stepperPin2 = 9;
const int stepperPin3 = 10;
const int stepperPin4 = 11;
const int potPin = 3;

// Wiring:
// Pin 8 to IN1 on the ULN2003 driver
// Pin 9 to IN2 on the ULN2003 driver
// Pin 10 to IN3 on the ULN2003 driver
// Pin 11 to IN4 on the ULN2003 driver
// Create stepper object called 'myStepper', note the pin order:

int steps = 0;
int oldpot = 0;

Stepper myStepper = Stepper(stepsPerRevolution, 8, 10, 9, 11);
void setup() {
  pinMode(potPin, INPUT);
  // Set the speed to 5 rpm:
  myStepper.setSpeed(15);
  
  // Begin Serial communication at a baud rate of 9600:
  Serial.begin(9600);
}
void loop() {
  int potValue = analogRead(potPin);
  if(potValue != oldpot){
    steps = potValue - oldpot;

    oldpot = potValue;
    myStepper.step(steps);
    delay(1);
  }
   
  
  // Step one revolution in one direction:
  Serial.println("clockwise");
//  delay(500);
  
  // Step one revolution in the other direction:
//  Serial.println("counterclockwise");
//  myStepper.step(-potValue);
//  delay(500);
}
