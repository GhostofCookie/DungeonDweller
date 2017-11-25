//
// Npc.h
//
/// \author Gates Kempenaar
/// \date Oct 25, 2017
//


#ifndef Npc_h
#define Npc_h

#include <stdio.h>
#include "Character.h"
#include "../Item/MyConsumables.h"
#include <vector>

class Item;
class MyConsumable;
class Player;

///Derived class from Character which provides Npc attributes
class Npc : public Character
{
    
public:
   ///Npc constructor
   /// \param[in] h, the health of the created Npc
   Npc(int s = 0, int g = 0, int h = 0, ImportImg img = ImportImg("../DD_Art/Player/DD_NPCEnemy.txt"));
    
   ///Deconstructor
   ~Npc();

};

#endif /* Npc_hpp */
