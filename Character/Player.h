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
#include <vector>

///Derived class from Character which provides Player attributes
class Player : public Character
{
private:
    ///Name of the player
    string name;
    
    ///Race of the player
    string race;
    
    ///Players stamina
   int stamina;

   ///Amoutn of keys player has
   int keys;

   
public:
    ///Player constructor
    /// \param[in] s, players stamina
    /// \param[in] k, players keys
    /// \param[in] n, players name
    /// \param[in] r, players race
   Player(int s, int k, string n, string r);
    
    ///Player deconstructor
    ~Player();
    
    ///Changes players stamina
    /// \param[in&] s, players current stamina
    /// \param[in] sMod, how the curent stamina will be modified
    void ChangeStamina(int& s, int sMod);
 
   ///Amount of keys the player has
   /// \param[in&] keys, current amount of keys the player has
   /// \param[in] keyMod, how the current amount of keys will be modified
   int ChangeKeys(int& keys, int keyMod);

   ///Function to use a key
   /// \param[in] keys, uses a key if availible
   bool UseKey(int keys);

    
};

#endif /* Player_hpp */
