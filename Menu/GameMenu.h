/// \date 21/10/2017
/// \author Tomas Rigaux
///
/// This is an abstract class. It is a subclass of Menu, and it will define the
/// minimal functions that are required by the subclasses of GameMenu.

#include "Menu.h"
#include <map>


#ifndef GAMEMENU_H
#define GAMEMENU_H

/// \class GameMenu GameMenu.h
/// \brief An abstract class, this is the base class for the all the in-game
/// menu classes. It requires less member functions than Menu.
class GameMenu : public Menu
{
public:
  /// This is the default constructor.
  GameMenu(int height = 10): Menu(height) {}

  /// This function sets the specific options for the Menu type. It is pure virtual
  /// \param[in] row Determines which row the options will start being set at.
  /// \param[in] col Determines which column the options will start from.
  /// \param[in] How mush space inbetween rows.
  virtual void SetOptions(int row, int col, int space) = 0;
  /// This function handles the input for the menu options.
  /// \param[in,out] is The in-stream operator to read the input.
  virtual void HandleInput( std::istream &is) = 0;
};

#endif
