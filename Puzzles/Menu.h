/// /date 21/10/2017
/// /author Tomas Rigaux
///
/// This is the Menu class. It handles the complicated inner workings of all menus.
///

#include <iostream>
#include <map>
#include <vector>
using namespace std;

#ifndef MENU_H
#define MENU_H

class Menu 
/// \class Menu Menu.h
/// \brief This is the base class for all menus for the main game.
{
private:
	map<int, string> IndexMap;
	int MenuHeight;
	int MenuWidth;
	char **Menu_Array;
	void BuildMenu();

public:
	/// This is the constructor. It initializes a multi-dimensional array to dimensions height*width.
	Menu(int height = 10, int width = 100);
	/// This is the destructor for the class. It is virtual.
	virtual ~Menu();
	/// Sets the character of a specific location in the array to a give character.
	void set(int x, int y, char ch);
	/// Sets the various options for the menu, mapping them to unique keys to make handling easier.
	virtual void SetOptions(map<int, string> OptionsList, string type = "generic");
	/// Handles the user input, and runs an option from the menu.
	virtual void HandleOptionInput(istream& is);
	/// Display the multi-dimensional array.
	virtual void OutputMenu();
};

#endif
