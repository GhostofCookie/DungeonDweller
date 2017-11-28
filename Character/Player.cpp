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

Player:: Player(Player &p)
{
   race = p.GetRace();
   keys = p.GetKeys();
   gold = p.GetGold();
   health = p.GetHealth();
   stamina = p.GetStamina();   
}

Player:: Player(const Player &p)
{
   race = p.GetRace();
   keys = p.GetKeys();
   gold = p.GetGold();
   health = p.GetHealth();
   stamina = p.GetStamina();
}

Player& Player:: operator=(const Player &p)
{
   race = p.GetRace();
   keys = p.GetKeys();
   gold = p.GetGold();
   health = p.GetHealth();
   stamina = p.GetStamina();

   return *this;
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

void Player:: Print()
{
   cout << "Name: " << name << endl;
   cout << "Race: " << race << endl;
   cout << "Stamina: " << stamina << endl;
   cout << "Health: " << health << endl;
   cout << "Gold: " << gold << endl;

   for(unsigned int i = 0; i < inventory.size(); i++)
      cout << inventory[i]->Name();
}
