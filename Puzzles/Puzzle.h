//
// puzzle.h
//
/// \author Tyler Siwy
/// \date Oct 20, 2017
///

#ifndef PUZZLE_H
#define PUZZLE_H

#include "../Menu/Menu.h"
#include "../Screen/Screen.h"
#include "../Image/DefaultImg.h"
#include "../Character/Character.h"
#include <vector>
#include <unistd.h>
#include <stdexcept>
///This class represents an abstract base class for each mini-game/puzzle to
///derive from.
class Puzzle
{
  public:
   int RandomNumber(int n) const;
   
   ///Virtual Destructor
   virtual ~Puzzle(){}
   ///Method to run the game, serves as a 'main' for the mini-game, calling
   ///functions from private until the player has won.                          
   virtual void RunGame(Character *player) = 0;
  protected:
   void SecondDelay(int seconds) const;
   ///Remains false until the mini-game/puzzle is ready to be terminated.
   bool PuzzleEnd;
    
};
#endif
