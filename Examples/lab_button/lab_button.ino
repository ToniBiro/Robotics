const int button_pin = 2;
const int led_built_in = 13;
const int led = 4;

void setup() {
  // put your setup code here, to run once:
  pinMode(button_pin, INPUT_PULLUP);
  pinMode(led_built_in, OUTPUT);
  Serial.begin(9600);
  digitalWrite(led, LOW);
}

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;
int buttonState = LOW;
int lastButtonState = buttonState;
int ledState = LOW;


void loop() {
  // put your main code here, to run repeatedly:
  int reading = digitalRead(button_pin);
  
  Serial.println(reading);

  if (reading != lastButtonState)
  {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay)
  {
    if(reading != buttonState)
    {
      buttonState = reading;
    }
    if (buttonState == LOW)
    {
      ledState = !ledState;
      
    }
    
  }
  lastButtonState = reading;
  digitalWrite(led, ledState);
  
}
