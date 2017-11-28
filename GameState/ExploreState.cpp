#include "ExploreState.h"
#include <stdlib.h>
#include <iomanip>



/// This is the the default constructor.
ExploreState::ExploreState()
{
   // set random seed
   srand((unsigned int) time(NULL));
   
   menu = new ExploreMenu();
   screen = new Screen();
   import = new ImageImporter("../DD_Art/DD_MasterFileLinux.txt");
   roomPtr = new Room(import->collection, 0);
   roomTree = new RoomTree(roomPtr);
   player = new Player(30, 1, "dicks", "balls", 100, 3, ImportImg("../DD_Art/Player/DD_Player.txt"));
}



/// Deconstructor
ExploreState::~ExploreState()
{
   delete menu;
   delete screen;
   delete roomPtr;
   delete roomTree;
   delete import;
   delete player;
}



/// Sets the layout for the game menu and screen.
void ExploreState::Set()
{
   if(menu != nullptr)
   {
      delete menu;
      menu = new ExploreMenu();
   }

   menu->AddOption('w',"Move Up");
   menu->AddOption('a',"Move Left");
   menu->AddOption('s',"Move Down");
   menu->AddOption('d',"Move Right");
   menu->AddOption('i',"Inventory");
   if((roomTree->At())->GetType() == 1)
      menu->AddOption('t', "Trade");
   if((roomTree->At())->GetType() == 3 && !roomTree->At()->IsComplete())
      menu->AddOption('p', "Solve Puzzle");
   menu->AddOption('q', "Quit to Menu");

}



/// Prints the layout of the screen, character info, and the menu
void ExploreState::Get()
{
   ImportImg r = ImportImg(player->Img());
   
   // clear the screen
   screen->Erase();
   // align the current room to the screen and print
   (roomTree->At())->AlignCenter(*screen);
   (roomTree->At())->Draw(*screen);

   r.AlignCenter(*screen);
   r.Draw(*screen);

   // draw the npc to the screen if there is one
   if((roomTree->At())->GetType() > 0)
       (roomTree->At())->GetNpc().Img().Draw(*screen);

   // print the player's informaton and the screen
   cout << setfill(' ') << "[^]Depth: " << roomTree->CurrentHeight();
   cout << setw(28) << "[$]Gold: " << player->GetGold();
   cout << setw(28) << "[S]Stamina: " << player->GetStamina();
   cout << setw(28) << right << "[+]Health: " << player->GetHealth() << right << endl;
   cout << screen;

   SetState((roomTree->At())->GetType());
   if(currState != 'M')
   {
      // Print the menu and handle user input
      menu->OutputMenu();
      menu->HandleInput(cin);
      // Handle input from player
      RunInput(menu->GetOption());
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
	 case 'w' :
	    anim = new Cutscene(player->Img(), roomTree->At()->GetImage(),
				roomTree->At());
	    anim->ExitUp();

	    // check to ensure room does not exist before creating new one
	    if(!roomTree->Move('U'))
	    {
	       roomTree->NewRoom('U', new Room(import->collection));
	       roomTree->Move('U');
	    }

	    delete anim;
	    anim = new Cutscene(player->Img(), roomTree->At()->GetImage(),
				roomTree->At());
	    anim->EnterDown();

	    // lower the stamina for moving
	    player->ChangeStamina(-1);
	    break;

	    // Move Left
	 case 'a' :
	    anim = new Cutscene(player->Img(), roomTree->At()->GetImage(),
				roomTree->At());
	    anim->ExitLeft();

	    // check to ensure room does not exist before creating new one
	    if(!roomTree->Move('L'))
	    {
	       roomTree->NewRoom('L',new Room(import->collection));
	       roomTree->Move('L');
	    }

	    delete anim;
	    anim = new Cutscene(player->Img(), roomTree->At()->GetImage(),
				roomTree->At());
	    anim->EnterRight();

	    // lower the stamina for moving
	    player->ChangeStamina(-1);
	    break;

	    // Move Down
	 case 's' :
	    anim = new Cutscene(player->Img(), roomTree->At()->GetImage(),
				roomTree->At());
	    anim->ExitDown();

	    // check to ensure room does not exist before creating new one
	    if(!roomTree->Move('D'))
	    {
	       roomTree->NewRoom('D',new Room(import->collection));
	       roomTree->Move('D');
	    }
	 
	    delete anim;
	    anim = new Cutscene(player->Img(), roomTree->At()->GetImage(),
				roomTree->At());
	    anim->EnterUp();

	    // lower the stamina for moving
	    player->ChangeStamina(-1);
	    break;

	    // Move Right
	 case 'd' :
	    anim = new Cutscene(player->Img(), roomTree->At()->GetImage(),
				roomTree->At());
	    anim->ExitRight();

	    // check to ensure room does not exist before creating new one
	    if(!roomTree->Move('R'))
	    {
	       roomTree->NewRoom('R',new Room(import->collection));
	       roomTree->Move('R');
	    }

	    delete anim;
	    anim = new Cutscene(player->Img(), roomTree->At()->GetImage(),
				roomTree->At());
	    anim->EnterLeft();

	    // lower the stamina for moving
	    player->ChangeStamina(-1);
	    break;

	    // Trade Option
	 case 't':
	    currState = 'S';
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
	    cout << "Are you sure you want to quit to main menu?";
	    cin >> ch;
	    if(tolower(ch) == 'y')
	      {
	       currState = 'M';
	       return;
	      }
	    else
	       currState = 'E';
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
   Cutscene c;
   
   // quit the game
   if(n == 113 || player->GetHealth() <= 0 || player->GetStamina() <= 0)
   {
      //  Insert defeat anim here
      cout << "You have run out of stamina" << endl;
      usleep(3000000);
      currState = 'M';
      return;
      
   } else {
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
	       roomTree->At()->GetNpc().Img() = ImportImg(import->collection['m'][1]);
	       roomTree->At()->GetNpc().Img().AlignCenter(*screen);
	       roomTree->At()->GetNpc().Img().ShiftRight(*screen, 10);
	       //currState = 'F';
	    }
	    else currState = 'E';
	    break;
	    
	 default:
	    currState = 'E';
	    return;
      }
   }
}
