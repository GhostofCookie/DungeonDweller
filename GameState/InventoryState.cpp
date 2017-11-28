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
  // Item *item = new Sword();
//   item = item->GetItem("SWORD");
   //  player.FillInventory(item);
   //  auto it = player.GetInventoryItems().begin();
   // while(it != player.GetInventoryItems().end())
//   {
      //     cout<<*it<<endl;
   //     ++it;
           //  }
   Item *item = new Sword();
   item = item->GetItem("SWORD");
   player->FillInventory(item);
   auto it = player->GetInventoryItems().begin();
   while(it != player->GetInventoryItems().end())
   {
      cout<<item->Name()<<endl;
      ++it;
   }
   menu->OutputMenu();
   menu->HandleInput(cin);
   
   switch(menu->GetOption())
     {
     case 'q':
       currState = 'E';
       return;
       break;
     case 'u':
       // Use the item
       break;
     case 'e':
       // Equip the item
       break;
     case 'i':
       // Show the items information exclusively
       break;
     default:
       return;
       break;
     }
}
