/**
 * Puzzle.h
 *
 * @author Tyler Siwy
 * @date Oct 20, 2017
 */

#pragma once

#ifdef __linux__
#include <unistd.h>
#elif _WIN32
#include <stdlib.h>
#else
#endif

#include "Menu.h"
#include "Viewport.h"
#include "DefaultImg.h"
#include "Character.h"
#include <vector>
#include <stdexcept>
/** This class represents an abstract base class for each mini-game/puzzle to
 * derive from.
 */
class Puzzle
{
  public:
   /** Virtual Destructor */
   virtual ~Puzzle() = default;

   /** Generates a random number.
    * @param[in] n The seed to generate random numeric values.
    */
   int RandomNumber(int n) const;

   /** Create a delay in seconds.
    * @param[in] seconds The number of seconds to delay by.
    */
   void SecondDelay(int seconds) const;


   /** Method to run the game, serves as a 'main' for the mini-game, calling
    * functions from private until the player has won.
    */
   virtual void RunGame(Character *player) = 0;

  protected:
   /** Remains false until the mini-game/puzzle is ready to be terminated. */
   bool PuzzleEnd;
    
};