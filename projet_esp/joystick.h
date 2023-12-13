#ifndef _JOYSTICK_
#define _JOYSTICK_

#include "capteur.h"

class Joystick : public capteur {
  private :
    float offset;
  public:
    Joystick(void);
    float getangle (void);
};

#endif