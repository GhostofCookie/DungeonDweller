/// \author Tomas Rigaux
/// \date 8/11/2017
///
/// This is the testing class for Menu. 
///

#include "MenuTest.h"
void TestAdd(int);

/// Sets up the test variables for testing.
void MenuTest::SetUp()
{
   menu = new Menu();
   menu2 = new Menu(100, 100);
}
/// Deletes any pointers to prevent memory leak.
void MenuTest::TearDown()
{
//   delete menu;
}
/// Tests that the constructor is wokring in several varieties of construction.
void MenuTest::TestConstructors()
{
   menu = new Menu();
   menu2 = new Menu(100,100);
}
/// Tests the setting of options.
void MenuTest::TestSetting()
{
   menu = new Menu();
   menu->AddOption('1',"tester 1",TestAdd);
   // menu->SetOptions();
   //  menu2->AddOption('2',"tester 2",exit);
   // menu2->SetOptions(5, 10);
}

void TestAdd(int i)
{

}
/// Tests that menu builds correctly.
void MenuTest::TestBuilding()
{
//   menu->AddOption('1',"tester 1",exit);
//   menu->SetOptions();
//   menu->OutputMenu();
//   menu2->AddOption('2',"tester 2",exit);//
//   menu2->SetOptions(10, 20);
//   menu2->OutputMenu();
}
