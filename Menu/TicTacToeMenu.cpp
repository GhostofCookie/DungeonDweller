/// \date 24/10/2017
/// \author Tomas Rigaux
///
/// This is the implementation for the menu class for the Tic Tac Toe minigame.

#include "TicTacToeMenu.h"

/// This is the default constructor.
TicTacToeMenu::TicTacToeMenu()
{
   coordinates.x = ' ';
   coordinates.y = 1;
   indexMap.clear();
   indexMap.erase('q');
   query = "Enter coordinates (e.g. A1)";
}

/// This is the virtual destructor.
TicTacToeMenu::~TicTacToeMenu()
{
}

/// This function sets the specific options for the Menu type.
/// \param[in] row Determines which row the options will start being set at.
/// \param[in] col Determines which column the options will start from.
/// \param[in] How mush space inbetween rows.
void TicTacToeMenu::SetOptions(int row, int col, int space)
{
   for(int i = 0; i < menuWidth - 2; i++)
      Set(menuHeight / 2 - 1, i, ' ');
   for(unsigned int i = 0; i < query.length(); i++)
      Set(menuHeight / 2 - 1, menuWidth / 2 - query.length() / 2 - 1 + i, query[i]);
}

/// This function handles the input for the menu options.
/// \param[in,out] is The in-stream operator to read the input.
void TicTacToeMenu::HandleInput(istream & is)
{
   char x;
   int y;
   cout << "-> ";
   is >> x >> y;
   is.clear();
   is.ignore(255, '\n');
   if((tolower(x) >= 'a' && tolower(x) < 'd') && (y > 0 && y < 4))
   {
      coordinates.x = x;
      coordinates.y = y;
      query = "Enter coordinates (e.g. A1)";
   }
   else 
   {
      query = "Invalid coordinates. Please ensure that your query is between A1 and C3";
      coordinates.x = ' ';
      coordinates.y = 0;
   }
   if(is.fail())
      throw invalid_argument("Invalid input. please enter coordinates in format A1.");
   
}

/// This function returns the coordinates the player entered.
TicTacToeMenu::Coord TicTacToeMenu::GetCoordinates() const
{
   return coordinates;
}
