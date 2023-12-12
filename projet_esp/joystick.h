#include "Actioneur.h"

#ifndef _JOYSTICK_
#define _JOYSTICK_

class Joystick : public Actioneur {
  private :
    float offset;
  public:
    Joystick(void);
    float getangle (void);
};

#endif