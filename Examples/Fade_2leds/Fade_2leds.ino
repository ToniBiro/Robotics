int first_led = 3;
int second_led = 9;
int aux;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  for( int i = 0; i < 256; ++i)
  {
    analogWrite(first_led, i);
    delay(3);
    analogWrite(second_led, 256-i);
    delay(3);
  }
  aux = first_led;
  first_led = second_led;
  second_led = aux;
  //delay(30);

}
