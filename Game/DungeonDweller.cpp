/// \date 24/10/2017
///
/// \author Team Kodika
///
/// This is the main file for the game.

// Screen Headers
#include "../Screen/Screen.h"
// Image Headers
#include "../Image/Image.h"
#include "../Image/DefaultImg.h"
#include "../Image/ImportImg.h"
#include "../ImageImporter/ImageImporter.h"
// Room Header
#include "../Room/Room.h"
// RoomTree Headers
#include "../RoomTree/RoomTree.h"
// Cutscene Header
#include "../Cutscene/Cutscene.h"
// Menu Headers
#include "../Menu/CharacterMenu.h"
#include "../Menu/ConnectFourMenu.h"
#include "../Menu/DialogueMenu.h"
#include "../Menu/ExploreMenu.h"
#include "../Menu/FightMenu.h"
#include "../Menu/GameMenu.h"
#include "../Menu/HanoiMenu.h"
#include "../Menu/MainMenu.h"
#include "../Menu/MemoryMenu.h"
#include "../Menu/Menu.h"
#include "../Menu/RiddleMenu.h"
#include "../Menu/TicTacToeMenu.h"
#include "../Menu/TradeMenu.h"
// GameState Headers
#include "../GameState/DialogueState.h"
#include "../GameState/FightState.h"
#include "../GameState/MainState.h"
#include "../GameState/PuzzleState.h"
#include "../GameState/ExploreState.h"
#include "../GameState/GameState.h"
#include "../GameState/MainState.h"
#include "../GameState/TradeState.h"
#include "../GameState/InventoryState.h"
// Puzzle Headers
#include "../Puzzles/CodeCracker.h"
#include "../Puzzles/ConnectFour.h"
#include "../Puzzles/Hanoi.h"
#include "../Puzzles/MemoryMatch.h"
#include "../Puzzles/Puzzle.h"
#include "../Puzzles/TicTacToe.h"
// Item Headers
//#include "../Item/MyConsumables.h"
//#include "../Item/MyWeapons.h"
// Character Headers
//#include "../Character/Npc.h"
//#include "../Character/Player.h"
// Misc Headers
#include <iostream>
#include <ctime> //srand()
#include <cctype>
#include <stdexcept>
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
