/** @author Rylan Bueckert
 * @date Nov 11, 2017
 */

#include "Item.h"
#include "MyWeapons.h"
#include "MyConsumables.h"
#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>

Item *Item::GetItem(std::string itemType)
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
      throw std::invalid_argument("invalid type");
   return newItem;
}

std::string &Item::Name()
{
   return itemName;
}

std::string Item::Name() const
{
   return itemName;
}

std::string Item::NameGenerator(std::string fileName)
{
   std::vector<std::string> adjectives;

   std::ifstream fin;
   fin.open(fileName);
   if(fin.fail())
      throw std::runtime_error("Could not open " + fileName);
   std::string tempName;
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
      throw std::runtime_error(fileName + " is empty");
	
   // Returns a random element of the std::vector
   return adjectives[Random(0,adjectives.size()-1)];
}

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
      std::swap(start,end);

   return rand()%(end-start+1)+start;
}
