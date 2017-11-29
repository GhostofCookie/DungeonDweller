/// \date 25/10/2017
/// \author Tomas Rigaux
///
/// Derived from GameMenu. This is the menu for the player to choose their
/// character.

#include "CharacterMenu.h"

/// This is the default constructor.
CharacterMenu::CharacterMenu()
{
}

/// This is the virtual destructor.
CharacterMenu::~CharacterMenu()
{
}

/// This function sets the specific options for the Menu type.
/// \param[in] row The row to start setting the options.
/// \param[in] col The column to start aetting options.
/// \param[in] space the space in-between options.
void CharacterMenu::SetOptions(int row, int col, int space)
{
   auto it = indexMap.begin();
   string tempName;
   int origRow = row;
   string ch;

   while (it != indexMap.end())
   {
   if(tolower(it->first) != 'q')
     ch = to_string(it->first);
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

/// This function handles the input for the menu options.
/// \param[in,out] is The in-stream operator to read the input.
void CharacterMenu::HandleInput(istream &is)
{
   Menu::HandleInput(is);
}
