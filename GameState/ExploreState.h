/// \date 21/10/2017
/// \author Tomas Rigaux
///
/// This is the state of the game when a player is exploring.
///

#include "GameState.h"

#ifndef EXPLORESTATE_H
#define EXPLORESTATE_H

/// \class ExploreState ExploreState.h
/// \brief This is defines the state of the game when the player character is
/// exploring rooms. Derived from GameState.
class ExploreState : public GameState
{
  public:
   /// This is the the default constructor.
   ExploreState();
   /// Sets the layout for the game menu and screen.
   void Set();
   /// Gets the layout for the game menu and screen.
   void Get();
};

#endif
