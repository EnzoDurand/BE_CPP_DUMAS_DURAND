#include "capteur.h"

int capteur::nbcapteur = 0;

capteur::capteur()
{
  nbcapteur++;
}
int capteur::getnbcapteur(){
  return this->nbcapteur;
}

