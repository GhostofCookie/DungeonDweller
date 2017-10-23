////////////////////////////////////////////////////////////////////////////////
///memory_match.h
///\author Tyler Siwy
///CPSC 2720-Howard Cheng-Dungeon Dweller
////////////////////////////////////////////////////////////////////////////////
#ifndef MEMORY_MATCH_H
#define MEMORY_MATCH_H
#include "puzzle.h"

class MemoryMatch: virtual Puzzle
{
  public:
   MemoryMatch();
   ~MemoryMatch();
   MemoryMatch(const MemoryMatch &copy);
   void RunGame();
  private:
   void PromptUser(&Screen);
   char UserInput(&Menu);
   bool ValidMove(char Input);
   bool ValidCommand(char Input);
   void OutputGame(&Screen);
   char UserInput(&Menu); //Might need to be a menu on its own.
   void ChangeState();
   void MatchCheck();
   
   /*The vector which holds each towers' contents. Contents are stored as
     integers.*/
   std::vector<vector<char>>CharTable;
   std::vector<vector<IntTable;
}
#endif
