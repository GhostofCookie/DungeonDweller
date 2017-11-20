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

   
   cout << "main worked" << endl << screen;
   return 0;
}