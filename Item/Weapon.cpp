///
/// Weapon class Implementation
///
/// \author Rylan Bueckert
/// \date Nov 13, 2017
///

#include "Weapon.h"
#include <vector>
using namespace std;

/// Returns the base damage of the weapon (for reading only)
/// \returns base damage of the weapon
int Weapon::BaseDamage() const
{
	return baseDmg;
}

/// Returns the base damage of the weapon (for writing)
/// \retrurns Reference to baseDmg
int &Weapon::BaseDamage()
{
	return baseDmg;
}

/// Returns the number of times the weapon can be used (for reading only)
/// \returns number of remainingUses
int Weapon::Durability() const
{
	return remainingUses;
}

/// Returns the number of times the weapon can be used (for writing)
/// \returns a reference to remainingUses
int &Weapon::Durability()
{
	return remainingUses;
}
