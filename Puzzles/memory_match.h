//
// memoery_match.h
//
/// \author Tyler Siwy
/// \date Oct 20, 2017
//  

#ifndef MEMORY_MATCH_H
#define MEMORY_MATCH_H
#include "puzzle.h"

///This class contains the mini-game/puzzle Memory Match
class MemoryMatch: virtual Puzzle
{
  public:
   ///Default constructor for MemoryMatch, sets height to: and width to:
   MemoryMatch();
   ///Deconstructor
   ~MemoryMatch();
   ///Method to run the game, serves as a 'main' for the mini-game, calling
   ///functions from private until the player has won.  
   void RunGame();

  private:
   //ALL HANDLED BY THE MENU OBJECT
   //void PromptUser(Screen &GameScreen);//Prompts user for input
   //char UserInput(Menu &MemGameMenu);//Gets user input
   //bool ValidCommand(char Input);//Checks input formatting
   
   ///Sends the menu class the options for the player to select.
   void setOptionsInMenu();

   ///Checks the semantics of the players selection
   bool ValidMove(char Input);  
   /// Displays the screen containing the gameboard
   /// \param[in] MemScreen, the screen object used for the MemoryMatch game.
   void OutputGame(Screen &MemScreen);

   ///Flips two cards and shows them to the user for a certain time, if they are
   /// a match, it leaves them face-up, otherwise flip them back down.
   ///\param[in] InputX1, The X-Coordinate of the first card to flip
   ///\param[in] InputY1, The Y-Coordinate of the first card to flip
   ///\param[in] InputX2, The X-Coordinate of the second card to flip
   ///\param[in] InputY2, The Y-Coordinate of the second card to flip
   void MovePiece(int InputX1, int InputY1, int InputX2, int InputY2);

   ///Checks if the two cards selected are a match, returns true if yes.
   ///\param[in] InputX1, The X-Coordinate of the first card to flip
   ///\param[in] InputY1, The Y-Coordinate of the first card to flip
   ///\param[in] InputX2, The X-Coordinate of the second card to flip
   ///\param[in] InputY2, The Y-Coordinate of the second card to flip 
   bool MatchCheck(int InputX1, int InputY1, int InputX2, int InputY2);

   ///Checks the state of the int table to see if the player has won the game,
   ///returns true when they have completed the puzzle.
   void WinCheck();
   
   ///The vector which holds the char values of the table to be matched
   std::vector<vector<char>>CharTable;
   ///The vector which holds the integer value for the table, 1 being matched,
   /// 0 being unmatched.
   std::vector<vector<int>> IntTable;
};
#endif
