#include "Player.h"
#include "Npc.h"

Player::Player(std::string name,
	std::string race,
	int stamina,
	int health,
	int gold,
	int keys,
	const ImportImg& img)
	: name{ name }, race{ race }, keys{ keys }
{
	this->img = ImportImg(img);
	this->gold = gold;
	this->health = health;
	this->stamina = stamina;
}

Player:: ~Player()
{
	EmptyInventory();
}

void Player::EmptyInventory()
{
	for (auto it = inventory.begin(); it != inventory.end(); ++it)
		delete* it;
}

Player::Player(const Player& p)
{
	name = p.name;
	race = p.race;
	keys = p.keys;
	gold = p.gold;
	health = p.health;
	stamina = p.stamina;
}

Player& Player::operator=(const Player& p)
{
	name = p.name;
	race = p.race;
	keys = p.keys;
	gold = p.gold;
	health = p.health;
	stamina = p.stamina;

	return *this;
}

void Player::ChangeKeys(int keyMod)
{
	if (keys += keyMod <= 0)
		keys = 0;
	else
		keys += keyMod;
}

bool Player::UseKey(int& keys)
{
	if (keys >= 1)
		keys--;
	else
		return 0;
	return keys;
}

void Player::Print()
{
	std::cout << std::endl;
	std::cout << "Name: " << name << std::endl;
	std::cout << "Race: " << race << std::endl;
	std::cout << "Stamina: " << stamina << std::endl;
	std::cout << "Health: " << health << std::endl;
	std::cout << "Gold: " << gold << std::endl << std::endl << "Items: " << std::endl;

	if (inventory.size() == 0)
	{
		std::cout << "N/A";
	}
	else
	{
		for (unsigned int i = 0; i < inventory.size(); i++)
			std::cout << inventory[i]->Name() << std::endl;
	}
	std::cout << std::endl;
}
