#include "Character.h"
#include "Player.h"
#include "../Item/Item.h"
#include "../Item/MyWeapons.h"

#include "../Screen/Screen.h"

Player *create(Player *);
int main()
{
    Screen *screen = new Screen();
    Player *t = nullptr;
    t = create(t);
   vector<Weapon*> inv = t->GetInventoryItems();
  auto it = inv.begin();

  while(it != inv.end())
    {
      cout<<(*it)->Name()<<endl;
      ++it;
    }
   // player.Draw(screen);
    t->Img().AlignCenter(*screen);
    t->Img().Draw(*screen);
   cout << *screen;
   return 0;
}

Player *create(Player *p)
{
  vector<Player*> players;


    Player *player = new Player(10, 10,"hi", "hello", 10, 10);
    Player *player2 = new Player(10, 10,"bi", "bye", 10, 10);

    Sword *sword = new Sword;
    player->FillInventory(sword);
    player->FillInventory(new Bow);
    player->FillInventory(new Sword);
    player2->FillInventory(new Bow);
    player2->FillInventory(new Bow);



    players.push_back(player);
    players.push_back(player2);
    int i;
    cin>>i;
    delete p;
    p = players[i];
    return p;
}
