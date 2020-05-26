#include "Hanoi.h"
#include "ConnectFour.h"
#include "TicTacToe.h"
#include "MemoryMatch.h"
#include "CodeCracker.h"
#include <ctime>
#include <iostream>


int main(){
   Character *Player=new Character;
   int input;
   srand(time(NULL));
   Hanoi HanoiTest;
   ConnectFour ConnectFourTest;
   TicTacToe ttt;
   MemoryMatch mmTest;
   CodeCracker cc;
   std::cout << "1:Hanoi     2:ConnectFour     3:TicTacToe     4:MemoryMatch      5:CodeCracker" <<std::endl;
   std::cin >> input;
   switch(input)
   {
      case 1:
	 HanoiTest.RunGame(Player);
	 break;
      case 2:
	 ConnectFourTest.RunGame(Player);
	 break;
      case 3:
	 ttt.RunGame(Player);
	 break;
      case 4:
	 mmTest.RunGame(Player);
	 break;
      case 5:
	 cc.RunGame(Player);
	 break;
   }
   delete Player;
   return 0;
}

   
