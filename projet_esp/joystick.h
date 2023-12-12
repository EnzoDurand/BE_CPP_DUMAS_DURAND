#ifndef _JOYSTICK_
#define _JOYSTICK_

#include "Actionneur.h"

class Joystick : public Actionneur {
  private :
    float offset;
  public:
    Joystick(void);
    float getangle (void);
};

#endif