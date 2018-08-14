/// \date 21/10/2017
/// \author Tomas Rigaux
///
/// This is the state of the game when the player is trading with an NPC
/// character.
///

#include "GameState.h"

#pragma once

class TradeState : public GameState
{
   /// \class TradeState TradeState.h
   /// \brief Sets the state of the game when a player is 'trading' with an NPC.
   /// Derived from GameState.
  public:
   /// Default constructor
   TradeState(Player *p);
   /// Default destructor.
   virtual ~TradeState();
   /// Sets the layout of the game.
   void Set();
   /// Outputs the set layout.
   void Get();
};

