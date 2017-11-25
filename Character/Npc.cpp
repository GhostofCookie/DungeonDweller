#include "Npc.h"
#include "Player.h"

using namespace std;

Npc:: Npc(int s, int g, int h, ImportImg i)
{
   img = ImportImg(i);
   gold = g;
   health = h;
   stamina = s;
}

   

Npc:: ~Npc()
{
   
}

void Npc:: AttackPlayer(Player *enemy)
{
   // int healthMod = Weapon.baseDamage;
   //ChangeHealth(Player.health, healthMod);
}

/*
void Npc:: ChangeStamina(int sMod)
{
   if(stamina += sMod <= 0)
      stamina = 0;
   else
      stamina += sMod;
}
*/
