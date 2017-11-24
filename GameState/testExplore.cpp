#include "GameState.h"
#include "ExploreState.h"
#include "PuzzleState.h"
using namespace std;

void GetState(char, GameState*);

int main()
{
  GameState *state = new ExploreState();
  try{
    while(true)
      {
	state->Set();
	state->Get();
      }
  }
  catch(invalid_argument)
    {
      state->Set();
      state->Get();
    }
  return 0;
}


