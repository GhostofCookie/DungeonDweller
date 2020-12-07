/** @date 25/11/2017
 * @author Tomas Rigaux
 *
 * This is the state of the game when a player is checking inventory
 */

#pragma once

#include "GameState.h"
#include "ExploreState.h"

/** @class ExploreState ExploreState.h
 * @brief This is defines the state of the game when the player character is
 * exploring rooms. Derived from GameState.
 */
class InventoryState : public GameState
{
  public:
   /** This is the the default constructor. */
   InventoryState(std::shared_ptr<Player> p, std::shared_ptr<Viewport> view);

   /** This is the default destructor. */
   ~InventoryState();

   /** Sets the layout for the game menu and viewport. */
   void Set();

   /** Gets the layout for the game menu and viewport. */
   void Get();
};

