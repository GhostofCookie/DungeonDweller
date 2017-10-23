//
// hanoi.h
//
/// \author Tyler Siwy
/// \date Oct 20, 2017
//
#ifndef HANOI_H
#define HANOI_H
#include "puzzle.h"


class Hanoi: public virtual Puzzle
{
  public:
   Hanoi();
   ~Hanoi();
   void RunGame();
  private:
   //void PromptUser(&screen);
   //char UserInput(Menu &menu);
   //bool ValidMove(char input);
   void setOptionsInMenu();
   void WinCheck();
   void MovePiece(int userSelection);
   //void OutputGameBoard(&screen);
   /*The vector which holds each towers' contents. Contents are stored as
     integers.*/
   std::vector<vector<int>>Tower;
   int x;//X-coordinate size in the table
   int y;//Y-Coordinate size in the table
   bool GameEnd;
   //Menu menu;
};
#endif