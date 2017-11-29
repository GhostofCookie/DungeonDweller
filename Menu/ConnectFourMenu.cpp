/// \date 24/10/2017
/// \author Tomas Rigaux
///
/// This is the implementationmenu class for the Connect Four minigame.
///

#include "ConnectFourMenu.h"

/// This is the default constructor.
ConnectFourMenu::ConnectFourMenu()
{
   column = 0;
   indexMap.clear();
   indexMap.erase('q');
   query = "Select a column to place your piece";
}

/// This is the virtual destructor.
ConnectFourMenu::~ConnectFourMenu()
{
}

/// This function sets the specific options for the Menu type.
/// \param[in] row Determines which row the options will start being set at.
/// \param[in] col Determines which column the options will start from.
/// \param[in] How mush space inbetween rows.
void ConnectFourMenu::SetOptions(int row, int col, int space)
{
   for(int i = 0; i < menuWidth-2; i++)
      Set(menuHeight / 2 - 1, i, ' ');
   for(unsigned int i = 0; i < query.length(); i++)
      Set(menuHeight / 2 - 1, menuWidth / 2 - query.length() / 2 - 1 + i
	  , query[i]);
}

/// This function handles the input for the menu options.
/// \param[in,out] is The in-stream operator to read the input.
void ConnectFourMenu::HandleInput(istream & is)
{
   int x;
   cout << "-> ";
   is >> x;
   is.clear();
   is.ignore(255,'\n');
   if(x < 8 && x > 0)
   {
      column = x;
      query = "Select a column to place your piece";
   }
   else 
   {
      query = "Invalid column number. Please enter a number from 1-7";
      column = 0;
      is.clear();
      is.ignore(255, '\n');
   }
   if(is.fail())
   {
      throw invalid_argument("Invalid input. please enter a signle number from 1-7.");
      is.clear();
      is.ignore(255, '\n');
   }
}
