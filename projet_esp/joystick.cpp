#include <Arduino.h>
#include "joystick.h"

Joystick::Joystick(void){
  offset = 0;
  for (int i = 0; i< 100; i++)
  {
      offset += (float)analogRead(A0); //calibrage.
  }
  offset /= 100.0;
  this->nbactioneur++;
}

float Joystick::getangle(void){
  return (float)(analogRead(A0)-(float)(offset/2)) * (float)(180/offset);
}