#include "ExploreState.h"
#include <stdlib.h>

/// This is the the default constructor.
ExploreState::ExploreState()
//  :roomTree{roomPtr}
{
   // set random seed
   srand((unsigned int) time(NULL));
   
   menu = new ExploreMenu();
   screen = new Screen();
   import = new ImageImporter("../DD_Art/DD_MasterFileLinux.txt");
   roomPtr = new Room(import->collection);
   roomTree = new RoomTree(roomPtr);
}
/// Sets the layout for the game menu and screen.
void ExploreState::Set()
{
 
   menu->AddOption('w',"Move Up");
   menu->AddOption('a',"Move Left");
   menu->AddOption('s',"Move Down");
   menu->AddOption('d',"Move Right");
}

/// Gets the layout for the game menu and screen.
void ExploreState::Get()
{
   //Remove in the future
   ImportImg player = ImportImg(import->collection['@'][0]);
   player.AlignCenter(*screen);
   
   while(true)
   {
     system("clear");
     system("clear");

      // clear the screen
      screen->Erase();
      // align the current room to the screen and print
      (roomTree->At())->AlignCenter(*screen);
      (roomTree->At())->Draw(*screen);
      player.Draw(*screen);
      cout<<screen;
      // Print the menu and handle user input
      menu->OutputMenu();
 menu->AddOption(roomTree->At()->GetType(),"Current room Type");
      menu->HandleInput(cin);
      SwitchRooms();
   }
}

/// Helper function to switch rooms in the room tree.
void ExploreState::SwitchRooms()
{
   Cutscene *anim;
      
   char n = menu->GetOption();
   switch(n)
   {
      case 'w' :
	 anim = new Cutscene(import->collection['@'][0], roomTree->At()->GetImage(), *roomTree->At());
	 anim->ExitUp();
	    
	 if(!roomTree->Move('u'))
	 {
	    roomTree->NewRoom('u', new Room(import->collection));
	    roomTree->Move('u');
	 }

	 delete anim;
	 anim = new Cutscene(import->collection['@'][0], roomTree->At()->GetImage(), *roomTree->At());
	 anim->EnterDown();
	 break;
	 
      case 'a' :
	 anim = new Cutscene(import->collection['@'][0], roomTree->At()->GetImage(), *roomTree->At());
	 anim->ExitLeft();
	 
	 if(!roomTree->Move('l'))
	 {
	    roomTree->NewRoom('l',new Room(import->collection));
	    roomTree->Move('l');
	 }

	 delete anim;
	 anim = new Cutscene(import->collection['@'][0], roomTree->At()->GetImage(), *roomTree->At());
	 anim->EnterRight();
	 break;
	 
      case 's' :
	 anim = new Cutscene(import->collection['@'][0], roomTree->At()->GetImage(), *roomTree->At());
	 anim->ExitDown();
	 
	 if(!roomTree->Move('d'))
	 {
	    roomTree->NewRoom('d',new Room(import->collection));
	    roomTree->Move('d');
	 }
	 
	 delete anim;
	 anim = new Cutscene(import->collection['@'][0], roomTree->At()->GetImage(), *roomTree->At());
	 anim->EnterUp();
	 break;
	 
      case 'd' :
	 anim = new Cutscene(import->collection['@'][0], roomTree->At()->GetImage(), *roomTree->At());
	 anim->ExitRight();
	 
	 if(!roomTree->Move('r'))
	 {
	    roomTree->NewRoom('r',new Room(import->collection));
	    roomTree->Move('r');
	 }

	 delete anim;
	 anim = new Cutscene(import->collection['@'][0], roomTree->At()->GetImage(), *roomTree->At());
	 anim->EnterLeft();
	 break;
	 
      default :
	 break;
   };

   delete anim;
}

void ExploreState::SetState(int n)
{
  switch(n)
    {
    case 0:
      currState = 'E';
      break;
    case 1:
      currState = 'S';
	break;
    case 2:
      currState = 'F';
      break;
    case 3:
      currState = 'P';
      break;
    }
}
