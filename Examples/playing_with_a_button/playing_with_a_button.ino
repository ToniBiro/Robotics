int LEDPIN = 4;
int pushButton = 2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pushButton, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int buttonState = digitalRead(pushButton);
  Serial.println(buttonState);
  delay(1);  
}
