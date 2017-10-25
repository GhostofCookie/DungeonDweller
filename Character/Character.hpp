//
//  Character.hpp
//  2720Project
//
//  Created by Gates Kempenaar on 2017-10-23.
//  Copyright © 2017 Gates Kempenaar. All rights reserved.
//

#ifndef Character_hpp
#define Character_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

///Abstract base class to provide input and output of Npc's and Player
class Character
{
  
    ///Reads information in for the character
    /// \param[in] is the input stream
    virtual iostream Read(istream &is);
    
    ///Writes the character object to the screen
    /// \param[out] os the output stream for printing on the screen
    virtual ostream Write(ostream &os);
    
};

#endif /* Character_hpp */
