#ifndef _BANDELED_
#define _BANDELED_

#include <Adafruit_NeoPixel.h>
#include "Actionneur.h"


class BandeLED : public Actionneur {
  private :
    int niveau; //De 0 à 9;
    Adafruit_NeoPixel matrix;
  public:
    BandeLED(const uint8_t pin);
    void setLevel (int level);
    int getLevel (void);
    void allume_cote(bool c); //0 gauche | 1 : droite

};

#endif