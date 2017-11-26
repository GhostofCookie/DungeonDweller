//
// memory_match.h
//
/// \author Tyler Siwy
/// \date Oct 20, 2017
//  

#ifndef MEMORY_MATCH_H
#define MEMORY_MATCH_H
#include "Puzzle.h"
#include <unistd.h>
#include "../Menu/MemoryMenu.h"

///This class contains the mini-game/puzzle Memory Match
class MemoryMatch: virtual public Puzzle
{
  public:
   ///Default constructor for MemoryMatch, sets height to: and width to:
   MemoryMatch();

   ///Deconstructor
   virtual ~MemoryMatch();

   ///Method to run the game, serves as a 'main' for the mini-game, calling
   ///functions from private until the player has won.  
   void RunGame(Character *player);

  private:
   //ALL HANDLED BY THE MENU OBJECT
   //void PromptUser(Screen &GameScreen);//Prompts user for input
   //char UserInput(Menu &MemGameMenu);//Gets user input
   //bool ValidCommand(char Input);//Checks input formatting
   
   ///Sends the menu class the options for the player to select.
   void SetOptionsInMenu();

   ///Sets the board up for the beginning of the game, placing them in screen
   void BoardSetup();

   void SetInputs(int &X1, int &Y1, int &X2,int &Y2, MemoryMenu &menu);
   
   ///Checks the semantics of the players selection

   bool CheckInput(int x1, int y1, int x2, int y2);

   bool IsInputValid(int input);

   bool ValidMove(int inputX1, int inputY1, int inputX2, int inputY2);  

   ///Flips two cards and shows them to the user for a certain time, if they are
   /// a match, it leaves them face-up, otherwise flip them back down.
   ///\param[in] inputX1, The X-Coordinate of the first card to flip
   ///\param[in] inputY1, The Y-Coordinate of the first card to flip
   ///\param[in] inputX2, The X-Coordinate of the second card to flip
   ///\param[in] inputY2, The Y-Coordinate of the second card to flip
   void MovePiece(int inputX1, int inputY1, int inputX2, int inputY2);

   ///Checks if the two cards selected are a match, returns true if yes.
   ///\param[in] inputX1, The X-Coordinate of the first card to flip
   ///\param[in] inputY1, The Y-Coordinate of the first card to flip
   ///\param[in] inputX2, The X-Coordinate of the second card to flip
   ///\param[in] inputY2, The Y-Coordinate of the second card to flip 
   bool MatchCheck(int inputX1, int inputY1, int inputX2, int inputY2);

   ///Checks the state of the int table to see if the player has won the game,
   ///returns true when they have completed the puzzle.
   void WinCheck();

   ///randomly puts pairs into the table
   void RandomlyInsertIntoTable(char symbol);

   ///Flips the char stored at the inputted coordinates on chartable and sets
   ///them on the screen.
   void FlipTwoChars(int inputX, int inputY);

   int ConvertCharToIndex(char input);
   
   ///Returns a random number between 0 and n-1 
   int RandomNumber(int n);

///Puts the values in the charTable into the screen in appropriate places among
///the game board
   void SaveBoardToScreen();

   void PeekAtBoard(int lengthInSeconds);

   void EndGamePrompt();
   
   ///Causes a "seconds" delay in the program process
   void SecondDelay(int seconds);

   ///Flips two squares and outputs it for 3 seconds then flips it back.   
   void Peek(int inputX1, int inputY1, int inputX2, int inputY2);

   ///Returns true if n is odd, false if even.
   bool IsOdd(int n);
   
//Checks if a char is in the used pairs vector
   bool IsInUsedPairs(char symbol);

   ///Returns true if char has a true value in the matchVector, false otherwise
   bool IsCharAlreadyMatched(int inputX, int inputY);
   
   Screen MemoryMatchScreen;

///The vector which holds the char values of the table to be matched
   std::vector<vector<char>>charTable;

   ///The vector which holds the integer value for the table, 1 being
   ///matched, 0 being unmatched.
   std::vector<vector<int>>matchVector;

   ///Vector containing symbols to be randomly inserted on the screen at start
   std::vector<char>pairsOfCharsVector;

   ///Vector containing all pairs that have already been matched up
   std::vector<char>usedPairs;

   ///dimensions for the gameboard
   int boardSize;
};
#endif
