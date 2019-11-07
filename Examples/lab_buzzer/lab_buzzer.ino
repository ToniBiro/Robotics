int buzzer = 10;
int photo = A0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
}

int value = 0;

void loop() {
  // put your main code here, to run repeatedly:
  int read = analogRead(photo);
  tone(buzzer, value, 500);
  delay(100);
  noTone(buzzer);
  delay(100);
  value += 50;
}
