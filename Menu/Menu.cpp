#include <iostream>
#include "Menu.h"
using namespace std;

Menu::Menu(int height, int width)
   : menuHeight{ height }, menuWidth{ width }, menu_Array{ new char*[height]}
{
   for (int i = 0; i < height; i++)
   {
      menu_Array[i] = new char[width];
      for (int j = 0; j < menuWidth; j++)
	 set(i, j, ' ');
   }
}

Menu::~Menu()
{
   for (int i = 0; i < menuWidth; i++)
      delete[] menu_Array[i];
   delete menu_Array;
}

void Menu::HandleInput(istream& is)
{
   char option;
   is >> option;
   if(indexMap.find(option) != indexMap.end())
      optionMap.find(option)->second;
//      cout << "You have selected "<<indexMap[static_cast<int>(option)]<<endl;
	
  
}

void Menu::AddOption(char command, string optionName, void (*f)(int))
{
   indexMap[static_cast<int>(command)] = optionName;
   optionMap[command] = f;
}

void Menu::SetOptions(map<int, string> optionsList, int row, int col)
{
   auto it = optionsList.begin();
   indexMap = optionsList;
   string tempName;
   while (it != optionsList.end())
   {
      tempName+= '[';
      tempName+= it->first;
      tempName+=']';
      tempName+=it->second+' ';
      for (unsigned int j = 0; j < tempName.length(); j++)
	 set(row, col + j, tempName[j]);
      row += 2;
      if (row >= menuHeight - 1)
      {
	 col += it->second.length() + 10;
	 row = 3;
      }
      ++it;
   }
   it = optionsList.begin();
}

void Menu::OutputMenu()
{
   BuildMenu();

   for (int i = 0; i < menuHeight; i++)
   {
      for (int j = 0; j < menuWidth; j++)
	 cout << menu_Array[i][j];
      cout << '\n';
   }
}

// Helper Functions
void Menu::set(int x, int y, char ch)
{
   menu_Array[x][y] = ch;
}

void Menu::BuildMenu()
{
   SetOptions(indexMap);
   // Builds the outline of the menu.
   for (int i = 0; i < menuHeight; i++)
      for (int j = 0; j < menuWidth; j++)
      {
	 set(0, j, '=');
	 set(i, 0, '|');
	 set(i, menuWidth - 1, '|');
	 set(menuHeight - 1, j, '=');
      }
   // Sets the corners of the menu.
   set(0, 0, '+');
   set(menuHeight - 1, menuWidth - 1, '+');
   set(0, menuWidth - 1, '+');
   set(menuHeight - 1, 0, '+');
}
