/// \date 25/11/2017
/// \author Tomas Rigaux
///
/// This is the implementation for the Trade State.

#include "TradeState.h"
#include <iomanip>
#include "../Menu/TradeMenu.h"

/// Default constructor
TradeState::TradeState(Player *p)
{
   screen = new Screen();
   menu = new TradeMenu();
   player = new Player(*p);
}

TradeState::~TradeState()
{
   delete menu;
   delete screen;
   delete player;
}

/// Sets the layout of the game.
void TradeState::Set()
{
   menu->AddOption('q', "Leave Shop");
}
/// Outputs the set layout.
void TradeState::Get()
{
   // print the player's informaton and the screen
   cout << setfill(' ') << "[N]Name: " << player->GetName();
   cout << setw(20) << "[R]Race: " << player->GetRace() << endl;
   cout << "[$]Gold: " << player->GetGold();
   cout << setw(27) << "[S]Stamina: " << player->GetStamina();
   cout << setw(27) << right << "[+]Health: " << player->GetHealth() << right << endl;
      
   cout<<screen;
   menu->OutputMenu();
   menu->HandleInput(cin);
   if(menu->GetOption() == 'q')
   {
      currState = 'E';
      return;
   }
}
