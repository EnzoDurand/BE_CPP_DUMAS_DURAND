/*
#include "AirQuality.h"
#include "Arduino.h"
#include "capteur_air.h"

void capteur_air::capteur_air(String pin){
  AirQualitySensor sensor(pin);
  this->sensor = sensor;
  this->pin = pin; 
  this->etatinit = false;
}
void capteur_air::init_capteur_air(){
 
  while(!(etatinit)){
    this->etatinit = this->sensor.init();
  }
  Serial.println("Sensor ready.");
}

int get_air_values(){
  if (!(this->etatinit)) {
    Serial.println("Sensor not initialized !!!");
    exit(-1);
  }
  return this->sensor.slope();
}
*/