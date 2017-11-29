/// \date 25/11/2017
/// \author Tomas Rigaux
///
/// This is the state of the game when a player is checking inventory
///

#include "InventoryState.h"
#include "../Menu/CharacterMenu.h"


/// This is the the default constructor.
InventoryState::InventoryState(Player *p)
{
   screen = new Screen();
   menu = new CharacterMenu();
   player = p;

}

/// This is the default destructor.
InventoryState::~InventoryState()
{
  delete screen;
  delete menu;
}

/// Sets the layout for the game menu and screen.
void InventoryState::Set()
{
  vector<Item*> inv = player->GetInventoryItems();
  auto it = inv.begin();
  int i = 1;
  if(inv.empty())
    cout<<"Empty."<<endl;
  while(it != inv.end())
    {
      menu->AddOption(i,(*it)->Name());
      ++it;
      ++i;
    }

  menu->AddOption('q', "Back to Room");
}

/// Gets the layout for the game menu and screen.
void InventoryState::Get()
{
  cout << " [#] Inventory"<<endl;
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
       currState = 'I';
       return;
       break;
     }
}
