#include "Player.h"
#include "Npc.h"

using namespace std;

Player:: Player(int s, int k, string n, string r, int g, int h, ImportImg i)
   : name{n}, race{r}, keys{k}
{
   img = ImportImg(i);
   gold = g;
   health = h;
   stamina = s;
}

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

