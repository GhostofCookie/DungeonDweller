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
   std::cout << std::setfill(' ') << "[N]Name: " << player->GetName();
   std::cout << std::setw(20) << "[R]Race: " << player->GetRace() << std::endl;
   std::cout << "[$]Gold: " << player->GetGold();
   std::cout << std::setw(27) << "[S]Stamina: " << player->GetStamina();
   std::cout << std::setw(27) << std::right << "[+]Health: " << player->GetHealth() << std::right << std::endl;
      
   std::cout<<screen;
   menu->OutputMenu();
   menu->HandleInput(std::cin);
   if(menu->GetOption() == 'q')
   {
      currState = 'E';
      return;
   }
}
