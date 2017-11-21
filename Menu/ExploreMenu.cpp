#include "ExploreMenu.h"

ExploreMenu::ExploreMenu()
{
}

ExploreMenu::~ExploreMenu()
{
}

void ExploreMenu::SetOptions(int row, int col,int space)
{
  Menu::SetOptions(row,col,space);
}

void ExploreMenu::HandleInput(istream & is)
{
  Menu::HandleInput(is);
}
