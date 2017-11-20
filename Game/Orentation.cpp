#include <iostream>
#include <cctype>
#include <stdexcept>
using namespace std;

void FindNewOrientation(char[4] directions, char dir, int treeHeight);
void ShiftDir(char[4] directions,unsigned int numOfShifts);
char Orientation(char[4] directions, char dir);

int main()
{
   char orientation[4] = {'p','l','c','r'}
   return 0;
}


void FindNewOrientation(char[4] directions, char dir, int treeHeight)
{
   dir = toupper(dir);
   switch(dir) {
      case 'P':
	 if(treeHeight == 1)
	    ShiftDir(directions,2);
	 break;
      case 'L':
	 ShiftDir(directions,1);
	 break;
      case 'R':
	 ShiftDir(directions,3);
	 break;
      case 'C':
	 break;
      default:
	 throw invalid_argument("invalid direction");
   }
}

void ShiftDir(char[4] directions,unsigned int numOfShifts)
{
   for(int i = 0; i < numOfShifts; ++i) {
      char temp = directions[0];
      directions[0] = directions[1];
      directions[1] = directions[2];
      directions[2] = directions[3];
      directions[3] = temp;
   }
}

char Orientation(char[4] directions, char dir)
{
   switch(dir) {
      case 'P':
	 return directions[0];
	 break;
      case 'L':
	 return directions[1];
	 break;
      case 'R':
	 return directions[3];
	 break;
      case 'C':
	 return directions[2];
	 break;
      default:
	 throw invalid_argument("invalid direction");
   }

}
