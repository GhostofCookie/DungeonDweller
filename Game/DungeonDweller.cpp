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
   //define character selection here
   GameState *baseState = new ExploreState();//ExploreState(player);
   Player *player = (*baseState).GetPlayer();
   while(true) 
   {
      system("clear");
      state->Set();
      
      switch(state->GetState())
      {	
	 case 'E':
	    if(player->GetStamina() <= 0 || player->GetHealth() <= 0 )
	    {
	       delete player;
	       //   CreatePlayer(player);
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
	 case 'P':
	    state = nullptr;
	    delete state;
	    state = new PuzzleState(player);
	    break;
	    
	 case 'F':
	    state = nullptr;
	    delete state;
	    state = new FightState(player);
	    break;
	    
	 case 'S':
	    state = nullptr;
	    delete state;
	    state = new TradeState(player);
	    break;
	    
/*	 case 'M':
	    state = nullptr;
	    delete state;
	    state = new MainState();
	    break;*/
	    
	 case 'I':
	    state = nullptr;
	    delete state;
	    state = new InventoryState(player);
	    break;
	    
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
