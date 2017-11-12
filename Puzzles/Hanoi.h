//
// hanoi.h
//
/// \author Tyler Siwy
/// \date Oct 20, 2017
//

#ifndef HANOI_H
#define HANOI_H
#include "Puzzle.h"
#include "../Menu/HanoiMenu.h"
#include "../Screen/Screen.h"
#include "../Image/Default.h"
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
   //ALL HANDLED BY THE MENU OBJECT
   //void PromptUser(&screen);//Prompts user for input
   //char UserInput(Menu &menu);//Gets user input
   //bool ValidCommand(char input);//Checks Formatting

   ///Checks the semantics of the user choice to make sure they aren't doing
   ///something that would break the game with their input. 
   ///\param[in]input, has been checked for syntax by input method
  bool ValidMove(const int currentStack,const int newStack) const;

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
   ///Fills the appropriate space on the screen depending on the disc size and
   ///coordinates passed to the function.
   /// \param[in] discSize, the size of the disc to be printed on screen
   /// \param[in] peg, which peg is the disc being moved to.
   void SetScreenSpaces(int discSize, int targetPeg);
   ///Clears the appropriate space on the screen depending on the disc size
   ///and the coordinates passed to the function.
   /// \param[in] discSize, the size of the disc to be cleared off of the screen.
   /// \param[in] xCoordinate, the x coordinate of the center of the disc
   /// \param[in] yCoordinate, the y coordinate of the disc. 
   void ClearScreenSpaces(int discSize, int xCoordinate, int yCoordinate);

   ///WhichDiscFromSize returns an index to wich disc in discsVector the size is
   ///referenced with
   /// \param[in]size, the size of disc we wouild like to know the location of
   int WhichDiscFromSize(int size);
   
   /// The vector which holds each towers' contents. Contents are stored as
   /// integers.
   std::vector<stack<DefaultImage>>tower;

   /// Number of stacks in the game
   ///X-coordinate size in the tower vector
   int numberOfStacks;
   /// Maintains the height of the stacks in the game
   int maxStackHeight;
   /// Used for the loop to see if the game has ended yet
   bool GameEnd;
   ///HanoiScreen stores and outputs the contents of the game to the terminal
   Screen HanoiScreen;
   /// GameMenu is used for handling input
   HanoiMenu HanoiGameMenu;
   ///A vector to store the size of all the discs in the game, stored in
   ///ascending order of size of discs. 0=3,1=7,2=11,3=15
   std::vector<DefaultImage>discsVector;
   /// MenuOption strings are used for outputting options to the user
   string menuOption1, menuOption2, menuOption3, menuOption4;
};
#endif
