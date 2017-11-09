#include <iostream>
//#include "../Screen/Screen.h"
#include "MainMenu.h"
#include "ExploreMenu.h"
#include "FightMenu.h"
#include "TradeMenu.h"
#include "DialogueMenu.h"
#include "RiddleMenu.h"
#include "TicTacToeMenu.h"
#include "HanoiMenu.h"
#include "CharacterMenu.h"
#include "MemoryMenu.h"
#include "ConnectFourMenu.h"
using namespace std;

void testFunction(int);

int main()
{
   Menu *menu = nullptr;
   map<int, string> options;
   menu = new MainMenu();
   menu->AddOption('p', "Pickup",testFunction);
   menu->AddOption('t', "Speak",testFunction);
   menu->AddOption('w', "Move",testFunction);
   menu->SetOptions(options,2,2);
   menu->OutputMenu();
   while(true)
      menu->HandleInput(cin);
   delete menu;
/*   menu = new MainMenu();
   menu->AddOption('i', "Inventory", testFunction);
   menu->SetOptions(options,2,2);
   menu->OutputMenu();
   menu->HandleInput(cin);
   delete menu;
*/  /*
     menu = new ExploreMenu();
     menu->HandleInput(cin);
     menu = new ExploreMenu();
     menu->SetOptions(options);
     menu->OutputMenu();
     menu = new FightMenu();
     menu= new HanoiMenu();
     menu->SetOptions(options);
     menu->OutputMenu();
   */
   return 0;
}

void testFunction(int x)
{
   cout<<"You added and used an option properly!"<<endl;
   
}
