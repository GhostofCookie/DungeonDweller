#include "DialogueMenu.h"

DialogueMenu::DialogueMenu()
{
}

DialogueMenu::~DialogueMenu()
{
}

void DialogueMenu::SetOptions(int row, int col, int space)
{
   std::map < int,std::string > optionsList = indexMap;
   Menu::SetOptions();
}

void DialogueMenu::HandleInput( std::istream & is)
{
}
