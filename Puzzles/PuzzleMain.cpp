#include "Hanoi.h"
#include "ConnectFour.h"
#include "TicTacToe.h"
#include "MemoryMatch.h"
#include "CodeCracker.h"
#include <unistd.h>
#include <ctime>
#include <iostream>
using namespace std;

int main(){
   srand(time(NULL));
   //Hanoi HanoiTest;
   ConnectFour ConnectFourTest;
   //MemoryMatch mmTest;
   //TicTacToe ttt;
   // CodeCracker cc;
   
//HanoiTest.RunGame();
ConnectFourTest.RunGame();
   //mmTest.RunGame();
   //ttt.RunGame();
   //cc.RunGame();

   return 0;
}

   
