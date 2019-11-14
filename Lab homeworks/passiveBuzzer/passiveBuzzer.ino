#include"pitches.h"

int p_buzzer = A0;
int a_buzzer = 11;
int button = 6;

int p_buzzer_value = 0;
int led_state = LOW;
int threshold = 450;

int button_state = LOW;
bool play = false;

unsigned long last_time = 0;

// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4, 4
};

void setup() {
  Serial.begin(9600);
  pinMode(a_buzzer, OUTPUT);
  pinMode(button, INPUT_PULLUP);
}

void play_song()
{
  unsigned long prev_time = millis();
  for (int i = 0; i < 8; ++i)
  {
    int duration = 1000 / noteDurations[i];
    tone(a_buzzer, melody[i], duration);
//    if(millis() - prev_time >= 1.3*duration)
//    {
//      prev_time = millis();
//      noTone(a_buzzer);
//    }
    delay(1.3*duration);
    noTone(a_buzzer);
//    if(button_reading == 0)
//    {
//      noTone(a_buzzer);
//    }
  }
}

void loop() {
  
  p_buzzer_value = analogRead(p_buzzer);
  int button_reading = digitalRead(button);

  if(p_buzzer_value != 0)
    Serial.println(p_buzzer_value);
  
  if(p_buzzer_value >= 600)
  {
    play = true;
  }
  if(play == false)
    last_time = millis();
    
  if(play == true)
  {
    if(millis() - last_time >= 5000)
    {
      tone(a_buzzer, NOTE_G3);
      play = false;
    }
  }
  if(button_reading == 0)
  {
    noTone(a_buzzer);
  }
  delay(100);
}
