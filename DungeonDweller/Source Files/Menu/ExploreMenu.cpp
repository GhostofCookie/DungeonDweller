/** @date 25/10/2017
 * @author Tomas Rigaux
 *
 * Derived from GameMenu. This is the menu for the player character to use when
 * they are exploring rooms in the game.
 */

#include "ExploreMenu.h"
#include <conio.h>

void ExploreMenu::SetOptions(int row, int col, int space)
{
	std::map < int, std::string > optionList = indexMap;
	int width = menuWidth;
	auto it = optionList.begin();
	int value = 1, count = 0, divider = 4;
	std::string temp;
	while (it != optionList.end())
	{
		temp += '['; temp += it->first; temp += ']'; temp += it->second;
		if (optionList.size() > 5)
			divider = 6;
		else
			divider = 4;
		for (unsigned int i = 0; i < temp.length(); i++)
		{

			if (it->first != 113 && count < 3)
				Set(row, ((width - 2) * value) / divider + i - temp.length() / 2 + 1, temp[i]);
			if (it->first != 113 && count >= 3)
				Set(row + 2, ((width - 2) * value) / divider + i - temp.length() / 2 + 1, temp[i]);
			if (it->first == 113)
				Set(8, width / 2 + i - it->second.length() / 2, temp[i]);
		}
		if (it->first != 'q')
			value += 2;
		++count;
		if (count == 3)
			value = 1;

		++it;
		temp = "";
	}
}
