#include "MainState.h"
#include "Cutscene.h"
#include "MainMenu.h"
#include <vector>
#include <stdlib.h>

MainState::MainState(std::shared_ptr<Viewport> view)
{
	menu = new MainMenu();
	viewport = view;
}

void MainState::Set()
{
	menu->AddOption('p', "Play Game");
	menu->AddOption('q', "Quit Game");
}

void MainState::Get()
{
	Cutscene anim(viewport);
	anim.Intro();
	menu->HandleInput(std::cin);

	if (tolower(menu->GetOption()) == 'p')
		currState = States::EXPLORE;
	else if (tolower(menu->GetOption()) == 'q')
	{
		std::cout << "Are you sure you want to quit (y/n)? ";
		menu->HandleInput(std::cin);
		anim.Outro();
		exit(0);
	}
}
