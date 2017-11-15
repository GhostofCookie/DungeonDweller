#include "Hanoi.h"
#include "ConnectFour.h"
#include "TicTacToe.h"
#include "MemoryMatch.h"
#include <unistd.h>
#include <ctime>
#include <iostream>
using namespace std;

int main(){
   srand(time(NULL));
   //Hanoi HanoiTest;
   //ConnectFour ConnectFourTest;
   //ConnectFourTest.RunGame();
   //HanoiTest.RunGame();
   //TicTacToe ttt;
   //ttt.RunGame();
   //ConnectFour Cf;
   MemoryMatch mmTest;
   mmTest.RunGame();
   //HanoiTest.RunGame();
   return 0;
}

   
