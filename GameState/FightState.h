/// \date 21/10/2017
/// \author Tomas Rigaux
///
/// This is the state of the game when a player character is engaged in combat.
///

#pragma once

#include "GameState.h"

class FightState : public GameState
{
   /// \class FightState FIghtState.h
   /// \brief This is the state of the game when the player character is
   /// engaged in combat. Derived from GameState.
  public:
   /// This is the default constructor.
   FightState(Player *p);
   /// Sets the layout of the game.
   void Set();
   /// Outpouts the layout of the game.
   void Get();
};

