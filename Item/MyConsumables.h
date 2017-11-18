//
// MyConsumables Header File
//
/// \author Rylan Bueckert
/// \date Oct 25, 2017
///

#ifndef MYCONSUMABLES_H
#define MYCONSUMABLES_H
#include "Consumable.h"
using namespace std;

/// Subclass of Consumable to represent an in game health potion
class HealthPotion: public Consumable
{
public:
	/// HealthPotion Constructor
	HealthPotion();

	/// Defines what happens when the health potion is used
	/// \param[in] target The Character that the health potion is used on
	/// \return true if use was successfull
	bool use(Character *target);
};


/// Subclass of Consumable to represent in game food
class Food: public Consumable
{
public:
	/// Food Constructor
	Food();

	/// Defines what happens when the food is used
	/// \param[in] target The Character that the food is used on
	/// \return true if use was successfull
	/// \exeption invalid_argument Thrown if target is not a player
	bool use(Character *target);
};

