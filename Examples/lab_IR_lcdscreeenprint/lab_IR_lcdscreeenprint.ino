#include <IRremote.h>
const int receiverPin = 8;
IRrecv irrecv(receiverPin);
decode_results results;
unsigned long keyValue = 0;

# include<LiquidCrystal.h>
const int RS = 12;
const int enable = 11;
const int d4 = 5;
const int d5 = 4;
const int d6 = 3;
const int d7 = 2;
unsigned long lastPrint = 0;

LiquidCrystal lcd(RS, enable, d4, d5, d6, d7);

void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn(); // configure the baud rate and start the IR receiver
  irrecv.blink13(true); // blinks the LED everytime it receives a signal
  lcd.begin(16, 2);
}

void loop(){
  if (irrecv.decode(&results)){
    if (results.value == 0XFFFFFFFF)
    results.value = keyValue;
    switch(results.value){
      case 0xFFA25D:
      Serial.println("CH-");
      if(millis() - lastPrint  > 500){
        lcd.setCursor(0, 0);
        lastPrint = millis();
        lcd.print("CH-");
        lcd.clear();
      }
      break;
      case 0xFF629D:
      Serial.println("CH");
      if(millis() - lastPrint  > 500){
        lcd.setCursor(0, 0);
        lastPrint = millis();
        lcd.print("CH");
        lcd.print(" ");
      }
      break;
      case 0xFFE21D:
      Serial.println("CH+");
      if(millis() - lastPrint  > 500){
        lcd.setCursor(0, 0);
        lastPrint = millis();
        lcd.print("CH+");
        lcd.print(" ");
      }
      break;
      case 0xFF22DD:
      Serial.println("|<<");
      if(millis() - lastPrint  > 500){
        lcd.setCursor(0, 0);
        lastPrint = millis();
        lcd.print("|<<");
        lcd.print(" ");
      }
      break;
      case 0xFF02FD:
      Serial.println(">>|");
      if(millis() - lastPrint  > 500){
        lcd.setCursor(0, 0);
        lastPrint = millis();
        lcd.print(">>|");
        lcd.print(" ");
      }
      break ;
      case 0xFFC23D:
      Serial.println(">|");
      if(millis() - lastPrint  > 500){
        lcd.setCursor(0, 0);
        lastPrint = millis();
        lcd.print(">|");
        lcd.print(" ");
      }
      break ;
      Serial.println("-");
      if(millis() - lastPrint  > 500){
        lcd.setCursor(0, 0);
        lastPrint = millis();
        lcd.print("-");
        lcd.print(" ");
      }
      break ;
      case 0xFFA857:
      Serial.println("+");
      if(millis() - lastPrint  > 500){
        lcd.setCursor(0, 0);
        lastPrint = millis();
        lcd.print("+");
        lcd.print(" ");
      }
      break ;
      case 0xFF906F:
      Serial.println("EQ");
      if(millis() - lastPrint  > 500){
        lcd.setCursor(0, 0);
        lastPrint = millis();
        lcd.print("EQ");
        lcd.print(" ");
      }
      break ;
      case 0xFF6897:
      Serial.println("0");
      if(millis() - lastPrint  > 500){
        lcd.setCursor(0, 0);
        lastPrint = millis();
        lcd.print("0");
        lcd.print(" ");
      }
      break ;
      case 0xFF9867:
      Serial.println("100+");
      if(millis() - lastPrint  > 500){
        lcd.setCursor(0, 0);
        lastPrint = millis();
        lcd.print("100+");
        lcd.print(" ");
      }
      break ;
      case 0xFFB04F:
      Serial.println("200+");
      if(millis() - lastPrint  > 500){
        lcd.setCursor(0, 0);
        lastPrint = millis();
        lcd.print("200+");
        lcd.print(" ");
      }
      break ;
      case 0xFF30CF:
      Serial.println("1");
      if(millis() - lastPrint  > 500){
        lastPrint = millis();
        lcd.print("1");
        lcd.print(" ");
      }
      break ;
      case 0xFF18E7:
      Serial.println("2");
      if(millis() - lastPrint  > 500){
        lcd.setCursor(0, 0);
        lastPrint = millis();
        lcd.print("2");
        lcd.print(" ");
      }
      break ;
      case 0xFF7A85:
      Serial.println("3");
      if(millis() - lastPrint  > 500){
        lcd.setCursor(0, 0);
        lastPrint = millis();
        lcd.print("3");
        lcd.print(" ");
      }
      break ;
      case 0xFF10EF:
      Serial.println("4");
      if(millis() - lastPrint  > 500){
        lcd.setCursor(0, 0);
        lastPrint = millis();
        lcd.print("4");
        lcd.print(" ");
      }
      break ;
      case 0xFF38C7:
      Serial.println("5");
      if(millis() - lastPrint  > 500){
        lcd.setCursor(0, 0);
        lastPrint = millis();
        lcd.print("5");
        lcd.print(" ");
      }
      break ;
      case 0xFF5AA5:
      Serial.println("6");
      if(millis() - lastPrint  > 500){
        lcd.setCursor(0, 0);
        lastPrint = millis();
        lcd.print("6");
        lcd.print(" ");
      }
      break ;
      case 0xFF42BD:
      Serial.println("7");
      if(millis() - lastPrint  > 500){
        lcd.setCursor(0, 0);
        lastPrint = millis();
        lcd.print("7");
        lcd.print(" ");
      }
      break ;
      case 0xFF4AB5:
      Serial.println("8");
      if(millis() - lastPrint  > 500){
        lcd.setCursor(0, 0);
        lastPrint = millis();
        lcd.print("8");
        lcd.print(" ");
      }
      break ;
      default:
      Serial.println("9");
      if(millis() - lastPrint  > 500){
        lcd.setCursor(0, 0);
        lastPrint = millis();
        lcd.print("9");
        lcd.print(" ");
      }
      break ;
    }
    keyValue = results.value;
    irrecv.resume();
  }
}
