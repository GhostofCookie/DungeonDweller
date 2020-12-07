#include "ExploreState.h"
#include "ExploreMenu.h"
#include "Cutscene.h"
#include "Image.h"
#include "DefaultImg.h"
#include "ImportImg.h"
#include "ImageImporter.h"
#include "Room.h"
#include <ctime>
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <stdexcept>
#include <conio.h>

ExploreState::ExploreState(std::shared_ptr<Player> player, std::shared_ptr<Viewport> view)
{
	srand((unsigned int)time(NULL));

	this->viewport = view;
	this->player = player;
	this->currState = States::EXPLORE;

	this->menu = new ExploreMenu();
	this->import = new ImageImporter("../ResourceFiles/MasterArtFile.txt");
	this->roomPtr = new Room(import->collection, 0);
	this->roomTree = new RoomTree(roomPtr);
}

ExploreState::~ExploreState()
{
	delete menu;
	delete roomTree;
	delete import;
}

ExploreState::ExploreState(const ExploreState& obj)
{
	import = obj.import;
	roomPtr = obj.roomPtr;
	roomTree = obj.roomTree;
	menu = obj.menu;
	viewport = obj.viewport;
	player = obj.player;
}

ExploreState& ExploreState::operator=(const ExploreState& obj)
{
	import = obj.import;
	roomPtr = obj.roomPtr;
	roomTree = obj.roomTree;
	menu = obj.menu;
	viewport = obj.viewport;
	player = obj.player;

	return *this;
}

void ExploreState::Set()
{
	menu->AddOption('w', "Move Up");
	menu->AddOption('a', "Move Left");
	menu->AddOption('s', "Move Down");
	menu->AddOption('d', "Move Right");
	menu->AddOption('i', "Inventory");

	if ((roomTree->At())->GetType() == 1)
		menu->AddOption('t', "Trade");
	if ((roomTree->At())->GetType() == 3 && !roomTree->At()->IsComplete())
		menu->AddOption('p', "Solve Puzzle");
	menu->AddOption('q', "Quit to Menu");
}

void ExploreState::Get()
{
	viewport->Erase();

	// Align the current room to the viewport and print
	(roomTree->At())->AlignCenter(*viewport);
	(roomTree->At())->Draw(*viewport);

	player->Img().AlignCenter(*viewport);
	player->Img().Draw(*viewport);

	// Draw the npc to the viewport if there is one
	if ((roomTree->At())->GetType() > 0)
	{
		(roomTree->At())->GetNpc().Img().AlignCenter(*viewport);
		(roomTree->At())->GetNpc().Img().ShiftRight(*viewport, 10);
		(roomTree->At())->GetNpc().Img().Draw(*viewport);
	}

	std::cout << viewport;

	SetState((roomTree->At())->GetType());
	if (currState != States::MAIN)
	{
		// Print the menu and handle user input
		menu->HandleInput(std::cin);
		// Handle input from player
		RunInput(menu->GetOption());
	}
}

