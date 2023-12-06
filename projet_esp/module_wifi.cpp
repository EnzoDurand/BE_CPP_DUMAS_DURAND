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


  File htmlFile = SPIFFS.open("/index.html", "r");
  if (!htmlFile) {
      Serial.println("Failed to open index.html");
      return;
  }

  // Send the content as the HTTP response
  server.streamFile(htmlFile, "text/html");

  htmlFile.close(); 
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
  



  // Définir la route pour basculer l'état du bouton
  server.on("/sendText", HTTP_GET, []() {
    String textReceived = server.arg("text");
    Serial.println(textReceived);
    server.send(200, "text/plain", "Text received: " + textReceived);    
  });
  server.on("/toggleLedEsp", HTTP_GET, []() {
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN)); // Inverser l'état de la LED
    server.send(200, "text/plain", "Toggle LED ESP");

  });
  server.on("/toggleServo", HTTP_GET, []() {
      //fct du servo
      server.send(200, "text/plain", "Toggle Servo");

  });
  
  server.on("/", HTTP_GET, module_wifi::handleRoot);
  server.begin();
  Serial.println("HTTP server started");



}


void module_wifi::run(void)
{
  server.handleClient();
}
