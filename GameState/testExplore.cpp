#include "GameState.h"
#include "MainState.h"
#include "ExploreState.h"
#include "PuzzleState.h"
#include "TradeState.h"
#include "FightState.h"
#include "InventoryState.h"
#include "../Character/Player.h"
#include "../Item/MyConsumables.h"
#include "../Item/Item.h"
#include "../Item/Weapon.h"
#include "../Item/MyWeapons.h"
using namespace std;

void CreatePlayer(Player *p);

int main()
{
   Player *player = new Player();

   GameState *state = new MainState(player);
   //define character selection here
   GameState *baseState = new ExploreState(player);

  
   
   while(true) 
   {
      system("clear");
      state->Set();
      
      switch(state->GetState())
      {
	 case 'E':
	    if(player->GetStamina() <= 0 || player->GetHealth() <= 0)
	     {
	       baseState = new ExploreState(player);
	       state = baseState;
	       CreatePlayer(player);
	     }
	     else
	       state = baseState;
	    break;
	 case 'P':
	    state = new PuzzleState(player);
	    break;
	 case 'F':
	    state = new FightState(player);
	    break;
	 case 'S':
	    state = new TradeState(player);
	    break;
	 case 'M':
	    state = new MainState(player);

	    break;
	 case 'I':
	    state = new InventoryState(player);
	    break;
	 default:
	    state = new MainState(player);

      }
      state->Set();
      state->Get();

   }
   
   delete state;
   delete baseState;
   return 0;
}

void CreatePlayer(Player *player)
{
  cout << "Hello! Welcome to the dungeon." << endl;
   cout << "You are going to need a character to get through this place, what do you want your name to be?" << endl;
   cout << ">:";
   string name;
   cin >> name;
   cout << "You are also going to need some equipment down there too, please choose your load-out." << endl;

   vector<Player> loadouts;
   Player ranger(40, 1, name, "Ranger", 20, 50);
   Sword *sword = new Sword;
   ranger.FillInventory(sword);
   
   Player hunter(50, 1, name, "Hunter", 20, 40);
   Bow *bow = new Bow;
   hunter.FillInventory(bow);
   
   Player warrior(20, 2, name, "Warrior", 20, 70);
   Bow *bowW = new Bow;
   Sword *swordW = new Sword;
   hunter.FillInventory(bowW);
   hunter.FillInventory(swordW);
   
   Player mage(40, 5, name, "Mage", 40, 30);
   Spell *spell = new Spell;
   Spell *spellM = new Spell;
   mage.FillInventory(spell);
   mage.FillInventory(spellM);

   Player comp(5, 0, name, "The Computer Scientist", 10000, 10);
   
   loadouts.push_back(ranger);
   loadouts.push_back(hunter);
   loadouts.push_back(warrior);
   loadouts.push_back(mage);
   loadouts.push_back(comp);

   char ans;
   int i = 0;
   do
   {
      loadouts[i].Print();
      cout << "[C] Choose" << endl;
      cout << "[N] Next" << endl;
      cout << ">:";
      cin >> ans;
      if(tolower(ans) == 'c')
      {
	 delete player;
	 player = new Player(loadouts[i]);
	 player->Img() = ImportImg("../DD_Art/Player/DD_Player.txt");
      } else
      {
	 if(i > 3)
	    i = 0;
	 else
	    i++;
      }
      system("clear");
      
   }while(ans == 'n');

}


