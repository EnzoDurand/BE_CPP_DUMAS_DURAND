/*
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
    this->etatinit = this->sensor.init(this->pin);
  }
  Serial.println("Sensor ready.");
}

int get_air_values(){
  if (!(this->etatinit)) {
    Serial.println("Sensor not initialized !!!");
    exit(-1);
  }
  return this->sensor.slope(); //renvoie une valeur de 0 à 3, 0 =très pollué
}

String get_string(){
  int temp = get_air_values()
  if (temp=0) return "Air très très pollué";
  else if (temp=1) return "Air très pollué";
  else if (temp=2) return "Air très pollué";
  else if (temp=3) return "Air frais";
  else return "erreur valeur"
}
*/