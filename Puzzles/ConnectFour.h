//
// connect_four.h
//
/// \author Tyler Siwy
/// \date Oct 20, 2017
//  

#ifndef  CONNECT_FOUR_H
#define CONNECT_FOUR_H
#include "Puzzle.h"

///This class contains the mini-game/puzzle Connect Four
class ConnectFour: virtual Puzzle
{
  public:
   ///Default constructor for ConnectFour, sets heigh to : and width to:
   ConnectFour();

   ///Deconstructor
   ~ConnectFour();

   ///Method to run the game, serves as a 'main' for the mini-game, calling
   ///functions from private until the player has won.  
   void RunGame();

  private:
   ///ALL HANDLED BY THE MENU OBJECT?
   //void PromptUser(&screen);//Prompts user for input
   //char UserInput(&menu);//Gets user input
   //bool ValidCommand(char input);//Checks formatting

   ///Checks the semantics of the user choice to make sure they aren't doing
   ///something that would break the game with their input. 
   ///\param[in]input, has been checked for syntax by input method
   bool ValidMove(char Input);

   ///Sends the menu class the options for the player to select.
   void SetOptionsInMenu();

   ///Assign the player selection to the board.
   ///\param[in] UserPiece, whichever token the player is using for the game
   ///\param[in] x, the X-coordinate (column) to drop the token in
   void MovePiece(char UserPiece, int x);

   /// Displays the screen containing the gameboard
   /// \param[in] CfScreen, the screen object used for displaying the mini-game 
   void OutputGame(Screen &CfScreen);

   ///Checks to see if there have been any 4 tokens in a row in the grid vector.
   bool WinCheck();

   /// The vector which stores the gameboards chars.
   std::vector<vector<char>>Grid;   

};
#endif
 
















