#include "GameState.h"
#include "ExploreState.h"
#include "PuzzleState.h"
using namespace std;

int main()
{
  GameState *state = new ExploreState();
  while(true)
    {
      state = new PuzzleState();
      state->Set();
      state->Get();
    }

  return 0;
}
