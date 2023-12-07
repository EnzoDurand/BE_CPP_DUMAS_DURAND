
/*********************************************************************
 * @file  Apllication.cpp
 * @author <mettre l'adresse mail ou nom prenom>
 * @brief Fichier source de l'application
 *********************************************************************/
#include "Application.h"



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


void Application::run(void)
{
  wifi_esp.run();
  if (wifi_esp.get_nb_clients() > 0)
  {
    lcd.setCursor(0,0);
    lcd.print(wifi_esp.get_lastText());
  }
}

