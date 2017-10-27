#include "DialogueMenu.h"

DialogueMenu::DialogueMenu()
{
}

DialogueMenu::~DialogueMenu()
{
}

void DialogueMenu::SetOptions(map<int,string> optionsList, string type)
{
  Menu::SetOptions(optionsList,"dialogue");
}

void DialogueMenu::HandleInput(istream & is)
{
}
