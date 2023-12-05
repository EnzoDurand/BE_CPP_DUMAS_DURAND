#include <Arduino.h>

#ifndef _CAPTEUR_AIR_
#define _CAPTEUR_AIR_

class capteur_air {

  String pin;
  bool etatinit;
  AirQualitySensor sensor;
  public :
  void init_capteur_air();
  int get_air_values();
  String get_string();

}



#endif

