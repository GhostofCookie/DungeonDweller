/// \date 24/10/2017
///
/// \author Team Kodika
///
/// This is the main file for the game.

// Screen Headers
#include "../Screen/Screen.h"
#include "../Screen/SlotScreen.h"
// Image Headers
#include "../Image/Image.h"
#include "../Image/DefaultImg.h"
#include "../Image/ImportImg.h"
#include "../ImageImporter/ImageImporter.h"
// Room Header
#include "../Room/Room.h"
// RoomTree Headers
#include "../RoomTree/RoomTree.h"
// Menu Headers
#include "../Menu/CharacterMenu.h"
#include "../Menu/ConnectFourMenu.h"
#include "../Menu/DialogueMenu.h"
#include "../Menu/ExploreMenu.h"
#include "../Menu/FightMenu.h"
#include "../Menu/GameMenu.h"
#include "../Menu/HanoiMenu.h"
#include "../Menu/MainMenu.h"
#include "../Menu/MemoryMenu.h"
#include "../Menu/Menu.h"
#include "../Menu/RiddleMenu.h"
#include "../Menu/TicTacToeMenu.h"
#include "../Menu/TradeMenu.h"
// GameState Headers
#include "../GameState/DialogueState.h"
#include "../GameState/FightState.h"
#include "../GameState/MainState.h"
#include "../GameState/PuzzleState.h"
#include "../GameState/ExploreState.h"
#include "../GameState/GameState.h"
#include "../GameState/MainState.h"
#include "../GameState/TradeState.h"
// Puzzle Headers
#include "../Puzzles/CodeCracker.h"
#include "../Puzzles/ConnectFour.h"
#include "../Puzzles/Hanoi.h"
#include "../Puzzles/MemoryMatch.h"
#include "../Puzzles/Puzzle.h"
#include "../Puzzles/TicTacToe.h"
// Item Headers
#include "../Item/MyConsumables.h"
#include "../Item/MyWeapons.h"
// Character Headers
#include "../Character/Npc.h"
#include "../Character/Player.h"
// Misc Headers
#include <iostream>
#include <ctime> //srand()
#include <cctype>
#include <stdexcept>
using namespace std;

//***FUNCTION PROTOTYPES********************************************************

// Orientation Translation Functions
void FindNewOrientation(char directions[], char dir, int treeHeight);
void ShiftDir(char directions[],unsigned int numOfShifts);
char Orientation(char directions[], char dir);



//******************************************************************************

int main()
{
  //Needed for randomization seed
  srand( (unsigned int) time(NULL));
	
  // The file path - ***change as desired
  string mastrFile = "../DD_Art/DD_MasterFileLinux.txt";
  // Create an importer object and read in the masterFile for Images
  ImageImporter imageImport = ImageImporter(mastrFile);
  // MainGame Screen
  Screen *screen = new Screen();
  // Menu
  Menu *menu = new Menu();
  menu->AddOption('W',"Move Up");
   
  // Construct the roomtree
  Room *roomptr = new Room(imageImport.collection);
  RoomTree roomTree(roomptr);

  // Remember Orientation
  /*
    Whenever roomTree.Move(dir) is used and is successfull, it must be used like this:

    roomTree.Move(Orientation(directions,dir));
    FindNewOrientation(directions,dir,roomTree.CurrentHeight());
    
   */
  char directions[4] = {'p','l','c','r'};
  char n;
  while(true)
    {
      // clear the screen
      screen->Erase();
      // align the current room to the screen and print
      (*roomTree.At()).AlignCenter(*screen);
      (*roomTree.At()).Draw(*screen);
      cout << roomTree.CurrentHeight() << endl << screen << endl;
 
      cin >> n;

      // case to select direction ('w' always means go back currently)
      switch(n)	{
	case 'w' :
	  if(!roomTree.Move(Orientation(directions,'p')))
	    {
	      roomTree.NewRoom(Orientation(directions,'p'), new Room(imageImport.collection));
	      roomTree.Move(Orientation(directions,'p'));
	    }
	  FindNewOrientation(directions,'p',roomTree.CurrentHeight());
	  break;
	case 'a' :
	  if(!roomTree.Move(Orientation(directions,'l')))
	    {
	      roomTree.NewRoom(Orientation(directions,'l'), new Room(imageImport.collection));
	      roomTree.Move(Orientation(directions,'l'));
	    }
	  FindNewOrientation(directions,'l',roomTree.CurrentHeight());
	  break;
	case 's' :
	  if(!roomTree.Move(Orientation(directions,'c')))
	    {
	      roomTree.NewRoom(Orientation(directions,'c'), new Room(imageImport.collection));
	      roomTree.Move(Orientation(directions,'c'));
	    }
	  FindNewOrientation(directions,'c',roomTree.CurrentHeight());
	  break;
	case 'd' :
	  if(!roomTree.Move(Orientation(directions,'r')))
	  {
	      roomTree.NewRoom(Orientation(directions,'r'), new Room(imageImport.collection));
	      roomTree.Move(Orientation(directions,'r'));
	  }
	  FindNewOrientation(directions,'r',roomTree.CurrentHeight());
	  break;
	default :
	  break;
	};
  }
  return 0;
}


//***FUNCTION DEFINITIONS*******************************************************

// Orientation Translation Functions
void FindNewOrientation(char directions[], char dir, int treeHeight)
{
   dir = toupper(dir);
   switch(dir) {
      case 'P':
	 if(treeHeight == 1)
	    ShiftDir(directions,2);
	 break;
      case 'L':
	 ShiftDir(directions,3);
	 break;
      case 'R':
	 ShiftDir(directions,1);
	 break;
      case 'C':
	 if(treeHeight == 2 && directions[2] == 'p')
	    ShiftDir(directions,2);
	 break;
      default:
	 throw invalid_argument("invalid direction1");
   }
}

void ShiftDir(char directions[],unsigned int numOfShifts)
{
   for(unsigned int i = 0; i < numOfShifts; ++i) {
      char temp = directions[0];
      directions[0] = directions[1];
      directions[1] = directions[2];
      directions[2] = directions[3];
      directions[3] = temp;
   }
}

char Orientation(char directions[], char dir)
{
   dir = toupper(dir);
   switch(dir) {
      case 'P':
	 return directions[0];
	 break;
      case 'L':
	 return directions[1];
	 break;
      case 'R':
	 return directions[3];
	 break;
      case 'C':
	 return directions[2];
	 break;
      default:
	 throw invalid_argument("invalid direction2");
   }

}



//******************************************************************************
