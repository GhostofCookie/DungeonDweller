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
// Cutscene Header
#include "../Cutscene/Cutscene.h"
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
//#include "../Item/MyConsumables.h"
//#include "../Item/MyWeapons.h"
// Character Headers
//#include "../Character/Npc.h"
//#include "../Character/Player.h"
// Misc Headers
#include <iostream>
#include <ctime> //srand()
#include <cctype>
#include <stdexcept>
using namespace std;

//***FUNCTION PROTOTYPES********************************************************
void SwitchRooms(char, RoomTree&, ImageImporter&);


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
  menu->AddOption('w',"Move Up");
  menu->AddOption('a',"Move Left");
  menu->AddOption('s',"Move Down");
  menu->AddOption('d',"Move Right");
   
  // Construct the roomtree
  Room *roomptr = new Room(imageImport.collection);
  RoomTree roomTree(roomptr);
  

  
  // CURRENT GAME LOOP
  while(true)
    {
      // clear the screen
      screen->Erase();
      // align the current room to the screen and print
      (*roomTree.At()).AlignCenter(*screen);
      (*roomTree.At()).Draw(*screen);
      cout << roomTree.CurrentHeight() << endl << screen;
      // Print the menu and handle user input
      menu->OutputMenu();
      menu->HandleInput(cin);
      SwitchRooms(menu->GetOption(),roomTree,imageImport);
      // case to select direction ('w' always means go back currently)

  }
  return 0;
}


//***FUNCTION DEFINITIONS*******************************************************
void SwitchRooms(char n, RoomTree &roomTree, ImageImporter &imageImport)
{
   Cutscene cutscene = Cutscene(imageImport.collection['@'][0], roomTree.At()->GetImage());
   
   switch(n)
   {
  case 'w' :
    if(!roomTree.Move('u'))
    {
       // run a room transition (WIP)
       cutscene = Cutscene(imageImport.collection['@'][0], roomTree.At()->GetImage());
       cutscene.CenterToTop();
       
	roomTree.NewRoom('u', new Room(imageImport.collection));
	roomTree.Move('u');

	// run a room transition (WIP)
       cutscene = Cutscene(imageImport.collection['@'][0], roomTree.At()->GetImage());
       cutscene.BottomToCenter();
      }
    break;
  case 'a' :
    if(!roomTree.Move('l'))
    {
       // run a room transition (WIP)
       cutscene = Cutscene(imageImport.collection['@'][0], roomTree.At()->GetImage());
       cutscene.CenterToLeft();
       
	roomTree.NewRoom('l',new Room(imageImport.collection));
	roomTree.Move('l');

	// run a room transition (WIP)
       cutscene = Cutscene(imageImport.collection['@'][0], roomTree.At()->GetImage());
       cutscene.RightToCenter();
      }
    break;
  case 's' :
    if(!roomTree.Move('d'))
    {
       // run a room transition (WIP)
       cutscene = Cutscene(imageImport.collection['@'][0], roomTree.At()->GetImage());
       cutscene.CenterToBottom();
       
	roomTree.NewRoom('d',new Room(imageImport.collection));
	roomTree.Move('d');

	// run a room transition (WIP)
       cutscene = Cutscene(imageImport.collection['@'][0], roomTree.At()->GetImage());
       cutscene.TopToCenter();
      }
    break;
  case 'd' :
    if(!roomTree.Move('r'))
    {
       // run a room transition (WIP)
       cutscene = Cutscene(imageImport.collection['@'][0], roomTree.At()->GetImage());
       cutscene.CenterToRight();
       
	roomTree.NewRoom('r',new Room(imageImport.collection));
	roomTree.Move('r');

	// run a room transition (WIP)
       cutscene = Cutscene(imageImport.collection['@'][0], roomTree.At()->GetImage());
       cutscene.LeftToCenter();
      }
    break;
    
  default :
    break;
  };
}




//******************************************************************************
