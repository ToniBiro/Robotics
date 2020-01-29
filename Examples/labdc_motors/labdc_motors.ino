//
//const int pin = 3;
//
//
//const int potentiometer = 6;
//int enablePin = 11;
//int in1Pin = 10;
//int in2Pin = 9;
//const int buttonPin = 8;
//int motorSpeed= 0;
//boolean reverse = LOW;
//
//
//int lastButtonState = 1;
//unsigned long lastDebounceTime;
//int debounceDelay = 500;
//int pushButtonState = 1;
//int buttonState = HIGH;
//
//void setup() {
//  // DC mototrs
//
//  Serial.begin(9600);
//  pinMode(pin, OUTPUT);
//  while(!Serial);
//  Serial.println("Intre 0 si 255");
//  pinMode(in1Pin, OUTPUT);
//  pinMode(in2Pin, OUTPUT);
//  pinMode(enablePin, OUTPUT);
//  pinMode(buttonPin,  INPUT_PULLUP);
//  pinMode(potentiometer, INPUT);
//}
//
////  if(Serial.available()){
////    int motorSpeed =  Serial.parseInt();
////    Serial.println(motorSpeed);
////    if(motorSpeed >= 0 && motorSpeed <= 255){
////      analogWrite(pin, motorSpeed);
////    }
////  }
//
////  for(int motorSpeed = 0; motorSpeed <= 255; motorSpeed += 10){
////    analogWrite(pin, motorSpeed);
////    delay(1000);
////    Serial.println(motorSpeed);
////  }
//
//
//void debounce(int reading){
//  if (reading != lastButtonState) {
//    lastDebounceTime = millis();
//  }
//
//  if ((millis() - lastDebounceTime) > debounceDelay) {
//    if (reading != pushButtonState) {
//      pushButtonState = reading;
//
//      if (pushButtonState == HIGH){
//        buttonState = !buttonState;
//      }
//    }
//  }
//  lastButtonState = reading;
//}
// 
//void loop()
//{
//  motorSpeed = map(analogRead(potentiometer), 0, 255, 0, 1023);
//  int reading = digitalRead(buttonPin);
//  debounce(reading);
//  Serial.println(buttonState);
//  Serial.println(motorSpeed);
//
//  if(buttonState == HIGH){
//    reverse = HIGH;
//  }
//  else{
//    reverse = LOW;
//  }
//  
//  setMotor(motorSpeed , reverse);
//}
// 
//void setMotor(int motorSpeed , boolean reverse)
//{
//  analogWrite(enablePin, motorSpeed);
//  digitalWrite(in1Pin, !reverse);
//  digitalWrite(in2Pin, reverse);
//}



#include <Servo.h>

const int potPin = A0;
int servoPin = 9;
Servo servo;  
 
int angle = 0;   // servo position in degrees
 
void setup()
{
  Serial.begin(9600);
  servo.attach(servoPin);
  pinMode(potPin, INPUT);
}
 
 
void loop()
{
  int potVal = map(analogRead(potPin), 0, 1023, 0, 180);
  Serial.println(potVal);

  servo.write(potVal);  
  
//  // scan from 0 to 180 degrees
//  for(angle = 0; angle < 180; angle++)  
//  {                                
//  servo.write(angle);            
//  delay(5);                 
//  }
//  // now scan back from 180 to 0 degrees
//  for(angle = 180; angle > 0; angle--)    
//  {                              
//  servo.write(angle);        
//  delay(5);     
//  }
}
