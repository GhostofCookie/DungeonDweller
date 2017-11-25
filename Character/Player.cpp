#include "Player.h"
#include "Npc.h"

using namespace std;

Player:: Player(int s, int k, string n, string r, int g, int h, ImportImg i)
   : keys{k}, name{n}, race{r}
{
   img = ImportImg(i);
   gold = g;
   health = h;
   stamina = s;
}

/*
void Player:: ChangeStamina(int sMod)
{
   if(stamina += sMod <= 0)
      stamina = 0;
   else
      stamina += sMod;
      }
*/

void Player:: ChangeKeys(int keyMod)
{
   if(keys += keyMod <= 0)
      keys = 0;
   else
      keys += keyMod;
}

bool Player:: UseKey(int& keys)
{
   if(keys >= 1)
      keys--;
   else
      return 0;
   return keys;
}

void Player:: AttackNpc(Npc enemy)
{
   //int healthMod = Weapon.baseDamage;
   //ChangeHealth(Npc.health, healthMod);
}
