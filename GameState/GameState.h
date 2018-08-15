/// \date 21/10/2017
/// \author Tomas Rigaux
///
/// This class defines the current state of the game, based on the current
/// location and actions of the player character.
///

#pragma once

#include "../Menu/Menu.h"
#include "../Screen/Screen.h"
#include "../Menu/MainMenu.h"
#include "../Menu/FightMenu.h"
#include "../Menu/ExploreMenu.h"
#include "../RoomTree/RoomTree.h"
#include "../Character/Character.h"
#include "../Character/Character.h"
#include "../Character/Player.h" 
#include "../Character/Npc.h"
#include "../Item/MyConsumables.h"
#include "../Item/Item.h"
#include "../Item/Weapon.h"
#include "../Item/MyWeapons.h"

class GameState
{
   /// \class GameState GameState.h
   /// \brief An abstract class, this class defines the state of the current 'state' of the game based 
   /// on the current situation of the player character.
  public:
   /// Default constructor.
   GameState(Player *p=nullptr):menu{nullptr},screen{nullptr}
   ,currState{'M'},roomTree{nullptr}
   ,player{p}{}
   /// Default destructor.
   virtual ~GameState(){}
   /// Sets the layout of the game.
   virtual void Set() = 0;
   /// Outputs the set layout.
   virtual void Get() = 0;

   /// Returns the current state.
   char GetState() const { return currState; }
   /// Returns the current player.
   Player *GetPlayer() const { return player; }
   /// Returns the room tree.
   RoomTree *GetRoomTree() const { return roomTree; }
   /// Returns menu.
   Menu *GetMenu() const { return menu; }
   /// Returns the screen.
   Screen *GetScreen() const {return screen; }

  protected:
   ///< Pointer to the menu.
   Menu *menu;
   ///< Pointer to the screen.
   Screen *screen;
   ///< Defines which gamestate will be used.
   char currState;
   ///< Allows access from different states to check whether room is complete.
   RoomTree *roomTree;
   ///< Pointer to the player character.
   Player *player;
   
};
