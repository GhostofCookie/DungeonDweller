/// /date 21/10/2017
/// /author Tomas Rigaux
///
/// This is the state of the game when the player is trading with an NPC character.
///

#include "GameState.h"

#ifndef TRADESTATE_H
#define TRADESTATE_H

class TradeState : public GameState
{
	/// \class TradeState TradeState.h
	/// \brief Sets the state of the game when a player is 'trading' with an NPC
public:
	/// Default constructor
	TradeState();
	/// Sets the layout of the game.
	void Set();
	/// Outputs the set layout.
	void Get();
};

#endif