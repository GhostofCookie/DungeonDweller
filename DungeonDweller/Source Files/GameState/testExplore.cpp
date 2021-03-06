#include "GameState.h"
#include "MainState.h"
#include "ExploreState.h"
#include "PuzzleState.h"
#include "TradeState.h"
#include "FightState.h"
#include "InventoryState.h"
#include "Player.h"
#include "MyConsumables.h"
#include "Item.h"
#include "Weapon.h"
#include "MyWeapons.h"


void CreatePlayer(Player *ptr);
int PlayerChoice();

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

void CreatePlayer(Player *ptr){
   delete ptr;
   ptr=nullptr;
   std::cout << "Hello! Welcome to the dungeon." << std::endl;
   std::cout << "You are going to need a character to get through this place, what do you want your name to be?" << std::endl;
   std::cout << ">:";
   std::string name;
   std::cin >> name;
   std::cout << "You are also going to need some equipment down there, please choose your load-out." << std::endl;

   int input=PlayerChoice();
   
   switch(input)
   {
      case 0:
	 // create a ranger preset
	 ptr = new Player(40, 1, name, "Ranger", 20, 50);
	 ptr->FillInventory(new Sword);
	 break;
      case 1:
	 // create a hunter preset
	 ptr = new Player(50, 1, name, "Hunter", 20, 40);
	 ptr->FillInventory(new Bow);
	 break;
      case 2:   // create a warrior preset
	 ptr = new Player(20, 2, name, "Warrior", 20, 70);
	 ptr->FillInventory(new Bow);
	 ptr->FillInventory(new Sword);
	 break;
      case 3:   // create a mage preset
	 ptr = new Player(40, 5, name, "Mage", 40, 30);
	 ptr->FillInventory(new Spell);
	 ptr->FillInventory(new Spell);
	 break;
      case 4:    // create a computer science preset
	 ptr = new Player(5, 0, name, "The Computer Scientist", 10000, 10);
	 break;
   }
}

int PlayerChoice(){
   int iterator=0;
   char ans;
   bool loopEnd=false;
   while(loopEnd==false)
   {
      switch(iterator)
      {
	 case 0:
	    std::cout << "Race: Ranger" << std::endl << "Stamina: 40" << std::endl
		 << "Health: 50" << std::endl << "Gold: 20" << std::endl;
	    break;
	 case 1:
	    std::cout << "Race: Hunter" << std::endl << "Stamina: 50" << std::endl
		 << "Health: 40" << std::endl << "Gold: 20" << std::endl;
	    break;
	 case 2:
	    std::cout << "Race: Warrior" << std::endl << "Stamina: 20" << std::endl
		 << "Health: 70" << std::endl << "Gold: 20" << std::endl;
	    break;
	 case 3:
	    std::cout << "Race: Mage" << std::endl << "Stamina: 40" << std::endl
		 << "Health: 30" << std::endl << "Gold: 40" << std::endl;
	    break;
	 case 4:
	    std::cout << "Race: Computer Scientist" << std::endl << "Stamina: 5" << std::endl
		 << "Health: 10" << std::endl << "Gold: 10,000" << std::endl;
	    break;
      }
      std::cout << "[C] Choose" << std::endl;
      std::cout << "[N] Next" << std::endl;
      std::cout << ">:";
      std::cin >> ans;
      if(ans == 'c' || ans == 'C')
	 loopEnd=true;
      else
	 iterator++;
      if(iterator>4)
	 iterator=0;
      system("clear");
   }
   return iterator;
}
