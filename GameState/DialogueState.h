/// \date 21/10/2017
/// \author Tomas Rigaux
///
/// This class defines thestate of the game qwhen the player character is
/// interacting with an NPC in dialogue.
///

#pragma once

#include "GameState.h"

/// \class DialogueState DialogueState.h
/// \brief This is the state of the game when the player character is engaged in
/// dialogue with an NPC. Derived from GameState.
class DialogueState : public GameState
{
  public:
   /// This is the default constructor.
   DialogueState();
   /// Sets the layout of the game.
   void Set();
   /// Gets the payout of the game.
   void Get();
};
