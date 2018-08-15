/// \date 21/10/2017
/// \author Tomas Rigaux
///
/// This is the menu for the player to use when they are either not in the game or have died and need to restart or quit.

#pragma once

#include "GameMenu.h"
#include <map>

/// \class MainMenu MainMenu.h
/// \brief This is the menu for the player to use when they are either not in the game or have died and need to restart or quit.
class MainMenu : public virtual GameMenu
{
public:
  /// This is the default constructor.
  MainMenu(int height = 33);

  /// This function sets the specific options for the Menu type.
  /// \param[in] OptionsList A std::map of all the options for the current
  /// menu. Each option has a unique key to make input easier.
  /// \param[in] type This denotes the type of menu to display.
  virtual void SetOptions(int row, int col, int space);
  /// This function handles the input for the menu options.
  /// \param[in,out] is The in-stream operator to read the input.
  virtual void HandleInput( std::istream &is);

  private:
  Menu *menu;
};
