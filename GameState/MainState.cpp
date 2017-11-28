#include "MainState.h"

MainState::MainState()
{
   menu = new MainMenu();
}

MainState::~MainState()
{
   delete screen;
   delete menu;
}

void MainState::Set()
{
   menu->AddOption('P',"Play Game");
   if(tolower(menu->GetOption()) == 'p')
      currState = 'E';
   menu->AddOption('q', "Quit Game");

}
void MainState::Get()
{
   Cutscene anim; anim.Intro();
   menu->HandleInput(cin);
   if(tolower(menu->GetOption()) == 'q')
   {
      cout<<"Are you sure you want to quit (y/n)? ";
      menu->HandleInput(cin);
      anim.Outro();
      exit(0);
   }
}
