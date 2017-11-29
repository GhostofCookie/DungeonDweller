#include "Character.h"

Character::Character()
{
   gold = 0;
   health = 0;
   stamina = 0;
}



Character:: Character(Character &p)
{
   gold = p.gold;
   health = p.health;
   stamina = p.stamina;
}

Character:: Character(const Character &p)
{
   gold = p.gold;
   health = p.health;
   stamina = p.stamina;
}

Character& Character:: operator = (const Character &p)
{
   gold = p.gold;
   health = p.health;
   stamina = p.stamina;

   return *this;
}

Character::~Character()
{
   EmptyInventory();
   
}


void Character:: ChangeGold(int goldMod)
{
 if(gold + goldMod <= 0)
    gold = 0;
 else
    gold += goldMod; 
}

void Character:: ChangeHealth(int hMod)
{
 if(health + hMod <= 0)
    health = 0;
 else
   health += hMod;
}

Item* Character:: UseItem(string item)
{
   for(unsigned int i = 0; i < inventory.size(); i++)
      if(inventory[i]->Name() == item)
	 return inventory[i];
   return nullptr;
}

vector < Item* > Character:: GetInventoryItems()
{
   return inventory; 
}

void Character:: FillInventory(Item *item)
{
   inventory.push_back(item);
}

void Character:: EmptyInventory()
{
   for(auto it = inventory.begin(); it != inventory.end(); ++it)
      delete *it;
}

void Character:: ChangeStamina(int sMod)
{
   if(stamina + sMod <= 0)
      stamina = 0;
   else
      stamina += sMod;
}

void Character:: Draw(Screen &screen)
{
   img.Draw(screen);
}
