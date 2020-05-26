/**
 * MyWeapons Implementation
 *
 * @author Rylan Bueckert
 * @date Nov 13,2017
 */

#include "MyWeapons.h"
#include "Character.h"
#include <string>
#include <stdexcept>

Sword::Sword()
{
   baseDmg = 5;
   remainingUses = 10;
   try
   {
      itemName = NameGenerator("WeaponNames.txt") + " Sword";
   }
   catch(std::runtime_error)
   {
      itemName = "Sword";
   }
}

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

Bow::Bow()
{
   baseDmg = 10;
   remainingUses = 5;
   hitPercent = 70;
   try
   {
      itemName = NameGenerator("WeaponNames.txt") + " Bow";
   }
   catch(std::runtime_error)
   {
      itemName = "Bow";
   }
}

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

int Bow::Accuracy() const
{
   return hitPercent;
}

int & Bow::Accuracy()
{
   return hitPercent;
}

Spell::Spell()
{
   baseDmg = 20;
   remainingUses = 1;
   try
   {
   itemName = NameGenerator("SpellNames.txt") + " Spell";
   }
   catch(std::runtime_error) {
      itemName = "Spell";
   }
}

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
