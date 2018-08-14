#include "Puzzle.h"

int Puzzle::RandomNumber(int n) const
{
   ///Returns 0 to n-1
   n=rand()%n;
   return n;
}
   
void Puzzle::SecondDelay(const int seconds) const
{
	#ifdef linux
	usleep(1000000*seconds);
	#endif
}

