#ifndef WEAPON_H
#define WEAPON_H
#include "Item.h"
using namespace std;

class Weapon : public Item
{
  protected:
   int baseDamage;
   int remainingUses;
};
#endif
