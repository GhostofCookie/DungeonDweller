/**
 * Weapon class Implementation
 *
 * @author Rylan Bueckert
 * @date Nov 13, 2017
 */

#include "Weapon.h"
#include <vector>


int Weapon::BaseDamage() const
{
	return baseDmg;
}

int &Weapon::BaseDamage()
{
	return baseDmg;
}

int Weapon::Durability() const
{
	return remainingUses;
}

int &Weapon::Durability()
{
	return remainingUses;
}
