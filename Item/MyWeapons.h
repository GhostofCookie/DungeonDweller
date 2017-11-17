//
// MyWeapons Header File
//
/// \author Rylan Bueckert
/// \date Oct 25, 2017
///

#ifndef MYWEAPONS_H
#define MYWEAPONS_H
#include "Weapon.h"


/// Subclass of Weapon to represent a sword in game
class Sword: public Weapon
{
public:
	/// Defines what happens when the sword is used
	/// \param[in] target The character that the sword is used on
	void use(Character *target);
};


/// Subclass of Weapon to represent a bow in game
class Bow: public Weapon
{
public:
	/// Defines what happens when the spell is used
	/// \param[in] target The character that the spell is used on
	void use(Character *target);


protected:
	/// The bows accuracy as a percent
	/// (accuracy less than 1 always miss) (accuracy greater than 99 always hit)
	int hitPercent;
};


/// Subclass of Weapon to represent a spell in game
class Spell: public Weapon
{
public:
	/// Defines what happens when the spell is used
	/// \param[in] target The character that the spell is used on
	void use(Character *target)
};
#endif
