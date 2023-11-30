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
  server.send(200, "text/html", "
  <h1>Matrice LED IoT :</h1>

  <head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>ESP8266 Button</title>
</head>
<body>
  <button id="toggleButton" onclick="toggleLED()">Toggle LED</button>

  <script>
    function toggleLED() {
      // Envoyer une requête AJAX pour basculer l'état du bouton
      var xhr = new XMLHttpRequest();
      xhr.onreadystatechange = function() {
        if (xhr.readyState == 4 && xhr.status == 200) {
          // Afficher la réponse de l'ESP8266 dans la console
          console.log(xhr.responseText);
        }
      };
      xhr.open("GET", "/toggle", true);
      xhr.send();
    }
  </script>
</body>
 
  
  ");
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


/*#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char *ssid = "Votre_SSID";
const char *password = "Votre_Mot_de_Passe";

ESP8266WebServer server(80);

int ledPin = D2; // Définir le numéro de broche de la LED

void setup() {
  Serial.begin(115200);

  // Connectez-vous au réseau WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Définir la broche de la LED comme sortie
  pinMode(ledPin, OUTPUT);

  // Définir la route pour basculer l'état du bouton
  server.on("/toggle", HTTP_GET, []() {
    digitalWrite(ledPin, !digitalRead(ledPin)); // Inverser l'état de la LED
    server.send(200, "text/plain", String(digitalRead(ledPin)));
  });

  // Charger la page HTML
  server.on("/", HTTP_GET, []() {
    server.send(200, "text/html", "<html><body><button onclick=\"toggleLED()\">Toggle LED</button><script>function toggleLED(){var xhr=new XMLHttpRequest();xhr.onreadystatechange=function(){if(xhr.readyState==4&&xhr.status==200){console.log(xhr.responseText);}};xhr.open(\"GET\",\"/toggle\",true);xhr.send();}</script></body></html>");
  });

  // Démarrer le serveur
  server.begin();
}

void loop() {
  // Gérer les requêtes du serveur
  server.handleClient();
}
Assurez-vous de remplacer "Votre_SSID" et "Votre_Mot_de_Passe" par les informations de votre réseau WiFi. Ce code crée un serveur web sur l'ESP8266 qui sert une page HTML avec un bouton. Lorsque le bouton est cliqué, une requête est envoyée à l'ESP8266 pour basculer l'état de la LED, et la réponse est renvoyée à la console série.

*/

