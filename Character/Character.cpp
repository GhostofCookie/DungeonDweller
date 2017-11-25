#include "Character.h"

Character:: Character(){}
// : gold{g}, health{h} {img = ImportImg(i)}

/*
Character:: ~Character()
{

}
*/

int Character:: ChangeGold(int goldMod)
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

Item Character:: UseItem(Item *inventory)
{

}

Item Character:: GetInventoryItems(Item *inventory)
{

}

void Character:: FillInventory(Item *item)
{
   inventory.pushback(item);
}
