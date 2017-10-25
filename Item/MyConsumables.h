//
// MyConsumables Header File
//
/// \author Rylan Bueckert
/// \date Oct 25, 2017
///

#ifndef MYCONSUMABLES_H
#define MYCONSUMABLES_H
#include "Consumable.h"
using namespace std;


/// Subclass of Consumable to represent an in game health potion
class HealthPotion : public Consumable
{
  public:

   /// Defines what happens when the health potion is used
   /// param[in] target The Character that the health potion is used on
   void use(Character *taget);
};


/// Subclass of Consumable to represent in game food
class Food : public Consumable
{
  public:

   /// Defines what happens when the food is used
   /// param[in] target The Character that the food is used on
   void use(Character *taget);
};


/// Subclass of Consumable to represent an in game invisibility potion
class InvisiblePotion : public Consumable
{
  public:

   /// Defines what happens when the invisibility potion is used
   /// param[in] target The Character that the invisibility potion is used on
   void use(Character *taget);
};
#endif
