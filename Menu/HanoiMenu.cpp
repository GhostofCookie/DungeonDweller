#include "HanoiMenu.h"

HanoiMenu::HanoiMenu()
{
}

HanoiMenu::~HanoiMenu()
{
}

void HanoiMenu::SetOptions(map<int,string> optionList,int row,int col,int space)
{
   int width = 101;
   for(int i=0; i<9; i++)
   {
      for(int j=0; j<10; j++)
      {
	 Menu::set(j,width/3-1,'|');
	 Menu::set(j,(width*2)/3-1,'|');
      }
   }
   auto it = optionList.begin();
   while(it!=optionList.end())
   {
      for(unsigned int i=0; i < it->second.length(); i++)
      {
	 Menu::set(5,width/4+i,it->second[i]);
//	 ++it;
	 Menu::set(row,width/2-it->second.length()+i,it->second[i]);
//	 ++it;
	 Menu::set(row,(width*3)/4-it->second.length()/2+i,it->second[i]);
//	 it=optionList.begin();
    }
      ++it;
   }
//   Menu::SetOptions(optionList);
}

void HanoiMenu::HandleInput(istream & is)
{
   Menu::HandleInput(is);
}
