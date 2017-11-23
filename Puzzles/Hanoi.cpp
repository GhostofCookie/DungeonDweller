//
// hanoi.cpp
//
/// \author Tyler Siwy
/// \date Oct 20, 2017
//
#include "Hanoi.h"

//       ===       (3)
//     =======     (7)
//   ===========   (11)
// =============== (15)
//screen is 101x33

Hanoi::Hanoi()
{
   BoardSetup();
   numberOfStacks=3;
   maxStackHeight=4;
   tower.resize(3);
   ///Create default images for each of the disc to be drawn on the screen.
   DefaultImg disc1(1,3,'=');
   DefaultImg disc2(1,7,'=');
   DefaultImg disc3(1,11,'=');
   DefaultImg disc4(1,15,'=');

   ///Draw to the game screen and then put the discs into the first stack to
   ///start the game.
   int leftPeg=34, bottom=15;   
   disc4.AlignCenter(HanoiScreen);
   disc4.ShiftLeft(leftPeg);
   disc4.ShiftDown(HanoiScreen, bottom);
   disc4.Draw(HanoiScreen);
   tower.at(0).push(disc4);
   bottom--;
   disc3.AlignCenter(HanoiScreen);
   disc3.ShiftLeft(leftPeg);
   disc3.ShiftDown(HanoiScreen, bottom);
   disc3.Draw(HanoiScreen);
   tower.at(0).push(disc3);
   bottom--;
   disc2.AlignCenter(HanoiScreen);
   disc2.ShiftLeft(leftPeg);
   disc2.ShiftDown(HanoiScreen, bottom);
   disc2.Draw(HanoiScreen);
   tower.at(0).push(disc2);
   bottom--;
   disc1.AlignCenter(HanoiScreen);
   disc1.ShiftLeft(leftPeg);
   disc1.ShiftDown(HanoiScreen, bottom);
   disc1.Draw(HanoiScreen);
   tower.at(0).push(disc1);
   bottom--;
 
   menuOption1="Move disc on peg 1 to peg 2.", menuOption2="Move disc on peg 2 to peg 1";
   menuOption3="Move disc on peg 3 to peg 2.", menuOption4="Move disc on peg 1 to peg 2.";
   menuOption5="Move disc on peg 2 to peg 3.",menuOption6="Move disc on peg 3 to peg 1.";

   PuzzleEnd=false;
}

Hanoi::~Hanoi()
{
}

void Hanoi:: BoardSetup()
{
   int leftDivider=18, peg=34, rightDivider=16, bottom=11;
   DefaultImg Divider1(31,1,'|');
   Divider1.AlignCenter(HanoiScreen);
   Divider1.ShiftLeft(leftDivider);
   Divider1.Draw(HanoiScreen);

   DefaultImg Divider2(31,1,'|');
   Divider2.AlignCenter(HanoiScreen);
   Divider2.ShiftRight(HanoiScreen, rightDivider);
   Divider2.Draw(HanoiScreen);
 
   DefaultImg Peg1(10,1,'|');
   Peg1.AlignCenter(HanoiScreen);
   Peg1.ShiftLeft(peg);
   Peg1.ShiftDown(HanoiScreen, bottom);
   Peg1.Draw(HanoiScreen);

   DefaultImg Peg2(10,1,'|');
   Peg2.AlignCenter(HanoiScreen);
   Peg2.ShiftDown(HanoiScreen, bottom);
   Peg2.Draw(HanoiScreen);
   
   DefaultImg Peg3(10,1,'|');
   Peg3.AlignCenter(HanoiScreen);
   Peg3.ShiftRight(HanoiScreen, peg);
   Peg3.ShiftDown(HanoiScreen, bottom);
   Peg3.Draw(HanoiScreen);
}

///Setup the options in the HanoiMenu object.
void Hanoi::SetOptionsInMenu()
{
   HanoiGameMenu.AddOption('1', menuOption1);
   HanoiGameMenu.AddOption('2', menuOption2);
   HanoiGameMenu.AddOption('3', menuOption3);
   HanoiGameMenu.AddOption('4', menuOption4);
   HanoiGameMenu.AddOption('5', menuOption4);
   HanoiGameMenu.AddOption('6', menuOption4);
}

