/*********************************************************************
 * @file  module_wifi.h
 * @author Enzo Durand
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

  public :
  
    /**
     * @fn module_wifi();
     * @brief Constructeur par defaut
    */    
    module_wifi();


    /**
     * @fn module_wifi();
     * @brief Destructeur
    */    
    ~module_wifi();    

    /**
     * @fn void handleRoot();
     * @brief Fonction pour HTML
    */
    static void handleRoot();


    /**
     * @fn void init(void)
     * @brief Fonction d'initialisation de l'module_wifi
    */
    void init(void);


    /**
     * @fn void run(void)
     * @brief Fonction de lancement de l'module_wifi
    */
    void run(void);
};


#endif