#include "TicTacToeMenu.h"

TicTacToeMenu::TicTacToeMenu()
{
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
   Menu::HandleInput(is);
}