void ExploreState::RunInput(char n)
{
	Cutscene anim = Cutscene(viewport);

	if (n != '\0')
	{
		switch (n)
		{
		case 'w':
			anim = Cutscene(viewport, player->Img(), roomTree->At()->GetImage(), roomTree->At());
			anim.ExitUp();

			// check to ensure room does not exist before creating new one
			try {
				if (!roomTree->Move('U'))
				{
					roomTree->NewRoom('U', new Room(import->collection));
					roomTree->Move('U');
				}
			}
			catch (std::invalid_argument& ia) {
				std::string temp = ia.what();
				throw std::runtime_error("Room error:" + temp);
			}

			anim = Cutscene(viewport, player->Img(), roomTree->At()->GetImage(), roomTree->At());
			anim.EnterDown();

			// lower the stamina for moving
			player->ChangeStamina(-1);
			break;

			// Move Left
		case 'a':
			anim = Cutscene(viewport, player->Img(), roomTree->At()->GetImage(), roomTree->At());
			anim.ExitLeft();

			// check to ensure room does not exist before creating new one
			try {
				if (!roomTree->Move('L'))
				{
					roomTree->NewRoom('L', new Room(import->collection));
					roomTree->Move('L');
				}
			}
			catch (std::invalid_argument& ia) {
				std::string temp = ia.what();
				throw std::runtime_error("Room error:" + temp);
			}

			anim = Cutscene(viewport, player->Img(), roomTree->At()->GetImage(), roomTree->At());
			anim.EnterRight();

			// lower the stamina for moving
			player->ChangeStamina(-1);
			break;

			// Move Down
		case 's':
			anim = Cutscene(viewport, player->Img(), roomTree->At()->GetImage(), roomTree->At());
			anim.ExitDown();

			// check to ensure room does not exist before creating new one
			try {
				if (!roomTree->Move('D'))
				{
					roomTree->NewRoom('D', new Room(import->collection));
					roomTree->Move('D');
				}
			}
			catch (std::invalid_argument& ia) {
				std::string temp = ia.what();
				throw std::runtime_error("Room error:" + temp);
				//throw std::runtime_error("Room Error: " + ia.what);
			}

			anim = Cutscene(viewport, player->Img(), roomTree->At()->GetImage(), roomTree->At());
			anim.EnterUp();

			// lower the stamina for moving
			player->ChangeStamina(-1);
			break;

			// Move Right
		case 'd':
			anim = Cutscene(viewport, player->Img(), roomTree->At()->GetImage(), roomTree->At());
			anim.ExitRight();

			// check to ensure room does not exist before creating new one
			try {
				if (!roomTree->Move('R'))
				{
					roomTree->NewRoom('R', new Room(import->collection));
					roomTree->Move('R');
				}
			}
			catch (std::invalid_argument& ia) {
				std::string temp = ia.what();
				throw std::runtime_error("Room error:" + temp);
				//throw std::runtime_error("Room Error: " + ia.what);
			}

			anim = Cutscene(viewport, player->Img(), roomTree->At()->GetImage(), roomTree->At());
			anim.EnterLeft();

			// lower the stamina for moving
			player->ChangeStamina(-1);
			break;

			// Trade Option
		case 't':
			currState = States::TRADE;
			return;
			break;

			// Puzzle Option
		case 'p':
			// check to ensure room does not exist before creating new one
			if (!roomTree->At()->IsComplete())
			{
				currState = States::PUZZLE;
				roomTree->At()->complete = true;
			}
			else currState = States::EXPLORE;
			return;
			break;

			// Quit the game
		case 'q':
			std::cout << "Are you sure you want to quit to main menu (y/n)? ";
			char ch;
			ch = _getch();

			if (tolower(ch) == 'y')
			{
				currState = States::MAIN;
				std::cout << viewport;
				return;
			}
			else
				currState = States::EXPLORE;
			return;
			// Inventory Option
		case 'i':
			currState = States::INVENTORY;
			return;
			break;

		default:
			currState = States::EXPLORE;
			return;
			break;
		};
	}
}

void ExploreState::SetState(int n)
{
	Cutscene c = Cutscene(viewport, player->Img(), (roomTree->At()->GetImage()), roomTree->At());

	// Quit the game
	if (n == 'q' || player->GetHealth() <= 0 || player->GetStamina() <= 0)
	{
		//  Insert defeat anim here
		std::cout << "*** You are unable to continue. Game Over ***" << std::endl;
		std::cout << "Your score: " << roomTree->TotalNodes() << std::endl;

#ifdef __linux__
		usleep(3000000);
#else
		//Sleep(3000);
#endif
		currState = States::MAIN;
		return;

	}
	else {
		switch (n)
		{
		case 2: // Fight state
			if (!roomTree->At()->IsComplete())
			{
				c.MonsterEncounter();
				roomTree->At()->complete = true;
				// sets the monster to dead and sets him to a location
				(roomTree->At())->GetNpc().Img() = ImportImg(import->collection['m'][1]);
				(roomTree->At())->GetNpc().Img().AlignCenter(*viewport);
				(roomTree->At())->GetNpc().Img().ShiftRight(*viewport, 10);
				(roomTree->At())->GetNpc().Img().Draw(*viewport);
				//std::cout << viewport;
				//currState = States::COMBAT;
			}
			else currState = States::EXPLORE;
			return;
		case 0:
		case 1:
		case 3:
		default:
			currState = States::EXPLORE;
			return;
		}
	}
}
