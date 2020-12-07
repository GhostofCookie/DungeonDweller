/** @date 21/10/2017
 * @author Tomas Rigaux
 *
 * This is the state of the game when the player is trading with an NPC
 * character.
 */

#pragma once

#include "GameState.h"

/** @class TradeState TradeState.h
 * @brief Sets the state of the game when a player is 'trading' with an NPC.
 * Derived from GameState.
 */
class TradeState : public GameState
{
  public:
   /** Default constructor */
   TradeState(std::shared_ptr<Player> player, std::shared_ptr<Viewport> view);
   
   /** Default destructor. */
   virtual ~TradeState();
   
   /** Sets the layout of the game. */
   void Set();
   
   /** Outputs the set layout. */
   void Get();
};

