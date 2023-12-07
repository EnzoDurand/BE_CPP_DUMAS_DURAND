/*********************************************************************
 * @file  module_wifi.cpp
 * @author Enzo Durand
 * @brief Fichier source du module_wifi
 *********************************************************************/

#include "module_wifi.h"

ESP8266WebServer module_wifi::server(80); // Initialisation de l'objet static (cf .h)

module_wifi::module_wifi()
{
  SSID = "ESP_Ecran_Servo";
  pass = "Cerveau82";
  servoValue = 90;  // Valeur par défaut

}


module_wifi::~module_wifi()
{

}  


void module_wifi::handleRoot() {


  File htmlFile = SPIFFS.open("/index.html", "r");
  if (!htmlFile) {
      Serial.println("Erreur ouverture index.html");
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
  Serial.println(WiFi.softAP(SSID, pass, 5, false, 4) ? "Ready" : "Failed!");
  Serial.println("Soft-AP IP address = ");
  Serial.println(WiFi.softAPIP());
  

  // Définir la route pour basculer l'état du bouton
  server.on("/sendText", HTTP_GET, [this]() {
    lastText = ( server.arg("text") );
    Serial.println(lastText);
    server.send(200, "text/plain", "Text received: " + get_lastText() );    
  });
  server.on("/toggleLedEsp", HTTP_GET, []() {
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN)); // Inverser l'état de la LED FAIRE DANS LE APPLI.CPP
    server.send(200, "text/plain", "Toggle LED ESP");

  });
  server.on("/toggleServo", HTTP_GET, []() {
      //fct du servo
      server.send(200, "text/plain", "Toggle Servo");

  });
  
  server.on("/getSliderValue", HTTP_GET,[this]() {
      String response = "{\"value\": " + String(servoValue) + "}";
      server.send(200, "application/json", response);
  });

  server.on("/adjustServo", HTTP_GET, [this]() {
    if (server.hasArg("value")) {
      servoValue = server.arg("value").toInt();
      String response = "{\"value\": " + String(servoValue) + "}";
      server.send(200, "application/json", response);
    }
    else {
      server.send(400, "text/plain", "Bad Request");
    }

  });

  server.client();
  server.on("/", HTTP_GET, module_wifi::handleRoot);
  server.begin();
  Serial.println("HTTP server started");

}


void module_wifi::run(void)
{
  server.handleClient();
  nb_clients = server.client().available();

}

String module_wifi::get_lastText() {return lastText;}
void module_wifi::set_lastText(String t) {lastText = t;}

String module_wifi::get_SSID() {return SSID;}
String module_wifi::get_pass() {return pass;}
int  module_wifi::get_nb_clients() {return nb_clients;}

int module_wifi::get_servoValue() {return servoValue;}
void module_wifi::set_servoValue(int v) {if ( 0<=v && v<=180) servoValue = v;}

