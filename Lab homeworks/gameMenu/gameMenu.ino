# include <LiquidCrystal.h>
# include <EEPROM.h>
# include <string.h>
int addr = 0;
const int RS = 12;
const int enable = 11;
const int d4 = 5;
const int d5 = 4;
const int d6 = 3;
const int d7 = 2;

const int swPin = 8;
const int xPin = A0;
const int yPin = A1;

LiquidCrystal lcd(RS, enable, d4, d5, d6, d7);

void print_main_menu(){
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Start");
  lcd.setCursor(8, 0);
  lcd.print("Settings");
  lcd.setCursor(1, 1);
  lcd.print("HighScore");
}

void print_start_menu(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Lives:");
  lcd.setCursor(8, 0);
  lcd.print("Level:");
  lcd.setCursor(0, 1);
  lcd.print("Score:");
}

void print_game_over(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Game Over!");
  delay(2000);
}

void print_highScore(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("HighScore:");
}

void print_settings(){
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Choose level:");
  lcd.setCursor(1, 1);
  lcd.print("Name:");
}

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Menu Homework:)!");
  delay(2500);
  print_main_menu();
  
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(swPin, INPUT_PULLUP);
}

unsigned long lastPrint = 0;
unsigned long lastDebounceTime = 0;
int debounceDelay = 50;
int buttonState= 0;
int lastButtonState = 0;

const int minThreshold = 400;
const int maxThreshold = 600;
int xValue;
int yValue;
int swState;
bool joyMoved = false;
int cursorPosition = 0;
int settingsCursor = 1;

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
  lastButtonState = reading;
}

int highScore = 0;
int score = 0;
int level = 1;
int lives = 3;
unsigned long initEntryTime;
unsigned long entryTime;
char player[8];
char inChar; 
byte index = 0;

bool check = true;

void loop() {

  xValue = analogRead(xPin);
  yValue = analogRead(yPin);
  debounce(digitalRead(swPin));
  
  if (yValue > maxThreshold && joyMoved == false && swState == 1) {
    if(cursorPosition >= 3)
      cursorPosition = 1;
    else
      cursorPosition++;
    print_main_menu();
    if(cursorPosition == 1){
      lcd.setCursor(0, 0);
      lcd.print(">");
    }
    else{
      if(cursorPosition == 2){
        lcd.setCursor(7, 0);
        lcd.print(">");
      }
      else{
        lcd.setCursor(0, 1);
        lcd.print(">");
      }
    }
    joyMoved = true;
  }

  if(cursorPosition == 1 && swState == 0){
    if(check == true){
      initEntryTime = millis();
      entryTime = millis();
      print_start_menu();
      check = false;
      score = 0;
    }
    if(millis() - initEntryTime >= 10000){
      print_game_over();
      print_main_menu();
      swState = 1;
      check = true;
    }
    else{
      // we are in the START menu
      lcd.setCursor(6, 0);
      lcd.print(lives);
      lcd.setCursor(14, 0);
      lcd.print(level);
      lcd.setCursor(7, 1);
      lcd.print(score);
      if(millis() - entryTime >= 3000){
        score = score + level * 3;
        entryTime = millis();
      }   
    }
   if(score > highScore){
    highScore = score;
    addr = 0;
    EEPROM.write(addr, highScore);
    addr++;   
   }
  }

  if(cursorPosition == 2 && swState == 0){
    if(check == true){
      print_settings();
      lcd.setCursor(0, 0);
      lcd.print(">");
      lcd.setCursor(6, 1);
      lcd.print(player);
      check = false;
    }
    if(yValue > maxThreshold && joyMoved == false){
      if(settingsCursor == 1){
        settingsCursor = 2;
        lcd.setCursor(0, 0);
        lcd.print(" ");
        lcd.setCursor(0, 1);
        lcd.print(">");
      }
      else{
          if(settingsCursor == 2){
            settingsCursor = 1;
            lcd.setCursor(0, 1);
            lcd.print(" ");
            lcd.setCursor(0, 0);
            lcd.print(">");
          }
      }
      joyMoved = true;
    }
    if(xValue > maxThreshold && joyMoved == false && settingsCursor == 1){
      if(level >= 9){
        level = 9;
      }
      else{
        level++;
      }
      joyMoved = true;
    }
    if(xValue < minThreshold && joyMoved == false && settingsCursor == 1){
      if(level <= 1){
        level = 1;
      }
      else{
        level--;
      }
      joyMoved = true;
    }
    lcd.setCursor(14, 0);
    lcd.print(level);

    if(settingsCursor == 2){
      if(Serial.available() > 0){
        
        if(index < 7){ // One less than the size of the array
          inChar = Serial.read(); // Read a character
          player[index] = inChar; // Store it
          index++; // Increment where to write next
          player[index] = '\0';
        }
      }
      lcd.setCursor(6, 1);
      lcd.print(player);
    }
  }


  if(cursorPosition == 3 && swState == 0){
    int hs;
    if(check == true){
      print_highScore();
      int aux_addr = 0;
      hs = EEPROM.read(aux_addr);
      aux_addr++;
      check = false;
    }   
    lcd.setCursor(10, 0);
    lcd.print(hs);
  }
  
  if (xValue >= minThreshold && xValue <= maxThreshold && yValue >= minThreshold && yValue <= maxThreshold) {
    joyMoved= false;
  }
  
  
  
   if(swState == 1 && check == false){
    print_main_menu();
    check = true;
   }
   
}
