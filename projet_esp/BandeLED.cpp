#include "BandeLED.h"

BandeLED::BandeLED(const uint8_t pin) : matrix(10, pin, NEO_GRB + NEO_KHZ800) {
    matrix.begin();
    this->matrix.clear();
    this->matrix.show();
    this->nbactioneur++;
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