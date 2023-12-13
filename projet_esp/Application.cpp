
/*********************************************************************
 * @file  Apllication.cpp
 * @author <mettre l'adresse mail ou nom prenom>
 * @brief Fichier source de l'application
 *********************************************************************/
#include "Application.h"

Application::Application() : servo(D5), mabandeLED(D7)
{
  attente_connexion = true;
  angleServo = 0.0;
  Msg = "Saisir du texte.";
  lastMsg = "";
}
  
Application::~Application()
{
  // Code
}  

void Application::init(void)
{

  //UTILISATION STL : vecteur d'entiers
  std::vector<int> monVecteur;
  // Ajouter des éléments au vecteur
  monVecteur.push_back(1);
  monVecteur.push_back(2);
  monVecteur.push_back(3);
  //Aurait réellement servi si on avait la matrice led, pour gérer chaque pixel et construire des images...

  //serial_ide liaison_serie;
  Serial.begin(115200);
  delay(100);
  Serial.println("Liaison série établie.");

  //Dans la mesure où les librairies renverraient des exceptions :
  try {

    pinMode(LED_BUILTIN, OUTPUT);  // Défini la broche de la LED intégrée comme sortie

    //Initialisation SPIFFS (système de fichier embarqué)
    if (!SPIFFS.begin()) {
      Serial.println("Failed to mount file system");
      //return;
    }

    //Initialisation wifi:
    wifi_esp.init();
    
    //Init lcd :
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
  catch(...){
      Serial.println("Failed to itialise peripherals");
}
}




void Application::run(void)
{
  //Le joystick a la priorité sur la version web dès qu'il n'est plus au repos.
  angleJoystick = joystick.getangle(); //Fait planter wifi.

  if (angleJoystick < 85 || angleJoystick > 95)
  {
    angleServoVoulu = angleJoystick;
    wifi_esp.set_servoValue(angleServoVoulu);
  }

  else angleServoVoulu = wifi_esp.get_servoValue();

  //Affichage de l'angle en proportion sur la bande LED
  //mabandeLED.setLevel((int)(angleServoVoulu/18));

  //Utilisation du joystick en tant que commodo :
  if (angleJoystick > 120) mabandeLED.allume_cote(1);
  else if (angleJoystick < 60 ) mabandeLED.allume_cote(0);
  else mabandeLED.setLevel(0);


  
  if (abs(angleServo-angleServoVoulu) >= 5) //hystérésis de 5 degrés
  {
    angleServo = angleServoVoulu;
    servo.setangle(angleServo); //Affecte l'angle sur le servo réel.
  }



  wifi_esp.run();

  if (wifi_esp.get_nb_clients() > 0) //Si au moins un client connecté
  {
    if (attente_connexion) 
    {
      lcd.clear(); //S'exécute lors de la première connexion uniquement.
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

