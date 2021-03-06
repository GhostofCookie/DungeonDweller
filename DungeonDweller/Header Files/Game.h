/**
 * @author Tomas Rigaux
 * @date 25/05/2020
 *
 * This file handles the game as a whole, changing the states as needed
 * using the old model of game states. This may change in future but for now
 * this handles the game fine.
 */

#pragma once

#include "GameState.h"
#include <memory>
#include <unordered_map>

class Menu;
class Player;
class GameState;
class Viewport;

class Game
{
public:
	/** Constructor for the Game. */
	Game();

	/** Initialises the game and state. */
	void Initialize();
	
	/** Runs the game in a loop until the user quits. */
	void Run();

	/** Runs a cleanup on anything that needs to be collected. */
	void Cleanup();

private:
	void GetPlayerStats(std::shared_ptr<Viewport> viewport);

	/** The state of the game. */
	std::unique_ptr<GameState> state;

	/** The menu for the game/ */
	//std::unique_ptr<Menu> menu;

	/** The player for the game. */
	std::shared_ptr<Player> player;

	/** All of the screens to show the aspects of the game. */
	std::unordered_map<std::string, std::shared_ptr<Viewport>> views;

	/** Stores the current state of the game to check if for state changes. */
	int currState;
};
