//
// Character.h
//
/// \author Gates Kempenaar
/// \date Oct 25, 2017
//

#ifndef Character_h
#define Character_h

#include <stdio.h>
#include <iostream>
//#include "../Item/MyConsumables.h"
#include "../Item/Item.h"
#include "../Image/ImportImg.h"
#include <vector>


using namespace std;
class Item;

///Abstract base class of Npc's and Player's attributes
class Character
{
   
  protected:
   
   ImportImg img;
   
   ///Vector of items the character has
   vector<Item> inventory;

   ///Amount of gold player has
   int gold;

   ///Characters health
   int health;
   
   public:
   /// Character constructor
   /// \param[in] g, starting amoutn of gold for the character
   /// \param[in] h, starting health for the character
   //Character() = 0;

   /// Character deconstructor
   virtual ~Character(){}

   ///Function to fill the characters inventory
   /// \param[in] inventory, the vector that stores the items in inventory
   virtual void FillInventory(Item *item);
   
   ///Shows a list of inventory items
   /// \param[in] Inventory, a pointer to a vector of inventory items
   virtual void GetInventoryItems(Item *inventory);

   ///Chooses the item to be used
   /// \param[in] Inventory, a pointer to a vector of inventory items
   virtual void UseItem(Item *inventory);

   ///Change the amount of gold a character has
   /// \param[in&] Gold, current amount of gold the character has
   /// \param[in] GoldMod, how much the current gold will be changed by
   virtual int ChangeGold(int goldMod);

   ///Changes the characters health
   /// \param[in&] H, characters current health
   /// \param[in] HMod, how the current health will be modified
   virtual void ChangeHealth(int hMod);

}; 

#endif /* Character_hpp */
