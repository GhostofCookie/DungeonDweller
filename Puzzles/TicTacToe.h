//
// tic_tac_toe.h
//
/// \author Tyler Siwy
/// \date Oct 20, 2017
//

#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H
#include "Puzzle.h"
#include "../Menu/ConnectFourMenu.h"
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
   virtual void RunGame();
   
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

   ///Sends the menu class the options for the player to select.
   void SetOptionsInMenu();

   /// Displays the screen containing the gameboard
   /// \param[in] inputX, the X-coordinate of the selection.
   /// \param[in] inputY, the Y-coordinate of the selection.
   void MovePiece(int inputX, int inputY, char userPiece);

   ///Checks the board to see if there are any 3 of a kind for either player
   void WinCheck();

   ///Performs the selection for the npc opponent.
   void AiMove();
   
   ///Vector to store the contents of the gameboard
   std::vector<vector<char>>gameBoard;

   int boardSize;

   ///Screen tttScreen;
};
#endif
