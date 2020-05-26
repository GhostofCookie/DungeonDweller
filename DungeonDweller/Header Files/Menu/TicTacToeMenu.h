/** @date 24/10/2017
 * @author Tomas Rigaux
 *
 * This is the menu class for the Tic Tac Toe minigame. It is a subclass of
 * MinigameMenu.
 */

#pragma once

#include "MinigameMenu.h"

/** @class TicTacToeMenu TicTacToeMenu.h
 * @brief This is the menu class for the Tic Tac Toe minigame.
 */
class TicTacToeMenu : public virtual MinigameMenu
{
  private:
   /** @struct Coord
    * @brief The coordinates of the location the player wishes to place their piece.
    */
   struct Coord
   {
      /** x is the character coordinate (columns). */
      char x;
      /** y is the integer coordinate (rows). */
      int y;
   };  

   /** coordinates of the piece played. */
   Coord coordinates;

  public:
   /** This is the default constructor. */
   TicTacToeMenu();
    
   /** This is the virtual destructor. */
   virtual ~TicTacToeMenu();
    
   /** This function sets the specific options for the Menu type.
    * @param[in] row Determines which row the options will start being set at.
    * @param[in] col Determines which column the options will start from.
    * @param[in] How mush space inbetween rows.
    */
   virtual void SetOptions(int row, int col, int space);
    
   /** This function handles the input for the menu options.
    * @param[in,out] is The in-stream operator to read the input.
    */
   virtual void HandleInput( std::istream &is);

   /** This function returns the coordinates the player entered. */
   Coord GetCoordinates() const;
};
