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
   int input;
   srand(time(NULL));
   Hanoi HanoiTest;
   ConnectFour ConnectFourTest;
   TicTacToe ttt;
   MemoryMatch mmTest;
   CodeCracker cc;
   cout << "1:Hanoi     2:ConnectFour     3:TicTacToe     4:MemoryMatch      5:CodeCracker" <<endl;
   cin >> input;
      switch(input)
      {
	 case 1:
	    HanoiTest.RunGame();
	    break;
	 case 2:
	    ConnectFourTest.RunGame();
	    break;
	 case 3:
	    ttt.RunGame();
	    break;
	 case 4:
	    mmTest.RunGame();
	    break;
	 case 5:
	    cc.RunGame();
	    break;
      }
   return 0;
}

   
