//
// Item Class Implementation
//
/// \author Rylan Bueckert
/// \date Nov 11, 2017
///

#include "Item.h"
#include "MyWeapons.h"
#include "MyConsumables.h"
#include <algorithm>
#include <string>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>
using namespace std;

Item* Item::GetItem(string itemType)
{
	transform(itemType.begin(),itemType.end(),itemType.begin(),toupper);

	Item* newItem;

	if(itemType == "SWORD")
		newItem = new Sword;
	else if(itemType == "BOW")
		newItem = new Bow;
	else if(itemType == "SPELL")
		newItem = new Spell;
	else if(itemType == "HEALTH POTION")
		newItem = new HealthPotion;
	else if(itemType == "FOOD")
		newItem = new Food;
	else
		throw invalid_argument("invalid type")
}

string &Item::name()
{
	return itemName;
}

string Item::name() const
{
	return itemName;
}


string Item::nameGenerator()
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
			weaponNames.push_back(tempName)
		}
		fin.close();
		if(weaponNames.size < 1)
			throw runtime_error("WeaponNames.txt is empty");
		gotNames=true;
	}

	// Returns a random element of the vector
	return weaponNames[random(0,weaponNames.size()-1)]
}


int Item::random(unsigned int start,unsigned int end)
{
	static bool seeded = false;
	if(!seeded)
		srand(time(NULL));
	
	// Makes sure end is not less than start
	if(start > end)
		swap(start,end);

	return rand()%(end-start+1)+start;
}