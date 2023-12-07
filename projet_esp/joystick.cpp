#include <Arduino.h>
#include "joystick.h"

Joystick::Joystick(void){
  this->angle=0;
}

float Joystick::getangle(void){
  this->angle=100*analogRead(A0);
  return this->angle;
}