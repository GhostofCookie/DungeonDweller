#include "Character.h"

Character:: Character(int g, int h, ImportImg i)
   : gold{g}, health{h} {img = ImportImg(i)}

Character:: ~Character()
{

}

int Character:: ChangeGold(int &gold, int goldMod)
{
 if(gold += goldMod <= 0)
    gold = 0;
 else
    gold += goldMod;
}

void Character:: ChangeHealth(int& health, int hMod)
{
 if(health += hMod <= 0)
    health = 0;
 else
   health += hMod;
}

Item Character:: UseItem(Item *inventory)
{

}

Item Character:: GetInventoryItems(Item *inventory)
{

}

void Character:: FillInventory(vector<*Item> &inventory, Item item)
{
   inventory.pushback(item);
}
