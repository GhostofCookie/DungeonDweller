//
// MemoryMatch.h
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
   ///Default constructor for MemoryMatch, sets height to: 4 and width to: 4
   MemoryMatch();

   ///Deconstructor
   virtual ~MemoryMatch();

   ///Method to run the game, serves as a 'main' for the mini-game, calling
   ///functions from private until the player has won.
   ///\param[in] player, pointer to the player, used to decrement health.
   virtual void RunGame(Character *player);

  private:
   ///Sets the board up for the beginning of the game, placing them in screen
   void BoardSetup();

   ///Setinputs assigns user input to the appropriate variables.
   ///\param[in]X1, the first x-coordinate to flip to the user.
   ///\param[in]Y1, the first y-coordinate to flip to the user.
   ///\param[in]X2, the second x-coordinate to flip to the user
   ///\param[in]Y2, the second y-coordinate to flip to the user.
   ///\param[in]menu, the menu object used for getting the input from the user.
   void SetInputs(int &x1, int &y1, int &x2, int &y2, MemoryMenu &menu);
   
   ///Checks to make sure all coordinates are within the bounds of the game
   ///board using IsInputValid helper function.
   ///\param[in]X1, the first x-coordinate to check.
   ///\param[in]Y1, the first y-coordinate to check.
   ///\param[in]X2, the second x-coordinate to check.
   ///\param[in]Y2, the second y-coordinate to check.
   bool CheckInput(int x1, int y1, int x2, int y2);

   ///IsInputValid checks to see if the input in within the bounds of the
   ///gameboard. Returns true if its valid.
   ///\param[in]input, is checked to see if it is within the bounds of the game.
   bool IsInputValid(int input);

   ///Checks if the coordinates have been matched already using the membership
   ///table stored in the match vector, returns true if they are unmatched,
   ///false if they have previously been matched
   ///\param[in] inputX1, The X-Coordinate of the first card to check
   ///\param[in] inputY1, The Y-Coordinate of the first card to check
   ///\param[in] inputX2, The X-Coordinate of the second card to check
   ///\param[in] inputY2, The Y-Coordinate of the second card to check 
   bool ValidMove(int inputX1, int inputY1, int inputX2, int inputY2);  

   ///Flips two cards and shows them to the user for a certain time, if they are
   /// a match, it leaves them face-up, otherwise flip them back down.
   ///\param[in] inputX1, The X-Coordinate of the first card to move
   ///\param[in] inputY1, The Y-Coordinate of the first card to move
   ///\param[in] inputX2, The X-Coordinate of the second card to move
   ///\param[in] inputY2, The Y-Coordinate of the second card to move
   void MovePiece(int inputX1, int inputY1, int inputX2, int inputY2);

   ///Checks if the two cards selected are a match, returns true if yes.
   ///\param[in] inputX1, The X-Coordinate of the first card to check
   ///\param[in] inputY1, The Y-Coordinate of the first card to check
   ///\param[in] inputX2, The X-Coordinate of the second card to check
   ///\param[in] inputY2, The Y-Coordinate of the second card to check
   bool MatchCheck(int inputX1, int inputY1, int inputX2, int inputY2);

   ///Checks the state of the int table to see if the player has won the game,
   ///returns true when they have completed the puzzle.
   void WinCheck();

   ///randomly puts char into the table twice.
   ///\param[in]symbol, the symbol to be inserted into the screen
   void RandomlyInsertIntoTable(char symbol);

   ///Flips the char stored at the inputted coordinates on chartable and sets
   ///them on the screen.
   ///\param[in]inputX, the x-coordinate to flip.
   ///\param[in]inputY, the y-cordinate to flip.
   void FlipTwoChars(int inputX, int inputY);

   ///Takes the char input given by the user and returns the associated index
   ///for its location within the vector as an int.
   ///\param[in]input, the character to convert to an integer index.
   int ConvertCharToIndex(char input);
   
   ///Returns a random number between 0 and n-1
   ///\param[in] n, the upper bound for the random number
   int RandomNumber(int n);

   ///Puts the values in the charTable into the screen in appropriate places among
   ///the game board
   void SaveBoardToScreen();

   ///Flips two squares and outputs it for the inputted amount of seconds and then
   ///flips them back over to hide them from the user.
   ///\param[in]lengthInSecond, the number of seconds you want to flip for
   void PeekAtBoard(int lengthInSeconds);

   ///Outputs a conclusion message to the user and then shows the puzzle results
   ///for 6 seconds before ending the game.
   void EndGamePrompt();

   ///Flips two squares and outputs it for 3 seconds then flips it back.   
   ///\param[in] inputX1, The X-Coordinate of the first card to flip
   ///\param[in] inputY1, The Y-Coordinate of the first card to flip
   ///\param[in] inputX2, The X-Coordinate of the second card to flip
   ///\param[in] inputY2, The Y-Coordinate of the second card to flip 
   void Peek(int inputX1, int inputY1, int inputX2, int inputY2);

   ///Returns true if n is odd, false if even.
   ///\param[in]n, an integer n, checks if it is odd.
   bool IsOdd(int n);
   
   ///Checks if a char is in the used pairs vector and returns true if its found
   ///\param[in]symbol, the symbol to be checked.
   bool IsInUsedPairs(char symbol);

   ///Returns true if char has a true value in the matchVector, false otherwise
   ///\param[in] inputX, The X-Coordinate of the first card to check
   ///\param[in] inputY, The Y-Coordinate of the first card to check 
   bool IsCharAlreadyMatched(int inputX, int inputY);

   ///The screen for the game to be outputted with
   Screen MemoryMatchScreen;

///The vector which holds the char values of the table to be matched
   std :: vector < vector < char > > charTable;

   ///The vector which holds the integer value for the table, 1 being
   ///matched, 0 being unmatched.
   std :: vector < vector < int > > matchVector;

   ///Vector containing symbols to be randomly inserted on the screen at start
   std :: vector < char > pairsOfCharsVector;

   ///Vector containing all pairs that have already been matched up
   std :: vector < char > usedPairs;

   ///dimensions for the gameboard
   int boardSize;
};
#endif
