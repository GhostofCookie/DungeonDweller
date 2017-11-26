/// \date 25/11/2017
/// \author Tomas Rigaux
///
/// This is the state of the game when a player is checking inventory
///

#include "InventoryState.h"
#include "../Menu/CharacterMenu.h"

/// This is the the default constructor.
InventoryState()
{
   screen = new Screen();
   menu = new CharacterMenu();
}

/// This is the default destructor.
~InventoryState()
{

}

/// Sets the layout for the game menu and screen.
void Set()
{
   menu->AddOption('e', "Equip Item");
   menu->AddOption('u', "Use Item");
   menu->AddOption('i', "Inspect Item");
//   menu->AddOption('',"");
//   menu->AddOption();
}

/// Gets the layout for the game menu and screen.
void Get()
{
   cout << screen;
   menu->OutputMenu();
}
