#include "PuzzleState.h"
#include "../Puzzles/Hanoi.h"
#include "../Puzzles/CodeCracker.h"
#include "../Puzzles/TicTacToe.h"
#include "../Puzzles/MemoryMatch.h"
#include "../Puzzles/ConnectFour.h"

PuzzleState::PuzzleState(Player *p)
{
   player = new Player(*p);
}

PuzzleState::~PuzzleState()
{
   delete player;
}

void PuzzleState::Set()
{
  puzzles.push_back(new Hanoi());
  puzzles.push_back(new TicTacToe());
  puzzles.push_back(new ConnectFour());
  puzzles.push_back(new MemoryMatch());
  puzzles.push_back(new CodeCracker());
}

void PuzzleState::Get()
{
  random_shuffle(puzzles.begin(), puzzles.end());
  auto it = puzzles.begin();
  
  (*it)->RunGame(player);
  currState = 'E';
  
}
