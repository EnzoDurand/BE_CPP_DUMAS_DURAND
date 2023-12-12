#include "Actionneur.h"

int Actionneur::nbactionneur = 0;

Actionneur::Actionneur()
{
  nbactionneur++;
}
int Actionneur::getnbactionneur(){
  return this->nbactionneur;
}

