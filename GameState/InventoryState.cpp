/// \date 25/11/2017
/// \author Tomas Rigaux
///
/// This is the state of the game when a player is checking inventory
///

#include "InventoryState.h"
#include "../Menu/CharacterMenu.h"
#include "../Item/Item.h"
#include "../Item/Weapon.h"
#include "../Item/MyWeapons.h"

/// This is the the default constructor.
InventoryState::InventoryState()
{
   screen = new Screen();
   menu = new CharacterMenu();
}

/// This is the default destructor.
InventoryState::~InventoryState()
{

}

/// Sets the layout for the game menu and screen.
void InventoryState::Set()
{
   menu->AddOption('e', "Equip Item");
   menu->AddOption('u', "Use Item");
   menu->AddOption('i', "Inspect Item");
   menu->AddOption('q', "Back to Room");
}

/// Gets the layout for the game menu and screen.
void InventoryState::Get()
{
<<<<<<< HEAD
  // Item *item = new Sword();
//   item = item->GetItem("SWORD");
   //  player.FillInventory(item);
   //  auto it = player.GetInventoryItems().begin();
   // while(it != player.GetInventoryItems().end())
//   {
      //     cout<<*it<<endl;
   //     ++it;
           //  }
=======
   Item *item = new Sword();
   item = item->GetItem("SWORD");
   player.FillInventory(item);
   auto it = player.GetInventoryItems().begin();
   while(it != player.GetInventoryItems().end())
   {
      cout<<item->Name()<<endl;
      ++it;
   }
>>>>>>> 7295800bc333a8d485f2c07d7bc674058980e7f1
   menu->OutputMenu();
   menu->HandleInput(cin);
}
