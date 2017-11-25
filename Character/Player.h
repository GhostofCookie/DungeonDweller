//
// Player.h
//
/// \author Gates Kempenaar
/// \date Oct 25, 2017
//


#ifndef Player_h
#define Player_h

#include <stdio.h>
#include "Character.h"
#include "Npc.h"
#include "../Item/MyConsumables.h"
#include "../Image/ImportImg.h"
#include <vector>
#include <string>
using namespace std; 

///Derived class from Character which provides Player attributes
class Player : public Character
{
 
public:
    ///Player constructor
    /// \param[in] s, players stamina
    /// \param[in] k, players keys
    /// \param[in] n, players name
    /// \param[in] r, players race
   Player(int s = 0, int k = 0, string n = " ", string r = " ", int g = 0, int h = 0, ImportImg img = ImportImg());
    
    ///Changes players stamina
    /// \param[in&] s, players current stamina
    /// \param[in] sMod, how the curent stamina will be modified
    void ChangeStamina(int sMod);
 
   ///Amount of keys the player has
   /// \param[in&] keys, current amount of keys the player has
   /// \param[in] keyMod, how the current amount of keys will be modified
   void ChangeKeys(int keyMod);

   ///Function to use a key
   /// \param[in] keys, uses a key if availible
   bool UseKey(int& keys);

   ///Attack function for the player to attack the Npc
   /// \param[in] damage, the base damage of the weapon
   /// \param[in] enemy, the Npc being attacked
   void AttackNpc(Npc enemy);

  private:
   
   ///Name of the player
   string name;
   
   ///Race of the player
   string race;
   
   ///Players stamina
   int stamina;
   
   ///Amoutn of keys player has
   int keys; 
};

#endif /* Player_hpp */
