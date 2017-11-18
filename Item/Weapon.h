//
// Weapon Class Header File
//
/// \author Rylan Bueckert
/// \date Oct 25, 2017
///

#ifndef WEAPON_H
#define WEAPON_H
#include "Item.h"
using namespace std;

/// This class is a abstract base class derived from Item to represent weapons in game
class Weapon: public Item
{
public:
	/// Returns the base damage of the weapon (for reading only)
	/// \returns base damage of the weapon
	int baseDamage() const;

	/// Returns the base damage of the weapon (for writing)
	/// \retrurns Reference to baseDmg
	int &baseDamage();

	/// Returns the number of times the weapon can be used (for reading only)
	/// \returns number of remainingUses
	int durability() const;

	/// Returns the number of times the weapon can be used (for writing)
	/// \returns a reference to remainingUses
	int &durability();

protected:

	/// The Base damage of the weapon
	int baseDmg;

	/// How many more times the wepon can be used
	int remainingUses;

};
#endif
