#include "ExploreState.h"
#include <stdlib.h>

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
}

ExploreState::~ExploreState()
{
  delete menu;
  delete screen;
  delete roomPtr;
  delete roomTree;
  delete import;
}

/// Sets the layout for the game menu and screen.
void ExploreState::Set()
{
  if(menu != nullptr)
    {
      delete menu;
      menu = new ExploreMenu();
    }
  SetState((roomTree->At())->GetType());
  menu->AddOption('w',"Move Up");
  menu->AddOption('a',"Move Left");
  menu->AddOption('s',"Move Down");
  menu->AddOption('d',"Move Right");
  if((roomTree->At())->GetType() == 1)
    menu->AddOption('t', "Trade");
}

/// Gets the layout for the game menu and screen.
void ExploreState::Get()
{
   //Remove in the future
   ImportImg player = ImportImg(import->collection['@'][0]);
   player.AlignCenter(*screen);
   
   // ensure the screen clears
   // system("clear");
   // system("clear");
 
   // clear the screen
   screen->Erase();
   // align the current room to the screen and print
   (roomTree->At())->AlignCenter(*screen);
   (roomTree->At())->Draw(*screen);
   player.Draw(*screen);

   // output the screen
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
      
   switch(n)
   {
      case 'w' :
	 anim = new Cutscene(import->collection['@'][0], roomTree->At()->GetImage(),
			     roomTree->At());
	 anim->ExitUp();
	    
	 if(!roomTree->Move('U'))
	 {
	    roomTree->NewRoom('U', new Room(import->collection));
	    roomTree->Move('U');
	 }

	 delete anim;
	 anim = new Cutscene(import->collection['@'][0], roomTree->At()->GetImage(),
			     roomTree->At());
	 anim->EnterDown();
	 break;
	 
      case 'a' :
	 anim = new Cutscene(import->collection['@'][0], roomTree->At()->GetImage(),
			     roomTree->At());
	 anim->ExitLeft();
	 
	 if(!roomTree->Move('L'))
	 {
	    roomTree->NewRoom('L',new Room(import->collection));
	    roomTree->Move('L');
	 }

	 delete anim;
	 anim = new Cutscene(import->collection['@'][0], roomTree->At()->GetImage(),
			     roomTree->At());
	 anim->EnterRight();
	 break;
	 
      case 's' :
	 anim = new Cutscene(import->collection['@'][0], roomTree->At()->GetImage(),
			     roomTree->At());
	 anim->ExitDown();
	 
	 if(!roomTree->Move('D'))
	 {
	    roomTree->NewRoom('D',new Room(import->collection));
	    roomTree->Move('D');
	 }
	 
	 delete anim;
	 anim = new Cutscene(import->collection['@'][0], roomTree->At()->GetImage(),
			     roomTree->At());
	 anim->EnterUp();
	 break;
	 
      case 'd' :
	 anim = new Cutscene(import->collection['@'][0], roomTree->At()->GetImage(),
			     roomTree->At());
	 anim->ExitRight();
	 
	 if(!roomTree->Move('R'))
	 {
	    roomTree->NewRoom('R',new Room(import->collection));
	    roomTree->Move('R');
	 }

	 delete anim;
	 anim = new Cutscene(import->collection['@'][0], roomTree->At()->GetImage(),
			     roomTree->At());
	 anim->EnterLeft();
	 break;
      case 't':
	 currState = 'S';
	 return;
	 break;
   };

   delete anim;
}

/// Helper function to set the current state of the game based on the current
/// room type.
void ExploreState::SetState(int n)
{
   switch(n)
   {
      case 0:
	 currState = 'E';
	 break;
      case 2:
	 //currState = 'F';
	 break;
      case 3:
	 if(!roomTree->At()->IsComplete())
	 {
	    currState = 'P';
	    roomTree->At()->complete = true;
	 }
	 else
	    currState = 'E';
	 break;
   }
}
