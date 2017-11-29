/// \date 24/10/2017
/// \author Tomas Rigaux
///
/// This is the implementation for the menu class for the Riddle minigame.
///

#include "RiddleMenu.h"

/// This is the default constructor.
RiddleMenu::RiddleMenu()
{
}

/// This is the virtual destructor.
RiddleMenu::~RiddleMenu()
{
}

/// This function sets the specific options for the Menu type.
/// \param[in] row Determines which row the options will start being set at.
/// \param[in] col Determines which column the options will start from.
/// \param[in] How mush space inbetween rows.
void RiddleMenu::SetOptions(int row, int col, int space)
{
   int mark = 0;
   string query_P1, query_P2;
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

/// This function handles the input for the menu options.
/// \param[in,out] is The in-stream operator to read the input.
void RiddleMenu::HandleInput(istream & is)
{
   int y;
   cout << "-> ";
   is >> y;
   is.clear();
   is.ignore(255, '\n');

   if(is.fail())
   {
      query = "Incorrect.";
      return;
      is.clear();
      is.ignore(255, '\n');
      throw invalid_argument("Invalid input. please enter coordinates in format A1.");
   }
   else
      input = y;

}
