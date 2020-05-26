/** @date 24/10/2017
 * @author Tomas Rigaux
 *
 * This is the menu class for the Memory Match minigame. It is a subclass of
 * MinigameMenu.
 */

#include "MemoryMenu.h"

MemoryMenu::MemoryMenu()
{
   coordinates.x1 = ' ';
   coordinates.x2 = ' ';
   coordinates.y1 = 1;
   coordinates.y2 = 1;
   indexMap.clear();
   indexMap.erase('q');
   query = "Enter coordinates (e.g. A1)";
}

MemoryMenu::~MemoryMenu()
{
}

void MemoryMenu::SetOptions(int row, int col, int space)
{
   for(int i = 0; i < menuWidth-2; i++)
      Set(menuHeight/2-1,i, ' ');
   for(unsigned int i = 0; i < query.length(); i++)
      Set(menuHeight / 2 - 1, menuWidth / 2 - query.length() / 2 - 1 + i
	  , query[i]);
}

void MemoryMenu::HandleInput( std::istream & is)
{
   char x1, x2;
   int y1, y2;
   std::cout << "-> ";
   is >> x1 >> y1 >> x2 >> y2;
   is.clear();
   is.ignore(255, '\n');
   if((tolower(x1) >= 'a' && tolower(x1) < 'e') && (y1 > 0 && y1 < 5) &&
      (tolower(x2) >= 'a' && tolower(x2) < 'e') && (y2 > 0 && y2 < 5))
   {
      coordinates.x1 = x1;
      coordinates.y1 = y1;
      coordinates.x2 = x2;
      coordinates.y2 = y2;
      query = "Enter two sets of coordinates (e.g. A1 C2)";
   }
   else 
   {
      query = "Invalid coordinates. Please enter coordinates between A1 and D4";
      coordinates.x1 = ' ';
      coordinates.x2 = ' ';
      coordinates.y1 = 0;
      coordinates.y2 = 0;
   }
   if(is.fail())
      throw std::invalid_argument("Invalid input. please enter coordinates in format A1.");
}

MemoryMenu::Coord MemoryMenu::GetCoordinates() const
{
  return coordinates;
}
