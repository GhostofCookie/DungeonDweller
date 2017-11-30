#include "MainState.h"
#include <vector>
#include <stdlib.h>

MainState::MainState(Player *p)
{
   menu = new MainMenu();
   currState = 'M';
   player = p;
}

MainState::~MainState()
{
   delete screen;
   delete menu;
   delete player;
}

void MainState::Set()
{
   menu->AddOption('p',"Play Game");
   if(tolower(menu->GetOption()) == 'p')
     currState = 'E';
   menu->AddOption('q', "Quit Game");
}

void MainState::Get()
{
   Cutscene anim;
   anim.Intro();
   menu->HandleInput(cin);
   if(tolower(menu->GetOption()) == 'q')
   {
      cout<<"Are you sure you want to quit (y/n)? ";
      menu->HandleInput(cin);
      anim.Outro();
      exit(0);
   }
}
