#include "GameState.h"
#include "ExploreState.h"
#include "PuzzleState.h"
using namespace std;

void GetState(char, GameState*);

int main()
{
   GameState *state = new ExploreState();
   GameState *baseState = new ExploreState();
   try{
      state = baseState;
     while(true)
     {
	state->Set();
	switch(state->GetState())
	{
	   case 'E':
	      state = baseState;
	      break;
	   case 'P':
//	   delete state;
	      state = new PuzzleState();
	      break;
	      /*   case 'F':
	      state = new FightState();
	      break;
	   case 'S':
	   state = new TradeState();
	   break;
	      */
	      
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


