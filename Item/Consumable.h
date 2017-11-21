//
// Consumable Header File
//
/// \author Rylan Bueckert
/// \date Oct 25, 2017
///

#ifndef CONSUMABLE_H
#define CONSUMABLE_H
#include "Item.h"
using namespace std;

/// This class is an abstaract base class derived from Item to represent in game consumables
class Consumable : public Item
{
public:
	/// Returns the the actuall value of the consumable (for reading only)
	/// \returns value of the consumable
	int power() const;

	/// Returns the the actuall value of the consumable (for writing)
	/// \returns a reference to value
	int &power();
protected:
	/// The actuall value of the item(ex how much health it restores)
	int value;

	bool used;
};
#endif
