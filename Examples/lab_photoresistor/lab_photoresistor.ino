int photo_rez = A0;
int led = 5;
int led_state = LOW;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(photo_rez, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int read = analogRead(photo_rez);
  Serial.println(read);
  //analogWrite(led, map(read, 0, 1023, 0, 255));

  if (read > 300)
  {
    digitalWrite(led, LOW);
  }
  else
  {
    digitalWrite(led, HIGH);
  }
}
