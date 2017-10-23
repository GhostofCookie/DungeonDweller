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
public:
	DialogueState();
	void Set();
};

#endif