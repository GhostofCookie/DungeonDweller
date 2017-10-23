/// /date 21/10/2017
/// /author Tomas Rigaux
///
/// This class is derived from the GameState abstract class. It sets the state of the game.
///

#include "GameState.h"
#include "Menu.h"

#ifndef MAINSTATE_H
#define MAINSTATE_H

class MainState : public GameState
{
	/// \class MainState MainState.h
	/// \brief This is the state of the game when the game is either not yet started or the game has ended.
public:
	/// Default constructor
	MainState();
	/// Sets the layout of the game.
	void Set();
	/// Outputs the set layout.
	void Get();
};
};

#endif