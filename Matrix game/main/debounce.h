#pragma once
#include "global_variables.h"

void debounceDino1(bool reading){
  if (reading != lastSwState) {
    lastSwDebounceTime = millis();
  }

  if ((millis() - lastSwDebounceTime) > debounceDelay) {
    if (reading != pushSwState) {
      pushSwState = reading;

      if (pushSwState == HIGH) {
        swState = !swState;
      }
    }
  }
  lastSwState = reading;
}

void debounceDino2(bool reading){
  if (reading != lastSwState2) {
    lastSwDebounceTime2 = millis();
  }

  if ((millis() - lastSwDebounceTime2) > debounceDelay) {
    if (reading != pushSwState2) {
      pushSwState2 = reading;

      if (pushSwState2 == HIGH) {
        swState2 = !swState2;
      }
    }
  }
  lastSwState2 = reading;
}

void debounceButton(bool reading){
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != pushButtonState) {
      pushButtonState = reading;

      if (pushButtonState == HIGH){
        buttonState = !buttonState;
      }
    }
  }
  lastButtonState = reading;
}
