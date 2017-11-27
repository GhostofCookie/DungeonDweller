#include "Puzzle.h"

int Puzzle::RandomNumber(int n) const
{
   ///Returns 0 to n-1
   n=rand()%n;
   return n;
}
   
void Puzzle::SecondDelay(int seconds)
{
   usleep(1000000*seconds);
}

