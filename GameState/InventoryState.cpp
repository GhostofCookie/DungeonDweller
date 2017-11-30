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
   delete player;
}

/// Sets the layout for the game menu and screen.
void InventoryState::Set()
{
   auto it = player->GetInventoryItems().begin();
   int i = 1;
   if(player->GetInventoryItems().empty())
      cout << "Empty." << endl;
   while(it != player->GetInventoryItems().end())
   {
      menu->AddOption(i,(*it)->Name());
      ++it;
      ++i;
   }
/*   it = inv.begin();
   for(; it != inv.end(); ++it)
   delete *it;*/
   menu->AddOption('q', "Back to Room");
}

/// Gets the layout for the game menu and screen.
void InventoryState::Get()
{
   cout << " [#] Inventory" << endl;
   menu->OutputMenu();
   menu->HandleInput(cin);
   
   switch(menu->GetOption())
   {
      case 'q':
	 currState = 'E';
	 return;
	 break;
      default:
	 currState = 'I';
	 return;
	 break;
   }
}
