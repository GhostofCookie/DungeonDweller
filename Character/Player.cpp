#include "Player.h"

using namespace std;

Player:: Player(int s, int k, string n, string r)
   : stamina{s}, keys{k}, name{n}, race{r} {}

Player:: ~Player()
{

}

void Player:: ChangeStamina(int& stamina, int sMod)
{
   if(stamina += sMod <= 0)
      stamina = 0;
   else
      stamina += sMod;
}

void Player:: ChangeKeys(int& keys, int keyMod)
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

void Player:: AttackNpc(Weapon damage, Npc enemy)
{
   int healthMod = Weapon.baseDamage;
   ChangeHealth(Npc.health, healthMod);
}
