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
   
   maxStackHeight=4;
   discsVector.resize(maxStackHeight);
   ///Create default images for each of the disc to be drawn on the screen.
   DefaultImg* imagePointer;
   int discWidth=3;
   for(int i=0; i<maxStackHeight; i++)
   {
   imagePointer= new DefaultImg(1,discWidth,'=');
   discsVector.at(i)=imagePointer;
   discWidth+=4;
   }

   tower.resize(numberOfStacks);
   ///Put the discs into the first stack to start the game
   int screenYCoordinate=31;
   int screenXCoordinate=9;
   for(int i=maxStackHeight; i>0; i--)
   {
      ///Push the discs on in descending order since it's a stack.
      tower.at(0).push(discsVector.at(i-1));
      tower.at(0).top()->Draw(HanoiScreen,screenYCoordinate,screenXCoordinate); 
      screenYCoordinate--;///Down one line for the next disc
      ///Move two to left since the next disc is 4 chars larger.
      screenXCoordinate+=2;
   }

   menuOption1="Move disc on peg 1 to center.", menuOption2="Move disc on peg 2 left.";
   menuOption3="Move disc on peg 2 right.", menuOption4="Move disc on peg 3 to center.";
   menuOption5="Move disc on peg 1 to peg 3.",menuOption6="Move disc on peg 3 to peg 1.";

   PuzzleEnd=false;
   
   numberOfStacks=3;
 

 
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

void Hanoi::DrawDiscOnTargetStack(int targetStack)
{
   int peg=34, bottom=16, targetHeight;
   switch(targetStack)
   {
      case 1:	 
	 targetHeight=tower.at(targetStack-1).size();
	 cout << "TargetHeight: " << targetHeight << endl;
	 tower.at(targetStack).top()->AlignCenter(HanoiScreen);
	 tower.at(targetStack).top()->ShiftLeft(peg);
	 ///Add the height of any discs stored on that stack
	 tower.at(targetStack).top()->ShiftDown(HanoiScreen,bottom-targetHeight);
	 tower.at(targetStack).top()->Draw(HanoiScreen);
	 break;
      case 2:
	 targetHeight=tower.at(targetStack-1).size();
	  cout << "TargetHeight: " << targetHeight << endl;
	 tower.at(targetStack).top()->AlignCenter(HanoiScreen);
	 ///Add the height of any discs stored on that stack
	 tower.at(targetStack).top()->ShiftDown(HanoiScreen, bottom-targetHeight);
	 tower.at(targetStack).top()->Draw(HanoiScreen);
	 break;

      case 3:
	 targetHeight=tower.at(targetStack-1).size();
	  cout << "TargetHeight: " << targetHeight << endl;
	 tower.at(targetStack).top()->ShiftRight(HanoiScreen, peg);
	 ///Add the height of any discs stored on that stack
	 tower.at(targetStack).top()->ShiftDown(HanoiScreen, bottom-targetHeight);
	 tower.at(targetStack).top()->Draw(HanoiScreen);
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
void Hanoi::MovePiece(int sourceTower, int targetTower)
{
   ///newStackTop is the size of the top disc on the target stack, used for a
   ///comparison to see if the player is making a valid move. 
   int targetStackTopSize;
   ///topOfStack is the size of the disc which we are going to move
   int topOfStack;
   ///Record the size of the disc we wish to move, GetCols gives us the
   ///x size of the default image
   topOfStack=tower.at(sourceTower).top()->GetCols();
    
   ///If the target tower is empty, the target tower has a top disc
   ///size of 0, otherwise find the size of the top disc and set it to
   ///newStackTop
   if(tower.at(targetTower).empty())
      targetStackTopSize=0;
   else
      targetStackTopSize=tower.at(targetTower).top()->GetCols();
   ///Check if the move is a valid, if yes, move it over and pop it
   ///from its old location.
   cout << "TargetSize: " << targetStackTopSize<< "     topOfStack: " << topOfStack << endl; 
   if(ValidMove(targetStackTopSize,topOfStack))
   {
      ///Push the right size disc from the vector of discs based on the
      ///size passed into WhichDiscFromSize, size is topOfStack
      tower.at(targetTower).push(tower.at(sourceTower).top());
      tower.at(sourceTower).pop();
      // tower.at(1).top().Draw(HanoiScreen);
      ///Clear the disc off of tower 1
      DrawDiscOnTargetStack(targetTower);	       
   }

}






void Hanoi::LogicSwitch(char userSelection)
{
   cout << "Stack 1 Size:" << tower.at(0).size() << "     Stack 2 Size:" <<tower.at(1).size() << "     Stack 3 size: " << tower.at(2).size() << endl;
   switch(userSelection)
   {
      case '1':
	 if(tower.at(0).empty())
	    cout << "That peg is empty, please try another" << endl;
	 else
	 {
	    MovePiece(0,1);//(source,target)
	 }
	 break;
	 
      case '2':
	 if(tower.at(1).empty())
	    cout << "That peg is empty, please try another" << endl;
	 else
	 {
	    MovePiece(1,0);
	 }
	 break;

	 	 
      case '3':
	 if(tower.at(1).empty())
	    cout << "That peg is empty, please try another" << endl;
	 else
	 {
	    MovePiece(1,2);
	 }
	 break;
	 
      case '4':
	 if(tower.at(2).empty())
	    cout << "That peg is empty, please try another" << endl;
      	 else
	 {
	    MovePiece(2,1);
	 }
	 break;
	 
      case '5':
	 cout << "Move left, far right" << endl;
	 if(tower.at(0).empty())
	    cout << "That peg is empty, please try another" << endl;
	 else
	 {
	    MovePiece(0,2);
	 }  
	 break;

      case '6':
	 cout << "Move right, far left" << endl;
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

///WhichDiscFromSize returns an index to wich disc in discsVector the size is
///referenced with
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

void Hanoi::ClearTopDisc(int targetTower)
{
   cout << "CLEAR DISC ON TOWER " << targetTower << endl;
   cout << "tower 1 " << tower.at(targetTower-1).top()->GetCols() << endl;
   tower.at(targetTower-1).top()->Erase();
   tower.at(targetTower-1).top()->Draw(HanoiScreen);
   cout << HanoiScreen;
   switch(targetTower)
   {
      case 1:
	 cout << "tower 1 " << tower.at(targetTower-1).top()->GetCols() << endl;
	 tower.at(targetTower-1).top()->Erase();
	 tower.at(targetTower-1).top()->Draw(HanoiScreen);
	 cout << HanoiScreen;
	 break;
      case 2:
	 //clear tower 2 top
	 cout << "CASE 2" << endl;
	 cout << "Clear tower 2 top" << endl;
	 cout << "tower2 " << tower.at(targetTower-1).top()->GetCols() << endl;
	 tower.at(targetTower-1).top()->Erase();
	 tower.at(targetTower-1).top()->Draw(HanoiScreen);	
	 ///18 is the center of the second tower, take away half the disc
	 ///size to start in the right spot, add the interator as we move
	 ///through the line.
	 //HanoiScreen.Set(yTarget,(i+51-(discSize%2)),' ');
	 break;
      case 3:
	 //clear tower 3 top
	 cout << "CASE 3" << endl;
	 cout << "tower3 " << tower.at(targetTower-1).top()->GetCols() << endl;
	 tower.at(targetTower-1).top()->Erase();
	 tower.at(targetTower-1).top()->Draw(HanoiScreen);	
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


