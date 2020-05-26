/** @date 24/10/2017
 * @author Tomas Rigaux
 *
 * This is the implementation for the menu class for the Riddle minigame.
 */

#include "RiddleMenu.h"

RiddleMenu::RiddleMenu()
{
}

RiddleMenu::~RiddleMenu()
{
}

void RiddleMenu::SetOptions(int row, int col, int space)
{
   int mark = 0;
   std::string query_P1, query_P2;
   if(query.length() > 98)
   {
      for(int i = 0 ; i < 99; i++)
      {
	 if(query[i] == ' ')
	    mark = i;
	 query_P1 = query[i];
	 if(query_P1.length() == 98)
	 {
	    query_P2[mark] = query[mark];
	    mark++;
	 }
      }
      
   }
   for(int i = 0; i < menuWidth - 2; i++)
      Set(menuHeight / 2 - 1, i, ' ');
   for(unsigned int i = 0; i < query.length(); i++)
   {
      Set(menuHeight / 2 - 1, menuWidth / 2 - query.length() / 2 - 1 + i
	  , query_P1[i]);
   }
}

void RiddleMenu::HandleInput( std::istream & is)
{
   int y;
   std::cout << "-> ";
   is >> y;
   is.clear();
   is.ignore(255, '\n');

   if(is.fail())
   {
      query = "Incorrect.";
      return;
      is.clear();
      is.ignore(255, '\n');
      throw std::invalid_argument("Invalid input. please enter coordinates in format A1.");
   }
   else
      input = y;

}
