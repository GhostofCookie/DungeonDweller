//
// character.h
//
/// \author Gates Kempenaar
/// \date Oct 25, 2017
//

#ifndef Character_hpp
#define Character_hpp

#include <stdio.h>
#include <iostream>
#include "Item.h"

using namespace std;

///Abstract base class to provide input and output of Npc's and Player
class Character
{
protected:
   ///Vector of items the character has
   vector<*Item> Inventory;
   
public:
    ///Reads information in for the character
    /// \param[in] is the input stream
    virtual iostream Read(istream &is);
    
    ///Writes the character object to the screen
    /// \param[out] os the output stream for printing on the screen
    virtual ostream Write(ostream &os);

   ///Shows a list of inventory items
   /// \param[in] Inventory, a pointer to a vector of inventory items
   virtual Item GetInventoryItems(Item  *Inventory);

   ///Chooses the item to be used
   /// \param[in] Inventory, a pointer to a vector of inventory items
   virtual Item UseItem(Item *Inventory);
    
};

#endif /* Character_hpp */
