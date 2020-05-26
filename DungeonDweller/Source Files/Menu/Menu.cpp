/** @author Tomas Rigaux
 * @date 21/10/2017
 *
 * This is the Menu class. It handles the complicated inner workings of all
 * menus.
 */

#include "Menu.h"
#include "Screen.h"
#include <iostream>
#include <conio.h>

Menu::Menu(int height, int width)
	: menu_Array{ new char* [height] }, currOption{ ' ' }, menuHeight{ height }, menuWidth{ width }
{
	for (int i = 0; i < height; i++)
	{
		menu_Array[i] = new char[width];
		for (int j = 0; j < menuWidth; j++)
			Set(i, j, ' ');
	}
}

Menu::~Menu()
{
	for (int i = 0; i < menuHeight; i++)
		delete[] menu_Array[i];
	delete[] menu_Array;
}

void Menu::HandleInput(std::istream& is)
{
	char option = _getch();
	auto it = indexMap.find(tolower(option));
	if (it != indexMap.end())
		currOption = tolower(option);
	else
	{
		currOption = '\n';
		return;
	}
}

void Menu::AddOption(char command, std::string optionName)
{
	auto it = indexMap.find(command);
	if (it == indexMap.end() || it->first != command)
		indexMap[static_cast <int> (tolower(command))] = optionName;
	else return;
}

char Menu::GetOption() const
{
	return currOption;
}

void Menu::SetOptions(int row, int col, int space)
{
	auto it = indexMap.begin();
	std::string tempName;
	int origRow = row;

	while (it != indexMap.end())
	{
		tempName += '['; tempName += it->first;
		tempName += ']'; tempName += it->second;
		for (unsigned int j = 0; j < tempName.length(); j++)
		{
			if (it->first != 113) Set(row, col + j, tempName[j]);
			else Set(menuHeight - 3, menuWidth / 2 + j - static_cast<int>(tempName.length()) / 2, tempName[j]);
		}
		if (it->first != 113) row += space;
		if (row >= menuHeight - 1)
		{
			row = origRow;
			col += static_cast<int>(it->second.length()) + menuWidth / 4 + 1;
		}
		++it;
		tempName = "";
	}
	it = indexMap.begin();
}

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

/******************************************************************************
 * Helper Functions
 *****************************************************************************/
void Menu::Set(int x, int y, char ch)
{
	if (x < menuHeight && y < menuWidth)
		menu_Array[x][y] = ch;
}

void Menu::BuildMenu()
{
	for (int i = 0; i < menuHeight; i++)
		for (int j = 0; j < menuWidth; j++)
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
