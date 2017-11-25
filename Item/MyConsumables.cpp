//
// MyConsumables Implementation File
//
/// \author Rylan Bueckert
/// \date Nov 18, 2017
///

#include "MyConsumables.h"
#include "../Character/Character.h"
#include "../Character/Player.h"
#include <stdexept>
#include <typeinfo>
using namespace std;

//*****************************************************************************
/// HealthPotion Constructor
//*****************************************************************************
HealthPotion::HealthPotion()
{
   value = 10;
   itemName = nameGenerator("ConsumableNames.txt") + " Health Potion";
   used = false;
}

//*****************************************************************************
/// Use HealthPotion Implementation
//*****************************************************************************
bool HealthPotion::use(Character *target)
{
   if(!used) {
      target->ChangeHealth(value);
      used = true;
      return true;
   }
   return false;
}

//*****************************************************************************
/// Food Constuctor
//*****************************************************************************
Food::Food()
{
   value = 3;
   itemName = nameGenerator("ConsumableNames.txt") + " Food";
   used = false;
}

//*****************************************************************************
/// Use Food Implementation
//*****************************************************************************
bool Food::use(Character *target)
{
   if(!used) {     
      target->ChangeStamina(value);
      used = true;
      return true;
   }
   return false;
}
