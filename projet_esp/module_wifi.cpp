/*********************************************************************
 * @file  module_wifi.cpp
 * @author Enzo Durand
 * @brief Fichier source du module_wifi
 *********************************************************************/

#include "module_wifi.h"

ESP8266WebServer module_wifi::server(80); // Initialisation de l'objet statique


module_wifi::module_wifi()
{

}


module_wifi::~module_wifi()
{

}  


void module_wifi::handleRoot() {
  server.send(200, "text/html", "<h1>Matrice LED IoT :</h1>");
}

void module_wifi::init(void)
{
  IPAddress local_IP(192,168,8,8);
  IPAddress gateway(192,168,7,7);
  IPAddress subnet(255,255,255,0);
  
  Serial.println("Setting soft-AP configuration ... ");
  Serial.println(WiFi.softAPConfig(local_IP, gateway, subnet) ? "Ready" : "Failed!");
  Serial.println("Setting soft-AP ... ");
  Serial.println(WiFi.softAP("Matrice_LED_IoT", "azertyuiop", 5, false, 4) ? "Ready" : "Failed!");
  Serial.println("Soft-AP IP address = ");
  Serial.println(WiFi.softAPIP());
  
  server.on("/", module_wifi::handleRoot);
  server.begin();
  Serial.println("HTTP server started");

}


void module_wifi::run(void)
{
  server.handleClient();
}




