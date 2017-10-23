////////////////////////////////////////////////////////////////////////////////
///tic_tac_toe.h
///\author Tyler Siwy
///CPSC 2720-Howard Cheng-Dungeon Dweller
////////////////////////////////////////////////////////////////////////////////
#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H
#include "puzzle.h"

class TicTacToe: public virtual Puzzle
{
  public:
   TicTacToe();
   virtual ~TicTacToe();
   virtual void RunGame();
  private:
   //virtual void PromptUser(&screen);
   virtual char UserInput(Menu &menu);
   virtual bool ValidMove(char input);
   virtual bool ValidCommand(char input);
//void OutputGame(&screen);//Outputs the contents of the board
   void ChangeState(char input); //Switches a square from blank to an x or o
   void WinCheck(); //Checks the board for a win
   void AiMove(); //Moves for the npc
   //bool puzzleState;
   //Menu puzzleMenu;
   std::vector<vector<char> > GameBoard;
};
#endif
