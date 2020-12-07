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

#define GAMESTART_HEIGHT 33
#define GAMESTART_WIDTH 127
#define INGAME_HEIGHT 33
#define INGAME_WIDTH 101
#define STATS_WIDTH GAMESTART_WIDTH - INGAME_WIDTH

Game::Game()
{
	auto viewport = std::make_shared<Viewport>(GAMESTART_HEIGHT, GAMESTART_WIDTH);

	state = std::make_unique<MainState>(viewport);
	//menu = std::make_unique<MainMenu>();
	player = std::make_shared<Player>("Player 1", "Human", 10, 10, 0);

	views["viewport"] = viewport;
}

void Game::Initialize()
{
	state->Set();
	currState = static_cast<int>(state->GetState());
}

void Game::Run()
{
	while (true)
	{
		Viewport::DisplayAll(views);
		state->Get();
		if (static_cast<int>(state->GetState()) != currState)
		{
			currState = static_cast<int>(state->GetState());
			switch (state->GetState())
			{
			case States::EXPLORE:
				state = std::make_unique<ExploreState>(player, views["viewport"]);

				views["viewport"]->Resize(33, 101);
				views["stats"] = std::make_shared<Viewport>(INGAME_HEIGHT, STATS_WIDTH, INGAME_WIDTH, 0);
				GetPlayerStats(views["stats"]);
				break;
			case States::PUZZLE:
				state = std::make_unique<PuzzleState>(player, views["viewport"]);
				break;
			case States::COMBAT:
				state = std::make_unique<FightState>(player, views["viewport"]);
				break;
			case States::TRADE:
				state = std::make_unique<TradeState>(player, views["viewport"]);
				break;
			case States::INVENTORY:
				state = std::make_unique<InventoryState>(player, views["viewport"]);
				break;
			case States::MAIN:
			default:
				state = std::make_unique<MainState>(views["viewport"]);

				for (auto it = views.begin(); it != views.end();)
					if (it != views.find("viewport"))
					{
						it->second->Wipe();
						it = views.erase(it);
					}
					else ++it;

				views["viewport"]->Resize(GAMESTART_HEIGHT, GAMESTART_WIDTH);
			}
			state->Set();
		}

		// Lose condition
		if (player->GetHealth() <= 0 || player->GetStamina() <= 0)
		{
			//  Insert defeat anim here
			std::cout << "*** You are unable to continue. Game Over ***" << std::endl;
			currState = 0;
		}
	}
}

void Game::Cleanup()
{
}

void Game::GetPlayerStats(std::shared_ptr<Viewport> viewport)
{
	viewport->Erase();
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
		viewport->Set(j, k++, ss.str()[i]);
	}
}

