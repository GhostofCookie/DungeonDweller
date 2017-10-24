/// /date 21/10/2017
/// /author Tomas Rigaux
///
/// This class defines thestate of the game qwhen the player character is interacting with an NPC in dialogue.
///

#include "GameState.h"

#ifndef DIALOGUESTATE_H
#define DIALOGUESTATE_H

class DialogueState : public GameState
{
	/// \class DialogueState DialogueState.h
	/// \brief This is the state of the game when the player character is engaged in dialogue with an NPC.
public:
	/// This is the default constructor.
	DialogueState();
	/// Sets the layout of the game.
	void Set();
};

#endif