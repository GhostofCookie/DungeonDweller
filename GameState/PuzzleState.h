/// \date 21/10/2017
/// \author Tomas Rigaux
///
/// This is the state of the player when they are trying to solve a puzzle
/// / minigame.
///

#include "GameState.h"
#include "../Puzzles/Puzzle.h"
#include "../Puzzles/Hanoi.h"
#include "../Puzzles/CodeCracker.h"
#include "../Puzzles/TicTacToe.h"
#include "../Puzzles/MemoryMatch.h"
#include "../Puzzles/ConnectFour.h"
#include <vector>
#include <algorithm>


#pragma once

class PuzzleState : public GameState
{
   /// \class PuzzleState PuzzleState.h
   /// \brief This is the state of the game when the player is interacting with
   /// a puzzle/minigame. Derived from GameState.
  public:
   /// Default constructor
   PuzzleState(Player *p);
   /// Default Destructor.
   ~PuzzleState();
   /// Sets the layout of the game.
   void Set();
   /// Outputs the set layout.
   void Get();
  private:
   std::vector<Puzzle*> puzzles;
};

