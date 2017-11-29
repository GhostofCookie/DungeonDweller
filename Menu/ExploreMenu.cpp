/// \date 25/10/2017
/// \author Tomas Rigaux
///
/// Derived from GameMenu. This is the menu for the player character to use when
/// they are exploring rooms in the game.

#include "ExploreMenu.h"

/// This is the default constructor.
ExploreMenu::ExploreMenu()
{
}

/// This is the virtual destructor.
ExploreMenu::~ExploreMenu()
{
}

/// This function sets the specific options for the Menu type.
/// \param[in] row Determines which row the options will start being set at.
/// \param[in] col Determines which column the options will start from.
/// \param[in] How mush space inbetween rows.
void ExploreMenu::SetOptions(int row, int col, int space)
{
   map < int, string > optionList = indexMap;
   int width = menuWidth;
   auto it = optionList.begin();
   int value = 1, count = 0, divider = 4;
   string temp;
   while(it != optionList.end())
   {
      temp += '['; temp += it->first; temp += ']'; temp += it->second;
      	 if(optionList.size() > 5)
	    divider = 6;
	 else
	    divider = 4;
      for(unsigned int i=0; i < temp.length(); i++)
      {

	 if(it->first != 113 && count < 3)
	    Set(row,((width - 2) * value) / divider + i - temp.length() / 2 + 1,temp[i]);
	 if(it->first!=113 && count >= 3)
	    Set(row + 2, ((width - 2) * value)/divider + i - temp.length() / 2 + 1, temp[i]);
	 if(it->first == 113)
	    Set(8, width / 2 + i - it->second.length() / 2,temp[i]);
      }
      if(it->first != 'q')
	 value += 2;
      ++count;      
      if(count == 3)
	 value = 1;
      
      ++it;
      temp = "";
   }
}

/// This function handles the input for the menu options.
/// \param[in,out] is The in-stream operator to read the input.
void ExploreMenu::HandleInput(istream &is)
{
   char option;
   cout << "-> ";
   is >> option;
   is.clear();
   is.ignore(255,'\n');

   auto it = indexMap.find(tolower(option));
   if(it != indexMap.end() && tolower(option) == it->first)
      currOption = tolower(option);
   else
   {
      currOption = '\n';
      return;
   }
   if(is.fail())
   {
      throw invalid_argument("Invalid input. Please enter something more sensible.");
      is.clear();
      is.ignore(255, '\n');
   }
}
