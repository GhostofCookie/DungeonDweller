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

Player *CreatePlayer(Player *p);

int main()
{
   Player *temp = new Player;

   GameState *state = new MainState(temp);
   //define character selection here
   GameState *baseState = nullptr;// new ExploreState(temp);//ExploreState(player);
   Player *player = nullptr;
   while(true) 
   {
      system("clear");
      state->Set();
      
      switch(state->GetState())
      {
	
	 case 'E':
	    if(player == nullptr || player->GetStamina() <= 0 || player->GetHealth() <= 0 )
	    {
	       delete player;
	       player = CreatePlayer(player);
	       delete baseState;
	       delete state;
	       baseState = new ExploreState(player);
	       state = baseState;
	    }
	    else
	       state = baseState;
	    break;
	    
	 case 'P':
	    delete state;
	    state = new PuzzleState(player);
	    break;
	    
	 case 'F':
	    delete state;
	    state = new FightState(player);
	    break;
	    
	 case 'S':
	    delete state;
	    state = new TradeState(player);
	    break;
	    
	 case 'M':
	    delete state;
	    state = new MainState(player);
	    break;
	    
	 case 'I':
	    delete state;
	    state = new InventoryState(player);
	    break;
	    
	 default:
	    delete state;
	    state = new MainState(player);

      }

      state->Set();
      state->Get();
   }
   
   delete player;
   delete temp;
   delete state;
   delete baseState;
   
   return 0;
}



Player *CreatePlayer(Player *player)
{
  cout << "Hello! Welcome to the dungeon." << endl;
   cout << "You are going to need a character to get through this place, what do you want your name to be?" << endl;
   cout << ">:";
   string name;
   cin >> name;
   cout << "You are also going to need some equipment down there too, please choose your load-out." << endl;

   // initialize a list of preset characters
   vector <Player*> loadouts;

   // create a ranger preset
   Player *ranger = new Player(40, 1, name, "Ranger", 20, 50);
   Sword *sword = new Sword;
   ranger->FillInventory(sword);

   // create a hunter preset
   Player *hunter = new Player(50, 1, name, "Hunter", 20, 40);
   Bow *bow = new Bow;
   hunter->FillInventory(bow);

   // create a warrior preset
   Player *warrior = new Player(20, 2, name, "Warrior", 20, 70);
   Bow *bowW = new Bow;
   Sword *swordW = new Sword;
   hunter->FillInventory(bowW);
   hunter->FillInventory(swordW);

   // create a mage preset
   Player *mage = new Player(40, 5, name, "Mage", 40, 30);
   Spell *spell = new Spell;
   Spell *spellM = new Spell;
   mage->FillInventory(spell);
   mage->FillInventory(spellM);

   // create a computer science preset
   Player *comp = new Player(5, 0, name, "The Computer Scientist", 10000, 10);

   loadouts.push_back(ranger);
   loadouts.push_back(hunter);
   loadouts.push_back(warrior);
   loadouts.push_back(mage);
   loadouts.push_back(comp);

   char ans;
   int i = 0;

   // flip between different classes until one is chosen
   do
   {
      loadouts[i]->Print();
      cout << "[C] Choose" << endl;
      cout << "[N] Next" << endl;
      cout << ">:";
      cin >> ans;

      // set the player to the selected character
      if(tolower(ans) == 'c')
      {
	 delete player;
	 player = new Player(*loadouts[i]);
	 player->Img() = ImportImg("../DD_Art/Player/DD_Player.txt");
	 
      } else
      {
	 if(i > 3)
	    i = 0;
	 else
	    i++;
      }
      system("clear");
      
   } while(ans == 'n');
   ///Deleting the loadout vectors pointers
   for(unsigned int i = 0; i < loadouts.size(); i++)
      delete loadouts[i];
   return player;
}


