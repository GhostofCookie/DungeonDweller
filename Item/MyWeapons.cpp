///
/// MyWeapons Implementation
///
/// \author Rylan Bueckert
/// \date Nov 13,2017
///

#include "MyWeapons.h"
using namespace std;

//*****************************************************************************
/// Sword Constructor
//*****************************************************************************
Sword::Sword()
{
	baseDmg = 5;
	remainingUses = 10;
	itemName = nameGenerator("WeaponNames.txt") + " Sword";
}

//*****************************************************************************
/// Use Sword Implementation
//*****************************************************************************
bool Sword::use(Character *target)
{
	if(remainingUses > 0) {
		
		//Modifies the damage output by up to +- 20%
		double modifier = static_cast<double>(random(0,40)-20) / 100);
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
	itemName = nameGenerator("WeaponNames.txt") + " Bow";
}

//*****************************************************************************
/// Use Bow Implementation
//*****************************************************************************
bool Bow::use(Character *target)
{
	if(remainingUses > 0) {

		// Checks for a miss
		if(random(1,100) <= hitPercent) {

			//Modifies the damage output by up to +- 50%
			double modifier = static_cast<double>(random(0,100)-50) / 100);
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
int Bow::accuracy() const
{
	return hitPercent;
}

//*****************************************************************************
/// Allows reading and writing of accuracy
//*****************************************************************************
int & Bow::accuracy()
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
	itemName = nameGenerator("SpellNames.txt") + " Spell";
}

//*****************************************************************************
/// Use Spell Implementation
//*****************************************************************************
bool Spell::use(Character * target)
{
	if(remainingUses > 0) {
		//Modifies the damage output by up to +- 75%
		double modifier = static_cast<double>(random(0,150)-75) / 100);
		int damage = baseDmg + static_cast<int>(static_cast<double>(baseDmg) * modifier + 0.5);

		target->ChangeHealth(-damage);
		--remainingUses;
		return true;
	}
}
