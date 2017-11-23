#include "ExploreState.h"
#include <stdlib.h>

/// This is the the default constructor.
ExploreState::ExploreState()
//  :roomTree{roomPtr}
{
   srand((unsigned int) time(NULL));
   menu = new ExploreMenu();
   screen = new Screen();
   imageImport = new ImageImporter("../DD_Art/DD_MasterFileLinux.txt");
   roomPtr = new Room(imageImport->collection);
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
   ImportImg player = ImportImg(imageImport->collection['@'][0]);
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
      menu->HandleInput(cin);
      SwitchRooms();
   }
}

/// Helper function to switch rooms in the room tree.
void ExploreState::SwitchRooms()
{
   Cutscene anim = Cutscene(imageImport->collection['@'][0],roomTree->At()->GetImage(),*roomPtr);
   char n = menu->GetOption();
   switch(n)
   {
      case 'w' :
	 anim = Cutscene(imageImport->collection['@'][0], roomTree->At()->GetImage(), *roomPtr);
	 anim.ExitUp():
	    
	 if(!roomTree->Move('u'))
	 {
	    roomTree->NewRoom('u', new Room(imageImport->collection));
	    roomTree->Move('u');
	 }
	 
	 anim = Cutscene(imageImport->collection['@'][0], roomTree->At()->GetImage(), *roomPtr);
	 anim.EnterTop();
	 break;
	 
      case 'a' :
	 anim = Cutscene(imageImport->collection['@'][0], roomTree->At()->GetImage(), *roomPtr);
	 anim.ExitLeft();
	 
	 if(!roomTree->Move('l'))
	 {
	    roomTree->NewRoom('l',new Room(imageImport->collection));
	    roomTree->Move('l');
	 }
	 
	 anim = Cutscene(imageImport->collection['@'][0], roomTree->At()->GetImage(), *roomPtr);
	 anim.EnterLeft();
	 break;
	 
      case 's' :
	 anim = Cutscene(imageImport->collection['@'][0], roomTree->At()->GetImage(), *roomPtr);
	 anim.ExitDown();
	 
	 if(!roomTree->Move('d'))
	 {
	    roomTree->NewRoom('d',new Room(imageImport->collection));
	    roomTree->Move('d');
	 }
	 
	 anim = Cutscene(imageImport->collection['@'][0], roomTree->At()->GetImage(), *roomPtr);
	 anim.EnterDown();
	 break;
	 
      case 'd' :
	 anim = Cutscene(imageImport->collection['@'][0], roomTree->At()->GetImage(), *roomPtr);
	 anim.ExitRight();
	 
	 if(!roomTree->Move('r'))
	 {
	    roomTree->NewRoom('r',new Room(imageImport->collection));
	    roomTree->Move('r');
	 }
	 
	 anim = Cutscene(imageImport->collection['@'][0], roomTree->At()->GetImage(), *roomPtr);
	 anim.EnterRight();
	 break;
	 
      default :
	 break;
   };
}
