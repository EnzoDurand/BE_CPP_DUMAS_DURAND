#include "BandeLED.h"

BandeLED::BandeLED(const uint8_t pin) : matrix(10, pin, NEO_GRB + NEO_KHZ800) {
    matrix.begin();
    this->matrix.clear();
    this->matrix.show();
}

void BandeLED::setLevel(int niveau) {
  this->matrix.clear();
  this->niveau = niveau;
  for (int i = 0; i < niveau; i++) {
      this->matrix.setPixelColor(i, matrix.Color(0, 30, 0));
  }
  this->matrix.show();
}

int BandeLED::getLevel(void) {
    return this->niveau;
}

void BandeLED::allume_cote(bool b) //0 gauche | 1 : droite
{
  static bool etat_precedent = 0; //Pour clignottement 
  
  this->matrix.clear();

  if (etat_precedent == 0)
  {
     if (!b)
  {
      for (int i = 0; i < 5; i++) {
      this->matrix.setPixelColor(i, matrix.Color(30, 10, 0)); //Orange
      }
  }
  else
  {
      for (int i = 5; i < 10; i++) {
      this->matrix.setPixelColor(i, matrix.Color(30, 10, 0)); //Orange
      }
  }
  }
  etat_precedent=!etat_precedent;
  delay(300);
  this->matrix.show();

}


