#include <Arduino.h>
#include "joystick.h"

Joystick::Joystick(void){
<<<<<<< Updated upstream
  this->angle=0;
}

float Joystick::getangle(void){
  this->angle=100*analogRead(A0);
  return this->angle;
=======
  offset = 0;
  for (int i = 0; i< 100; i++)
  {
      offset += (float)analogRead(A0); //calibrage.
  }
  offset /= 100.0;
}

float Joystick::getangle(void){
  return (float)(analogRead(A0)-(float)(offset/2)) * (float)(180/offset);
>>>>>>> Stashed changes
}