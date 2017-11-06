#include "MainMenu.h"

MainMenu::MainMenu()
{
  new Menu(33,101);
}

MainMenu::~MainMenu()
{
}

void MainMenu::SetOptions(map<int,string> optionsList, int row, int col)
{
  Menu::SetOptions(optionsList,2,(Menu::menuWidth-1)/2);
}

void MainMenu::HandleInput(istream & is)
{
}
