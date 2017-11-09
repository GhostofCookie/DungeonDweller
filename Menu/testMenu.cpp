#include <iostream>
#include "MainMenu.h"
#include "ExploreMenu.h"
#include "FightMenu.h"
#include "TradeMenu.h"
#include "DialogueMenu.h"
#include "RiddleMenu.h"
#include "TicTacToeMenu.h"
#include "HanoiMenu.h"
#include "CharacterMenu.h"
#include "MemoryMenu.h"
#include "ConnectFourMenu.h"
using namespace std;

int main()
{
	Menu *menu = new Menu(10, 101);
	map<int, string> options;
	options.insert(pair<int, string>(1, "Option 1"));
	options.insert(pair<int, string>(2, "Option 2"));
	options.insert(pair<int, string>(3, "Option 3"));
	options.insert(pair<int, string>(4, "Option 4"));
	// Testing all menu outputs //

	menu->SetOptions(options);
	menu->OutputMenu();
	menu = new Menu(33);
	menu = new MainMenu();
	menu->SetOptions(options);
	menu->OutputMenu();
	menu->HandleOptionInput(cin);
	menu = new ExploreMenu();
	menu->HandleInput(cin);
	/*  menu = new ExploreMenu();
	menu->SetOptions(options);
	menu->OutputMenu();
	menu = new FightMenu();
	menu= new HanoiMenu();
	menu->SetOptions(options);
	menu->OutputMenu();

	*/
	return 0;
}
