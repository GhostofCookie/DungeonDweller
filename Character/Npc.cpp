#include "Npc.h"

using nampespace std;

Npc:: Npc()
{

}
   

Npc:: ~Npc()
{
   
}

void Npc:: AttackPlayer(Weapon damage, Player enemy)
{
   int healthMod = Weapon.baseDamage;
   ChangeHealth(Player.health, healthMod);
}
