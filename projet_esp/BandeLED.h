#include <Adafruit_NeoPixel.h>


#ifndef _BANDELED_
#define _BANDELED_

class BandeLED {
  private :
    int niveau; //De 0 à 9;
    Adafruit_NeoPixel matrix;
  public:
    BandeLED(const uint8_t pin);
    void setLevel (int level);
    int getLevel (void);
};

#endif