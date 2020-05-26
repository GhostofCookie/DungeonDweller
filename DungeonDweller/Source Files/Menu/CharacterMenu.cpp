/** @date 25/10/2017
 * @author Tomas Rigaux
 *
 * Derived from GameMenu. This is the menu for the player to choose their
 * character.
 */

#include "CharacterMenu.h"
#include <string>

CharacterMenu::CharacterMenu()
{
}

CharacterMenu::~CharacterMenu()
{
}

void CharacterMenu::SetOptions(int row, int col, int space)
{
   auto it = indexMap.begin();
   std::string tempName;
   int origRow = row;
   std::string ch;

   while (it != indexMap.end())
   {
   if(tolower(it->first) != 'q')
     ch = std::to_string(it->first);
   else ch = tolower(it->first);
     tempName += '['; tempName += ch;
      tempName += ']';tempName += it->second;
      for (unsigned int j = 0; j < tempName.length(); j++)
      {
	 if(it->first != 113) Set(row-1, col + j, tempName[j]);
	 else Set(menuHeight - 3, menuWidth / 2 + j - tempName.length() / 2
		  , tempName[j]);
      }
      if(it->first != 113 && row > 2) row += space;
      if (row >= menuHeight - 1)
      {
	 row = origRow;
	 col += it->second.length() + menuWidth / 4 + 1;
      }
      ++it;
      tempName = "";
   }
   it = indexMap.begin();
}

void CharacterMenu::HandleInput( std::istream &is)
{
   Menu::HandleInput(is);
}
