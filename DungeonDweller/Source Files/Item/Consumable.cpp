/**
 * Consumable class Implementation
 *
 * @author Rylan Bueckert
 * @date Nov 13, 2017
 *
 */

#include "Consumable.h"

/** Returns the the actuall value of the consumable (for reading only)
 * @returns value of the consumable
 */
int Consumable::Power() const
{
	return value;
}

/** Returns the the actuall value of the consumable (for writing)
 * @returns a reference to value
 */
int & Consumable::Power()
{
	return value;
}
