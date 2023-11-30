#include "Air_Quality_Sensor.h"

#ifndef _CAPTEUR_AIR_
#define _CAPTEUR_AIR_

class capteur_air {

  char pin;
  bool etatinit;
  AirQualitySensor sensor;
  void init_capteur_air();
  int get_air_values();

}



#endif

