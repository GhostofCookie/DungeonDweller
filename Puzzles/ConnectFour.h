//
// connect_four.h
//
/// \author Tyler Siwy
/// \date Oct 20, 2017
//  

#ifndef  CONNECT_FOUR_H
#define CONNECT_FOUR_H
#include "Puzzle.h"
#include "../Menu/ConnectFourMenu.h"
#include "../Screen/Screen.h"
#include "../Image/DefaultImg.h"

///This class contains the mini-game/puzzle Connect Four
class ConnectFour: virtual Puzzle
{
  public:
  ///Default constructor for ConnectFour, sets heigh to : and width to:
   ConnectFour();
  ///De-constructor
   virtual ~ConnectFour();

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
   bool ValidMove(int input);

   ///Sends the menu class the options for the player to select.
   void SetOptionsInMenu();

   ///Sets the board up for the beginning of the game, placing the screen
   void BoardSetup();

   ///Assign the player selection to the board.
   ///\param[in] UserPiece, whichever token the player is using for the game
   ///\param[in] x, the X-coordinate (column) to drop the token in
   void MovePiece(char userPiece, int column);

   /// Displays the screen containing the gameboard
   /// \param[in] CfScreen, the screen object used for displaying the mini-game 
   void OutputGame();

   ///Checks to see if there have been any 4 tokens in a row in the grid vector.
   bool WinCheck();

   ///Checks the entire grid to see if there is 4 of a kind in the horizontal
   ///position, returns true if it finds 4 of a kind, false otherwise.   
   bool HorizontalCheck();

   ///Checks the entire grid to see if there is 4 of a kind in the vertical
   ///position, returns true if it finds 4 of a kind, false otherwise.
   bool VerticalCheck();

   ///Checks the entire grid to see if there's 4 of a kind in the right diagonal
   ///position, returns true if it finds 4 of a kind, false otherwise.   
   bool RightDiagonalCheck();

   ///Checks the entire grid to see if there is 4 of a kind in the left diagonal
   ///position, returns true if it finds 4 of a kind, false otherwise.  
   bool LeftDiagonalCheck();
   
   void PlayAI();

///ConnectFourScreen stores and outputs the contents of the game to the
   ///terminal
   Screen ConnectFourScreen;

   ///Function which checks if a column is full, returns true if its full
   ///\param[in]input, the column selected by the user to be checked for status
   bool IsColumnFull(int input);

   ///Returns true if every space in the board has been filled with a character 
   bool IsBoardFull(); 

   ///Resets the game for another round in the event that the AI wins.
   void ResetGame();
   
   ///The vector which stores the gameboards chars.
   std::vector<vector<char>>grid;

   ///xSize is the horizontal dimensions of the game board, ySize is the
   ///vertical dimensions of the gameboard vector
   int xSize, ySize;

};
#endif
 
















