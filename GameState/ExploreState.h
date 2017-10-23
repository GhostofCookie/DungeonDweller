/// /date 21/10/2017
/// /author Tomas Rigaux
///
/// This is the state of the game when a player is exploring.
///

#include "GameState.h"
#include "Menu.h"

#ifndef EXPLORESTATE_H
#define EXPLORESTATE_H

class ExploreState : public GameState
{
public:
	ExploreState();
	void Set();
};

#endif