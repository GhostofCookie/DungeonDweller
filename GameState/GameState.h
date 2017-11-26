/// \date 21/10/2017
/// \author Tomas Rigaux
///
/// This class defines the current state of the game, based on the current
/// location and actions of the player character.
///

#include "../Menu/Menu.h"
#include "../Screen/Screen.h"
#include "../Screen/SlotScreen.h"
#include "../Menu/MainMenu.h"
#include "../Menu/FightMenu.h"
#include "../Menu/ExploreMenu.h"
#include "../RoomTree/RoomTree.h"
#include "../Character/Character.h"
#include "../Character/Character.h"
#include "../Character/Player.h" 
#include "../Character/Npc.h"
#include "../Item/Item.h"
#include "../Item/MyConsumables.h"

#ifndef GAMESTATE_H
#define GAMESTATE_H



class GameState
{
   /// \class GameState GameState.h
   /// \brief An abstract class, this class defines the state of the current 'state' of the game based 
   /// on the current situation of the player character.
  public:
   /// Default constructor
   GameState(){}
   /// Default destructor
   virtual ~GameState(){}
   /// Sets the layout of the game.
   virtual void Set() = 0;
   /// Outputs the set layout.
   virtual void Get() = 0;
   /// Returns the current state.
   char GetState() const {return currState;}

  protected:
   ///< pointer to the menu.
   Menu *menu;
   ///< pointer to the screen;
   Screen *screen;
   ///< defines which gamestate will be used.
   char currState;
   /// allows access from different states to check whether room is complete
   RoomTree *roomTree;
   /// The main character
   Character player;

};

#endif
