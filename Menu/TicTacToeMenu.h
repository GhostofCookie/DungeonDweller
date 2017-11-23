/// \date 24/10/2017
/// \author Tomas Rigaux
///
/// This is the menu class for the Tic Tac Toe minigame. It is a subclass of
/// MinigameMenu.
///

#include "MinigameMenu.h"
#include <map>
using namespace std;

#ifndef TICTACTOEMENU_H
#define TICTACTOEMENU_H

/// \class TicTacToeMenu TicTacToeMenu.h
/// \brief This is the menu class for the Tic Tac Toe minigame.
class TicTacToeMenu : public virtual MinigameMenu
{
  public:
   /// This is the default constructor.
   TicTacToeMenu();
   /// This is the virtual destructor.
   virtual ~TicTacToeMenu();
   /// This function sets the specific options for the Menu type.
   /// \param[in] row Determines which row the options will start being set at.
   /// \param[in] col Determines which column the options will start from.
   /// \param[in] How mush space inbetween rows.
   virtual void SetOptions(int row, int col, int space);
   /// This function handles the input for the menu options.
   /// \param[in,out] is The in-stream operator to read the input.
   virtual void HandleInput(istream &is);
   /// This function returns the coordinates the player entered.
   Coord void GetCoordinates();
  private:
   /// \struct Coord
   /// The coordinates of the location the player wishes to place their piece.
   struct Coord
   {
      int x,y;
   };
};

#endif
