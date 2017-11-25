#include "MemoryMenu.h"

MemoryMenu::MemoryMenu()
{
   coordinates.x = ' ';
   coordinates.y = 1;
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
      Set(menuHeight/2-1,menuWidth/2 - query.length()/2-1+i, query[i]);
}

void MemoryMenu::HandleInput(istream & is)
{
   char x;
   int y;
   cout << "-> ";
   is>>x>>y;
   is.clear();
   is.ignore(255,'\n');
   if((tolower(x) >= 'a' && tolower(x) < 'e') && (y > 0 && y < 5))
   {
      coordinates.x = x;
      coordinates.y = y;
      query = "Enter coordinates (e.g. A1)";
   }
   else 
   {
      query = "Invalid coordinates. Please ensure that your query is between A1 and D4";
      coordinates.x = ' ';
      coordinates.y = 0;
   }
   if(is.fail())
      throw invalid_argument("Invalid input. please enterr coordinates in format A1.");
}

MemoryMenu::Coord MemoryMenu::GetCoordinates() const
{
  return coordinates;
}
