int red_pot = A0;
int green_pot = A1;
int blue_pot = A2;

int red_led = 11;
int green_led = 10;
int blue_led = 9;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(red_pot, INPUT);  // initialize the pins
  pinMode(green_pot, INPUT);
  pinMode(blue_pot, INPUT);
  pinMode(red_led, OUTPUT);
  pinMode(green_led, OUTPUT);
  pinMode(blue_led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int red_read = map(analogRead(red_pot), 0, 1023, 0, 255);     // reading the values of the potentiometers and mapping them
  int green_read = map(analogRead(green_pot), 0, 1023, 0, 255);
  int blue_read = map(analogRead(blue_pot), 0, 1023, 0, 255);
  setColor(red_read, green_read, blue_read);  //call the setColor function in order to light up the leds accordingly to the mapped values
  Serial.println(max(max(red_read, green_read), blue_read));  //a little debugging help ;3
}

void setColor(int red, int green, int blue)
{
  analogWrite(red_led, red);
  analogWrite(green_led, green);
  analogWrite(blue_led, blue);
}
