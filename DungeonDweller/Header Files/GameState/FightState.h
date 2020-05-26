/** @date 21/10/2017
 * @author Tomas Rigaux
 *
 * This is the state of the game when a player character is engaged in combat.
 */

#pragma once

#include "GameState.h"

/** @class FightState FIghtState.h
 * @brief This is the state of the game when the player character is
 * engaged in combat. Derived from GameState.
 */
class FightState : public GameState
{
  public:
   /** This is the default constructor. */
   FightState(std::shared_ptr<Player> p, std::shared_ptr<Screen> scr);
   
   /** Sets the layout of the game. */
   void Set();
   
   /** Outputs the layout of the game. */
   void Get();
};

