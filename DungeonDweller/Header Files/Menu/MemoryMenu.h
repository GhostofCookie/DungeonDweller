/** @date 24/10/2017
 * @author Tomas Rigaux
 *
 * This is the menu class for the Memory Match minigame. It is a subclass of
 * MinigameMenu.
 */

#pragma once

#include "MinigameMenu.h"
#include <map>

/** @class MemoryMenu MemoryMenu.h
 * @brief This is the menu class for the Memory match minigame.
 */
class MemoryMenu : public virtual MinigameMenu
{
  private:
   /** @struct Coord
    * The coordinates of the location the player wishes to place their piece.
    */
   struct Coord
   {
      char x1, x2;
      int y1, y2;
   };
   Coord coordinates;
   std::string query;
  public:
   /** This is the default constructor. */
   MemoryMenu();

   /** This is the virtual destructor. */
   virtual ~MemoryMenu();
    
   /** This function sets the specific options for the Menu type.
    * @param[in] OptionsList A std::map of all the options for the current menu. Each option has a unique key to make input easier.
    * @param[in] type This denotes the type of menu to display.
    */
   virtual void SetOptions(int row, int col, int space);
    
   /** This function handles the input for the menu options.
    * @param[in,out] is The in-stream operator to read the input.
    */
   virtual void HandleInput( std::istream &is);
    
   /** This function returns the coordinates the player entered. */
   Coord GetCoordinates() const;

};
