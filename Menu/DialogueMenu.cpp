#include "DialogueMenu.h"

DialogueMenu::DialogueMenu()
{
}

DialogueMenu::~DialogueMenu()
{
}

void DialogueMenu::SetOptions(int row, int col, int space)
{
   map<int,string> optionsList = indexMap;
   Menu::SetOptions();
}

void DialogueMenu::HandleInput(istream & is)
{
}
