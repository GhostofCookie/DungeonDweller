/** @date 25/11/2017
 * @author Tomas Rigaux
 *
 * This is the implementation for the Trade State.
 */

#include "TradeState.h"
#include "TradeMenu.h"

TradeState::TradeState(std::shared_ptr<Player> player, std::shared_ptr<Viewport> view)
{
	this->player = player;
	this->viewport = view;

	menu = new TradeMenu();
}

TradeState::~TradeState()
{
	delete menu;
}

void TradeState::Set()
{
	menu->AddOption('q', "Leave Shop");
}

void TradeState::Get()
{
	std::cout << viewport;
	menu->OutputMenu();
	menu->HandleInput(std::cin);
	if (menu->GetOption() == 'q')
	{
		currState = States::EXPLORE;
		return;
	}
}
