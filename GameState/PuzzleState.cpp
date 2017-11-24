#include "PuzzleState.h"

PuzzleState::PuzzleState()
{

}

void PuzzleState::Set()
{
  puzzle = new Hanoi();
}

void PuzzleState::Get()
{
  puzzle->RunGame();
}
