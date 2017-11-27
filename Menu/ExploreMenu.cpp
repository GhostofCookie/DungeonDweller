#include "ExploreMenu.h"

ExploreMenu::ExploreMenu()
{
}

ExploreMenu::~ExploreMenu()
{
}

void ExploreMenu::SetOptions(int row, int col,int space)
{
   map<int,string> optionList = indexMap;
   int width = menuWidth;
   auto it = optionList.begin();
   int value = 1, count=0, divider = 4;
   string temp;
   while(it!=optionList.end())
   {
      temp += '[';temp += it->first;temp += ']';temp += it->second;
      	 if(optionList.size() > 5)
	    divider = 6;
	 else
	    divider = 4;
      for(unsigned int i=0; i < temp.length(); i++)
      {

	 if(it->first!=113 && count < 3)
	    Set(row,((width-2) * value)/divider + i - temp.length()/2 + 1,temp[i]);
	 if(it->first!=113 && count >= 3)
	    Set(row + 2, ((width - 2) * value)/divider + i - temp.length()/2 + 1, temp[i]);
	 if(it->first == 113)
	    Set(8, width/2 + i - it->second.length()/2,temp[i]);
      }
      if(it->first != 'q')
	 value += 2;
      ++count;      
      if(count == 3)
	 value = 1;
      
      ++it;
      temp="";
   }
}

void ExploreMenu::HandleInput(istream &is)
{
   char option;
   cout<<"-> ";
   is >> option;
   is.clear();
   is.ignore(255,'\n');

   auto it = indexMap.find(tolower(option));
   if(it != indexMap.end() && tolower(option) == it->first)
      currOption = tolower(option);
   else
   {
      currOption='\n';
      return;
   }
   if(is.fail())
   {
      throw invalid_argument("Invalid input. Please enter something more sensible.");
      is.clear();
      is.ignore(255,'\n');
   }
}
