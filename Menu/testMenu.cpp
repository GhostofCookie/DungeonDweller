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
void testCoord(char,int);
int main()
{
  // TicTacToeMenu *menu = nullptr;
  // ConnectFourMenu * menu = new ConnectFourMenu();;
//   Menu *menu = nullptr;
//   MemoryMenu *menu = nullptr;
   RiddleMenu *menu = nullptr;
   Screen *screen = nullptr;
   map<int, string> options;
   menu = new RiddleMenu();
   screen = new Screen();
//   menu = new MemoryMenu();
   menu->AddOption('W', "Move Up");
   menu->AddOption('S', "Move Down");
   menu->AddOption('A', "Move Left");
   menu->AddOption('D', "Move Right");
   
   while(true)
   {
      if(menu->GetInput()==1)
	 menu->SetQuery("Incorrect.");
      else
	 menu->SetQuery("How do you answer?");

      cout<<screen;
      menu->OutputMenu();
      menu->HandleInput(cin);
//      testFunction(menu->GetOption());
      //    testCoord(menu->GetCoordinates().x1, menu->GetCoordinates().y1);
      //testCoord(menu->GetCoordinates().x2, menu->GetCoordinates().y2);
//      menu->GetColumn();
   }
//   delete menu;

   return 0;
}
void testCoord(char x, int y)
{
  cout<<"X = "<<x<<"Y = "<<y<<endl;
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
