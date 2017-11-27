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


/// \class Character Character.h
/// \brief Abstract base class of Npc's and Player's attributes
class Character
{
   Character();
   
   ~Character();

  protected:
   
   ImportImg img;
   
   /// Vector of items the character has
   vector<Item*> inventory;

   /// Amount of gold player has
   int gold;

   /// Characters health
   int health;

   /// Characters stamina
   int stamina;
   
  public:
   
   /// Character deconstructor
   virtual ~Character(){}

   /// Function to fill the characters inventory
   /// \param[in] inventory, the vector that stores the items in inventory
   virtual void FillInventory(Item *item);
   
   /// Shows a list of inventory items
   /// \param[in] Inventory, a pointer to a vector of inventory items
   virtual vector<Item*> GetInventoryItems();

   /// Chooses the item to be used
   /// \param[in] Inventory, a pointer to a vector of inventory items
   virtual Item* UseItem(string item);

   /// Change the amount of gold a character has
   /// \param[in&] Gold, current amount of gold the character has
   /// \param[in] GoldMod, how much the current gold will be changed by
   virtual void ChangeGold(int goldMod);

   /// Changes the characters health
   /// \param[in&] H, characters current health
   /// \param[in] HMod, how the current health will be modified
   virtual void ChangeHealth(int hMod);

   /// Changes players stamina
   /// \param[in&] s, players current stamina
   /// \param[in] sMod, how the curent stamina will be modified
   virtual void ChangeStamina(int sMod);

   /// Returns the stamina value
   virtual int GetStamina() { return stamina; };
   
   /// Returns the gold value
   virtual int GetGold() { return gold; };
   
   /// Returns the health value
   virtual int GetHealth() { return health; };

   /// Return the image
   virtual ImportImg Img();

   /// Draw the player
   virtual void Draw(Screen &screen);
}; 

#endif /* Character_hpp */
