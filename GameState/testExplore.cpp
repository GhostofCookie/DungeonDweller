#include "GameState.h"
#include "ExploreState.h"
#include "PuzzleState.h"
using namespace std;

void GetState(char, GameState*);

int main()
{
  GameState *state = new ExploreState();
  while(true)
    {
      switch(state->GetState())
	{
	case 'E':
	  delete state;
	  state = new ExploreState();
	  break;
	case 'P':
	  delete state;
	  state = new PuzzleState();
	  break;
	}
      state->Set();
      state->Get();
    }
  //  delete state;
  return 0;
}

void GetState(char ch, GameState *state)
{
  switch(ch)
    {
    case 'E':
      delete state;
      state = new ExploreState();
      break;
    case 'P':
      delete state;
      state = new PuzzleState();
      break;
    }
}
