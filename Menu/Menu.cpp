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
	 Set(i, j, ' ');
   }
   AddOption('q',"Quit",exit);
}

Menu::~Menu()
{
   for (int i = 0; i < menuHeight; i++)
      delete[] menu_Array[i];
   delete[] menu_Array;
}

void Menu::HandleInput(istream& is)
{
   char option;
   int item =1;
   cout<<"-> ";
   is >> option;
   if(optionMap.find(option) != optionMap.end())
      optionMap.find(option)->second(item);
   if(is.fail())
      throw invalid_argument("Invalid input. Please enter something more sensible.");
}

void Menu::AddOption(char command, string optionName, void (*f)(int))
{
   indexMap[static_cast<int>(command)] = optionName;
   optionMap[command] = f;
}

void Menu::SetOptions(int row,int col,int space)
{
   auto it = indexMap.begin();
   string tempName;
   int origRow = row;
  
   while (it != indexMap.end())
   {
      tempName+='[';tempName+=it->first;tempName+=']';tempName += it->second;
      for (unsigned int j = 0; j < tempName.length(); j++)
      {
	 if(it->first!=113) Set(row,col+j,tempName[j]);
	 else Set(menuHeight-3, menuWidth/2 +j- tempName.length()/2,tempName[j]);
      }
      if(it->first != 113) row += space;
      if (row >= menuHeight - 1)
      {
	 row = origRow;
	 col += it->second.length() + menuWidth/4+1;
      }
      ++it;
      tempName="";
   }
   it = indexMap.begin();
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
void Menu::Set(int x, int y, char ch)
{
   menu_Array[x][y] = ch;
}

void Menu::BuildMenu()
{
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

void Menu::QuitGame(int value)
{
   char ch;
   cout<<"Are you sure you want to quit(y/n)? ";
   cin>>ch;
   if(ch=='y') exit(value);
   else return;
}
