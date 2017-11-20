//
// hanoi.cpp
//
/// \author Tyler Siwy
/// \date Oct 20, 2017
//
#include "Hanoi.h"

//      ===       (3)
//    ███████     (7)
//  ███████████   (11)
//███████████████ (15)
//screen is 101x33

Hanoi::Hanoi()
{
   maxStackHeight=4;
   discsVector.resize(4);
///Create default images for each of the disc to be drawn on the screen.
   DefaultImg Disc1(1,3,'=');
   discsVector.at(0)=Disc1;
   DefaultImg Disc2(1,7,'=');
   discsVector.at(1)=Disc2;
   DefaultImg Disc3(1,11,'=');
   discsVector.at(2)=Disc3;
   DefaultImg Disc4(1,15,'=');
   discsVector.at(3)=Disc4;

   menuOption1="Move disc on peg 1 right.";
   menuOption2="Move disc on peg 2 left.";
   menuOption3="Move disc on peg 2 right.";
   menuOption4="Move disc on peg 3 left.";

   PuzzleEnd=false;
   
   numberOfStacks=3;
   tower.resize(numberOfStacks);

   ///Put the discs into the first stack to start the game
   int screenYCoordinate=14;
   int screenXCoordinate=16;
   for(int i=maxStackHeight; i<0; i--)
   {
      ///Push the discs on in descending order since it's a stack.
      tower.at(0).push(discsVector.at(i));
      tower.at(0).top().Draw(HanoiScreen, screenYCoordinate, screenXCoordinate); //screen, y, x
      ///Down one line for the next disc
      screenYCoordinate++;
      ///Move two to left since the next disc is 4 chars larger.
      screenXCoordinate-=2;
   }
}

Hanoi::~Hanoi()
{
   
}

void Hanoi:: BoardSetup()
{
   int leftDivider=18, centerPeg=60, rightDivider=16;
   DefaultImg Divider1(31,1,'|');
   Divider1.AlignCenter(HanoiScreen);
   Divider1.ShiftLeft(leftDivider);
   Divider1.Draw(HanoiScreen);

   DefaultImg Divider2(31,1,'|');
   Divider2.AlignCenter(HanoiScreen);
   Divider2.ShiftRight(HanoiScreen, rightDivider);
   Divider2.Draw(HanoiScreen);


}

bool Hanoi:: ValidMove(const int currentStackTop, const int newStackTop) const
{
   ///If the disc on the current stack is smaller than the disc on the new stack
   ///it is considered a valid move, so return true, otherwise return false.
   if(currentStackTop<newStackTop)
      return true;
   else
      return false;
}

///Setup the options in the HanoiMenu object.
void Hanoi::SetOptionsInMenu()
{
   cout << "Options have been set" << endl;
   //HanoiGameMenu.AddOption('1', menuOption1, MovePiece);
//    HanoiGameMenu.AddOption('2', menuOption2, MovePiece);
//    HanoiGameMenu.AddOption('3', menuOption3, MovePiece);
//     HanoiGameMenu.AddOption('4', menuOption4, MovePiece);
}

