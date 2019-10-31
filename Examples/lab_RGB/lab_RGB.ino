int R_led_pin = 11;
int G_led_pin = 10;
int B_led_pin = 9;
int pot_pin = A0;
int simple_led_pin = 5;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(R_led_pin, OUTPUT);
  pinMode(G_led_pin, OUTPUT);
  pinMode(B_led_pin, OUTPUT);
  pinMode(pot_pin, INPUT);
}

void RGB_set_color(int R_value, int G_value, int B_value)
{
  analogWrite(R_led_pin, R_value);
  analogWrite(G_led_pin, G_value);
  analogWrite(B_led_pin, B_value);
}

int a = 0;
int b = 0;
int c = 0;
void loop() {
  // put your main code here, to run repeatedly:

  int pot_value = analogRead(pot_pin);
  Serial.println(pot_value);
  int simple_led_value = map(pot_value, 0, 1023, 0, 255);
  analogWrite(simple_led_pin, simple_led_value);

  RGB_set_color(a, b, c);
  a = pot_value%125;
  b = pot_value%100;
  c = pot_value;

}
