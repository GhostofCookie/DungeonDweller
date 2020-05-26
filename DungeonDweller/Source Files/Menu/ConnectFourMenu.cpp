/** @date 24/10/2017
 * @author Tomas Rigaux
 *
 * This is the implementationmenu class for the Connect Four minigame.
 */

#include "ConnectFourMenu.h"

ConnectFourMenu::ConnectFourMenu()
{
   column = 0;
   indexMap.clear();
   indexMap.erase('q');
   query = "Select a column to place your piece";
}

ConnectFourMenu::~ConnectFourMenu()
{
}

void ConnectFourMenu::SetOptions(int row, int col, int space)
{
   for(int i = 0; i < menuWidth-2; i++)
      Set(menuHeight / 2 - 1, i, ' ');
   for(unsigned int i = 0; i < query.length(); i++)
      Set(menuHeight / 2 - 1, menuWidth / 2 - query.length() / 2 - 1 + i
	  , query[i]);
}

void ConnectFourMenu::HandleInput(std::istream & is)
{
   int x;
   std::cout << "-> ";
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
      throw std::invalid_argument("Invalid input. please enter a signle number from 1-7.");
      is.clear();
      is.ignore(255, '\n');
   }
}
