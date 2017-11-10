#include "MainMenu.h"

MainMenu::MainMenu()
{

}

void MainMenu::SetOptions(int row, int col)
{
   map<int,string> optionsList;
   for(auto it = optionsList.begin(); it != optionsList.end(); it++)
      Menu::SetOptions(2,(Menu::menuWidth-1)/2);
}

void MainMenu::HandleInput(istream & is)
{
  Menu::HandleInput(is);
}

