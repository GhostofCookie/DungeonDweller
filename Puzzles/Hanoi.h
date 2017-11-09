//
// hanoi.h
//
/// \author Tyler Siwy
/// \date Oct 20, 2017
//

#ifndef HANOI_H
#define HANOI_H
#include "Puzzle.h"
#include <iostream>
using namespace std;

///This class contains the mini-game/Puzzle Towers of Hanoi
class Hanoi: public virtual Puzzle
{
  public:
   /// Default constructor for hanoi, sets height to: and width to:
   Hanoi();

   ///Deconstructor
   virtual ~Hanoi();

   ///Method to run the game, serves as a 'main' for the mini-game, calling
   ///functions from private until the player has won.
   void RunGame();

  private:
   //ALL HANDLDED BY THE MENU OBJECT
   //void PromptUser(&screen);//Prompts user for input
   //char UserInput(Menu &menu);//Gets user input
   //bool ValidCommand(char input);//Checks Formatting

   ///Checks the semantics of the user choice to make sure they aren't doing
   ///something that would break the game with their input. 
   ///\param[in]input, has been checked for syntax by input method
   bool ValidMove(int input);

   ///Sends the menu class the options for the player to select.
   void SetOptionsInMenu();

   ///Checks the state of Tower to see if the player has won the game,
   ///returns true when they have completed the puzzle.
   void WinCheck();

   ///Moves the piece the depending on which option the player selects
   /// \param[in] userSelection, the option of moves the player chose
   void MovePiece(int userSelection);

   /// Displays the screen containing the gameboard
   /// \param[in] HanoiScreen, the screen object used for the hanoi game.
   void OutputGame(Screen &hScreen);

   /// The vector which holds each towers' contents. Contents are stored as
   /// integers.
   std::vector<vector<int>>tower;
   
   ///X-coordinate size in the tower vector
   int xSize;

   /// Y-Coordinate size in the tower vector
   int ySize;

   /// Used for the loop to see if the game has ended yet
   bool GameEnd;
};
#endif
