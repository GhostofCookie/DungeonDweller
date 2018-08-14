//
// puzzle.h
//
/// \author Tyler Siwy
/// \date Oct 20, 2017
///

#pragma once

#ifdef __linux__
#include <unistd.h>
#elif _WIN32
// Place windows unistd.h equivalent.
#else
#endif

#include "../Menu/Menu.h"
#include "../Screen/Screen.h"
#include "../Image/DefaultImg.h"
#include "../Character/Character.h"
#include <vector>
#include <stdexcept>
///This class represents an abstract base class for each mini-game/puzzle to
///derive from.
class Puzzle
{
  public:
   int RandomNumber(int n) const;
   void SecondDelay(int seconds) const;
   ///Virtual Destructor
   virtual ~Puzzle(){}
   ///Method to run the game, serves as a 'main' for the mini-game, calling
   ///functions from private until the player has won.                          
   virtual void RunGame(Character *player) = 0;
  protected:
   ///Remains false until the mini-game/puzzle is ready to be terminated.
   bool PuzzleEnd;
    
};