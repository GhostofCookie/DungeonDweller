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
    Npc(int h);
    
    ///Deconstructor
    ~Npc();
   
};

#endif /* Npc_hpp */
