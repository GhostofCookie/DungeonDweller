#include "ExploreState.h"
#include "../Menu/ExploreMenu.h"
#include "../Cutscene/Cutscene.h"
#include "../Image/Image.h"
#include "../Image/DefaultImg.h"
#include "../Image/ImportImg.h"
#include <ctime>
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <stdexcept>

/// This is the the default constructor.
ExploreState::ExploreState()
{
   // set random seed
   srand((unsigned int)time(NULL));

   menu = new ExploreMenu();
   screen = new Screen();
   import = new ImageImporter("../DD_Art/DD_MasterFileLinux.txt");
   roomPtr = new Room(import->collection,0);
   roomTree = new RoomTree(roomPtr);
   player = new Player(20,0,"Howard","Computer Scientist",100,10);
   currState = 'E';
}

/// Deconstructor
ExploreState::~ExploreState()
{
   delete menu;
   menu = nullptr;
   delete screen;
   screen = nullptr;
   delete roomPtr;
   roomPtr = nullptr;
   delete roomTree;
   roomTree = nullptr;
   delete import;
   import = nullptr;
   delete player;
   player = nullptr;
}

ExploreState::ExploreState(GameState &obj)
{
   roomTree = obj.GetRoomTree();
   player = obj.GetPlayer();
   menu = obj.GetMenu();
   screen = obj.GetScreen();
   import = new ImageImporter("../DD_Art/DD_MasterFileLinux.txt");
   roomPtr = new Room(import->collection,0);
   currState = obj.GetState();
}

ExploreState::ExploreState(const ExploreState &obj)
{
   import = obj.import;
   roomPtr = obj.roomPtr;
   roomTree = obj.roomTree;
   menu = obj.menu;
   screen = obj.screen;
   player = obj.player;
}

ExploreState& ExploreState::operator=(const ExploreState &obj)
{
   import = obj.import;
   roomPtr = obj.roomPtr;
   roomTree = obj.roomTree;
   menu = obj.menu;
   screen = obj.screen;
   player = obj.player;

   return *this;
}

/// Sets the layout for the game menu and screen.
void ExploreState::Set()
{
//   menu = new ExploreMenu();
   menu->AddOption('w',"Move Up");
   menu->AddOption('a',"Move Left");
   menu->AddOption('s',"Move Down");
   menu->AddOption('d',"Move Right");
   menu->AddOption('i',"Inventory");
   if((roomTree->At())->GetType() == 1)
      menu->AddOption('t',"Trade");
   if((roomTree->At())->GetType() == 3 && !roomTree->At()->IsComplete())
      menu->AddOption('p',"Solve Puzzle");
   menu->AddOption('q',"Quit to Menu");

}

/// Prints the layout of the screen, character info, and the menu
void ExploreState::Get()
{
   if(player != nullptr)
   {
      // clear the screen
      screen->Erase();
      // align the current room to the screen and print
      (roomTree->At())->AlignCenter(*screen);
      (roomTree->At())->Draw(*screen);

      player->Img().AlignCenter(*screen);
      player->Img().Draw(*screen);

      // draw the npc to the screen if there is one
      if((roomTree->At())->GetType() > 0)
      {
	 (roomTree->At())->GetNpc().Img().AlignCenter(*screen);
	 (roomTree->At())->GetNpc().Img().ShiftRight(*screen,10);
	 (roomTree->At())->GetNpc().Img().Draw(*screen);
      }

      // print the player's informaton and the screen
      std::cout << std::setfill(' ') << "[N]Name: " << player->GetName();
      std::cout << std::setw(24) << "[R]Race: " << player->GetRace() << std::endl;
      std::cout << "[^]Depth: " << roomTree->CurrentHeight();
      std::cout << std::setw(28) << "[$]Gold: " << player->GetGold();
      std::cout << std::setw(27) << "[S]Stamina: " << player->GetStamina();
      std::cout << std::setw(27) << std::right << "[+]Health: " << player->GetHealth() << std::right << std::endl;
      std::cout << screen;


      SetState((roomTree->At())->GetType());
      if(currState != 'M')
      {
	 // Print the menu and handle user input
	 menu->OutputMenu();
	 menu->HandleInput(std::cin);
	 // Handle input from player
	 RunInput(menu->GetOption());
      }
   }
}

