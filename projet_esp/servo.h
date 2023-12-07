#ifndef _SERVO_
#define _SERVO_

class Servo {
  private :
    float angle;
    bool etatinit;
    int indexServo = -1;

  public:
    Servo(const uint8_t pin);
    void setangle (float angle);
    float getangle ();

};

#endif