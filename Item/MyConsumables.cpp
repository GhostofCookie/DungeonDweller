//
// MyConsumables Implementation File
//
/// \author Rylan Bueckert
/// \date Nov 18, 2017
///

#include "MyConsumables.h"
#include "../Character/Character.h"
#include "../Character/Player.h"
#include <stdexcept>
#include <typeinfo>


/// HealthPotion Constructor
HealthPotion::HealthPotion()
{
   value = 10;
   try
   {
      itemName = NameGenerator("../Item/ConsumableNames.txt") + " Health Potion";
   }
   catch(std::runtime_error &re)
   {
      itemName = "Health Potion";
   }

      used = false;
}

/// Defines what happens when the health potion is used
/// \param[in] target The Character that the health potion is used on
/// \return true if use was successfull
bool HealthPotion::Use(Character *target)
{
   if(!used)
   {
      target->ChangeHealth(value);
      used = true;
      return true;
   }
   return false;
}

/// Food Constuctor
Food::Food()
{
   value = 3;
   try
   {
      itemName = NameGenerator("../Item/ConsumableNames.txt") + " Food";
   }
   catch(std::runtime_error &re)
   {
      itemName = "Food";
   }
   
   used = false;
}

/// Defines what happens when the food is used
/// \param[in] target The Character that the food is used on
/// \return true if use was successfull
/// \exeption std::invalid_argument Thrown if target is not a player
bool Food::Use(Character *target)
{
   if(!used)
   {
      target->ChangeStamina(value);
      used = true;
      return true;
   }
   return false;
}
