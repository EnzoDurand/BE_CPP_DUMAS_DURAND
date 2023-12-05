#ifndef haut_parleur_H
#define haut_parleur_H

#include <Arduino.h>

class haut_parleur {
public:
  haut_parleur(uint8_t pin);
  ~haut_parleur();

  void playTone(int frequency, int duration);
  void stopSound();

private:
  int haut_parleurPin;
};

#endif
