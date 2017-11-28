#include "MainState.h"
#include <vector>

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
      CreatePlayer();
   menu->AddOption('q', "Quit Game");

}
void MainState::Get()
{
   Cutscene anim; anim.Intro();
   menu->HandleInput(cin);
   if(tolower(menu->GetOption()) == 'q')
   {
      cout<<"Are you sure you want to quit?";
      menu->HandleInput(cin);
      exit(0);
   }
}

void MainState::CreatePlayer()
{
   cout << "Hello! Welcome to the dungeon." << endl;
   cout << "You are going to need a character to get through this place, what do you want your name to be?" << endl;
   cout << ">:"
   string name;
   cin >> name;
   cout << "You are also going to need some equipment down there too, please choose your load-out." << endl;

   vector<Player> loadOuts;
   Player ranger(40, 1, name, "Ranger", 20, 50);
   Sword *sword;
   ranger.FillInventory(sword);
   
   Player hunter(50, 1, name, "Hunter", 20, 40);
   Bow *bow;
   hunter.FillInventory(bow);
   
   Player warrior(20, 2, name, "Warrior", 20, 70);
   Bow *bowW;
   Sword *swordW;
   hunter.FillInventory(bowW);
   hunter.FillInventory(swordW);
   
   Player mage(40, 5, name, "Mage", 40, 30);
   Spell *spell;
   Spell *spellM;
   mage.FillInventory(spell);
   mage.FillInventory(spellM);

   Player comp(5, 0, name, "The Computer Scientist", 10000, 10);
   
   loadouts.push_back(ranger);
   loadouts.push_back(hunter);
   loadouts.push_back(warrior);
   loadouts.push_back(mage);
   loadouts.push_back(comp);
   
   while(menu->GetOption != 'c')
   {
      int i = 0;

      loadout[i].Print();
      menu->AddOption('c', "Choose race");
      menu->AddOption('n', "Next race");
      if(menu->GetOption() == 'c')
      {
	 player = loadout[i];
	 currState = 'E';
	 break;
      }
      else
	 if(i+1 == 5)
	    i = 0;
      i++;
   }
}
