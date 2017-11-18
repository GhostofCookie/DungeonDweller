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
void Sword::use(Character *target)
{
	if(remainingUses > 0) {
		
		//Modifies the damage output by up to +- 20%
		double modifier = static_cast<double>(random(0,40)-20) / 100);
		int damage = static_cast<int>(static_cast<double>(baseDamage) * modifier + 0.5);
		
		target->ChangeHealth(-damage);
		--remainingUses;
	}
}

//*****************************************************************************
///
//*****************************************************************************
Bow::Bow()
{
}

//*****************************************************************************
/// Use Bow Implementation
//*****************************************************************************
void Bow::use(Character *target)
{
	if(remainingUses > 0) {
		
		// Checks for a miss
		double modifier = static_cast<double>(random(0,40)-20) / 100);
		int damage = static_cast<int>(static_cast<double>(baseDamage) * modifier + 0.5);
		target->ChangeHealth(-damage);
		--remainingUses;
	}
}

//*****************************************************************************
///
//*****************************************************************************
int Bow::accuracy() const
{
	return hitPercent;
}

//*****************************************************************************
///
//*****************************************************************************
int & Bow::accuracy()
{
	return hitPercent;
}

//*****************************************************************************
///
//*****************************************************************************
Spell::Spell()
{
}
