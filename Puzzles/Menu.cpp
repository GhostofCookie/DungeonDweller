#include <iostream>
#include "Menu.h"

Menu::Menu(int height, int width)
	: MenuHeight{ height }, MenuWidth{ width }, Menu_Array{ new char*[height] }
{
	for (int i = 0; i < height; i++)
	{
		Menu_Array[i] = new char[width];
		for (int j = 0; j < MenuWidth; j++)
			set(i, j, ' ');
	}
}

Menu::~Menu()
{

}

void Menu::HandleOptionInput(istream& is)
{

	int option;
	is >> option;
	auto it = IndexMap.begin();
	while (it != IndexMap.end()) {
		if (option != it->first)
			++it;
		else
			cout << "You have selected" << it->second;
	}

}

void Menu::SetOptions(map<int, string> OptionsList, string type)
{
	auto it = OptionsList.begin();
	int row = 3;
	int col = 3;
	if (type == "generic")
	{
		while (it != OptionsList.end())
		{

			for (unsigned int j = 0; j < it->second.length(); j++)
				set(row, col + j, it->second[j]);

			row += 2;
			if (row >= MenuHeight - 1)
			{
				col += it->second.length() + 10;
				row = 3;
			}
			++it;
		}
		it = OptionsList.begin();
	}
	else if (type == "dialogue")
	{
		while (it != OptionsList.end())
		{
			for (unsigned int i = 0; i < it->second.length(); i++)
				set(row, col + i, it->second[i]);
			++it;
			row += 1;
		}
		it = OptionsList.begin();
	}
}

void Menu::OutputMenu()
{
	BuildMenu();

	for (int i = 0; i < MenuHeight; i++)
	{
		for (int j = 0; j < MenuWidth; j++)
			cout << Menu_Array[i][j];
		cout << '\n';
	}
}

// Helper Functions
void Menu::set(int x, int y, char ch)
{
	Menu_Array[x][y] = ch;
}

void Menu::BuildMenu()
{
	SetOptions(IndexMap);
	// Builds the outline of the menu.
	for (int i = 0; i < MenuHeight; i++)
		for (int j = 0; j < MenuWidth; j++)
		{
			set(0, j, '=');
			set(i, 0, '|');
			set(i, MenuWidth - 1, '|');
			set(MenuHeight - 1, j, '=');
		}
	// Sets the corners of the menu.
	set(0, 0, '+');
	set(MenuHeight - 1, MenuWidth - 1, '+');
	set(0, MenuWidth - 1, '+');
	set(MenuHeight - 1, 0, '+');
}
