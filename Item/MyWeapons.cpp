///
/// MyWeapons Implementation
///
/// \author Rylan Bueckert
/// \date Nov 13,2017
///

#include "MyWeapons.h"
#include "../Character/Character.h"
using namespace std;

//*****************************************************************************
/// Sword Constructor
//*****************************************************************************
Sword::Sword()
{
   baseDmg = 5;
   remainingUses = 10;
   itemName = NameGenerator("../Item/WeaponNames.txt");
//   itemName += " Sword";
}

//*****************************************************************************
/// Use Sword Implementation
//*****************************************************************************
bool Sword::Use(Character *target)
{
   if(remainingUses > 0) {
		
      //Modifies the damage output by up to +- 20%
      double modifier = static_cast<double>((Random(0,40)-20) / 100);
      int damage = baseDmg + static_cast<int>(static_cast<double>(baseDmg) * modifier + 0.5);
		
      target->ChangeHealth(-damage);
      --remainingUses;
      return true;
   }
   return false;
}

//*****************************************************************************
/// Bow Constructor
//*****************************************************************************
Bow::Bow()
{
   baseDmg = 10;
   remainingUses = 5;
   hitPercent = 70;
   itemName = NameGenerator("../Item/WeaponNames.txt") + " Bow";
}

//*****************************************************************************
/// Use Bow Implementation
//*****************************************************************************
bool Bow::Use(Character *target)
{
   if(remainingUses > 0) {
      
      // Checks for a miss
      if(Random(1,100) <= hitPercent) {
	 
	 //Modifies the damage output by up to +- 50%
	 double modifier = static_cast<double>((Random(0,100)-50) / 100);
	 int damage = baseDmg + static_cast<int>(static_cast<double>(baseDmg) * modifier + 0.5);
      
	 target->ChangeHealth(-damage);
	 --remainingUses;
	 return true;
      }
   }
   return false;
}

//*****************************************************************************
/// Allows reading of the accuracy
//*****************************************************************************
int Bow::Accuracy() const
{
   return hitPercent;
}

//*****************************************************************************
/// Allows reading and writing of accuracy
//*****************************************************************************
int & Bow::Accuracy()
{
   return hitPercent;
}

//*****************************************************************************
/// Spell Constructor
//*****************************************************************************
Spell::Spell()
{
   baseDmg = 20;
   remainingUses = 1;
   itemName = NameGenerator("../Item/SpellNames.txt") + " Spell";
}

//*****************************************************************************
/// Use Spell Implementation
//*****************************************************************************
bool Spell::Use(Character * target)
{
   if(remainingUses > 0) {
      //Modifies the damage output by up to +- 75%
      double modifier = static_cast<double>((Random(0,150)-75) / 100);
      int damage = baseDmg + static_cast<int>(static_cast<double>(baseDmg) * modifier + 0.5);

      target->ChangeHealth(-damage);
      --remainingUses;
      return true;
   }
   return false;
}
