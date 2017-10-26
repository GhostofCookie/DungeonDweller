//
// hanoi.cpp
//
/// \author Tyler Siwy
/// \date Oct 20, 2017
//
#include "Hanoi.h"

Hanoi::Hanoi()
{
   ySize=3;
   xSize=4;
   tower.resize(ySize);
   for(int i=0; i<ySize; i++)
   {
      tower.at(i).resize(xSize);
      for(int j=0; j<xSize; j++)
	 tower.at(i).at(j)=0;
   }
}

Hanoi::~Hanoi()
{
   
}

bool Hanoi:: ValidMove(char input)
{
   return true;
}

void Hanoi::SetOptionsInMenu()
{

}

void Hanoi::WinCheck()
{
   
   bool win=false;
   //Check if the game has been won
   if(win==true)
      PuzzleEnd=true;

   //Check the vector, columns at a time to see if the play has won.
   int successfulStackCount=0;
   int index=1;
   for(int j=0; j<ySize; j++)
   {
      //If the first element in the fourth row is 1, it is the smallest object.
      //Continue checking the column, checking if every succeeding element is
      //smaller, if they are in order, the player has won.
      if(tower.at(xSize).at(j)>=index)
      {
	 index=tower.at(xSize).at(j);
	 successfulStackCount++;
      }
   }
   //If the final stack is full, and in order, set GameEnd to true
   if(successfulStackCount==4)
      GameEnd=true;
}


void Hanoi::MovePiece(int userSelection)
{
   switch(userSelection)
   {
      case 1:
	 int index;
	 int zeroCount;
	 cout << "Move left, right" << endl;
	 for(int i=0; i<ySize; i++)
	 {
	    if(tower.at(1).at(i)!=0)
	       index=tower.at(1).at(i);
	    tower.at(1).at(i)=0;
	    else
	       zeroCount++;
	    if(zeroCount==4)
	    {
	       cout << "That stack is empty, please try again!" << endl;
	       break;
	    }
	    for(int i=0; i<ySize; i++)
	    {
	       //Once we find a spot thats already filled or the bottom of the stack
	       if(tower.at(1).at(i)!=0 || i==3)
	       tower.at(2).at(i-1)=index;
	    }
	 }
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


void Hanoi::OutputGame(Screen &hScreen)
{
   //These for loops to be replaced by a screen function call
   for(int i=0; i<column; i++)
   {
      for(int j=0; j<x; j++)
      {
	 cout << tower.at(i).at(j);
      }
      cout << endl;
   }
   
}

void Hanoi:: RunGame()
{
   
   
   Menu hMenu;
   Screen hScreen;
   hMenu.SetOptions();
   hMenu.OutputMenu();
   hMenu.PromptUser();
   while(GameEnd==false)
   {
      OutputGame(hScreen);
      hMenu.OutputMenu();
      int userSelection=hMenu.PromptUser();
      MovePiece(userSelection);
      WinCheck();
   }
   cout << "A noise creaks behind the wall and the door slides open." << endl;
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


