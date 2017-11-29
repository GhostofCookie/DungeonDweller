/// \date 21/10/2017
/// \author Tomas Rigaux
///
/// This is the fight class. This is the menu for the player to use when they are engaged in
/// combat.
///

#include "FightMenu.h"

/// This is the default constructor.
FightMenu::FightMenu()
{
}

/// This is the virtual destructor.
FightMenu::~FightMenu()
{
}

/// This function sets the specific options for the Menu type.
/// \param[in] row Determines which row the options will start being set at.
/// \param[in] col Determines which column the options will start from.
/// \param[in] How mush space inbetween rows.
void FightMenu::SetOptions(int row, int col, int space)
{
   map<int,string> optionList = indexMap;
   int width = menuWidth;
   auto it = optionList.begin();
   int value = 1, count=0;
   string temp;
   row -= 1;
   while(it!=optionList.end()) 
   {
      if(optionList.size() > 9)
	 throw invalid_argument("Too many menu options. Max is 9 for FightMenu.");
      if(count < 9)
      {
	 temp += '[';temp += it->first;temp += ']';temp += it->second;
	 for(unsigned int i=0; i < temp.length(); i++)
	 {

	    if(it->first!=113 && count < 3)
	       Menu::Set(row,((width-2) * value)/6 + i - temp.length()/2 + 1,temp[i]);
	    if(it->first!=113 && (count%3 == 0 || count >=3))
	    {
	       Menu::Set(row, ((width - 2) * value)/6 + i - temp.length()/2 + 1, temp[i]);
	    }
	    if(it->first == 113) Menu::Set(8, width/2 + i - it->second.length()/2,temp[i]);
	 }
      }
      if(it->first!='q')
	 value += 2;
      
      ++count;      
      if(count == 3 || count%3 == 0)
      {
	 value = 1;
	 row+=2;
      }
      
      ++it;
      temp="";
   }
}

/// This function handles the input for the menu options.
/// \param[in,out] is The in-stream operator to read the input.
void FightMenu::HandleInput(istream & is)
{
   Menu::HandleInput(is);
}
