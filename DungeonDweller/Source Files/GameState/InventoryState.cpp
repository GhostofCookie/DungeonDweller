/** @date 25/11/2017
 * @author Tomas Rigaux
 *
 * This is the state of the game when a player is checking inventory
 */

#include "InventoryState.h"
#include "CharacterMenu.h"
#include "Cutscene.h"
#include "Room.h"
#include "Image.h"
#include "DefaultImg.h"
#include "ImportImg.h"
#include <ctime>
#include <iostream>

InventoryState::InventoryState(std::shared_ptr<Player> p, std::shared_ptr<Viewport> view)
{
	menu = new CharacterMenu();
	player = p;
	viewport = view;
}

InventoryState::~InventoryState()
{
	delete menu;
}

void InventoryState::Set()
{
	auto it = player->GetInventoryItems().begin();
	int i = 1;
	if (player->GetInventoryItems().empty())
		menu->AddOption(0, "Empty.");
	while (it != player->GetInventoryItems().end())
	{
		menu->AddOption(i, (*it)->Name());
		++it;
		++i;
	}

	/* FIXME: This likely empties the inventory.
	it = player->GetInventoryItems().begin();
	for (; it != player->GetInventoryItems().end(); ++it)
		delete* it;
	*/
	menu->AddOption('q', "Back to Room");
}

void InventoryState::Get()
{
	std::cout << " [#] Inventory" << std::endl;
	menu->OutputMenu();
	menu->HandleInput(std::cin);

	switch (menu->GetOption())
	{
	case 'q':
		currState = States::EXPLORE;
		return;
		break;
	default:
		currState = States::INVENTORY;
		return;
		break;
	}
}
