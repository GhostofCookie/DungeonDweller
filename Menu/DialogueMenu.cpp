#include "DialogueMenu.h"

DialogueMenu::DialogueMenu()
{
}

DialogueMenu::~DialogueMenu()
{
}

void DialogueMenu::SetOptions(map<int,string> optionsList, int row, int col)
{
  Menu::SetOptions(optionsList);
}

void DialogueMenu::HandleInput(istream & is)
{
}
