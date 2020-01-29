

const int enablePin = 11;
const int in1Pin = 10;
const int in2Pin = 9;


void setup() {
  
  Serial.begin(9600); // communication with bluetooth module
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(enablePin, OUTPUT);


}

void setMotor(int motorSpeed , boolean reverse)
{
  analogWrite(enablePin, motorSpeed );
  digitalWrite(in1Pin, ! reverse);
  digitalWrite(in2Pin, reverse);
}


void loop() {
  if(Serial.available()){
    int t = Serial.read();
    Serial.println(t);
  }
}
