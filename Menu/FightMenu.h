/// \date 21/10/2017
/// \author Tomas Rigaux
///
/// This is the fight class. This is the menu for the player to use when they are engaged in combat.

#include "GameMenu.h"
#include <map>
using namespace std;

#ifndef FIGHTMENU_H
#define FIGHTMENU_H

/// \class FightMenu FightMenu.h
/// \brief This is the menu for the player to use when they are engaged in combat.
class FightMenu : public GameMenu
{
public:
	/// This is the default constructor.
	FightMenu();
	/// This is the virtual destructor.
	virtual ~FightMenu();
	/// This function sets the specific options for the Menu type.
	/// \param[in] OptionsList A map of all the options for the current
	/// menu. Each option has a unique key to make input easier.
	/// \param[in] type This denotes the type of menu to display.
	virtual void SetOptions(map<int,string> OptionsList, string type);
	/// This function handles the input for the menu options.
	/// \param[in,out] is The in-stream operator to read the input.
	virtual void HandleInput(istream &is);
};

#endif
