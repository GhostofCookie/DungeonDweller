/// /date 21/10/2017
/// /author Tomas Rigaux
///
/// This is the state of the game when a player character is engaged in combat.
///

#include "GameState.h"

#ifndef FIGHTSTATE_H
#define FIGHTSTATE_H

class FightState : public GameState
{
	/// \class FightState FIghtState.h
	/// \brief This is the state of the game when the player character is engaged in combat.
public:
	/// This is the default constructor.
	FightState();
	/// Sets the layout of the game.
	Set();
	/// Outpouts the layout of the game.
	Get();
};

#endif