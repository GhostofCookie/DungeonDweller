// Created 05/10/2017
/// \author "Tomas Rigaux"
///
/// This is the interface for the Menu class. This class defines a Menu object for the 
///
///

#ifndef MENU_H
#define MENU_H

#include <iostream>

class Menu {
private:
	int MenuHeight;
	int MenuWidth;
	char** Menu_Array;
public:
	Menu(int height = 10, int width = 100);
	virtual ~Menu();

};

#endif