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
	switch(state->GetState())
	{
	   case 'E':
//	   delete state;
	      state = new ExploreState();
	      break;
	   case 'P':
//	   delete state;
	      state = new PuzzleState();
	}
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


