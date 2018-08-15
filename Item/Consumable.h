//
// Consumable Header File
//
/// \author Rylan Bueckert
/// \date Oct 25, 2017
///

#pragma once

#include "Item.h"

/// This class is an abstaract base class derived from Item to represent in game consumables
class Consumable : public Item
{
public:
	/// Returns the the actuall value of the consumable (for reading only)
	/// \returns value of the consumable
	int Power() const;

	/// Returns the the actuall value of the consumable (for writing)
	/// \returns a reference to value
	int &Power();
protected:
	/// The actuall value of the item(ex how much health it restores)
	int value;

	bool used;
};
