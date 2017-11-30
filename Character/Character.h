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
#include "../Item/MyWeapons.h"
#include "../Item/Weapon.h"
#include "../Item/MyConsumables.h"
#include "../Item/Item.h"
#include "../Image/ImportImg.h"
#include <vector>


using namespace std;

class Item;
class MyConsumable;
class Weapon;
//class MyWeapons;


/// \class Character Character.h
/// \brief Abstract base class of Npc's and Player's attributes
class Character
{
  protected:
   ImportImg img;
   
   /// Vector of items the character has
   vector < Item* > inventory;

   /// Amount of gold player has
   int gold;

   /// Characters health
   int health;

   /// Characters stamina
   int stamina;
 
  public:
   
   /// Character constructor
   Character();
   
   /// Character deconstructor
   virtual ~Character();

   /// Const copy constructor
   Character(const Character&);

   /// Copy constructor
   Character(Character&);
   
   /// Assignment operator overloader for copy constructor
   Character& operator = (const Character &p);

   /// Function to fill the characters inventory
   /// \param[in] inventory, the vector that stores the items in inventory
   virtual void FillInventory(Item *item);
   
   /// Shows a list of inventory items
   /// \param[in] Inventory, a pointer to a vector of inventory items
   virtual vector < Item* > GetInventoryItems();

   /// Chooses the item to be used
   /// \param[in] Inventory, a pointer to a vector of inventory items
   virtual Item* UseItem(string item);

   /// Change the amount of gold a character has
   /// \param[in] GoldMod, how much the current gold will be changed by
   virtual void ChangeGold(int goldMod);

   /// Changes the characters health
   /// \param[in] HMod, how the current health will be modified
   virtual void ChangeHealth(int hMod);

   /// Changes players stamina
   /// \param[in] sMod, how the curent stamina will be modified
   virtual void ChangeStamina(int sMod);

   /// Returns the stamina value
   virtual int GetStamina() const { return stamina; };
   
   /// Returns the gold value
   virtual int GetGold() const { return gold; };
   
   /// Returns the health value
   virtual int GetHealth() const { return health; };

   /// Return the image
   virtual ImportImg& Img() { return img; };

   /// Draw the player
   virtual void Draw(Screen &screen);

   void EmptyInventory();
}; 

#endif /* Character_hpp */
