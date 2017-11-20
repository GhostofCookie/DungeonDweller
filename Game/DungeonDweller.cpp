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
using namespace std;



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
  cout<<screen<<endl;
  // Menu
  Menu *menu = new Menu();
  menu->AddOption('W',"Move Up");
   
  // Construct the roomtree
/*  Room *roomptr = new Room(imageImport.collection);
  RoomTree roomTree(roomptr);
*/

/*   
  char n;
  while(true)
    {
      // clear the screen
      screen->Erase();
      // align the current room to the screen and print
      (*roomTree.at()).AlignCenter(*screen);
      (*roomTree.at()).Draw(*screen);
      cout << screen << endl;
 
      cin >> n;

      // case to select direction ('w' always means go back currently)
      switch(n)
	{
	case 'w' :
	  if(!roomTree.move('p'))
	    {
	      roomTree.newRoom('p', new Room(imageImport.collection));
	      roomTree.move('p');
	    }
	  break;
	case 'a' :
	  if(!roomTree.move('l'))
	    {
	      roomTree.newRoom('l', new Room(imageImport.collection));
	      roomTree.move('l');
	    }
	  break;
	case 's' :
	  if(!roomTree.move('c'))
	    {
	      roomTree.newRoom('c', new Room(imageImport.collection));
	      roomTree.move('c');
	    }
	  break;
	case 'd' :
	  if(!roomTree.move('r'))
	    {
	      roomTree.newRoom('r', new Room(imageImport.collection));
	      roomTree.move('r');
	    }
	  break;
	default :
	  break;
	};
	}*/
  return 0;
}
