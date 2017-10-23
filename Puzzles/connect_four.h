////////////////////////////////////////////////////////////////////////////////
///connect_four.h
///\author Tyler Siwy
///CPSC 2720-Howard Cheng-Assignment 2
////////////////////////////////////////////////////////////////////////////////
#ifndef  CONNECT_FOUR_H
#define CONNECT_FOUR_H
#include "puzzle.h"
class ConnectFour: virtual puzzle
{
   ConnectFour();
   ~ConnectFour();
   ConnectFour(const ConnectFour &copy);
   void RunGame();
  private:
   void PromptUser(&screen);
   char UserInput(&menu);
   bool ValidMove(char input);
   bool ValidCommand(char input);
   void OutputGame(&screen);
   std::vector<vector<char>>Grid;   
}
#endif
 
















