/// \date 24/10/2017
/// \author Tomas Rigaux
///
/// This is an abstract class. It is a subclass of GameMenu.

#include "GameMenu.h"
#include <map>
using namespace std;

#ifndef MINIGAMEMENU_H
#define MINIGAMEMENU_H

/// \class MinigameMenu MinigameMenu.h
/// \brief An abstract class, this is the base class for the all the in-game
/// puzzle/minigame menu classes.
class MinigameMenu : public GameMenu
{
 public:
  /// This is the default constructor.
  MinigameMenu(){}
  /// This is the virtual destructor.
  virtual ~MinigameMenu(){}
  /// This function sets the specific options for the Menu type.
  /// \param[in] OptionsList A map of all the options for the current
  /// menu. Each option has a unique key to make input easier.
  /// \param[in] type This denotes the type of menu to display.
  virtual void SetOptions(map<int,string> optionsList, string type="minigame") = 0;
  /// This function handles the input for the menu options.
  /// \param[in,out] is The in-stream operator to read the input.
  virtual void HandleInput(istream &is) = 0;

};

#endif
