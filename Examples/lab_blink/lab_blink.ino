void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

unsigned int currentValue = 0;
unsigned int lastValue = currentValue;
int ledState = LOW;
int interval = 1000;

void loop() {
  // put your main code here, to run repeatedly:

  currentValue = millis();
  if(currentValue - lastValue> interval)
  {
    ledState = !ledState;
    lastValue = currentValue;
  }  
  
  Serial.println(currentValue);
  digitalWrite(LED_BUILTIN, ledState);
}
