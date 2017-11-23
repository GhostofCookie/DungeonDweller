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
   //ALL HANDLED BY THE MENU OBJECT
   //void PromptUser(&screen);//Prompts user for input
   //char UserInput(Menu &menu);//Gets user input
   //bool ValidCommand(char input);//Checks Formatting

   ///Checks the semantics of the user choice to make sure they aren't doing
   ///something that would break the game with their input. 
   ///\param[in]input, has been checked for syntax by input method
   bool ValidMove(const int currentStack, const int newStack) const;

   ///Sends the menu class the options for the player to select.
   void SetOptionsInMenu();

   ///Checks the state of Tower to see if the player has won the game,
   ///sets GameEnd to true when they have completed the puzzle.
   void WinCheck();

   ///Moves the piece the depending on which option the player selects
   /// \param[in] userSelection, the option of moves the player chose
   void LogicSwitch(char userSelection);

   ///Moves the disc from source tower to target tower.
   void MovePiece(int sourceTower, int targetTower);

   
   ///WhichDiscFromSize returns an index to wich disc in discsVector the size is
   ///referenced with
   /// \param[in]size, the size of disc we wouild like to know the location of
   int WhichDiscFromSize(int size);

   ///Function which clears the discs previous location from the screen object
   ///You cannot use the erase function in the screen class because you would
   ///have to re-draw everything afterwards and the nature of a stack does not
   ///give you access to elements not on top.
   void ClearTopDisc(int targetTower);

   void BoardSetup();

   void DrawDiscOnTargetStack(int targetSize, int sourceStack);
   
   /// The vector which holds each towers' defaultImg
   std::vector<stack<DefaultImg>>tower;
   
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
   
   string menuOption1, menuOption2, menuOption3,
      menuOption4, menuOption5, menuOption6;
};
#endif
