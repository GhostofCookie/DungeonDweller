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

void testFunction(char);

int main()
{
   Menu *menu = nullptr;
   Screen *screen = nullptr;
   map<int, string> options;
   menu = new TicTacToeMenu();
   screen = new Screen();

   menu->AddOption('W', "Move Up");
   menu->AddOption('S', "Move Down");
   menu->AddOption('A', "Move Left");
   menu->AddOption('D', "Move Right");
   
   while(true)
   {
      cout<<screen;
      menu->OutputMenu();
      menu->HandleInput(cin);
      cout<<menu->GetOption();
      testFunction(menu->GetOption());
   }
   delete menu;

   return 0;
}

void testFunction(char x)
{
  switch(x)
    {
    case 'W':
      cout<<"Moved Up!"<<endl;
      break;
    case 'S':
      cout<<"Moved Down."<<endl;
      break;
    case 'A':
      cout<<"Moved left."<<endl;
      break;
    case 'D':
      cout<<"Moved Right!"<<endl;
      break;
    };
  
}
