#include "ExploreState.h"

/// This is the the default constructor.
ExploreState::ExploreState()
//  :roomTree{roomPtr}
{
  menu = new ExploreMenu();
  screen = new Screen();
  masterFile = "../DD_Art/DD_MasterFileLinux.txt";
  imageImport = ImageImporter(masterFile);
  roomPtr = new Room(imageImport.collection);
  roomTree = new RoomTree(roomPtr);
  ImportImg *img = new ImportImg(imageImport.collection['@'][0]);
  anim = new Cutscene(*img, roomPtr->GetImage());
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
  while(true)
  {
    // clear the screen
    screen->Erase();
    // align the current room to the screen and print
    (roomTree->At())->AlignCenter(*screen);
    (roomTree->At())->Draw(*screen);
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
  char n = menu->GetOption();
  switch(n)	{
  case 'w' :
    if(!roomTree->Move('u'))
      {
	anim->CenterToTop(*screen);
	roomTree->NewRoom('u', new Room(imageImport.collection));
	roomTree->Move('u');
      }
    break;
  case 'a' :
    if(!roomTree->Move('l'))
      {
	anim->CenterToLeft(*screen);
	roomTree->NewRoom('l',new Room(imageImport.collection));
	roomTree->Move('l');
      }
    break;
  case 's' :
    if(!roomTree->Move('d'))
      {
	anim->CenterToBottom(*screen);
	roomTree->NewRoom('d',new Room(imageImport.collection));
	roomTree->Move('d');
      }
    break;
  case 'd' :
    if(!roomTree->Move('r'))
      {
	anim->CenterToRight(*screen);
	roomTree->NewRoom('r',new Room(imageImport.collection));
	roomTree->Move('r');
      }
    break;
  default :
    break;
  };
}
