#include "Character.h"
Character::Character()
{
}



Character:: Character(Character &p)
{
   gold = p.GetGold();
   health = p.GetHealth();
   stamina = p.GetStamina();
}

Character:: Character(const Character &p)
{
   gold = p.GetGold();
   health = p.GetHealth();
   stamina = p.GetStamina();
}

Character& Character:: operator=(const Character &p)
{
   gold = p.GetGold();
   health = p.GetHealth();
   stamina = p.GetStamina();

   return *this;
}


void Character:: ChangeGold(int goldMod)
{
 if(gold += goldMod <= 0)
    gold = 0;
 else
    gold += goldMod; 
}

void Character:: ChangeHealth(int hMod)
{
 if(health += hMod <= 0)
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

vector<Item*> Character:: GetInventoryItems()
{
   return inventory; 
}

void Character:: FillInventory(Item *item)
{
   inventory.push_back(item);
}

void Character:: ChangeStamina(int sMod)
{
  stamina += sMod;
}

void Character:: Draw(Screen &screen)
{
   img.Draw(screen);
}

ImportImg Character:: Img()
{
   return img;
}
