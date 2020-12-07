/** @date 21/10/2017
 * @author Tomas Rigaux
 *
 * This class is derived from the GameState abstract class. It sets the state
 * of the game.
 */

#pragma once

#include "GameState.h"

/** @class MainState MainState.h
 * @brief This is the state of the game when the game is either not yet started or the game has ended.
 * Derived from GameState.
 */
class MainState : public GameState
{
  public:
   /** Default constructor */
   MainState(std::shared_ptr<Viewport> view);
   
   /** Sets the layout of the game. */
   void Set();
   
   /** Outputs the set layout. */
   void Get();

};
