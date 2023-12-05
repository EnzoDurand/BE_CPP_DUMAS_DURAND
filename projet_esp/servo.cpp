#include "ESP8266_ISR_Servo.h"
#include "servo.h"

#define MIN_MICROS      800  
#define MAX_MICROS      2450
Servo::Servo(const uint8_t pin, int * servoIndex){
  ISR_Servo.enableAll();
  this->etatinit=false;
  servoIndex[(int) pin]=ISR_Servo.setupServo(pin, MIN_MICROS, MAX_MICROS);
}

void Servo::setangle (float angle,int * servoIndex,const uint8_t pin){

  ISR_Servo.setPosition(servoIndex[(int)pin], angle);
  this->angle=angle;
}
float Servo::getangle (int * servoIndex,const uint8_t pin){
  return ISR_Servo.getPosition(servoIndex[(int)pin]);
}