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
using namespace std;

Item* Item::GetItem(string itemType)
{
	transform(itemType.begin(),itemType.end(),itemType.begin(),::toupper);

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

string Item::name() const
{
	return itemName;
}

string Item::nameGenerator()
{
	return string();
}

int Item::random(unsigned int start,unsigned int end)
{
	static bool seeded = false;
	if(!seeded)
		srand(time(NULL));
	return rand()%(end-start+1)+start;
}