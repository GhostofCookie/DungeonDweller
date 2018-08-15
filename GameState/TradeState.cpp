/// \date 25/11/2017
/// \author Tomas Rigaux
///
/// This is the implementation for the Trade State.

#include "TradeState.h"
#include "../Menu/TradeMenu.h"

/// Default constructor
TradeState::TradeState(Player *p)
{
	screen = new Screen();
	menu = new TradeMenu();
	player = new Player(*p);
}

TradeState::~TradeState()
{
	delete menu;
	delete screen;
	delete player;
}

/// Sets the layout of the game.
void TradeState::Set()
{
	menu->AddOption('q', "Leave Shop");
}
/// Outputs the set layout.
void TradeState::Get()
{
	GetStatistics();
      
	std::cout<<screen;
	menu->OutputMenu();
	menu->HandleInput(std::cin);
	if(menu->GetOption() == 'q')
	{
		currState = EXPLORE;
		return;
	}
}
