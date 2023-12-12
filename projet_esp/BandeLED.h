#include <Adafruit_NeoPixel.h>
#include "Actioneur.h"

#ifndef _BANDELED_
#define _BANDELED_

class BandeLED : public Actioneur {
  private :
    int niveau; //De 0 à 9;
    Adafruit_NeoPixel matrix;
  public:
    BandeLED(const uint8_t pin);
    void setLevel (int level);
    int getLevel (void);
};

#endif