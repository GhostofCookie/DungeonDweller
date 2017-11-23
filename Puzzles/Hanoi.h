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
#include "../Image/DefaultImg.h"
#include <stack>
#include <iostream>
using namespace std;

///This class contains the mini-game/Puzzle Towers of Hanoi
class Hanoi: public virtual Puzzle
{
  public:
   /// Default constructor for hanoi, sets height to: and width to:
   Hanoi();

   ///Deconstructor
   ~Hanoi();

   ///Method to run the game, serves as a 'main' for the mini-game, calling
   ///functions from private until the player has won.
   void RunGame();

  private:
   ///Checks to see if the target stack has a larger disc than that of the
   ///source stack, returns false if target is smaller than source.
   ///\param[in]sourceStack, used for comparison against target stack
   ///\param[in]targetStack, used for comparison against source stack
   bool ValidMove(const int sourceStack, const int targetStack) const;

   ///Sends the menu class the options for the player to select.
   void SetOptionsInMenu();

   ///Checks the state of Tower to see if the player has won the game,
   ///sets PuzzleEnd to true when they have completed the puzzle by getting all
   ///discs to the fourth peg.
   void WinCheck();

   ///Moves the piece the depending on which option the player selects
   /// \param[in] userSelection, the option of moves the player chose
   void LogicSwitch(const char userSelection);

   ///Moves the disc from source tower to target tower.
   void MovePiece(int sourceTower, int targetTower);
   
   ///Function which clears the discs previous location from the screen object
   ///You cannot use the erase function in the screen class because you would
   ///have to re-draw everything afterwards and the nature of a stack does not
   ///give you access to elements not on top.
   ///\param[in] targetTower, the tower which you wish to have cleared on top.
   void ClearTopDisc(int targetTower);

   ///Sets up the screen with the appropriate game board.
   void BoardSetup();

   ///Moves the disc on the screen from the sourcestack to the targetstack
   ///\param[in] sourceStack, the tower to copy the disc from
   ///\param[in] targetStack, the tower to copy the disc to
   void DrawDiscOnTargetStack(int sourceStack, int targetStack);
   
   /// The vector which holds each towers' defaultImg
   std::vector<stack<DefaultImg>>tower;
   
   /// Number of stacks in the game
   ///X-coordinate size in the tower vector
   int numberOfStacks;
   
   /// Maintains the height of the stacks in the game
   int maxStackHeight;
   
   ///HanoiScreen stores and outputs the contents of the game to the terminal
   Screen HanoiScreen;
   
   /// GameMenu is used for handling input
   HanoiMenu HanoiGameMenu;
   
   string menuOption1, menuOption2, menuOption3,
      menuOption4, menuOption5, menuOption6;
};
#endif
