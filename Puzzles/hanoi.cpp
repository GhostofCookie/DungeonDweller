//
// hanoi.cpp
//
/// \author Tyler Siwy
/// \date Oct 20, 2017
//
#include "hanoi.h"

Hanoi::Hanoi()
{
   y=3;
   x=4;
   Tower.resize(y);
   for(int i=0; i<y; i++)
   {
      Tower.at(i).resize(x);
      for(int j=0; j<x; j++)
	 Tower.at(i).at(j)='*';
   }
}

Hanoi::~Hanoi()
{
   
}

// void Hanoi::PromptUser()
// {
//    cout << "The door is locked, there is three pressure plates in front of you"
// 	<< "with rods pertruding from them. Fixed on the far left is 4 disks,"
// 	<< "all different sizes. In order to open the door you must move them"
// 	<< " one at a time to the right side. They must be in order on the "
// 	<< "third rod." << endl;
// }

// int Hanoi::UserInput(Menu &menu)
// {
//    int input;
//    cin >> input;
//    getline(cin, garbage);///<Used to clear the buffer.
//    if(cin.fail())
//    {
//       cin.clear();
//       cout << "Throw exception, invalid selection" << endl;
//    }
//    return input;	 
// }

// bool Hanoi::ValidMove(char input)
// {

// }

void Hanoi::WinCheck()
{
   bool win=false;
   //Check if the game has been won
   if(win==true)
      PuzzleEnd=true;
}

void Hanoi::MovePiece(int userSelection)
{
   switch(userSelection)
   {
      case 1:
	 cout << "Move left, right" << endl;
	 
	 break;
      case 2:
	 cout << "Move centre left" << endl;
	 break;
      case 3:
	 cout << "Move centre right" << endl;
	 break;
      case 4:
	 cout << "<Move right, left" << endl;
	 break;
      default:
	 cout << "Invalid input, please try again." << endl;
	 break;
   } 
}

// void Hanoi::OutputGameBoard(&screen)
// {
//    for(int i=0; i<column; i++)
//    {
//       for(int j=0; j<x; j++)
// 	 cout << Tower.at(i).at(j);
//    }
//    cout << endl;
// }

void Hanoi:: RunGame()
{
   map <int, string> MAPPP;
   MAPPP.insert(pair<int,string>(1,"Blaaaaaaah"));
   Menu menu;
   menu.SetOptions(MAPPP);
   menu.OutputMenu();
   // //PromptUser();
   // while(GameEnd==false)
   // {
   //    // OutputGame(&screen);
   //    //int userSelection=UserInput(&menu);
   //    //MovePiece(userSelection);
   //    WinCheck();
   // }
   cout << "A noise creaks behind the wall and the door slides open." << endl;
}
