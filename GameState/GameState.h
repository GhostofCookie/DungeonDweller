/// \date 21/10/2017
/// \author Tomas Rigaux
///
/// This class defines the current state of the game, based on the current
/// location and actions of the player character.
///

#include "../Menu/Menu.h"
#include "../Screen/Screen.h"
#include "../Screen/SlotScreen.h"
#include "../Menu/MainMenu.h"
#include "../Menu/FightMenu.h"
#include "../Menu/ExploreMenu.h"

#ifndef GAMESTATE_H
#define GAMESTATE_H

class GameState
{
  /// \class GameState GameState.h
  /// \brief An abstract class, this class defines the state of the current 'state' of the game based 
  /// on the current situation of the player character.
 public:
  /// Default constructor
  GameState(){}
  /// Default destructor
  virtual ~GameState(){}
  /// Sets the layout of the game.
  virtual void Set() = 0;
  /// Outputs the set layout.
  virtual void Get() = 0;

 protected:
  Menu *menu; ///< pointer to the menu.
  Screen *screen; ///< pointer to the screen;
};

#endif
