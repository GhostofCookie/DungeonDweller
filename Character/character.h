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
#include "Item.h"

using namespace std;

///Abstract base class to provide input and output of Npc's and Player
class Character
{
protected:
   ///Vector of items the character has
   vector<*Item> inventory;

   ///Amount of gold player has
   int gold;

    ///Characters health
    int health;
   
public:
    ///Reads information in for the character
    /// \param[in] is the input stream
    virtual iostream Read(istream &is);
    
    ///Writes the character object to the screen
    /// \param[out] os the output stream for printing on the screen
    virtual ostream Write(ostream &os);

   ///Shows a list of inventory items
   /// \param[in] Inventory, a pointer to a vector of inventory items
   virtual Item GetInventoryItems(Item  *inventory);

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
   void ChangeHealth(int& h, int hMod);

    ///Attack function for the character
    int Attack();
};

#endif /* Character_hpp */
