Cette application pour ESP8266/Arduino est conçue pour lier une carte wifi embarquée, un joystick, un servomoteur, un écran LCD, et une bande led.
Ce read-me a pour vocation d'aider à l'utilisation de l'application.
Veuillez vous référer au rapport ci-joint pour plus de détails sur le projet.

# Comment mettre en route le système
- Brancher l’afficheur LCD sur le port I2C.
- Brancher les autres périphériques sur les ports disponibles tel que vous l’avez indiqué dans les constructeurs de l’application.
    (actuellement : D5 pour le servo, D7 pour la bande led, et A0 pour le joystick).
- mettre sous tension la carte ESP8266 et injecter le code après l’avoir compilé via l'IDE Arduino.
    (Ce dernier vous demandera probablement d'installer les librairies nécessaires.)
- Connectez-vous à la carte ESP8266 via le réseau Wi-Fi | SSID :”ESP_Ecran_Servo” et avec le mot de passe : “Cerveau82”.
- Sur la page HTML accessible sur l'IP 192.168.8.8, vous pourrez basculer l'état de la led embarquée, envoyer un message vers l'écran LCD, et modifier l'angle du servomoteur.
- Utilisez un joystick pour ajuster l'angle du servomoteur et/ou les clignotants (selon le code commenté ou non dans Application.cpp).
    (Le joystick est prioritaire sur l'interfaçe web).

# Application Arduino
Voici un aperçu du fonctionnement : 

## Initialisation
- La classe `Application` est responsable de l'initialisation de divers composants tels que le servomoteur, l'écran LCD, et le Wi-Fi.
- La liaison série est établie à une vitesse de 115200 bauds.
- La gestion des exceptions est activée pour faciliter le traitement des erreurs.

## Fonctionnement en continu
La méthode `run` est appelée en continu dans le projet ".ino".
Voici ce qui se passe à l'intérieur de Application.run() :

### Gestion du Joystick
- Une condition sur l'angle mesuré est utilisée pour donner la priorité au joystick, par rapport à la version web.
- L'angle du joystick est récupéré, et s'il n'est pas au repos, il est utilisé pour définir la valeur de l'angle du servomoteur.

### Mise à jour du Servomoteur
- L'angle du servomoteur est mis à jour si la différence entre la valeur actuelle et la valeur souhaitée est supérieure à 5 degrés.
    (pour éviter les tremblements retranscrits par le Joystick).

### Mise à jour de la Bande LED
- Une partie de la bande LED clignote en fonction du côté où est incliné le Joystick, à la manière d'un clignotant et d'un commodo.
- En commentaire dans le code : on peut également afficher sur la bande LED un niveau en fonction de l'angle du servomoteur.

### Gestion du Wi-Fi
- La méthode `run` de la classe `wifi_esp` est appelée pour gérer les communications Wi-Fi/traiter les requêtes avec le serveur.
- Si au moins un client est connecté, l'affichage des identifiants WiFi disparait, et le dernier message reçu est affiché sur l'écran LCD.




