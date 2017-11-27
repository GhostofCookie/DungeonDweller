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
   roomPtr = new Room(import->collection,0);
   roomTree = new RoomTree(roomPtr);

   // create the player
   player = Player(30, 0, "Reid", "Human", 100, 3, ImportImg("../DD_Art/Player/DD_Player.txt"));
}

ExploreState::~ExploreState()
{
   delete menu;
   delete screen;
   delete roomPtr;
   delete roomTree;
   delete import;
   delete character;
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

/// Gets the layout for the game menu and screen.
void ExploreState::Get()
{
   // clear the screen
   screen->Erase();
   // align the current room to the screen and print
   (roomTree->At())->AlignCenter(*screen);
   (roomTree->At())->Draw(*screen);

   player.Img().AlignCenter(*screen);
   player.Draw(*screen);

   SetState((roomTree->At())->GetType());

   // print the player's informaton and the screen
   cout << setfill(' ') << "[$]Gold: " << player.GetGold();
   cout << setw(43) << "[S]Stamina: " << player.GetStamina();
   cout << setw(41) << right << "[+]Health: " << player.GetHealth() << right << endl;
   cout << screen;
          
   // Print the menu and handle user input
   menu->OutputMenu();
   menu->HandleInput(cin);


   // Handle input from player
   RunInput(menu->GetOption());
}

/// Helper function to give input functionality
void ExploreState::RunInput(char n)
{
   Cutscene *anim;
   if(n != '\0')
   {
      switch(n)
      {
	 case 'w' :
	    anim = new Cutscene(player.Img(), roomTree->At()->GetImage(),
				roomTree->At());
	    anim->ExitUp();
	    
	    if(!roomTree->Move('U'))
	    {
	       roomTree->NewRoom('U', new Room(import->collection));
	       roomTree->Move('U');
	    }

	    delete anim;
	    anim = new Cutscene(player.Img(), roomTree->At()->GetImage(),
				roomTree->At());
	    anim->EnterDown();
	    break;
	 
	 case 'a' :
	    anim = new Cutscene(player.Img(), roomTree->At()->GetImage(),
				roomTree->At());
	    anim->ExitLeft();
	 
	    if(!roomTree->Move('L'))
	    {
	       roomTree->NewRoom('L',new Room(import->collection));
	       roomTree->Move('L');
	    }

	    delete anim;
	    anim = new Cutscene(player.Img(), roomTree->At()->GetImage(),
				roomTree->At());
	    anim->EnterRight();
	    break;
	 
	 case 's' :
	    anim = new Cutscene(player.Img(), roomTree->At()->GetImage(),
				roomTree->At());
	    anim->ExitDown();
	 
	    if(!roomTree->Move('D'))
	    {
	       roomTree->NewRoom('D',new Room(import->collection));
	       roomTree->Move('D');
	    }
	 
	    delete anim;
	    anim = new Cutscene(player.Img(), roomTree->At()->GetImage(),
				roomTree->At());
	    anim->EnterUp();
	    break;
	 
	 case 'd' :
	    anim = new Cutscene(player.Img(), roomTree->At()->GetImage(),
				roomTree->At());
	    anim->ExitRight();
	 
	    if(!roomTree->Move('R'))
	    {
	       roomTree->NewRoom('R',new Room(import->collection));
	       roomTree->Move('R');
	    }

	    delete anim;
	    anim = new Cutscene(player.Img(), roomTree->At()->GetImage(),
				roomTree->At());
	    anim->EnterLeft();
	    break;
	 case 't':
	    currState = 'S';
	    return;
	    break;
	 case 'p':
	    if(!roomTree->At()->IsComplete())
	    {
	       currState = 'P';
	       roomTree->At()->complete = true;
	    }
	    else currState = 'E';
	    return;
	    break;
	 case 'q':
	    char ch;
	    cout << "Are you sure you want to quit to main menu?";
	    cin >> ch;
	    if(tolower(ch) == 'y')
	       currState = 'M';
	    else
	       currState = 'E';
	    return;
	    break;
	 case 'i':
	    currState = 'I';
	    return;
	    break;
	 default:
	    currState = 'E';
	    return;
      };

      delete anim;
   }
}

/// Helper function to set the current state of the game based on the current
/// room type.
void ExploreState::SetState(int n)
{
   if(n == 113)
      currState = 'M';
   else
      switch(n)
      {
	 case 0:
	 case 1:
	 case 3:
	    currState = 'E';
	    return;
	    break;
	 case 2:
	    if(!roomTree->At()->IsComplete())
	    {
	       int i;
	       screen->outlineOn = false;
	       for(i = 0; i < 2; i++)
	       {
		  system("clear");
		  screen->Erase();
		  usleep(200000);
		  if(i%2 == 0)
		     screen->Fill('*');
		  else
		     screen->Fill(' ');
		  cout<<screen;
		  usleep(200000);

	       }
	    
	       screen->outlineOn = true;
	       roomTree->At()->complete = true;
	       //currState = 'F';
	    }
	    else currState = 'E';
	    break;
	 default:
	    currState = 'E';
	    return;
      }
}
