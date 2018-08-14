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


void testFunction(char);
void testCoord(char,int);
int main()
{
  // TicTacToeMenu *menu = nullptr;
  // ConnectFourMenu * menu = new ConnectFourMenu();;
//   Menu *menu = nullptr;
//   MemoryMenu *menu = nullptr;
   Menu *menu = nullptr;
   Screen *screen = nullptr;
   std::map < int, std::string > options;
   menu = new FightMenu();
   screen = new Screen();
//   menu = new MemoryMenu();
   menu->AddOption('W', "Move Up");
   menu->AddOption('S', "Move Down");
   menu->AddOption('A', "Move Left");
   menu->AddOption('D', "Move Right");
   menu->AddOption('t', "Move Up");
   menu->AddOption('y', "Move Down");
   menu->AddOption('h', "Move Left");
   menu->AddOption('j', "Move Right");
   menu->AddOption('o', "Move Right");

   
   while(true)
   {
      /*   if(menu->GetInput() == 1)
	 menu->SetQuery("Incorrect.");
      else
	 menu->SetQuery("How do you answer?");
      */
      std::cout << screen;
      menu->OutputMenu();
      menu->HandleInput(std::cin);
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
  std::cout << "X = " << x << "Y = " << y << std::endl;
}
void testFunction(char x)
{
  switch(x)
    {
    case 'W':
      std::cout << "Moved Up!" << std::endl;
      break;
    case 'S':
      std::cout << "Moved Down." << std::endl;
      break;
    case 'A':
      std::cout << "Moved left." << std::endl;
      break;
    case 'D':
      std::cout << "Moved Right!" << std::endl;
      break;
    };
  
}
