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
	/// Builds the menu based on the options and outline to the dimensions specified by the constructor.
	void BuildMenu();

protected:
	/// Sets the character of a specific location in the array to a give character.
	/// \param[in] x This is the x-coordinate of the multi-dimensional array. (A[x,y])
	/// \param[in] y This is the y-coordinate of the multi-dimensional array. (A[x,y])
	/// \param[in] ch This is the character to be set at the coordinates (x,y) in the multi-dimensional array.
	void set(int x, int y, char ch);
	/// Sets the various options for the menu, mapping them to unique keys to make handling easier.
	/// \param[in] OptionsList A map of all the options for the current menu. Each option has a unique key to make input easier.
	/// \param[in] type This denotes the type of menu to display.
public:
		/// This is the constructor. It initializes a multi-dimensional array to dimensions height*width.
	/// \param[in] height This is the height of the menu.
	/// \param[in] width This is the width of the menu.
	Menu(int height = 10, int width = 100);
	/// This is the destructor for the class. It is virtual.
	virtual ~Menu();
	virtual void SetOptions(map<int, string> OptionsList, string type = "generic");
	/// Handles the user input, and runs an option from the menu.
	/// \param[in,out] is The in-stream operator to read the input.
	virtual void HandleOptionInput(istream& is);
	/// Display the multi-dimensional array.
	virtual void OutputMenu();
};

#endif
