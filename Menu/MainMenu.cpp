#include "MainMenu.h"

MainMenu::MainMenu()
{

}

MainMenu::~MainMenu()
{
}

void MainMenu::SetOptions(map<int,string> optionsList, int row, int col)
{
  for(auto it = optionsList.begin(); it != optionsList.end(); it++)
    Menu::SetOptions(optionsList,2,(Menu::menuWidth-1)/2);// - 
		     //		     it->first);
}

void MainMenu::HandleInput(istream & is)
{
  Menu::HandleInput(is);
}
