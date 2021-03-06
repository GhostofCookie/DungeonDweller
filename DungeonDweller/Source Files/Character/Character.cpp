#include "Character.h"
#include "MyWeapons.h"

Character::Character()
{
	gold = 0;
	health = 0;
	stamina = 0;
}

Character::Character(const Character& p)
{
	gold = p.gold;
	health = p.health;
	stamina = p.stamina;
	inventory = p.inventory;
}

Character& Character::operator=(const Character& p)
{
	gold = p.gold;
	health = p.health;
	stamina = p.stamina;
	inventory = p.inventory;

	return *this;
}

Character::~Character()
{
	EmptyInventory();
}


void Character::ChangeGold(int goldMod)
{
	if (gold + goldMod <= 0)
		gold = 0;
	else
		gold += goldMod;
}

void Character::ChangeHealth(int hMod)
{
	if (health + hMod <= 0)
		health = 0;
	else
		health += hMod;
}

Item* Character::UseItem(std::string item)
{
	for (unsigned int i = 0; i < inventory.size(); i++)
		if (inventory[i]->Name() == item)
			return inventory[i];
	return nullptr;
}

std::vector<Item*> Character::GetInventoryItems()
{
	return inventory;
}

void Character::FillInventory(Item* item)
{
	inventory.push_back(item);
}

void Character::EmptyInventory()
{
	if (inventory.size() != 0)
	{
		for (unsigned int i = 0; i < inventory.size(); i++)
		{
			delete inventory.at(i);
			inventory.at(i) = nullptr;
		}
		// for(auto it = inventory.begin(); it != inventory.end(); ++it)
		// {
		//     delete *it;
		//     *it = nullptr;
		// }
		inventory.clear();
	}
}

void Character::ChangeStamina(int sMod)
{
	if (stamina + sMod <= 0)
		stamina = 0;
	else
		stamina += sMod;
}

void Character::Draw(Viewport& viewport)
{
	img.Draw(viewport);
}
