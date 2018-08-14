/// \author Tomas Rigaux
/// \date 21/10/2017
///
/// This is the Menu class. It handles the complicated inner workings of all
/// menus.
///

#include <iostream>
#include "Menu.h"


/// This is the constructor. It initializes a multi-dimensional array
/// to dimensions height*width.
/// \param[in] height This is the height of the menu.
/// \param[in] width This is the width of the menu.
Menu::Menu(int height, int width)
   : menu_Array{ new char *[height] }, currOption{' '}, menuHeight{ height }, menuWidth{ width }
{
   for (int i = 0; i < height; i++)
   {
      menu_Array[i] = new char[width];
      for (int j = 0; j < menuWidth; j++)
	 Set(i, j, ' ');
   }
}

/// This is the destructor for the class. It is virtual.
Menu::~Menu()
{
   for (int i = 0; i < menuHeight; i++)
      delete[] menu_Array[i];
   delete[] menu_Array;
}

/// Handles the user input, and runs an option from the menu.
/// \param[in,out] is The in-stream operator to read the input.
void Menu::HandleInput( std::istream& is)
{
   char option;
   std::cout << "-> ";
   is >> option;
   is.clear();
   is.ignore(255, '\n');

   auto it = indexMap.find(tolower(option));
   if(it != indexMap.end())
      currOption = tolower(option);
   else
   {
      currOption = '\n';
      return;
   }
   if(is.fail())
   {
      throw std::invalid_argument("Invalid input. Please enter something more sensible.");
      is.clear();
      is.ignore(255, '\n');
   }
}

/// Adds an option with a character for the user to call, a name to 
/// display, and function to run.
/// \param[in] command The character for the user to input.
/// \param[in] optionName The name to display for the user.
void Menu::AddOption(char command, std::string optionName)
{
   auto it = indexMap.find(command);
   if(it->first != command)
      indexMap[static_cast < int > (tolower(command))] = optionName;
   else return;
}

char Menu::GetOption() const
{
   return currOption;
}
/// A function to set the added options to the character array.
/// \param[in] row Determines which row the options will start being set at.
/// \param[in] col Determines which column the options will start from.
/// \param[in] How much space inbetween rows.
void Menu::SetOptions(int row, int col, int space)
{
   auto it = indexMap.begin();
   std::string tempName;
   int origRow = row;
  
   while (it != indexMap.end())
   {
      tempName += '['; tempName += it->first;
      tempName += ']';tempName += it->second;
      for (unsigned int j = 0; j < tempName.length(); j++)
      {
	 if(it->first != 113) Set(row, col + j, tempName[j]);
	 else Set(menuHeight - 3, menuWidth / 2 + j - tempName.length() / 2
		  , tempName[j]);
      }
      if(it->first != 113) row += space;
      if (row >= menuHeight - 1)
      {
	 row = origRow;
	 col += it->second.length() + menuWidth / 4 + 1;
      }
      ++it;
      tempName = "";
   }
   it = indexMap.begin();
}

/// Display the multi-dimensional array.
void Menu::OutputMenu()
{
   BuildMenu();

   for (int i = 0; i < menuHeight; i++)
   {
      for (int j = 0; j < menuWidth; j++)
	 std::cout << menu_Array[i][j];
      std::cout << '\n';
   }
}

// Helper Functions
/// Sets the character of a specific location in the array to a give
/// character.
/// \param[in] x This is the x-coordinate of the multi-dimensional
/// array. (A[x,y])
/// \param[in] y This is the y-coordinate of the multi-dimensional
/// array. (A[x,y])
/// \param[in] ch This is the character to be set at the coordinates
/// (x,y) in the multi-dimensional array.
void Menu::Set(int x, int y, char ch)
{
   if( x < menuHeight && y < menuWidth )
      menu_Array[x][y] = ch;
}

/// Builds the menu based on the options and outline to the dimensions
/// specified by the constructor.
void Menu::BuildMenu()
{
  for(int i = 0; i < menuHeight; i++)
    for(int j = 0; j <menuWidth; j++)
      Set(i, j, ' ');
   SetOptions();
   // Builds the outline of the menu.
   for (int i = 0; i < menuHeight; i++)
      for (int j = 0; j < menuWidth; j++)
      {
	 Set(0, j, '=');
	 Set(i, 0, '|');
	 Set(i, menuWidth - 1, '|');
	 Set(menuHeight - 1, j, '=');
      }
   // Sets the corners of the menu.
   Set(0, 0, '+');
   Set(menuHeight - 1, menuWidth - 1, '+');
   Set(0, menuWidth - 1, '+');
   Set(menuHeight - 1, 0, '+');
}
