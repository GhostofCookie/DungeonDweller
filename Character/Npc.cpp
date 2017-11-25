#include "Npc.h"

using namespace std;

Npc:: Npc(int g = 0, int h = 0, ImportImg img = ImportImg())
{
   img = ImportImg(i);
   gold = g;
   health = h;
}

   

Npc:: ~Npc()
{
   
}

void Npc:: AttackPlayer(Player enemy)
{
   // int healthMod = Weapon.baseDamage;
   //ChangeHealth(Player.health, healthMod);
}
