#include "MainState.h"

MainState::MainState()
{
   menu = new MainMenu();
}

void MainState::Set()
{
   menu->AddOption('P',"Play Game");
   if(tolower(menu->GetOption()) == 'p')
      currState = 'E';

}
void MainState::Get()
{
   Cutscene anim; anim.Intro();
   menu->HandleInput(cin);
}
