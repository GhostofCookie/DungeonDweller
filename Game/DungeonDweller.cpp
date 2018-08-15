/// \date 24/10/2017
///
/// \author Team Kodika
///
/// This is the main file for the game.

#include "../GameState/DialogueState.h"
#include "../GameState/FightState.h"
#include "../GameState/MainState.h"
#include "../GameState/ExploreState.h"
#include "../GameState/PuzzleState.h"
#include "../GameState/MainState.h"
#include "../GameState/TradeState.h"
#include "../GameState/InventoryState.h"
using namespace std;

int main()
{
   GameState *state = new MainState();

   // TODO: define character selection here.

   GameState *baseState = new ExploreState();
   Player *player = (*baseState).GetPlayer();
   while(true) 
   {
#ifdef __linux__
	   system("clear");
#elif _WIN32
	   system("CLS");
#endif
      state->Set();
      
      switch(state->GetState())
      {	
	 case EXPLORE:
	    if(player->GetStamina() <= 0 || player->GetHealth() <= 0 )
	    {
	       delete player;
	       // CreatePlayer(player);
	       baseState = nullptr;
	       delete baseState;
	       state = nullptr;
	       delete state;
	       baseState = new ExploreState();
	       state = new MainState();
	       player = (*baseState).GetPlayer();
	    }
	    else
	       state = new ExploreState(*baseState);
	    break;

	 case PUZZLE:
	    state = nullptr;
	    delete state;
	    state = new PuzzleState(player);
	    break;
	    
	 case COMBAT:
	    state = nullptr;
	    delete state;
	    state = new FightState(player);
	    break;
	    
	 case TRADE:
	    state = nullptr;
	    delete state;
	    state = new TradeState(player);
	    break;
	    
	 case INVENTORY:
	    state = nullptr;
	    delete state;
	    state = new InventoryState(player);
	    break;
	 
	 case MAIN:
	 default:
	    state = nullptr;
	    delete state;
	    state = new MainState();

      }
      state->Set();
      state->Get();
   }
   delete player;
   delete state;
   delete baseState;
   
   return 0;
}
