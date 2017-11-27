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
using namespace std;

//*****************************************************************************
/// Item Factory
//*****************************************************************************
Item *Item::GetItem(string itemType)
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
      throw invalid_argument("invalid type");
   return newItem;
}

//*****************************************************************************
/// read or write to name
//*****************************************************************************
string &Item::Name()
{
   return itemName;
}

//*****************************************************************************
/// read name
//*****************************************************************************
string Item::Name() const
{
   return itemName;
}

//******************************************************************************
/// Creates names for Items
//******************************************************************************
string Item::NameGenerator(string fileName)
{
   vector<string> adjectives;

   ifstream fin;
   fin.open(fileName);
   if(fin.fail())
      throw invalid_argument("Could not open " + fileName);
   string tempName;
   while(!fin.eof())
   {
      getline(fin,tempName);
      if(tempName[tempName.length() - 1] == '\r')
	 tempName = tempName.substr(0,tempName.size() - 1);
      if(tempName != "")
	 adjectives.push_back(tempName);
   }
   fin.close();
   if(adjectives.size() < 1)
      throw runtime_error(fileName + " is empty");
	
   // Returns a random element of the vector
   return adjectives[Random(0,adjectives.size()-1)];
}

//*****************************************************************************
/// random number generator
//*****************************************************************************
int Item::Random(unsigned int start,unsigned int end)
{
   static bool seeded = false;
   if(!seeded)
   {
      srand(time(NULL));
      seeded = true;
   }
   // Makes sure end is not less than start
   if(start > end)
      swap(start,end);

   return rand()%(end-start+1)+start;
}
