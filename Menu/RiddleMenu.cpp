#include "RiddleMenu.h"

RiddleMenu::RiddleMenu()
{
}

RiddleMenu::~RiddleMenu()
{
}

void RiddleMenu::SetOptions(int row, int col, int space)
{
   for(int i = 0; i < menuWidth-2; i++)
      Set(menuHeight/2-1,i, ' ');
   for(unsigned int i = 0; i < query.length(); i++)
      Set(menuHeight/2-1,menuWidth/2 - query.length()/2-1+i, query[i]);
}

void RiddleMenu::HandleInput(istream & is)
{
   int y;
   cout << "-> ";
   is>>y;
   is.clear();
   is.ignore(255,'\n');

   if(is.fail())
   {
      query = "Incorrect.";
      return;
      is.clear();
      is.ignore(255,'\n');
      throw invalid_argument("Invalid input. please enter coordinates in format A1.");
   }
   else
      input = y;

}

int RiddleMenu::GetInput() const
{
   return input;
}
