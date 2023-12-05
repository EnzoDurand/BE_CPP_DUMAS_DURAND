#include "haut_parleur.h"

haut_parleur::haut_parleur(uint8_t  pin) : haut_parleurPin(pin) {
  pinMode(haut_parleurPin, OUTPUT);
}

haut_parleur::~haut_parleur() {
}

void haut_parleur::playTone(int frequency, int duration) {
  tone(haut_parleurPin, frequency, duration);
  delay(duration); //Attention bloquant
  noTone(haut_parleurPin);
}

void haut_parleur::stopSound() {
  noTone(haut_parleurPin);
}