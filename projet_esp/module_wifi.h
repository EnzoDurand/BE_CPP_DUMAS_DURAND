/*********************************************************************
 * @file  module_wifi.h
 * @author Enzo Durand et Julien Dumas
 * @brief Fichier header du module_wifi
 *********************************************************************/
#ifndef MODULE_WIFI_H
#define MODULE_WIFI_H

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
/**
  * @class module_wifi
  * @brief Classe module_wifi 
*/    

class module_wifi
{
  private :
    static ESP8266WebServer server;
    String lastText = " ";
    String SSID;
    String pass;
    int nb_clients;
    int servoValue; //Valeur sur la page HTML

  public :
  
    module_wifi(); 
    ~module_wifi();    

    static void handleRoot();
    void init(void);
    void run(void);

    String get_lastText();
    void set_lastText(String t);

    String get_SSID();
    String get_pass();
    int get_nb_clients();

    int get_servoValue();
    void set_servoValue(int);

};


#endif