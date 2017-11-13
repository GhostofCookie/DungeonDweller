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
   int width = 101;
   for(int i=0; i<9; i++)
   {
      for(int j=0; j<10; j++)
      {
	 Menu::Set(j,width/3-1,'|');
	 Menu::Set(j,(width*2)/3-1,'|');
      }
   }
   auto it = optionList.begin();
   int value = 1, count=0;
   string temp;
   while(it!=optionList.end())
   {
      temp+='[';temp+=it->first;temp+=']';temp+=' ';temp+=it->second;
      for(unsigned int i=0; i < temp.length(); i++)
      {
	 if(it->first!=113 && count != 3)
	    Menu::Set(row,((width-2)*value)/6+i-temp.length()/2,temp[i]);
	 else if(count == 3)
	 {
	    Menu::Set(row+2,(width-2)/2+i-temp.length()/2, temp[i]);
	 }
	 else Menu::Set(8, width/2 + i - it->second.length(),temp[i]);
      }
      if(it->first!='q' && count!=3)
	 value+=2;
      ++count;
      ++it;
      temp="";
   }
}

void HanoiMenu::HandleInput(istream & is)
{
   Menu::HandleInput(is);
}
