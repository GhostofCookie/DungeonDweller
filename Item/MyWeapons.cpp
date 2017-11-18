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
	baseDamage = 5;
	remainingUses = 10;
	itemName = nameGenerator() + " Sword";
}

//*****************************************************************************
/// Use Sword Implementation
//*****************************************************************************
bool Sword::use(Character *target)
{
	if(remainingUses > 0) {
		
		//Modifies the damage output by up to +- 20%
		double modifier = static_cast<double>(random(0,40)-20) / 100);
		int damage = baseDamage + static_cast<int>(static_cast<double>(baseDamage) * modifier + 0.5);
		
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
	baseDamage = 10;
	remainingUses = 5;
	hitPercent = 70;
	itemName = nameGenerator() + " Bow";
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
			int damage = baseDamage + static_cast<int>(static_cast<double>(baseDamage) * modifier + 0.5);
			
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
	baseDamage = 20;
	remainingUses = 1;
	itemName = nameGenerator() = " Spell";
}

//*****************************************************************************
/// Use Spell Implementation
//*****************************************************************************
void Spell::use(Character * target)
{
	if(remainingUses > 0) {
		//Modifies the damage output by up to +- 75%
		double modifier = static_cast<double>(random(0,150)-75) / 100);
		int damage = baseDamage + static_cast<int>(static_cast<double>(baseDamage) * modifier + 0.5);

		target->ChangeHealth(-damage);
		--remainingUses;
		return true;
	}
}
