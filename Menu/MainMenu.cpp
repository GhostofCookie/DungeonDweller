#include "MainMenu.h"

MainMenu::MainMenu(int height)
   : GameMenu(height)
{

}

void MainMenu::SetOptions(int row, int col,int space)
{
   map<int,string> optionsList = indexMap;
   auto it = optionsList.begin();
   string temp;
   while(it != optionsList.end())
   {
      temp = '['; temp += it->first; temp += ']'; temp += it->second;
      for(unsigned int i = 0; i < temp.length(); i++)
      {
	 Set(row, (menuWidth-2)/2 + i - temp.length()/2, temp[i]);
      }
      row+=2;
      ++it;
   }
}

void MainMenu::HandleInput(istream & is)
{
  Menu::HandleInput(is);
}

