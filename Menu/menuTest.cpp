/// \author Tomas Rigaux
/// \date 8/11/2017
///
/// This is the testing class for Menu. 
///

#include "MenuTest.h"

/// Sets up the test variables for testing.
void MenuTest::setUp()
{
	menu = new Menu();
	menu2 = new Menu(100, 100);
	options.insert(pair<int, string>(1, "I'm the first option!"));
	options.insert(pair<int, string>(2, "I'm the second!"));
}
/// Deletes any pointers to prevent memory leak.
void MenuTest::tearDown()
{
	//   delete menu;
}
/// Tests that the constructor is wokring in several varieties of construction.
void MenuTest::testConstructors()
{

}
/// Tests the setting of options.
void MenuTest::testSetting()
{
	menu->SetOptions(options);
	menu2->SetOptions(options, 5, 10);
}
/// Tests that menu builds correctly.
void MenuTest::testBuilding()
{
	menu->SetOptions(options);
	menu->OutputMenu();
	menu2->SetOptions(options, 10, 20);
	menu2->OutputMenu();
}
