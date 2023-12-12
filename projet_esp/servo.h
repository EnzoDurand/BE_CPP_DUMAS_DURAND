#ifndef _SERVO_
#define _SERVO_

#include "Actionneur.h"

class Servo: public Actionneur{
  private :
    float angle;
    bool etatinit;
    int indexServo = -1;

  public:
    Servo(const uint8_t pin);
    void setangle (float angle);
    float getangle ();
    Servo& operator+=(float valeur);

};

#endif