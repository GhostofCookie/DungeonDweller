/// \date 21/10/2017
/// \author Tomas Rigaux
///
/// This is the state of the player when they are trying to solve a puzzle
/// / minigame.
///

#include "GameState.h"

#ifndef PUZZLESTATE_H
#define PUZZLESTATE_H

class PuzzleState : public GameState
{
   /// \class PuzzleState PuzzleState.h
   /// \brief This is the state of the game when the player is interacting with
   /// a puzzle/minigame. Derived from GameState.
  public:
   /// Default constructor
   PuzzleState();
   /// Sets the layout of the game.
   void Set();
   /// Outputs the set layout.
   void Get();
};

#endif
