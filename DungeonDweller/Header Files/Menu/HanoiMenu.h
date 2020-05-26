/** @date 24/10/2017
 * @author Tomas Rigaux
 *
 * This is the menu class for the Hanoi minigame. It is a subclass of
 * MinigameMenu.
 */

#pragma once

#include "MinigameMenu.h"
#include <map>

/** @class HanoiMenu HanoiMenu.h
 * @brief This is the menu class for the Hanoi minigame.
 */
class HanoiMenu : public virtual MinigameMenu
{
  public:
   /** This is the default constructor. */
   HanoiMenu();
    
   /** This is the virtual destructor. */
   virtual ~HanoiMenu();
    
   /** This function sets the specific options for the Menu type.
    * @param[in] OptionsList A std::map of all the options for the current menu. Each option has a unique key to make input easier.
    * @param[in] type This denotes the type of menu to display.
    */
   virtual void SetOptions(int row = 5, int col = 30,int space = 5);
    
   /** This function handles the input for the menu options.
    * @param[in,out] is The in-stream operator to read the input.
    */
   virtual void HandleInput( std::istream &is);

};
