////////////////////////////////////////////////////////////////////////////////
///code_cracker.h
///\author Tyler Siwy
///CPSC 2720-Howard Cheng-Assignment 2
////////////////////////////////////////////////////////////////////////////////
#ifndef  CODE_CRACKER_H
#define CODE_CRACKER_H
#include "puzzle.h"

class CodeCracker: virtual Puzzle
{
  public:
   CodeCracker();
   ~CodeCracker();
   CodeCracker(const CodeCracker &copy);
   void RunGame();
  private:
   void PromptUser(&screen);
   char UserInput(&menu);
   bool ValidMove(char input);
   bool ValidCommand(char input);
   bool ValidAnswer(const string);
   void WinCheck();
   void DeathCheck();//Will need to take some kind of character variable/object
   void OutputGame(&screen);
   void ImportRiddles();//Takes riddles out of a text file and stores them
   /*The vector which holds each towers' contents. Contents are stored as
     integers.*/
   std::vector<string>>Question(3);
   std::vector<int>>Answer(3);//Answers to questions, in order.
   std::vector<string>>Format(3);//Descriptions of how to answer questions
   bool GameEnd;
}
#endif




