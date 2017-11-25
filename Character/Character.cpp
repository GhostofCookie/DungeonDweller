#include "Character.h"

/********
Character:: Character(){}
// : gold{g}, health{h} {img = ImportImg(i)}


Character:: ~Character()
{

}
*/

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

void Character:: UseItem(Item *inventory)
{

}

void Character:: GetInventoryItems(Item *inventory)
{

}

void Character:: FillInventory(Item *item)
{
   //inventory.push_back(item);
}

void Character:: ChangeStamina(int sMod)
{
   if(stamina += sMod <= 0)
      stamina = 0;
   else
      stamina += sMod;
}
