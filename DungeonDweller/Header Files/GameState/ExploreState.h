/** @date 21/10/2017
 * @author Tomas Rigaux
 *
 * This is the state of the game when a player is exploring.
 */

#pragma once

#include "GameState.h"
#include <memory>


/** @class ExploreState ExploreState.h
 * @brief This is defines the state of the game when the player character is
 * exploring rooms. Derived from GameState.
 */
class ExploreState : public GameState
{
  public:
   /** This is the the default constructor. */
   ExploreState(std::shared_ptr<Player> player, std::shared_ptr<Viewport> view);

   /** This is the default destructor. */
   ~ExploreState();

   /** Copy constructor */ // TODO: Potentially remove this.
   ExploreState(GameState &obj);

   /** Const copy constructor
    * @param[in] state reference to an explore state
    */
   ExploreState(const ExploreState &obj);
   /** Assignment operator for the ExploreState.
    * @param[in] obj The state object to assign from.
    */
   ExploreState& operator=(const ExploreState &obj);

   /** Sets the layout for the game menu and viewport. */
   void Set();

   /** Gets the layout for the game menu and viewport. */
   void Get();
   
  private:
   /** Helper function to set the current state of the game based on the current
    * room type.
    * @param[in] type Defines the type of room the player is in.
    */
   void SetState(int type);

   /** Helper function to give input functionality
    * @param[in] option The current option chosen by the player.
    */
   void RunInput(char option);

   /** Importer object to get room images. */
   class ImageImporter *import;

   /** A pointer to the current room the character is in. */
   class Room *roomPtr;
};

