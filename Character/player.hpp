//
// player.hpp
//
/// \author Gates Kempenaar
/// \date Oct 25, 2017
//


#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include "Character.hpp"
#include <vector>

///Derived class from Character which provides Player attributes
class Player : public Character
{
private:
    ///Name of the player
    string Name;
    
    ///Race of the player
    string Race;
    
    ///PLayers health
    int Health;
    
    ///Players stamina
    int Stamina;
    
    ///Players attack power
    int AttackPower;
    
public:
    ///Player constructor
    /// \param[in] H, players health
    /// \param[in] S, players stamina
    /// \param[in] AP, players attack power
    /// \param[in] N, players name
    /// \param[in] R, players race
    Player(int H, int S, int AP, string N, string R);
    
    ///Player deconstructor
    ~Player();
    
    ///Changes the players health
    /// \param[in&] H, players current health
    /// \param[in] HMod, how the current health will be modified
    void ChangeHealth(int& H, int HMod);
    
    ///Changes players stamina
    /// \param[in&] S, players current stamina
    /// \param[in] SMod, how the curent stamina will be modified
    void ChangeStamina(int& S, int SMod);
    
    ///Changes the players attack power
    /// \param[in&] AP, players current attack power
    /// \param[in] APMod, how the current attack power will be modified
    void ChangeAttackPower(int& AP, int APMod);
    
    
    ///Function to allow the player to attack
    int Attack();
    
};

#endif /* Player_hpp */
