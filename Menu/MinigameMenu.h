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
  /// This function sets the specific options for the minigame.
  /// \param[in] row Determines which row the options will start being set at.
  /// \param[in] col Determines which column the options will start from.
  /// \param[in] How mush space inbetween rows.
  virtual void SetOptions(int row, int col, int space) = 0;
  /// This function handles the input for the menu options.
  /// \param[in,out] is The in-stream operator to read the input.
  virtual void HandleInput(istream &is) = 0;

};

#endif
