/** @date 25/10/2017
 * @author Tomas Rigaux
 *
 * Derived from GameMenu. This is the menu for the player character to use when
 * they are exploring rooms in the game.
 */

#pragma once

#include "GameMenu.h"
#include <map>

/** @class ExploreMenu ExploreMenu.h
 * @brief This is the menu displayed when the player character is exploring
 * rooms.
 */
class ExploreMenu : public GameMenu
{
  public:
   /** This function sets the specific options for the Menu type.
    * @param[in] row Determines which row the options will start being set at.
    * @param[in] col Determines which column the options will start from.
    * @param[in] How mush space inbetween rows.
    */
   virtual void SetOptions(int row, int col, int space) override;
};

