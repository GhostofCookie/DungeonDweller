/// \date 25/11/2017
/// \author Tomas Rigaux
///
/// This is the state of the game when a player is checking inventory
///

#include "InventoryState.h"
#include "../Menu/CharacterMenu.h"
//#include "../Menu/ExploreMenu.h"
#include "../Cutscene/Cutscene.h"
#include "../Room/Room.h"
#include "../ImageImporter/ImageImporter.h"
#include "../Image/Image.h"
#include "../Image/DefaultImg.h"
#include "../Image/ImportImg.h"
#include <ctime>
#include <iostream>

/// This is the the default constructor.
InventoryState::InventoryState(Player *p)
{
   screen = new Screen();
   menu = new CharacterMenu();
   player = new Player(*p);
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
//   if(player->GetInventoryItems().empty())
      menu->AddOption(0,"Empty.");
   while(it != player->GetInventoryItems().end())
   {
      menu->AddOption(i,(*it)->Name());
      ++it;
      ++i;
      }
   it = player->GetInventoryItems().begin();
   for(; it != player->GetInventoryItems().end(); ++it)
   delete *it;
   menu->AddOption('q', "Back to Room");
}

/// Gets the layout for the game menu and screen.
void InventoryState::Get()
{
   std::cout << " [#] Inventory" << std::endl;
   menu->OutputMenu();
   menu->HandleInput(std::cin);
   
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
