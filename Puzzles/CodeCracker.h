//
// code_cracker.h
//
/// \author Tyler Siwy
/// \date Oct 20, 2017
//

#ifndef  CODE_CRACKER_H
#define CODE_CRACKER_H
#include "Puzzle.h"
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
   void RunGame();

  private:
//ALL HANDLED BY THE MENU OBJECT
//void PromptUser(&screen);
//char UserInput(Menu &menu);
//bool ValidCommand(char input);
   
///Checks the semantics of the user choice to make sure they aren't doing
///something that would break the game with their input.
///\param[in]input, has been checked for syntax by input method  
   bool ValidMove(char input);

///Checks to see if the user input is one of the accepted answers.
///\param[in] Input, an answer to the riddle in the form of the char.
   bool ValidAnswer(const char input);
   
///Checks if the player has successfully answered 3 riddles.
   void WinCheck();

///Checks if the player is now dead
   void DeathCheck();//Will need to take some kind of character variable/object

///Imports riddles from a text file and stores them in the vector.
   void ImportRiddles();

void SetOptionsInMenu();
   
///Vector to store the question strings read in from the file 
std::vector<string>question;

///Vector to store the descriptions on how to answer each question, in order.
std::vector<string>format;//Descriptions of how to answer questions

///Vector to store the questions answers read in from the file, in order
std::vector<int>answer;

int riddleCompletionCount;

int numberOfRiddles;

bool riddleCorrect;
};
#endif




