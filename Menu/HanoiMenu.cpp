#include "HanoiMenu.h"

HanoiMenu::HanoiMenu()
{
}

HanoiMenu::~HanoiMenu()
{
}

void HanoiMenu::SetOptions(int row,int col,int space)
{
   map<int,string> optionList = indexMap;
   int width = menuWidth;
   for(int i = 0; i < 9; i++)
   {
      for(int j = 0; j < 10; j++)
      {
	 Menu::Set(j,width/3,'|');
	 Menu::Set(j,(width * 2)/3 - 1,'|');
      }
   }
   auto it = optionList.begin();
   int value = 1, count=0;
   string temp;
   while(it!=optionList.end())
   {
      temp += '[';temp += it->first;temp += ']';temp += it->second;
      for(unsigned int i=0; i < temp.length(); i++)
      {
	 if(it->first!=113 && count < 3)
	    Menu::Set(row,((width-2) * value)/6 + i - temp.length()/2 + 1,temp[i]);
	 if(it->first!=113 && count >= 3)
	 {
	    Menu::Set(row + 2, ((width - 2) * value)/6 + i - temp.length()/2 + 1, temp[i]);
	 }
	 if(it->first == 113) Menu::Set(8, width/2 + i - it->second.length()/2,temp[i]);
      }
      if(it->first!='q')
	value += 2;
      ++count;      
      if(count == 3)
	value = 1;
      
      ++it;
      temp="";
   }
}

void HanoiMenu::HandleInput(istream & is)
{
   Menu::HandleInput(is);
}
