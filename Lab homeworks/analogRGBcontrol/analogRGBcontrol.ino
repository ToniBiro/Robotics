int red_pot = A0;
int green_pot = A1;
int blue_pot = A2;

int red_led = 11;
int green_led = 10;
int blue_led = 9;

const int buzz_pin = 3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(red_pot, INPUT);  // initialize the pins
  pinMode(green_pot, INPUT);
  pinMode(blue_pot, INPUT);
  pinMode(red_led, OUTPUT);
  pinMode(green_led, OUTPUT);
  pinMode(blue_led, OUTPUT);
  pinMode(buzz_pin, OUTPUT);
}

unsigned long last_time = 0;
unsigned long current_time = 0;
int interval = 500;

void loop() {
  // put your main code here, to run repeatedly:
  int red_read = map(analogRead(red_pot), 0, 1023, 0, 255);     // reading the values of the potentiometers and mapping them
  int green_read = map(analogRead(green_pot), 0, 1023, 0, 255);
  int blue_read = map(analogRead(blue_pot), 0, 1023, 0, 255);
  setColor(red_read, green_read, blue_read);  //call the setColor function in order to light up the leds accordingly to the mapped values
  Serial.println(max(max(red_read, green_read), blue_read));  //a little debugging help ;3

  current_time = millis();
  if (current_time-last_time >= 100)
  {
    last_time = current_time;
    tone(buzz_pin, map(max(max(red_read, green_read), blue_read), 0, 255, 0, 1000));  // added a buzzer and a button to the circuit
                                                                                      // so that the buzzer plays the max value read from the potentiometer only when the button is pushed        
  }
  else
  {
    noTone(buzz_pin);
  }
  
}

void setColor(int red, int green, int blue)
{
  analogWrite(red_led, red);
  analogWrite(green_led, green);
  analogWrite(blue_led, blue);
}
