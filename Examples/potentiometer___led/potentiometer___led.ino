
int LEDPIN = 3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LEDPIN, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  int ledValue = map(sensorValue, 0, 1023, 0, 255);
  analogWrite(LEDPIN, ledValue);
}
