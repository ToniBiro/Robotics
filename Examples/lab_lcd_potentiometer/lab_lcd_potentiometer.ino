# include<LiquidCrystal.h>
const int RS = 12;
const int enable = 11;
const int d4 = 5;
const int d5 = 4;
const int d6 = 3;
const int d7 = 2;

const int trigPin = 9;
const int echoPin = 10;
long duration;
int distance;

LiquidCrystal lcd(RS, enable, d4, d5, d6, d7);
void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
  lcd.begin(16, 2);
}

unsigned long lastPrint = 0;

void loop() {

  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Sound wave reflects from the obstacle, so to calculate the distance we
  // consider half of the distance traveled.
  distance= duration*0.034/2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);

  if(millis() - lastPrint  > 500){
    lastPrint = millis();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Distance: ");
    lcd.print(distance);
    lcd.print(" cm");
    delay(10);
    lcd.setCursor(0, 1);
    lcd.print("Duration: ");
    lcd.print(duration);
    delay(10);
  }
}

//void loop() {
//  // set the cursor to column 0, line 1
//  // (note: line 1 is the second row, since counting begins with 0):
//  lcd.setCursor(1, 3);
//  // print the number of seconds since reset:
//  lcd.print("404");
//
//  
//}
