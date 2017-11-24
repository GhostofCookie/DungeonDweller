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
   Cutscene anim1 = Cutscene(imageImport->collection['@'][0], roomTree->At()->GetImage(), *roomPtr);
   Cutscene anim2 = Cutscene(imageImport->collection['@'][0], roomTree->At()->GetImage(), *roomPtr);
   Cutscene anim3 = Cutscene(imageImport->collection['@'][0], roomTree->At()->GetImage(), *roomPtr);
   Cutscene anim4 = Cutscene(imageImport->collection['@'][0], roomTree->At()->GetImage(), *roomPtr);
   Cutscene anim5 = Cutscene(imageImport->collection['@'][0], roomTree->At()->GetImage(), *roomPtr);
   Cutscene anim6 = Cutscene(imageImport->collection['@'][0], roomTree->At()->GetImage(), *roomPtr);
   Cutscene anim7 = Cutscene(imageImport->collection['@'][0], roomTree->At()->GetImage(), *roomPtr);
   Cutscene anim8 = Cutscene(imageImport->collection['@'][0], roomTree->At()->GetImage(), *roomPtr);
   
   char n = menu->GetOption();
   switch(n)
   {
      case 'w' :
	 anim1 = Cutscene(imageImport->collection['@'][0], roomTree->At()->GetImage(), *roomPtr);
	 anim1.ExitUp();
	    
	 if(!roomTree->Move('u'))
	 {
	    roomTree->NewRoom('u', new Room(imageImport->collection));
	    roomTree->Move('u');
	 }
	 
	 anim2 = Cutscene(imageImport->collection['@'][0], roomTree->At()->GetImage(), *roomPtr);
	 anim2.EnterDown();
	 break;
	 
      case 'a' :
	 anim3 = Cutscene(imageImport->collection['@'][0], roomTree->At()->GetImage(), *roomPtr);
	 anim3.ExitLeft();
	 
	 if(!roomTree->Move('l'))
	 {
	    roomTree->NewRoom('l',new Room(imageImport->collection));
	    roomTree->Move('l');
	 }
	 
	 anim4 = Cutscene(imageImport->collection['@'][0], roomTree->At()->GetImage(), *roomPtr);
	 anim4.EnterRight();
	 break;
	 
      case 's' :
	 anim5 = Cutscene(imageImport->collection['@'][0], roomTree->At()->GetImage(), *roomPtr);
	 anim5.ExitDown();
	 
	 if(!roomTree->Move('d'))
	 {
	    roomTree->NewRoom('d',new Room(imageImport->collection));
	    roomTree->Move('d');
	 }

	 anim6 = Cutscene(imageImport->collection['@'][0], roomTree->At()->GetImage(), *roomPtr);
	 anim6.EnterUp();
	 break;
	 
      case 'd' :
	 anim7 = Cutscene(imageImport->collection['@'][0], roomTree->At()->GetImage(), *roomPtr);
	 anim7.ExitRight();
	 
	 if(!roomTree->Move('r'))
	 {
	    roomTree->NewRoom('r',new Room(imageImport->collection));
	    roomTree->Move('r');
	 }

	 anim8 = Cutscene(imageImport->collection['@'][0], roomTree->At()->GetImage(), *roomPtr);
	 anim8.EnterLeft();
	 break;
	 
      default :
	 break;
   };
}
