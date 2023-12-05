#include <Arduino.h>
#include "ESP8266_ISR_Servo.h"

#ifndef _SERVO_
#define _SERVO_

class Servo {
  float angle;
  bool etatinit;
  public:
  Servo(const uint8_t pin,int * servoIndex);
  void setangle (float angle, int * servoIndex,const uint8_t pin);
  float getangle (int * servoIndex,const uint8_t pin);
};

#endif