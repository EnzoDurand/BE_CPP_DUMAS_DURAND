
/*********************************************************************
 * @file  Apllication.cpp
 * @author <mettre l'adresse mail ou nom prenom>
 * @brief Fichier source de l'application
 *********************************************************************/
#include "Application.h"
#include "servo.h"
#include "joystick.h"

Application::Application() 

{
  //Déclarations et création des objets : 
  
}
  
Application::~Application()
{
  // Code

}  

void Application::init(void)
{
  //serial_ide liaison_serie;
  //Serial.begin(115200);
  //delay(1000); // Wait for serial to initialize
  //Serial.println("Liaison série établie.");

  // Définir la broche de la LED comme sortie
  //pinMode(LED_BUILTIN, OUTPUT);

  // Initialisation SPIFFS
  //if (!SPIFFS.begin()) {
  //  Serial.println("Failed to mount file system");
  //  return;
  //}

  //Initialisation wifi:
  //wifi_esp.init();
  /*int indexServo[16] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
  Joystick MonJoystick;
  Servo MonServo(D3,indexServo);*/

}


void Application::run(void)
{
  //wifi_esp.run();
}
