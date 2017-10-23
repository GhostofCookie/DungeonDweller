/// \date 21/10/2017
/// \author Tomas Rigaux
///
/// This is an abstract class. It is a subclass of Menu, and it will define the minimal functions that are required by the subclasses of
/// GameMenu.

#include "Menu.h"
#include <map>
using namespace std;

#ifndef GAMEMENU_H
#define GAMEMENU_H

class GameMenu : public Menu
{
public:
	/// This is the default constructor.
	GameMenu();
	/// This is the virtual destructor.
	virtual ~GameMenu();
	/// This function sets the specific options for the Menu type.
	virtual void SetOptions(map<string> OptionsList, string type) = 0;
	/// This function handles the input for the menu options.
	virtual void HandleInput(istream &is) = 0;

};

#endif