/*********************************************************************
 * @file  Apllication.h
 * @author Julien Dumas et Enzo Durand
 * @brief Fichier header de l'application
 *********************************************************************/
#ifndef APPLICATION_H_
#define APPLICATION_H_

#include <Arduino.h>
#include <Wire.h>
#include "rgb_lcd.h"
#include "module_wifi.h"
#include "FS.h"
#include "servo.h"
#include "joystick.h"
#include "BandeLED.h"
#include <vector> //LA STL

/**
  * @class Application
  * @brief Classe Application 
*/    
class Application
{
  private :
    module_wifi wifi_esp;
    bool attente_connexion;
    String lastMsg;
    String Msg;

    rgb_lcd lcd;
    Servo servo;   
    Joystick joystick;
    BandeLED mabandeLED;

    float angleJoystick;
    float angleServo;
    float angleServoVoulu;

  public :
  /**
    * @fn Application();
    * @brief Constructeur par defaut
  */    
  Application();


  /**
    * @fn Application();
    * @brief Destructeur
  */    
  ~Application();  


  /**
    * @fn void init(void)
    * @brief Fonction d'initialisation de l'application
  */
  void init(void);


  /**
    * @fn void run(void)
    * @brief Fonction de lancement de l'application
  */
  void run(void);

  void lireAnalogique();
};
#endif