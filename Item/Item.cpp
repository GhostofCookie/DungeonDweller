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

/// Uses factory design pattern to create items
/// \param[in] itemType The type of item to be created
/// \return Pointer to created item
/// \exception invalid_argument Thrown if type does not exist or is not allowed
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

/// Allows access to the items name
/// \return Reference to the name of the item
string &Item::Name()
{
   return itemName;
}

/// Gives the name of the item without allowing chages
/// \return Name of the item
string Item::Name() const
{
   return itemName;
}

/// Generates adjectives to add to Item names
/// \param[in] fileName the file that the names comme from
/// \returns Adjective generated and to be used
/// \exception runtime_error Thrown if source file has no names
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
	  if(tempName.length() > 0)
		  if(tempName[tempName.length() - 1] == '\r')
			  tempName = tempName.substr(0,tempName.size() - 1);
      if(tempName != "") // Remove any empty lines
	 adjectives.push_back(tempName);
   }
   fin.close();
   if(adjectives.size() < 1)
      throw runtime_error(fileName + " is empty");
	
   // Returns a random element of the vector
   return adjectives[Random(0,adjectives.size()-1)];
}

/// Helper function to generate random positive numbers
/// \return Random number between start and end
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
