#include "GameState.h"
#include "MainState.h"
#include "ExploreState.h"
#include "PuzzleState.h"
#include "TradeState.h"
#include "FightState.h"
#include "InventoryState.h"
using namespace std;

void GetState(char, GameState*);

int main()
{
   GameState *state = new MainState();
   GameState *baseState = new ExploreState();
   while(true)
   {
      system("clear");
      state->Set();
      switch(state->GetState())
      {
	 case 'E':
	    state = baseState;
	    break;
	 case 'P':
	    state = new PuzzleState();
	    break;
	 case 'F':
	    state = new FightState();
	    break;
	 case 'S':
	    state = new TradeState();
	    break;
	 case 'M':
	    state = new MainState();
	    break;
	 case 'I':
	    state = new InventoryState();
	    break;
      }
      state->Set();
      state->Get();
   }
   delete state;
   delete baseState;
   return 0;
}


