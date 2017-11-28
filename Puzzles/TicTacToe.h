//
// tic_tac_toe.h
//
/// \author Tyler Siwy
/// \date Oct 20, 2017
//

#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H
#include "Puzzle.h"
#include "../Menu/TicTacToeMenu.h"
#include "../Screen/Screen.h"
#include "../Image/DefaultImg.h"
#include <iostream>
using namespace std;

///This class contains the mini-game/puzzle Tic Tac Toe
class TicTacToe: public virtual Puzzle
{
  public:
   ///Default constructor for TicTacToe, sets height to 3 and width to 3
   TicTacToe();

   ///Deconstructor
   virtual ~TicTacToe();

   ///Method to run the game, serves as a 'main' for the mini-game, calling
   ///functions from private until the player has won.   
   virtual void RunGame(Character *player);
   
  private:
   ///ALL HANDLED BY THE MENU OBJECT?
   //void PromptUser(&screen);//Prompts user for input
   //char UserInput(&menu);//Gets user input
   //bool ValidCommand(char input);//Checks formatting

   ///Checks the semantics of the user choice to make sure they aren't doing
   ///something that would break the game with their input.
   /// \param[in] inputX, the X-coordinate of the selection.
   /// \param[in] inputY, the Y-coordinate of the selection. 
   bool ValidMove(int inputX, int inputY);

   ///Sets the board up for the beginning of the game, placing the grid
   void BoardSetup();

   /// Displays the screen containing the gameboard
   /// \param[in] inputX, the X-coordinate of the selection.
   /// \param[in] inputY, the Y-coordinate of the selection.
   void MovePiece(int inputX, int inputY, char userPiece);

   void EndGamePrompt(int &currentPlayer, TicTacToeMenu menu, Character *player);
      
   ///Checks to see if there have been any 3 tokens in a row in the grid vector.
   bool WinCheck();

   bool TieGameCheck(int &currentPlayer);
   
   ///Performs the selection for the npc opponent.
   void AiMove(char AiPiece);

   ///Checks the entire grid to see if there is 3 of a kind in a horizontal
   ///position, returns true if it finds 3 of a kind, false otherwise.   
   bool HorizontalCheck();

   ///Checks the entire grid to see if there is 3 of a kind in a vertical
   ///position, returns true if it finds 3 of a kind, false otherwise.
   bool VerticalCheck();

   ///Checks the entire grid to see if there's 3 of a kind in a right diagonal
   ///position, returns true if it finds 3 of a kind, false otherwise.   
   bool RightDiagonalCheck();

   ///Checks the entire grid to see if there is 3 of a kind in a left diagonal
   ///position, returns true if it finds 3 of a kind, false otherwise.  
   bool LeftDiagonalCheck();

   bool IsInputValid(char inputX, int inputY);

   bool IsIntInputValid(int inputY);
   
   ///Checks who's turn it is and sets CurrentPlayerChar to their
   ///correct char.
   void SetCurrentPlayersChar(int currentPlayer);

   void ResetGame(int &currentPlayer);

   int ConvertCharCoordinateToIndex(char input);
   
   ///Vector to store the contents of the gameboard
   std::vector < vector < char > > gameBoard;

   ///Dimensions for the board
   int boardSize;

   char currentPlayerChar;
   
   ///returns true if character is filled, false otherwise
   bool IsSpotFilled(int inputX, int inputY);

///Returns true if every space in the board has been filled with a character 
   bool IsBoardFull();

   ///Resets the game for another round in the event that the AI wins.
   void ResetGame();

   ///TicTacToeScreen stores and outputs the contents of the game to the
   ///terminal
   Screen TicTacToeScreen;

   ///TicTacToeMenu tttMenu;
};
#endif
