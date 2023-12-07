
#include "ESP8266_ISR_Servo.h"
#include "servo.h"

#define MIN_MICROS      700
#define MAX_MICROS      2400

Servo::Servo(const uint8_t pin){
  ISR_Servo.enableAll();
  this->etatinit=false;
  indexServo=ISR_Servo.setupServo(pin, MIN_MICROS, MAX_MICROS);
}

void Servo::setangle (float angle){

  ISR_Servo.setPosition(indexServo, angle);
  this->angle=angle;
}
float Servo::getangle (){
  return ISR_Servo.getPosition(indexServo);
}
