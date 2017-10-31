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

void Menu::HandleOptionInput(istream& is)
{
  int option;
  is >> option;
  auto it = indexMap.begin();
  while (it != indexMap.end()) {
    if (option != it->first)
      ++it;
    else
      std::cout << "You have selected" << it->second;
  }
}

void Menu::SetOptions(map<int, string> optionsList, string type)
{
  auto it = optionsList.begin();
  int row = 3;
  int col = 3;
  if (type == "generic")
    {
      while (it != optionsList.end())
	{
	  for (unsigned int j = 0; j < it->second.length(); j++)
	    set(row, col + j, it->second[j]);

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
  else if (type == "dialogue")
    {
      while (it != optionsList.end())
	{
	  for (unsigned int i = 0; i < it->second.length(); i++)
	    set(row, col + i, it->second[i]);
	  ++it;
	  row += 1;
	}
      it = optionsList.begin();
    }
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
