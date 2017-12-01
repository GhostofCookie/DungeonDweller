///
/// MyWeapons Implementation
///
/// \author Rylan Bueckert
/// \date Nov 13,2017
///

#include "MyWeapons.h"
#include "../Character/Character.h"
#include <string>
#include <stdexcept>
using namespace std;

/// Sword Constructor
Sword::Sword()
{
   baseDmg = 5;
   remainingUses = 10;
   try
   {
      itemName = NameGenerator("../Item/WeaponNames.txt") + " Sword";
   }
   catch(runtime_error)
   {
      itemName = "Sword";
   }
}

/// Defines what happens when the sword is used
/// \param[in] target The character that the sword is used on
/// \return true if use was successfull
bool Sword::Use(Character *target)
{
   if(remainingUses > 0)
   {
      //Modifies the damage output by up to +- 20%
      double modifier = static_cast<double>((Random(0,40)-20) / 100);
      int damage = baseDmg + static_cast<int>(static_cast<double>(baseDmg) * modifier + 0.5);
		
      target->ChangeHealth(-damage);
      --remainingUses;
      return true;
   }
   return false;
}

/// Bow Constructor
Bow::Bow()
{
   baseDmg = 10;
   remainingUses = 5;
   hitPercent = 70;
   try
   {
      itemName = NameGenerator("../Item/WeaponNames.txt") + " Bow";
   }
   catch(runtime_error)
   {
      itemName = "Bow";
   }
}

/// Defines what happens when the bow is used
/// \param[in] target The character that the spell is used on
/// \return true if use was successfull
bool Bow::Use(Character *target)
{
   if(remainingUses > 0) {
      
      // Checks for a miss
      if(Random(1,100) <= hitPercent)
      {	 
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

/// Returns the accuracy of the bow (for reading only)
/// \returns Bow accuracy
int Bow::Accuracy() const
{
   return hitPercent;
}

/// Returns the accuracy of the weapon (for writing)
/// \returns reference to hitPercent
int & Bow::Accuracy()
{
   return hitPercent;
}

/// Spell Constructor
Spell::Spell()
{
   baseDmg = 20;
   remainingUses = 1;
   try
   {
   itemName = NameGenerator("../Item/SpellNames.txt") + " Spell";
   }
   catch(runtime_error) {
      itemName = "Spell";
   }
}

/// Defines what happens when the spell is used
/// \param[in] target The character that the spell is used on
/// \return true if use was successfull
bool Spell::Use(Character * target)
{
   if(remainingUses > 0)
   {
      //Modifies the damage output by up to +- 75%
      double modifier = static_cast<double>((Random(0,150)-75) / 100);
      int damage = baseDmg + static_cast<int>(static_cast<double>(baseDmg) * modifier + 0.5);

      target->ChangeHealth(-damage);
      --remainingUses;
      return true;
   }
   return false;
}
