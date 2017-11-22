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
#include <vector>

///Derived class from Character which provides Npc attributes
class Npc : public Character
{
    
public:
   ///Npc constructor
   /// \param[in] h, the health of the created Npc
   Npc();
    
   ///Deconstructor
   ~Npc();

   ///Attack function for the Npc to attack the Player
   /// \param[in] damage, the base damage of the weapon
   /// \param[in] enamy, the player being attacked
   void AttackPlayer(Weapon damage, Player enemy);
};

#endif /* Npc_hpp */
