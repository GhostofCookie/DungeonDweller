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
#include "/home/kemg2720/Kodika/Item/Item.h"
#include "/home/kemg2720/Kodika/Screen"
#include "/home/kemg2720/Kodika/Image"


using namespace std;

///Abstract base class of Npc's and Player's attributes
class Character
{
  private:
   ImportImg img;
   
protected:
   ///Vector of items the character has
   vector<*Item> inventory;

   ///Amount of gold player has
   int gold;

   ///Characters health
   int health;
   
  public:
   /// Character constructor
   /// \param[in] g, starting amoutn of gold for the character
   /// \param[in] h, starting health for the character
   Character(int g = 0, int h = 0, ImportImg img = ImportImg());

   /// Character deconstructor
   ~Character();

   ///Function to fill the characters inventory
   /// \param[in] inventory, the vector that stores the items in inventory
   virtual void FillInventory(vector<*Item> &inventory, item item);
   
   ///Shows a list of inventory items
   /// \param[in] Inventory, a pointer to a vector of inventory items
   virtual Item GetInventoryItems(Item *inventory);

   ///Chooses the item to be used
   /// \param[in] Inventory, a pointer to a vector of inventory items
   virtual Item UseItem(Item *inventory);

   ///Change the amount of gold a character has
   /// \param[in&] Gold, current amount of gold the character has
   /// \param[in] GoldMod, how much the current gold will be changed by
   virtual int ChangeGold(int &gold, int goldMod);

   ///Changes the characters health
   /// \param[in&] H, characters current health
   /// \param[in] HMod, how the current health will be modified
   virtual void ChangeHealth(int& h, int hMod);

  

  
};

#endif /* Character_hpp */
