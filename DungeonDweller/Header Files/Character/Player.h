/**
 * Player.h
 *
 * @author Gates Kempenaar
 * @date Oct 25, 2017
 *
 */

#pragma once

#include <stdio.h>
#include "Character.h"
#include "MyConsumables.h"
#include "Item.h"
#include "ImportImg.h"
#include <vector>
#include <string>

class Item;
class MyConsumable;
class Npc;

/** Derived class from Character which provides Player attributes. */
class Player : public Character
{
public:
	/** Player constructor
	 * @param[in] s, players stamina
	 * @param[in] k, players keys
	 * @param[in] n, players name
	 * @param[in] r, players race
	 * @param[in] g, players gold amount
	 * @param[in] h, playes health
	 * @param[in] img, image representing the player
	 */
	Player(std::string name = " ",
		std::string race = " ",
		int stamina = 0,
		int health = 0,
		int gold = 0,
		int keys = 0,
		const ImportImg& img = ImportImg("../ResourceFiles/Art/Player/DD_Player.txt"));

	/** Player deconstructor */
	~Player();

	/** Const copy constructor */
	Player(const Player&);

	/** Assignment operator overloader for copy constructor */
	Player& operator = (const Player& p);

	/** Amount of keys the player has
	 * @param[in] keyMod, how the current amount of keys will be modified
	 */
	void ChangeKeys(int keyMod);

	/** Function to use a key
	 * @param[in] keys, uses a key if available
	 * @returns true if a key can be used
	 */
	bool UseKey(int& keys);

	/** Shows the amount of keys
	 * @returns the number of keys the player has
	 */
	int GetKeys() const { return keys; };

	/** Get the player's gold.
	 * @returns the std::string representing the players race
	 */
	double GetGold() const { return gold; };

	/** Shows players race
	 * @returns the std::string representing the players race
	 */
	std::string GetRace() const { return race; };

	/** Shows players name
	 * @returns the std::string representing the players name
	 */
	std::string GetName() const { return name; };

	/** Prints all player stats */
	void Print();

	/** Helper function for deconstructor */
	void EmptyInventory();

private:
	/** Name of the player. */
	std::string name;

	/** Race of the player. */
	std::string race;

	/** The player's gold. */
	double gold;

	/*Amount of keys player has. */
	int keys;
};

