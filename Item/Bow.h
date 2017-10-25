#ifnedef BOW_H
#define BOW_H
#include "Weapon.h"

class Bow : public Weapon
{
   void use(Character *target);
};
#endif
