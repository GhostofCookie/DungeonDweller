///
/// Weapon class Implementation
///
/// \author Rylan Bueckert
/// \date Nov 13, 2017
///

#include "Weapon.h"
using namespace std;

//*****************************************************************************
/// read base damage
//*****************************************************************************
int Weapon::baseDamage() const
{
	return baseDmg;
}

//*****************************************************************************
/// write base damage
//*****************************************************************************
int &Weapon::baseDamage()
{
	return baseDmg;
}

//*****************************************************************************
/// read durability
//*****************************************************************************
int Weapon::durability() const
{
	return remainingUses;
}

//*****************************************************************************
/// write durability
//*****************************************************************************
int &Weapon::durability()
{
	return remainingUses;
}