void Hanoi::WinCheck()
{
   ///If the user has managed to successfully move all discs to the last peg
   ///then its size should be 4.
   if(tower.at(2).size()==4)
      PuzzleEnd=true;
}

///Draws the disc movement to the screen
void Hanoi::DrawDiscOnTargetStack(int sourceStack, int targetStack)
{
   cout << "DRAW DISC ON TARGET STACK" << endl;
   int peg=34, bottom=15, targetHeight;
   switch(targetStack)
   {
      case 0:
	 targetHeight=tower.at(targetStack).size();
	 
	 tower.at(sourceStack).top().AlignCenter(HanoiScreen);
	 tower.at(sourceStack).top().ShiftLeft(peg);
	 ///Add the height of any discs stored on that stack
	 tower.at(sourceStack).top().ShiftDown(HanoiScreen, bottom-targetHeight);
	 tower.at(sourceStack).top().Draw(HanoiScreen);
	 break;
      case 1:
	 targetHeight=tower.at(targetStack).size();
	
	 tower.at(sourceStack).top().AlignCenter(HanoiScreen);
	 ///Add the height of any discs stored on that stack
	 tower.at(sourceStack).top().ShiftDown(HanoiScreen, bottom-targetHeight);
	 tower.at(sourceStack).top().Draw(HanoiScreen);
	 break;

      case 2:
	 targetHeight=tower.at(targetStack).size();
	 
	 tower.at(sourceStack).top().AlignCenter(HanoiScreen);
	 tower.at(sourceStack).top().ShiftRight(HanoiScreen, peg);
	 ///Add the height of any discs stored on that stack
	 tower.at(sourceStack).top().ShiftDown(HanoiScreen, bottom-targetHeight);
	 tower.at(sourceStack).top().Draw(HanoiScreen);
	 break;
   }
}

bool Hanoi:: ValidMove(const int targetStackTopSize, const int currentTopSize) const
{
   ///If the disc on the current stack is smaller than the disc on the new stack
   ///it is considered a valid move, so return true, otherwise return false.
   if(currentTopSize<targetStackTopSize || targetStackTopSize==0)
   {
      cout << "VALID MOVE" << endl;
      return true;
   }
      else
	 return false;
}

///Moves the piece in the vector.stack and calls the function to move the images
///on the screen
void Hanoi::MovePiece(int sourceTower, int targetTower)
{
   cout << "MOVE PIECE" << endl;
   ///targetStackTopSize is the size of the top disc on the target stack, used for a
   ///comparison to see if the player is making a valid move. 
   int targetStackTopSize; 
   ///If the target tower is empty, the target tower has a top disc
   ///size of 0, otherwise find the size of the top disc and set it to
   ///newStackTop
   if(tower.at(targetTower).empty())
      targetStackTopSize=0;
   else
      targetStackTopSize=tower.at(targetTower).top().GetCols();

   ///Check if the move is a valid, if yes, move it over and pop it
   ///from its old location.
   ///currentDiscSize is the size of the disc which we are going to move
   int currentDiscSize;
   currentDiscSize=tower.at(sourceTower).top().GetCols();//get cols gives the width
   
   cout << "TargetSize: " << targetStackTopSize<< "    currentDiscSize: " << currentDiscSize << endl; 
   if(ValidMove(targetStackTopSize,currentDiscSize))
   {
      ///Push the right size disc from the vector of discs based on the
      ///size passed into WhichDiscFromSize, size is topOfStack
      ClearTopDisc(sourceTower);
      DrawDiscOnTargetStack(sourceTower,targetTower);
      tower.at(targetTower).push(tower.at(sourceTower).top());
      tower.at(sourceTower).pop();
      cout << HanoiScreen;
   }

}

