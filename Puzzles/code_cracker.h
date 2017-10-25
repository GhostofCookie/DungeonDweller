//
// code_cracker.h
//
/// \author Tyler Siwy
/// \date Oct 20, 2017
//

#ifndef  CODE_CRACKER_H
#define CODE_CRACKER_H
#include "puzzle.h"

///This class contains the mini-game/puzzle Code Cracker
class CodeCracker: virtual Puzzle
{
  public:
   ///Default constructor for hanoi, reads in riddles from .txt files
   CodeCracker();
   ///Deconstructor
   ~CodeCracker();
   void RunGame();
  private:
   //ALL HANDLDED BY THE MENU OBJECT
   //void PromptUser(&screen);
   //char UserInput(Menu &menu);
   //bool ValidCommand(char input);
   
   ///Checks the semantics of the user choice to make sure they aren't doing
   ///something that would break the game with their input.
   ///\param[in]input, has been checked for syntax by input method  
   bool ValidMove(char Input);
   ///Checks to see if the user input is one of the accepted answers.
   ///\param[in] Input, an answer to the riddle in the form of the char.
   bool ValidAnswer(const char Input);
   
   void WinCheck();
///Checks if the player is now dead
   void DeathCheck();//Will need to take some kind of character variable/object
   /// Displays the screen containing the gameboard
   /// \param[in] CfScreen, the screen object used for displaying the mini-game 
   void OutputGame(Screen &CcScreen);
   ///Imports riddles from a text file and stores them in the vector.
   void ImportRiddles();
   ///Vector to store the question strings read in from the file 
   std::vector<string>>Question(3);
   ///Vector to store the questions answers read in from the file, in order
   std::vector<int>>Answer(3);
   ///Vector to store the descriptions on how to answer each question, in order.
   std::vector<string>>Format(3);//Descriptions of how to answer questions
}
#endif




