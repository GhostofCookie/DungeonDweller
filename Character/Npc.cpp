#include "Npc.h"
#include "Player.h"

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
