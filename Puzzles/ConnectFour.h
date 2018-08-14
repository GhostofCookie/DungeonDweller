//
// connect_four.h
//
/// \author Tyler Siwy
/// \date Oct 20, 2017
//  

#pragma once

#ifdef __linux__
#include <unistd.h>
#endif

#ifdef _WIN32
// Place windows unistd.h equivalent.
#endif

#include <ctime>
#include "Puzzle.h"
#include "../Menu/ConnectFourMenu.h"
#include "../Screen/Screen.h"
#include "../Image/DefaultImg.h"

///This class contains the mini-game/puzzle Connect Four
class ConnectFour: virtual public Puzzle
{
  public:
   ///Default constructor for ConnectFour, sets heigh to : and width to:
   ConnectFour();
   ///De-constructor
   virtual ~ConnectFour();

   ///Method to run the game, serves as a 'main' for the mini-game, calling
   ///functions from private until the player has won.  
   virtual void RunGame(Character *player);

  private:
   ///Assign the player selection to the board.
   ///\param[in] UserPiece, whichever token the player is using for the game
   ///\param[in] x, the X-coordinate (column) to drop the token in
   void MovePiece(char userPiece, int column);

   ///The function which initiates the computers turn.
   ///\param[in] AiPiece, the current user piece.
   void PlayAI(char AiPiece);

   ///Checks the semantics of the user choice to make sure they aren't doing
   ///something that would break the game with their input. 
   ///\param[in]input, has been checked for syntax by input method
   bool ValidMove(int input);

   ///Checks to see if the players input is larger than the game board.
   ///\param[in] The input to be checked, returns false if input out of bounds.
   bool IsInputOutOfScope(int input);

   ///Checks to see if there have been any 4 tokens in a row in the grid std::vector.
   bool WinCheck();

   ///Checks the entire grid to see if there is 4 of a kind in the horizontal
   ///position, returns true if it finds 4 of a kind, false otherwise.   
   bool HorizontalCheck();

   ///Checks the entire grid to see if there is 4 of a kind in the vertical
   ///position, returns true if it finds 4 of a kind, false otherwise.
   bool VerticalCheck();

   ///Checks the entire grid to see if there is 4 of a kind in the left diagonal
   ///position, returns true if it finds 4 of a kind, false otherwise.  
   bool LeftDiagonalCheck();
   
   ///Checks the entire grid to see if there's 4 of a kind in the right diagonal
   ///position, returns true if it finds 4 of a kind, false otherwise.   
   bool RightDiagonalCheck();

   ///Function which checks if a column is full, returns true if its full
   ///\param[in]input, the column selected by the user to be checked for status
   bool IsColumnFull(int input);

   ///Returns true if every space in the board has been filled with a character 
   bool IsBoardFull(); 

   ///Checks to see if no player has won the game, returns true if there's a tie.
   ///\param[in]currentPlayer, used to reset the player char for another round.
   bool TieGameCheck(int &currentPlayer);

   ///Sets the board up for the beginning of the game, plastd::cing them in screen
   void BoardSetup();
   
   ///Prompts the player and handles the end of the game appropriately.
   ///\param[in] currentPlayer, assigned to be human for new game.
   ///\pram[in] menu, the menu used to output stuffs
   ///\param[in] player, a pointer to the player usd to modify stats
   void EndGamePrompt(int &currentPlayer, ConnectFourMenu &menu
		      , Character *player);
   
   ///Resets the game for another round in the event that the AI wins.
   void ResetGame(int &currentPlayer);

   ///Sets the currenPlayerChar appropriately based on which parameters.
   ///\param[in]currentPlayer, even number=ai, odd number=human player.
   void SetCurrentPlayerChar(int currentPlayer);

   ///ConnectFourScreen stores and outputs the contents of the game to the
   ///terminal
   Screen ConnectFourScreen;
   
   ///The std::vector which stores the gameboards chars.
   std::vector < std::vector <char> > grid;

   ///currentPlayerChar keeps track of which character to insert depending on
   ///whos turn it is.
   char currentPlayerChar;
   
   ///xSize is the horizontal dimensions of the game board, ySize is the
   ///vertical dimensions of the gameboard std::vector
   int xSize, ySize;

};

