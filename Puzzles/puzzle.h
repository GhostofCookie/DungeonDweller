#ifndef PUZZLE_H
#define PUZZLE_H
//#include "slotscreen.h
#include "Menu.h"
#include <iostream>
using namespace std;

class Puzzle
{
  public:
   Puzzle();
   virtual ~Puzzle();
   Puzzle(const Puzzle &copy);
   virtual void RunGame();
  protected:
   //virtual void PromptUser(screen &screen);
   virtual char UserInput(Menu &menu);
   virtual bool ValidMove(char input);
   //virtual bool ValidCommand(char input);
  private:
   bool puzzleState;
};
#endif
