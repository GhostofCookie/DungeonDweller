/** @date 21/10/2017
 * @author Tomas Rigaux
 *
 * This is the fight class. This is the menu for the player to use when they are engaged in
 * combat.
 */

#include "FightMenu.h"

FightMenu::FightMenu()
{
}

FightMenu::~FightMenu()
{
}

void FightMenu::SetOptions(int row, int col, int space)
{
   std::map<int,std::string> optionList = indexMap;
   int width = menuWidth;
   auto it = optionList.begin();
   int value = 1, count=0;
   std::string temp;
   row -= 1;
   while(it!=optionList.end()) 
   {
      if(optionList.size() > 9)
	 throw std::invalid_argument("Too many menu options. Max is 9 for FightMenu.");
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

void FightMenu::HandleInput( std::istream & is)
{
   Menu::HandleInput(is);
}
