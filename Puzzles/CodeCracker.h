//
// CodeCracker.h
//
/// \author Tyler Siwy
/// \date Oct 20, 2017
//

#ifndef  CODE_CRACKER_H
#define CODE_CRACKER_H
#include "Puzzle.h"
#include "../Menu/RiddleMenu.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

///This class contains the mini-game/puzzle Code Cracker
class CodeCracker: public virtual Puzzle
{
  public:
   ///Default constructor for hanoi, reads in riddles from .txt files
   CodeCracker();

   ///Deconstructor
   virtual ~CodeCracker();

   ///Method to run the game, serves as a 'main' for the mini-game, calling
   ///functions from private until the player has won.
   ///\param[in] player, a pointer to the players character for changing stats.
   virtual void RunGame(Character *player);

  private:
   ///Checks to see if the user input is one of the accepted answers.
   ///\param[in] Input, an answer to the riddle in the form of the char.
   ///\param[in] riddleIndex, location of the puzzles answer in riddle vector
   bool ValidAnswer(int input, int riddleIndex);

   ///Checks if the riddle has already been used so that the player doesn't do
   ///the same one twice, returns true if it has been used already.
   ///\param[in] index, location of the riddle in the riddle vector
   bool IsRiddleUsed(int index);
   
   ///Checks if the player has successfully answered 3 riddles and sets
   ///PuzzlEnd to true if they have.
   void WinCheck();

   ///Outputs the initial message to the player
   ///\param[in] menu, the menu object to be set and then outputted.
   void InitialPrompt(RiddleMenu &menu);
   
   ///Checks if the player is now dead and ends the game if yes
   ///\param[in] player, a pointer to the players character passed from main.
   void DeathCheck(Character *player);
   
   ///Outputs the selected riddle, limiting the characters to a set length
   ///and moving them down to the next line if the string is longer than they
   ///limit.
   ///\param[in]index, the location of the riddle to output.
   void OutputRiddle(int index);
   
   ///Imports riddles from a text file and stores them in the riddles vector.
   void ImportRiddles();

   ///Sets a riddle in the games menu so that it can be outputted to the user.
   ///\param[in]riddleIndex, the location of the riddle in the riddle vector.
   ///\param[in]menu, the menu object to be saved to and then outputted.
   void SetRiddleInMenu(int riddleIndex, RiddleMenu &menu);

   ///Sets a riddles index to false in the membership table usedRiddles.
   ///\param[in]currentRiddle, the riddle to switch the truth value for
   void MakeRiddleUsed(int currentRiddle);

   ///Picks one of the unused riddles randomly and returns its index
   int UnusedRandomRiddle();

   
   ///Vector to store the question strings read in from the file 
   std::vector < string > question;

   ///Vector to store the questions answers read in from the file, in order
   std::vector < int > answer;

   ///Stores the indexes of all used riddle strings so that they aren't asked
   ///twice.
   std::vector < bool > usedRiddles;

   ///Total riddles compeleted
   int riddleCompletionCount;

   ///Total number of riddles imported into the game
   int numberOfRiddles;

   ///incorrectPrompt is the message to be displayed to the user in the case
   ///where they get a question wrong, correctPrompt is for when they get the
   ///question correct.
   string incorrectPrompt, correctPrompt;
};
#endif




