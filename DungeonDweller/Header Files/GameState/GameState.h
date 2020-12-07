/** @date 21/10/2017
 * @author Tomas Rigaux
 *
 * This class defines the current state of the game, based on the current
 * location and actions of the player character.
 */

#pragma once

#include "Menu.h"
#include "Viewport.h"
#include "MainMenu.h"
#include "FightMenu.h"
#include "ExploreMenu.h"
#include "RoomTree.h"
#include "Character.h"
#include "Player.h" 
#include "Npc.h"
#include "MyConsumables.h"
#include "Item.h"
#include "Weapon.h"
#include "MyWeapons.h"
#include <iomanip>
#include <memory>

enum class States { MAIN, PUZZLE, INVENTORY, COMBAT, TRADE, DIALOGUE, EXPLORE };

/** @class GameState GameState.h
 * @brief An abstract class, this class defines the state of the current 'state' of the game based
 * on the current situation of the player character.
 */
class GameState
{
public:
	/** Default constructor. */
	GameState() = default;

	/** Default destructor. */
	virtual ~GameState() {}

	/** Sets the layout of the game. */
	virtual void Set() = 0;

	/** Outputs the set layout. */
	virtual void Get() = 0;

	/** Returns the current state. */
	States GetState() const { return currState; }

	/** Returns the current player. */
	std::shared_ptr<Player> GetPlayer() const { return player; }

	/** Returns the room tree. */
	RoomTree* GetRoomTree() const { return roomTree; }

	/** Returns menu. */
	Menu* GetMenu() const { return menu; }

	/** Returns the viewport. */
	std::shared_ptr<Viewport> GetScreen() const { return viewport; }

protected:
	/** Pointer to the menu. */
	Menu* menu;

	/** Allows access from different states to check whether room is complete. */
	RoomTree* roomTree;

	/** Defines which gamestate will be used. */
	States currState = States::MAIN;

	/** Pointer to the player character. */
	std::shared_ptr<Player> player;

	/** Pointer to the viewport. */
	std::shared_ptr<Viewport> viewport;
};
