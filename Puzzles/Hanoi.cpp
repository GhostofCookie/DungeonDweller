//
// hanoi.cpp
//
/// \author Tyler Siwy
/// \date Oct 20, 2017
//
#include "Hanoi.h"

Hanoi::Hanoi()
{
   menuOption1="Move disc on peg 1 right.";
   menuOption2="Move disc on peg 2 left.";
   menuOption3="Move disc on peg 2 right.";
   menuOption4="Move disc on peg 3 left.";
   PuzzleEnd=false;
   maxStackHeight=4;
   numberOfStacks=3;
   tower.resize(numberOfStacks);
   for(int i=0; i<numberOfStacks; i++)
   {
      while(tower.at(i).size()=<maxStackHeight)
      {
	 tower.at(i).push(0);
      }
   }
   
}

Hanoi::~Hanoi()
{
   
}

bool Hanoi:: ValidMove(const int currentStackTop, const int newStackTop) const
{
   ///If the disc on the current stack is smaller than the disc on the new stack
   ///it is considered a valid move, so return true, otherwise return false.
   if(currentStack<newStack)
      return true;
   else
      return false;
}

void Hanoi::SetOptionsInMenu()
{
   HanoiGameMenu.AddOption('1', menuOption1, MovePiece(int));
   HanoiGameMenu.AddOption('2', menuOption2, MovePiece(int));
   HanoiGameMenu.AddOption('3', menuOption3, MovePiece(int));
   HanoiGameMenu.AddOption('4', menuOption4, MovePiece(int));
}

void Hanoi::WinCheck()
{
   if(tower.at(2).size()==4)
      PuzzleEnd=true;
}


void Hanoi::MovePiece(int userSelection)
{
   switch(userSelection)
   {
      case 1:
	 if(tower.at(0).empty())
	 {
	    cout << "That peg is empty, please try another" << endl;
	 }
	 else
	 {
	    cout << "Move left, right" << endl;
	    int topOfStack=tower.at(0).top();
	    int newStackTop;
	    
	    if(tower.at(1).empty())
	       newStackTop=0;
	    else
	       newStackTop=tower.at(1).top();
	    
	    if(validMove(topOfStack, newStackTop))
	    {
	       tower.at(0).pop();
	       tower.at(1).push(topOfStack);
	    }
	 }
	 break;
	 
      case 2:
	 if(tower.at(1).empty())
	 {
	    cout << "That peg is empty, please try another" << endl;
	 }
	 else
	 {
	    cout << "Move centre left" << endl;
	    int topOfStack=tower.at(1).top();
	    int newStackTop;
	    
	    if(tower.at(0).empty())
	       newStackTop=0;
	    else
	       newStackTop=tower.at(0).top();
	    
	    if(validMove(topOfStack, newStackTop))
	    {
	       tower.at(1).pop();
	       tower.at(0).push(topOfStack);
	    }
	 }
	 break;

	 	 
      case 3:
	 if(tower.at(1).empty())
	 {
	    cout << "That peg is empty, please try another" << endl;
      	 }
	 else
	 {
	    cout << "Move centre right" << endl;
	    int topOfStack=tower.at(1).top();
	    int newStackTop;
	    
	    if(tower.at(2).empty())
	       newStackTop=0;
	    else
	       newStackTop=tower.at(2).top();
	    
	    if(validMove(topOfStack, newStackTop))
	    {
	       tower.at(1).pop();
	       tower.at(2).push(topOfStack);
	    }
	 }
	 break;
	 
      case 4:
	 if(tower.at(2).empty())
	 {
	    cout << "That peg is empty, please try another" << endl;
	 }
      	 else
	 {
	    cout << "Move right, left" << endl;
	    int topOfStack=tower.at(2).top();
	    int newStackTop;
	    if(tower.at(1).empty())
	       newStackTop=0;
	    else
	       newStackTop=tower.at(1).top(); 
	    if(validMove(topOfStack, newStackTop))
	    {
	       tower.at(2).pop();
	       tower.at(1).push(topOfStack);
	    }
	 }
	 break;

      default:
	 cout << "Invalid input, please try again." << endl;
	 break;
   } 
}


void Hanoi::OutputGame(Screen &hScreen)
{
   //These for loops to be replaced by a screen function call
   std::vector<stack<int>>temp(3);
   for(int i=0; i<3; i++)
   {
      while(!(tower.at(i).empty()))
      {
	 temp.at(i).push(tower.at(i).top());
	 tower.at(i).pop();
      }
   }
   for(int i=0; i<3; i++)
   {
      while(!(temp.at(i).empty()))
      {
	 
	 tower.at(i).push(temp.at(i).top());
	 cout << tower.at(i).top() << " ";
	 temp.at(i).pop();
      }
      cout << endl;
   }
}

void Hanoi:: RunGame()
{
   Screen hScreen;
   SetOptionsInMenu();
   HanoiGameMenu.OutputMenu();
   //hMenu.PromptUser();
   while(GameEnd==false)
   {
      // OutputGame(hScreen);
      HanoiGameMenu.OutputMenu();
      HanoiGameMenu.HandleInput(cin);
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


