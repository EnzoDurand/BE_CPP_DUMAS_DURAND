
/*********************************************************************
 * @file  Apllication.cpp
 * @author <mettre l'adresse mail ou nom prenom>
 * @brief Fichier source de l'application
 *********************************************************************/
#include "Application.h"



Application::Application() : servo(D3)
{
  attente_connexion = true;
  Msg = "Saisir du texte.";
  lastMsg = "";
}
  
Application::~Application()
{
  // Code

}  

void Application::init(void)
{
  //serial_ide liaison_serie;
  Serial.begin(115200);
  delay(100);
  Serial.println("Liaison série établie.");

  // Définir la broche de la LED intégrée comme sortie
  pinMode(LED_BUILTIN, OUTPUT);


  // Initialisation SPIFFS (système de fichier embarqué)
  if (!SPIFFS.begin()) {
    Serial.println("Failed to mount file system");
    return;
  }

  //Initialisation wifi:
  wifi_esp.init();
  
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("Bonjour !");
  delay(4000);
  lcd.setCursor(0,0);
  lcd.print("Parametres WiFi:");
  delay(4000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(wifi_esp.get_SSID());
  lcd.setCursor(0,1);
  lcd.print(wifi_esp.get_pass());
  delay(1000);
}

int count = 0;


void Application::run(void)
{

  //Le joystick à la priorité sur la version web dès qu'il n'est plus au repos.
  if (count > 10000)
  {
     angleJoystick = joystick.getangle();
  if (angleJoystick < 85 || angleJoystick > 95) angleServoVoulu = angleJoystick;
  else angleServoVoulu = wifi_esp.get_servoValue();
  }
  count++;
 
  
  if (abs(angleServo-angleServoVoulu) >= 5) //hystérésis de 2 degrés
  {
    angleServo = angleServoVoulu;
    servo.setangle(angleServo);
  }
  

  wifi_esp.run();
  if (wifi_esp.get_nb_clients() > 0) //Si au moins un client connecté
  {
    if (attente_connexion) 
    {
      lcd.clear(); //Lors de la première connexion
      attente_connexion = false;
    }

    Msg = wifi_esp.get_lastText();
    if (Msg != lastMsg)
    {
      lastMsg = Msg;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(lastMsg.substring(0, 16));
      lcd.setCursor(0,1);
      lcd.print(lastMsg.substring(17, 32));
    }

  }
}

