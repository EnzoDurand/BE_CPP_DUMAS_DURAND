#ifndef _JOYSTICK_
#define _JOYSTICK_

class Joystick {
  private :
    float offset;
  public:
    Joystick(void);
    float getangle (void);
};

#endif