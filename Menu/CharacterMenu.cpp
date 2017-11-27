#include "CharacterMenu.h"

CharacterMenu::CharacterMenu()
{
}

CharacterMenu::~CharacterMenu()
{
}

void CharacterMenu::SetOptions(int row, int col, int space)
{
   Menu::SetOptions(row,col,space);
}

void CharacterMenu::HandleInput(istream & is)
{
   Menu::HandleInput(is);
}
