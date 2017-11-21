#include "MainMenu.h"

MainMenu::MainMenu(int height)
   : GameMenu(height)
{

}

void MainMenu::SetOptions(int row, int col,int space)
{
   map<int,string> optionsList = indexMap;
   for(auto it = optionsList.begin(); it != optionsList.end(); it++)
      Menu::SetOptions(3,(menuWidth-2)/2-it->second.length()/2);
}

void MainMenu::HandleInput(istream & is)
{
  Menu::HandleInput(is);
}

