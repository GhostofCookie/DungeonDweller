#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Menu {
private:
	map<int, string> IndexMap;
	int MenuHeight;
	int MenuWidth;
	char **Menu_Array;
	void BuildMenu();

public:
	Menu(int height = 10, int width = 100);
	~Menu();
	void set(int x, int y, char ch);
	virtual void SetOptions(map<int, string> OptionsList, string type = "generic");
	virtual void HandleOptionInput(istream& is);
	virtual void OutputMenu();
};

#endif
