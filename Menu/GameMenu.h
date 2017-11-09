/// \date 21/10/2017
/// \author Tomas Rigaux
///
/// This is an abstract class. It is a subclass of Menu, and it will define the
/// minimal functions that are required by the subclasses of GameMenu.

#include "Menu.h"
#include <map>
using namespace std;

#ifndef GAMEMENU_H
#define GAMEMENU_H

/// \class GameMenu GameMenu.h
/// \brief An abstract class, this is the base class for the all the in-game
/// menu classes. It requires less member functions than Menu.
class GameMenu : public Menu
{
public:
  /// This is the default constructor.
  GameMenu() {}

  /// This function sets the specific options for the Menu type.
  /// \param[in] OptionsList A map of all the options for the current
  /// menu. Each option has a unique key to make input easier.
  /// \param[in] type This denotes the type of menu to display.
  virtual void SetOptions(map<int,string> OptionsList, int row, int col) = 0;
  /// This function handles the input for the menu options.
  /// \param[in,out] is The in-stream operator to read the input.
  virtual void HandleInput(istream &is) = 0;
};

#endif
