#include "PuzzleState.h"

PuzzleState::PuzzleState()
{

}

void PuzzleState::Set()
{
  puzzles.push_back(new Hanoi());
  puzzles.push_back(new TicTacToe());
}

void PuzzleState::Get()
{
  random_shuffle(puzzles.begin(), puzzles.end());
  auto it = puzzles.begin();
  
  it->RunGame();
}
