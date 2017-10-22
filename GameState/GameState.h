#include "Menu.h"
#include "MainMenu.h"
#include "FightMenu.h"
#include "ExploreMenu"


#ifndef GAMESTATE_H
#define GAMESTATE_H

class GameState
{
public:
	GameState();
	Set() = 0;
protected:
	Menu *menu;
};

#endif