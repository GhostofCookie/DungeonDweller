/// \author Tomas Rigaux
/// \date 8/11/2017
///
/// This is the testing class for Menu. 
///

#include "MenuTest.h"
void TestAdd(int);

/// Sets up the test variables for testing.
void MenuTest::setUp()
{
   menu = new Menu();
   menu2 = new Menu(100, 100);
   menu3 = new FightMenu();
   menu4 = new TradeMenu();
   menu5 = new HanoiMenu();
   menu6 = new ConnectFourMenu();
   menu7 = new TicTacToeMenu();
   menu8 = new ExploreMenu();
   menu9 = new RiddleMenu();
}
/// Deletes any pointers to prevent memory leak.
void MenuTest::tearDown()
{
   delete menu;
   delete menu2;
   delete menu3;
   delete menu4;
   delete menu5;
   delete menu6;
   delete menu7;
   delete menu8;
   delete menu9;
}
/// Tests that the constructor is wokring in several varieties of construction.
void MenuTest::TestConstructors()
{
   if(menu != nullptr) delete menu;
   menu = new Menu();
   if(menu2 != nullptr) delete menu2;
   menu2 = new Menu(100, 100);
   if(menu3 != nullptr) delete menu3;
   menu3 = new FightMenu();
   if(menu4 != nullptr) delete menu4;
   menu4 = new TradeMenu();
   if(menu5 != nullptr) delete menu5;
   menu5 = new HanoiMenu();
   if(menu6 != nullptr) delete menu6;
   menu6 = new ConnectFourMenu();
   if(menu7 != nullptr) delete menu7;
   menu7 = new TicTacToeMenu();
   if(menu8 != nullptr) delete menu8;
   menu8 = new ExploreMenu();
   if(menu9 != nullptr) delete menu9;
   menu9 = new RiddleMenu();
}
/// Tests the setting of options.
void MenuTest::TestSetting()
{
   menu->AddOption('1', "tester 1");
   menu2->AddOption('2',"tester 2");
   menu3->AddOption('3',"tester 3");
   menu4->AddOption('4',"tester 4");
   menu5->AddOption('5',"tester 5");
   menu6->AddOption('6',"tester 6");
   menu7->AddOption('7',"tester 7");
   menu8->AddOption('8',"tester 8");
   menu9->AddOption('9',"tester 9");
   menu->OutputMenu();
   menu2->OutputMenu();
   menu3->OutputMenu();
   menu4->OutputMenu();
   menu5->OutputMenu();
   menu6->OutputMenu();
   menu7->OutputMenu();
   menu8->OutputMenu();
   menu9->OutputMenu();
}

/// Tests that menu builds correctly.
void MenuTest::TestBuilding()
{
   menu->AddOption('1', "tester 1");
   menu2->AddOption('2',"tester 2");
   menu3->AddOption('3',"tester 3");
   menu4->AddOption('4',"tester 4");
   menu5->AddOption('5',"tester 5");
   menu6->AddOption('6',"tester 6");
   menu7->AddOption('7',"tester 7");
   menu8->AddOption('8',"tester 8");
   menu9->AddOption('9',"tester 9");
   menu->SetOptions();
   menu2->SetOptions();
   menu3->SetOptions();
   menu4->SetOptions();
   menu5->SetOptions();
   menu6->SetOptions();
   menu7->SetOptions();
   menu8->SetOptions();
   menu9->SetOptions();
   menu->OutputMenu();
   menu2->OutputMenu();
   menu3->OutputMenu();
   menu4->OutputMenu();
   menu5->OutputMenu();
   menu6->OutputMenu();
   menu7->OutputMenu();
   menu8->OutputMenu();
   menu9->OutputMenu();
}
