#include "Application.h"
#include "servo.h"
#include "joystick.h"

Application App;


/*
A FAIRE :
• Création	de	plusieurs	classes
• Utilisation	du	mécanisme	d’héritage
• Redéfinition	d’opérateur
• Utilisation	de	la	STL
• Utilisation	des	exceptions
*/
float angle;
int indexServo[16] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
Servo MonServo(D3,indexServo);
Joystick MonJoystick;

void setup()
{
  //App.init();
  MonServo.setangle(0,indexServo,D3);
  delay(1000);
  MonServo.setangle(90,indexServo,D3);
  delay(1000);
  MonServo.setangle(180,indexServo,D3);
  delay(1000);
  MonServo.setangle(0,indexServo,D3);
  delay(1000);
}

void loop()
{
  //App.run();
  angle = MonJoystick.getangle();
  MonServo.setangle(1000*angle,indexServo,D3);
  delay(1000);
}