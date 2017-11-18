///
/// Weapon class Implementation
///
/// \author Rylan Bueckert
/// \date Nov 13, 2017
///

#include "Weapon.h"
#include <vector>
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

string Weapon::nameGenerator()
{
	static vector<string> weaponNames;
	static bool gotNames = false;

	// Generates the vector if it is first time
	if(!gotNames) {
		ifstream fin;
		fin.open("WeaponNames.txt");
		string tempName;
		while(!fin.eof()) {
			getline(fin,tempName);
			weaponNames.push_back(tempName);
		}
		fin.close();
		if(weaponNames.size < 1)
			throw runtime_error("WeaponNames.txt is empty");
		gotNames=true;
	}

	// Returns a random element of the vector
	return weaponNames[random(0,weaponNames.size()-1)]
}
