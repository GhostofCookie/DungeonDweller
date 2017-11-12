#include <iostream>
#include "../Screen/Screen.h"
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
   Screen *screen = nullptr;
   map<int, string> options;
   menu = new Menu();
   screen = new Screen();

   menu->AddOption('p', "Pickup",testFunction);
   menu->AddOption('t', "Speak",testFunction);
   menu->AddOption('a', "Move",testFunction);
   menu->AddOption('w', "Move Up",testFunction);
   menu->SetOptions();
   while(true)
   {
      cout<<screen;
      menu->OutputMenu();
      menu->HandleInput(cin);
   }
   delete menu;

   return 0;
}

void testFunction(int x)
{
   system("clear");
   cout<<"You added and used an option properly!"<<endl;
   
}
