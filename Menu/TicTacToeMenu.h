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
   /// \param[in] OptionsList A map of all the options for the current
   /// menu. Each option has a unique key to make input easier.
   /// \param[in] type This denotes the type of menu to display.
   virtual void SetOptions(map<int,string> optionsList, int row, int col);
   /// This function handles the input for the menu options.
   /// \param[in,out] is The in-stream operator to read the input.
   virtual void HandleInput(istream &is);

};

#endif