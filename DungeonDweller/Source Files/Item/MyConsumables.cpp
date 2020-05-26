/** @author Rylan Bueckert
 * @date Nov 18, 2017
 */

#include "MyConsumables.h"
#include "Character.h"
#include "Player.h"
#include <stdexcept>
#include <typeinfo>


HealthPotion::HealthPotion()
{
   value = 10;
   try
   {
      itemName = NameGenerator("ConsumableNames.txt") + " Health Potion";
   }
   catch(std::runtime_error &re)
   {
      itemName = "Health Potion";
   }

      used = false;
}

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

Food::Food()
{
   value = 3;
   try
   {
      itemName = NameGenerator("ConsumableNames.txt") + " Food";
   }
   catch(std::runtime_error &re)
   {
      itemName = "Food";
   }
   
   used = false;
}

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
