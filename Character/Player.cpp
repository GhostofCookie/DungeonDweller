#include "Player.h"

using namespace std;

Player:: Player(int s, int k, string n, string r)
   : stamina{s}, keys{k}, name{n}, race{r} {}

Player:: ~Player()
{

}

void Player:: ChangeStamina(int& s, int sMod)
{
   if(s += sMod <= 0)
      s = 0;
   s += sMod;
}

void Player:: ChangeKeys(int& keys, int keyMod)
{
   if(keys += keyMod <= 0)
      keys = 0;
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