void Hanoi::WinCheck()
{
   ///If the user has managed to successfully move all discs to the last peg
   ///then its size should be 4.
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
	    int topOfStack=tower.at(0).top().GetCols();
            //GetCols gives us the x size of the image

	    int newStackTop;
	    ///If the target tower is empty, the disc should go in spot 0,
	    ///otherwise place it at the top.
	    if(tower.at(1).empty())
	       newStackTop=0;
	    else
	       newStackTop=tower.at(1).top().GetCols();

	    ///Check if the move is a valid, if yes, move it over and pop it
	    ///from its old location.
	    if(ValidMove(topOfStack, newStackTop))
	    {
	       tower.at(0).pop();
	       ///Push the right size disc from the vector of discs based on the
	       ///size passed into WhichDiscFromSize, size is topOfStack
	       tower.at(1).push(discsVector.at(WhichDiscFromSize(topOfStack)));
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
	    int topOfStack=tower.at(1).top().GetCols();
	    int newStackTop;

	    ///If the target tower is empty, the disc should go in spot 0,
	    ///otherwise place it at the top.    
	    if(tower.at(0).empty())
	       newStackTop=0;
	    else
	       newStackTop=tower.at(0).top().GetCols();

	    ///Check if the move is a valid, if yes, move it over and pop it
	    ///from its old location.   
	    if(ValidMove(topOfStack, newStackTop))
	    {
	       tower.at(1).pop();
	       tower.at(0).push(discsVector.at(WhichDiscFromSize(topOfStack)));
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
	    int topOfStack=tower.at(1).top().GetCols();
	    int newStackTop;

	    ///If the target tower is empty, the disc should go in spot 0,
	    ///otherwise place it at the top.    
	    if(tower.at(2).empty())
	       newStackTop=0;
	    else
	       newStackTop=tower.at(2).top().GetCols();

	    ///Check if the move is a valid, if yes, move it over and pop it
	    ///from its old location.   
	    if(ValidMove(topOfStack, newStackTop))
	    {
	       tower.at(1).pop();
	       tower.at(2).push(discsVector.at(WhichDiscFromSize(topOfStack)));
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
	    int topOfStack=tower.at(2).top().GetCols();
	    int newStackTop;

	    ///If the tower is empty, the disc should go in spot 0, otherwise
	    ///place it at the top.   
	    if(tower.at(1).empty())
	       newStackTop=0;
	    else
	       newStackTop=tower.at(1).top().GetCols(); 

	    ///Check if the move is a valid, if yes, move it over and pop it
	    ///from its old location.   
	    if(ValidMove(topOfStack, newStackTop))
	    {
	       tower.at(2).pop();
	       tower.at(1).push(discsVector.at(WhichDiscFromSize(topOfStack)));
	    }
	 }
	 break;

      default:
	 cout << "Invalid input, please try again." << endl;
	 break;
   } 
}


int Hanoi::WhichDiscFromSize(int size)
{
   switch(size)
   {
      case 3:
	 return 0;
	 break;
      case 7:
	 return 1;
	 break;
      case 11:
	 return 2;
	 break;
      case 15:
	 return 3;
	 break;
      default:
	 cout << "Invalid size" << endl;
	 return -1;
   }	 
}

void Hanoi::ClearScreenOfOldDisc(int sizeOfDisc, int targetTower,int yCoordinate)
{
   switch(targetTower)
   {
      
      case 1:
	 for(int i=0; i<sizeOfDisc; i++)
	 {
	    ///18 is the center of the first tower, take away half the disc size
	    ///to start in the right spot, add the interator as we move through
	    ///the line.
	    HanoiScreen.Set(yCoordinate,(i+18-(sizeOfDisc%2)),' ');
	 }
	 //clear tower 1 top
	 break;
      case 2:
	 //clear tower 2 top
	 for(int i=0; i<sizeOfDisc; i++)
	 {
	    ///18 is the center of the second tower, take away half the disc
	    ///size to start in the right spot, add the interator as we move
	    ///through the line.
	    HanoiScreen.Set(yCoordinate,(i+51-(sizeOfDisc%2)),' ');
	 }
	 break;
      case 3:
	 //clear tower 3 top
	 for(int i=0; i<sizeOfDisc; i++)
	 {
	    ///84 is the center of the third tower, take away half the disc size
	    ///to start in the right spot, add the interator as we move through
	    ///the line.
	    HanoiScreen.Set(yCoordinate,(i+84-(sizeOfDisc%2)), ' ');
	 }
	 break; 
   }
}
   
void Hanoi:: RunGame()
{
   cout << "Start" << endl;
   SetOptionsInMenu();
   BoardSetup();
   while(GameEnd==false)
   {
      cout << HanoiScreen;
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


