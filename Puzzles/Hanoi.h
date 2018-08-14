//
// hanoi.h
//
/// \author Tyler Siwy
/// \date Oct 20, 2017
//

#pragma once

#include "Puzzle.h"
#include "../Menu/HanoiMenu.h"
#include "../Screen/Screen.h"
#include "../Image/DefaultImg.h"
#include <stack>
#include <iostream>


///brief This class contains the mini-game/Puzzle Towers of Hanoi, to be called from the main dugeonDweller program using RunGame();
class Hanoi: public virtual Puzzle
{
  public:
   /// Default constructor for hanoi, sets height to: 4 and width to: 3
   Hanoi();

   ///Deconstructor
   ~Hanoi();

   ///Method to run the game, serves as a 'main' for the mini-game, calling
   ///functions from private until the player has won.
   ///\param[in] player, reference to the player for editing player stats
   virtual void RunGame(Character *player);

  private:
   ///Checks to see if the target stack has a larger disc than that of the
   ///source stack, returns false if target is smaller than source.
   ///\param[in]sourceStack, used for comparison against target stack
   ///\param[in]targetStack, used for comparison against source stack
   bool ValidMove(const int sourceStack, const int targetStack) const;

   ///Setup the options in the HanoiMenu object for the player to select. 
   void SetOptionsInMenu();

   ///Checks the state of Tower to see if the player has won the game,
   ///sets PuzzleEnd to true when they have completed the puzzle by getting all
   ///discs to the fourth peg.
   void WinCheck();

   ///Moves the piece the depending on which option the player selects
   /// \param[in] userSelection, the option of moves the player chose
   void LogicSwitch(const char userSelection);

   ///Moves the piece in the std::vector.stack and calls the helper function to move the
   ///images on the screen.
   ///\param[in]sourceTower, the stack from which we move the disc image.
   ///\param[in]targetTower, the stack to which we move the disc image.
   void MovePiece(int sourceTower, int targetTower);
   
   ///Function which clears the discs previous location from the screen object
   ///You cannot use the erase function in the screen class because you would
   ///have to re-draw everything afterwards and the nature of a stack does not
   ///give you access to elements not on top.
   ///\param[in] targetTower, the tower which you wish to have cleared on top.
   void ClearTopDisc(int targetTower);

   ///Sets up the discs on the gameboard for the beginning of the game.
   void DiscSetup();

   ///Outputs the end of game text and changes the players stats
   void EndGamePrompt(Character *player);
   
   ///Outputs an appropriate error message of the user tries to move a disc
   ///from an empty stack
   void EmptyPrompt();
      
   ///Helper function for discSetup, pushes a disc on the left stack at the
   ///height specified by bottom.
   ///\param[in] bottom, the height to place the disc at.
   ///\param[in] disc, the disc you wish to push into the std::vector.
   void PushDiscOnLeftStack(int bottom, DefaultImg disc);
   
   ///Sets up the screen with the appropriate game board.
   void BoardSetup();

   ///Moves the disc on the screen from the sourcestack to the targetstack
   ///\param[in] sourceStack, the tower to copy the disc from
   ///\param[in] targetStack, the tower to copy the disc to
   void DrawDiscOnTargetStack(int sourceStack, int targetStack);
   
   /// The std::vector which holds each towers' defaultImg
   std::vector<std::stack<DefaultImg>>tower;
   
   /// Number of stacks in the game
   ///X-coordinate size in the tower std::vector
   int numberOfStacks;
   
   /// Maintains the height of the stacks in the game
   int maxStackHeight;

   std::string endGamePrompt;
   
   ///HanoiScreen stores and outputs the contents of the game to the terminal
   Screen HanoiScreen;
   
   /// GameMenu is used for handling input
   HanoiMenu HanoiGameMenu;
};
