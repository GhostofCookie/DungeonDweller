///
/// MyWeapons Implementation
///
/// \author Rylan Bueckert
/// \date Nov 13,2017
///

#include "MyWeapons.h"
using namespace std;

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