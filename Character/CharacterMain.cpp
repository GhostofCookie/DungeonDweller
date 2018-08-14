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
  std::vector<Item*> inv = t->GetInventoryItems();
  auto it = inv.begin();

  while(it != inv.end())
    {

      Player *t = nullptr;
      t = create(t);
      auto it = t->GetInventoryItems().begin();

      while(it != t->GetInventoryItems().end())
	{

	  std::cout<<(*it)->Name()<<std::endl;
	  ++it;
	}

      it = (t->GetInventoryItems()).begin();
      // player.Draw(screen);
      t->Img().AlignCenter(*screen);
      t->Img().Draw(*screen);
      std::cout << *screen;
      for(; it != (t->GetInventoryItems()).end(); ++it)
	delete *it;
      delete t;
      delete screen;
      return 0;
    }
}

Player *create(Player *p)
{
  std::vector<Player*> players;


  Player *player = new Player(10, 10,"hi", "hello", 10, 10);
  Player *player2 = new Player(10, 10,"bi", "bye", 10, 10);

  //   Sword *sword = new Sword;
  player->FillInventory(new Sword);
  player->FillInventory(new Bow);
  player->FillInventory(new Sword);
  player2->FillInventory(new Bow);
  player2->FillInventory(new Bow);

  players.push_back(player);
  players.push_back(player2);
  int i=0;
  std::cin>>i;
  delete p;
  p = new Player(*players[i]);
  /*   for(auto it = players.begin(); it != players.end(); ++it)
       delete (*it);*/
  return p;
}