void Hanoi::ClearTopDisc(int targetTower)
{
   cout << "CLEAR TOP DISC" << endl;
   cout << "TargetTower:" << targetTower << endl;
   switch(targetTower)
   {
      case 0:
	 cout << "tower 1 " << tower.at(targetTower).top().GetCols() << endl;
	 tower.at(targetTower).top().Erase();
	 cout << "2" << endl;
	 tower.at(targetTower).top().Draw(HanoiScreen);
	 tower.at(targetTower).top().Fill('4');
	 cout << "END OF CASE 1" << endl;
//cout << HanoiScreen;
	 break;
      case 1:
	 //clear tower 2 top
	 cout << "tower2 " << tower.at(targetTower).top().GetCols() << endl;
	 tower.at(targetTower).top().Erase();
	 tower.at(targetTower).top().Draw(HanoiScreen);	
	 ///18 is the center of the second tower, take away half the disc
	 ///size to start in the right spot, add the interator as we move
	 ///through the line.
	 //HanoiScreen.Set(yTarget,(i+51-(discSize%2)),' ');
	 break;
      case 2:
	 //clear tower 3 top
	 cout << "tower3 " << tower.at(targetTower).top().GetCols() << endl;
	 tower.at(targetTower).top().Erase();
	 tower.at(targetTower).top().Draw(HanoiScreen);	
	 // for(int i=0; i<discSize; i++)
	 // {
	 //    cout << "Clear tower 3 top" << endl;
	 //    ///84 is the center of the third tower, take away half the disc size
	 //    ///to start in the right spot, add the interator as we move through
	 //    ///the line.
	 //    // HanoiScreen.Set(yTarget,(i+84-(discSize%2)), ' ');
	 // }
	 break; 
   }
}
   
void Hanoi:: RunGame()
{
   cout << "Start" << endl;
   char input;
   SetOptionsInMenu();

   while(GameEnd==false)
   {
      cout << HanoiScreen;
      HanoiGameMenu.OutputMenu();
      HanoiGameMenu.HandleInput(cin);
      input=HanoiGameMenu.GetOption();//returns a char
      LogicSwitch(input);
      WinCheck();
      cout << "Stack 1 Size:" << tower.at(0).size() << "                Stack 2 Size:" <<tower.at(1).size() << "               Stack 3 size: " << tower.at(2).size() << endl;
   }
   cout << "A noise creaks behind the wall and the door slides open." << endl;
}

void Hanoi::LogicSwitch(char userSelection)
{
   cout << "Stack 1 Size:" << tower.at(0).size() << "     Stack 2 Size:" <<tower.at(1).size() << "     Stack 3 size: " << tower.at(2).size() << endl;
   switch(userSelection)
   {
      case '1':
	 cout << "Move peg 1 to peg 2" << endl;
	 if(tower.at(0).empty())
	    cout << "That peg is empty, please try another" << endl;
	 else
	 {
	    MovePiece(0,1);//(source,target)
	 }
	 break;
      case '2':
	 cout << "Move peg 2 to peg 1" << endl;
	 if(tower.at(1).empty())
	    cout << "That peg is empty, please try another" << endl;
	 else
	 {
	    MovePiece(1,0);
	 }
	 break;
      case '3':
	 cout << "Move disk on peg 3 to peg 2" << endl;
	 if(tower.at(2).empty())
	    cout << "That peg is empty, please try another" << endl;
	 else
	 {
	    MovePiece(2,1);
	 }
	 break;
      case '4':
	 cout << "Move peg 1 to peg 3" << endl;
	 if(tower.at(0).empty())
	    cout << "That peg is empty, please try another" << endl;
	 else
	 {
	    MovePiece(0,2);
	 }
	 break;
      case '5':
	 cout << "Move peg 2 to peg 3" << endl;
	 if(tower.at(1).empty())
	    cout << "That peg is empty, please try another" << endl;
	 else
	 {
	    MovePiece(1,2);
	 }
	 break;
      case '6':
	 cout << "Move peg 3 to peg 1" << endl;
	 if(tower.at(2).empty())
	    cout << "That peg is empty, please try another" << endl;
	 else
	 {
	    MovePiece(2,0);
	 }
	 break;
      default:
	 cout << "Invalid input, please try again." << endl;
	 break;
   }
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


