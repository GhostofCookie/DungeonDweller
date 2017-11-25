#include "GameState.h"
#include "MainState.h"
#include "ExploreState.h"
#include "PuzzleState.h"
#include "TradeState.h"
#include "FightState.h"
using namespace std;

void GetState(char, GameState*);

int main()
{
   GameState *state = new MainState();
   GameState *baseState = new ExploreState();
   while(true)
   {
      state->Set();
      switch(state->GetState())
      {
	 case 'E':
	    state = baseState;
	    break;
	 case 'P':
	    delete state;
	    state = new PuzzleState();
	    break;
	 case 'F':
	    state = new FightState();
	    break;
	 case 'S':
	    state = new TradeState();
	    break;
	    
      }
      state->Set();
      state->Get();
   }
   return 0;
}


