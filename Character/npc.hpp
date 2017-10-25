//
// npc.h
//
/// \author Gates Kempenaar
/// \date Oct 25, 2017
//


#ifndef Npc_hpp
#define Npc_hpp

#include <stdio.h>
#include "Character.hpp"
#include <vector>

///Derived class from Character which provides Npc attributes
class Npc : public Character
{
    
private:
    ///The Npc's health
    int Health;
    
    ///The Npc's attack power
    int AttackPower;
    
public:
    ///Npc constructor
    /// \param[in] H, the health of the created Npc
    /// \param[in] AP, the attack power of the created Npc
    Npc(int H, int AP);
    
    ///Deconstructor
    ~Npc();
    
    ///Changes the health of the Npc either up or down
    /// \param[in&] H, the current health of the Npc
    /// \param[in] Hmod, how the current health will be modified
    void ChangeHealth(int& H, int HMod);
    
    ///Attack function for the Npc
    int Attack();
    
    
};

#endif /* Npc_hpp */
