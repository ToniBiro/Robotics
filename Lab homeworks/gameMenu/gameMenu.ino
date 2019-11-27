# include<LiquidCrystal.h>
const int RS = 12;
const int enable = 11;
const int d4 = 5;
const int d5 = 4;
const int d6 = 3;
const int d7 = 2;

const int swPin = A2;
const int xPin = A0;
const int yPin = A1;

unsigned long lastPrint = 0;

LiquidCrystal lcd(RS, enable, d4, d5, d6, d7);
void setup() {
  Serial.begin(9600); // Starts the serial communication
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Hello World");
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(swPin, INPUT_PULLUP);
}

unsigned long lastDebounceTime;
int debounceDelay = 500;
int buttonState,lastButtonState;
int swState;

void debounce(bool reading){
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;

      if (buttonState == LOW) {
        swState = !swState;
      }
    }
  }
}

int xRead, yRead, swRead;

void loop() {

  xRead = analogRead(xPin);
  yRead = analogRead(yPin);
  swRead = digitalRead(swPin);
  debounce(swRead);

  Serial.println(swState);
    
  if(millis() - lastPrint >=500){
    lastPrint = millis();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(xRead);
    lcd.print(" ");
    lcd.print(yRead);
    lcd.print(" ");
    lcd.print(swState);
  }
}