/// Helper function to give input functionality
/// \param[in] n the menu option to set
void ExploreState::RunInput(char n)
{
   Cutscene *anim;

   if(n != '\0')
   {
      switch(n)
      {
	 // Move up
	 case 'w':
	    anim = new Cutscene(player->Img(),roomTree->At()->GetImage(),
				roomTree->At());
	    anim->ExitUp();

	    // check to ensure room does not exist before creating new one
	    try {
	       if(!roomTree->Move('U'))
	       {
		  roomTree->NewRoom('U',new Room(import->collection));
		  roomTree->Move('U');
	       }
	    }
	    catch(std::invalid_argument &ia) {
	       std::string temp=ia.what();
	       throw std::runtime_error("Room error:"+temp);
	       //throw std::runtime_error("Room Error: " + ia.what());
	    }

	    delete anim;
	    anim = new Cutscene(player->Img(),roomTree->At()->GetImage(),
				roomTree->At());
	    anim->EnterDown();

	    // lower the stamina for moving
	    player->ChangeStamina(-1);
	    break;

	    // Move Left
	 case 'a':
	    anim = new Cutscene(player->Img(),roomTree->At()->GetImage(),
				roomTree->At());
	    anim->ExitLeft();

	    // check to ensure room does not exist before creating new one
	    try {
	       if(!roomTree->Move('L'))
	       {
		  roomTree->NewRoom('L',new Room(import->collection));
		  roomTree->Move('L');
	       }
	    }
	    catch(std::invalid_argument &ia) {
	       //throw std::runtime_error("Room Error: " + ia.what);
	       std::string temp=ia.what();
	       throw std::runtime_error("Room error:"+temp);
	    }

	    delete anim;
	    anim = new Cutscene(player->Img(),roomTree->At()->GetImage(),
				roomTree->At());
	    anim->EnterRight();

	    // lower the stamina for moving
	    player->ChangeStamina(-1);
	    break;

	    // Move Down
	 case 's':
	    anim = new Cutscene(player->Img(),roomTree->At()->GetImage(),
				roomTree->At());
	    anim->ExitDown();

	    // check to ensure room does not exist before creating new one
	    try {
	       if(!roomTree->Move('D'))
	       {
		  roomTree->NewRoom('D',new Room(import->collection));
		  roomTree->Move('D');
	       }
	    }
	    catch(std::invalid_argument &ia) {
	       std::string temp=ia.what();
	       throw std::runtime_error("Room error:"+temp);
	       //throw std::runtime_error("Room Error: " + ia.what);
	    }

	    delete anim;
	    anim = new Cutscene(player->Img(),roomTree->At()->GetImage(),
				roomTree->At());
	    anim->EnterUp();

	    // lower the stamina for moving
	    player->ChangeStamina(-1);
	    break;

	    // Move Right
	 case 'd':
	    anim = new Cutscene(player->Img(),roomTree->At()->GetImage(),
				roomTree->At());
	    anim->ExitRight();

	    // check to ensure room does not exist before creating new one
	    try {
	       if(!roomTree->Move('R'))
	       {
		  roomTree->NewRoom('R',new Room(import->collection));
		  roomTree->Move('R');
	       }
	    }
	    catch(std::invalid_argument &ia) {
	       std::string temp=ia.what();
	       throw std::runtime_error("Room error:"+temp);
	       //throw std::runtime_error("Room Error: " + ia.what);
	    }

	    delete anim;
	    anim = new Cutscene(player->Img(),roomTree->At()->GetImage(),
				roomTree->At());
	    anim->EnterLeft();

	    // lower the stamina for moving
	    player->ChangeStamina(-1);
	    break;

	    // Trade Option
	 case 't':
	    currState = 'S';
	    return;
	    break;

	    // Puzzle Option
	 case 'p':
	    // check to ensure room does not exist before creating new one
	    if(!roomTree->At()->IsComplete())
	    {
	       currState = 'P';
	       roomTree->At()->complete = true;
	    }
	    else currState = 'E';
	    return;
	    break;

	    // Quit the game
	 case 'q':
	    char ch;
	    std::cout << "Are you sure you want to quit to main menu (y/n)? ";
	    std::cin >> ch;
	    if(tolower(ch) == 'y')
	    {
	       currState = 'M';
	       return;
	    }
	    else
	       currState = 'E';
	    return;
	    break;

	    // Inventory Option
	 case 'i':
	    currState = 'I';
	    return;
	    break;

	 default:
	    currState = 'E';
	    return;
	    break;
      };

      delete anim;
   }
}

/// Helper function to set the current state of the game based on the current
/// room type.
/// \param[in] n the state to set
void ExploreState::SetState(int n)
{
   Cutscene c = Cutscene((*player).Img(),(roomTree->At()->GetImage()),
			 roomTree->At());

   // quit the game
   if(n == 113 || player->GetHealth() <= 0 || player->GetStamina() <= 0)
   {
      //  Insert defeat anim here
      std::cout << "*** You are unable to continue. Game Over ***" << std::endl;
      std::cout << "Your score: " << roomTree->TotalNodes() << std::endl;
      
	  #ifdef __linux__
	  usleep(3000000);
	  #endif
      currState = 'M';
      return;

   }
   else {
      switch(n)
      {
	 case 0:
	 case 1:
	 case 3:
	    currState = 'E';
	    break;

	    // fight state
	 case 2:
	    if(!roomTree->At()->IsComplete())
	    {
	       c.MonsterEncounter();
	       roomTree->At()->complete = true;
	       // sets the monster to dead and sets him to a location
	       (roomTree->At())->GetNpc().Img() = ImportImg(import->collection['m'][1]);
	       (roomTree->At())->GetNpc().Img().AlignCenter(*screen);
	       (roomTree->At())->GetNpc().Img().ShiftRight(*screen,10);
	       (roomTree->At())->GetNpc().Img().Draw(*screen);
	       //currState = 'F';
	    }
	    else currState = 'E';
	    return;
	    break;

	 default:
	    currState = 'E';
	    return;
      }
   }
}
