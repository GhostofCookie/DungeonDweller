#include "TicTacToeMenu.h"

TicTacToeMenu::TicTacToeMenu()
{
   coordinates.x = ' ';
   coordinates.y = 1;
   indexMap.clear();
   indexMap.erase('q');
   query = "Enter coordinates (e.g. A1)";
}

TicTacToeMenu::~TicTacToeMenu()
{
}

void TicTacToeMenu::SetOptions(int row, int col, int space)
{
   for(int i = 0; i < menuWidth-2; i++)
      Set(menuHeight/2-1,i, ' ');
   for(unsigned int i = 0; i < query.length(); i++)
      Set(menuHeight/2-1,menuWidth/2 - query.length()/2-1+i, query[i]);
}

void TicTacToeMenu::HandleInput(istream & is)
{
   char x;
   int y;
   cout << "-> ";
   is>>x>>y;
   is.clear();
   is.ignore(255,'\n');
   if((tolower(x) >= 'a' && tolower(x) < 'd') && (y > 0 && y < 4))
   {
      coordinates.x = x;
      coordinates.y = y;
      query = "Enter coordinates (e.g. A1)";
   }
   else 
   {
      query = "Invalid coordinates. Please ensure that your query is between A1 and C3";
      is.clear();
      is.ignore(255,'\n');
   }
   if(is.fail())
      throw invalid_argument("Invalid input. please enterr coordinates in format A1.");
   
}

TicTacToeMenu::Coord TicTacToeMenu::GetCoordinates() const
{
   return coordinates;
}
