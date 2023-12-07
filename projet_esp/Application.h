/*********************************************************************
 * @file  Apllication.h
 * @author <mettre l'adresse mail ou nom prenom>
 * @brief Fichier header de l'application
 *********************************************************************/
#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "module_wifi.h"
#include "FS.h"
#include "servo.h"
#include "joystick.h"

/**
  * @class Application
  * @brief Classe Application 
*/    
class Application
{
  private :
    module_wifi wifi_esp;

  public :
    int indexServo[16] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    Joystick MonJoystick;
    //Servo MonServo;
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
};
#endif