/**
 * @author Tomas Rigaux
 * @date 25/05/2020
 *
 * This file handles the game as a whole, changing the states as needed
 * using the old model of game states. This may change in future but for now
 * this handles the game fine.
 */

#include "Game.h"
#include "DialogueState.h"
#include "FightState.h"
#include "MainState.h"
#include "ExploreState.h"
#include "PuzzleState.h"
#include "MainState.h"
#include "TradeState.h"
#include "InventoryState.h"
#include "Menu.h"
#include "Player.h"
#include <iomanip>
#include <sstream>

Game::Game()
{
	auto viewport = std::make_shared<Screen>(33, 101);
	auto stats = std::make_shared<Screen>(33, 26, 101, 0);

	state = std::make_unique<MainState>(viewport);
	//menu = std::make_unique<MainMenu>();
	player = std::make_shared<Player>("Player 1", "Human", 10, 10, 0);

	screens.push_back(viewport);
	screens.push_back(stats);
}

void Game::Initialise()
{
	state->Set();
	currState = static_cast<int>(state->GetState());
}

void Game::Run()
{
	while (true)
	{
		state->Get();
		if (static_cast<int>(state->GetState()) != currState)
		{
			currState = static_cast<int>(state->GetState());
			switch (state->GetState())
			{
			case States::EXPLORE:
				state = std::make_unique<ExploreState>(player, screens[0]);
				break;
			case States::PUZZLE:
				state = std::make_unique<PuzzleState>(player, screens[0]);
				break;
			case States::COMBAT:
				state = std::make_unique<FightState>(player, screens[0]);
				break;
			case States::TRADE:
				state = std::make_unique<TradeState>(player, screens[0]);
				break;
			case States::INVENTORY:
				state = std::make_unique<InventoryState>(player, screens[0]);
				break;
			case States::MAIN:
			default:
				screens[1]->Wipe();
				state = std::make_unique<MainState>(screens[0]);
			}
			state->Set();
		}

		// Display stats screen.
		if (currState != 0)
			GetPlayerStats(screens[1]);

		// Lose condition
		if (player->GetHealth() <= 0 || player->GetStamina() <= 0)
		{
			//  Insert defeat anim here
			std::cout << "*** You are unable to continue. Game Over ***" << std::endl;
			currState = 0;
			screens[1]->Wipe();
			state = std::make_unique<MainState>(screens[0]);
		}
	}
}

void Game::Cleanup()
{
}

void Game::GetPlayerStats(std::shared_ptr<Screen> screen)
{
	screen->Erase();
	std::stringstream ss;
	ss << "Name: " << player->GetName() << '\n';
	ss << "Race: " << player->GetRace() << '\n';
	//ss << "[^]Depth: " << roomTree->CurrentHeight() << '\n';
	ss << "Gold: " << player->GetGold() << '\n';
	ss << "Stamina: " << player->GetStamina() << '\n';
	ss << "Health: " << player->GetHealth() << '\n';

	int j = 1, k = 2;
	for (int i = 0; i < ss.str().length(); i++)
	{
		if (ss.str()[i] == '\n')
		{
			k = 1;
			++j;
		}
		screen->Set(j, k++, ss.str()[i]);
	}
	std::cout << screen.get();
}

