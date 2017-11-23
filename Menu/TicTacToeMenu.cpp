#include "TicTacToeMenu.h"

TicTacToeMenu::TicTacToeMenu()
{
  coordinates.x = ' ';
  coordinates.y = 1;
}

TicTacToeMenu::~TicTacToeMenu()
{
}

void TicTacToeMenu::SetOptions(int row, int col, int space)
{
   Menu::SetOptions(row,col,space);
}

void TicTacToeMenu::HandleInput(istream & is)
{
  char x;
  int y;
  cout << "Enter coordinates (e.g. A1)-> ";
  is>>x>>y;
  is.clear();
  is.ignore(255,'\n');
  if((tolower(x) >= 'a' && tolower(x) < 'd') && (y > 0 && y < 4))
    {
      coordinates.x = x;
      coordinates.y = y;
    }
  if(x == 'q')
    QuitGame(0);
  if(is.fail())
    throw invalid_argument("Invalid input. please enterr coordinates in format A1.");
   
}

TicTacToeMenu::Coord TicTacToeMenu::GetCoordinates() const
{
  return coordinates;
}
