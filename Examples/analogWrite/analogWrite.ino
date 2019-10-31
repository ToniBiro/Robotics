int led_pin = 3;
void setup() {
  // put your setup code here, to run once:
  pinMode(led_pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 256; i+=10)
    {analogWrite(led_pin, i);
    delay(30);}
}
