//
// Weapon Class Header File
//
/// \author Rylan Bueckert
/// \date Oct 25, 2017
///

#ifndef WEAPON_H
#define WEAPON_H
#include "Item.h"
using namespace std;

/// This class is a abstract base class derived from Item to represent weapons in game
class Weapon : public Item
{
  public:

   /// The number of time the weapon can be used
   /// \returns number of remainingUses
   int durability();
   
  protected:

   /// The Base damage of the weapon
   int baseDamage;

   /// How many more times the wepon can be used
   int remainingUses;
};
#endif
