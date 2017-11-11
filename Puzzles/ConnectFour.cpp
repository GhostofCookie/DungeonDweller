////////////////////////////////////////////////////////////////////////////////
///connect_four.cpp
///\author Tyler Siwy
///CPSC 2720-Howard Cheng-Assignment 2
////////////////////////////////////////////////////////////////////////////////
#include "ConnectFour.h"

ConnectFour::ConnectFour()
{
   xSize=7;
   ySize=6;
   grid.resize(xSize);
   for(int i=0; i<xSize; i++)
   {
      grid.at(i).resize(ySize);
      for(int j=0; j<ySize; j++)
      {
	 grid.at(i).at(j)=' ';
      }
   }  
}

ConnectFour::~ConnectFour()
{

}

void ConnectFour::RunGame()
{

}

// ConnectFour::void PromptUser(&screen)
// {

// }

// ConnectFour::char UserInput(&menu)
// {

// }

bool ConnectFour:: ValidMove(char input)
{
  return true;
}

void ConnectFour::MovePiece(char userPiece, int column)
{
   char currentSpot=' ';
   int height=ySize-1;
   while(currentSpot=' ')
   {
      ///If we have reached the bottom of the column and not found a piece, set
      ///the piece at the bottom of the column and break.
      if(height==0)
      {
	 grid.at(column).at(height)=userPiece;
	 break;
      }
      ///If there are no pieces here, keep moving down through the column
      if(grid.at(column).at(height)==' ')
      {
	 height--;
      }
      ///Else we have found a characters piece, place on top of it and break
      else
      {
	 grid.at(column).at(height+1)=userPiece;
	 break;
      }
   }
}

bool ConnectFour::WinCheck()
{
   if(VerticalCheck()||HorizontalCheck()||
      RightDiagonalCheck()||LeftDiagonalCheck())
      return true;
   else
      return false;
}

///Checks the entire grid to see if there is 4 of a kind in the horizontal
///position, returns true if it finds 4 of a kind, false otherwise.
bool ConnectFour::HorizontalCheck()
{
   ///atCount counts the number of '@' tokens in the line.
   ///copyrightCount counts the number of '©' tokens in the line. 
   int atCount=0, copyrightCount=0;
   for(int i=0; i<ySize; i++)
   {
      for(int j=0; j<xSize; j++)
      {
	 ///If an '@' token is found, reset the count for copyright since it is
	 /// not consecutive anymore.
	 if(grid.at(i).at(j)=='@')
	 {
	    atCount++;
	    copyrightCount=0;
	 }
	 ///If a '©' token is found, reset the count for at since it is not
	 ///consecutive anymore.  
	 else if(grid.at(i).at(j)=='©')
	 {
	    copyrightCount++;
	    atCount=0;
	 }
      }

      ///If either count is at 4 then we have found four of a kind and a player
      ///has won so return true.                                               
      if(atCount==4||copyrightCount==4)
	 return true;

      ///Reset both counters since we've reached the end of the column with no
      ///match found.  
      atCount=0;
      copyrightCount=0;
   }
   return false;
}

///Checks the entire grid to see if there is 4 of a kind in the vertical
///position, returns true if it finds 4 of a kind, false otherwise.  
bool ConnectFour::VerticalCheck()
{
   ///atCount counts the number of '@' tokens in the line.
   ///copyrightCount counts the number of '©' tokens in the line.
   int atCount=0, copyrightCount=0;
   for(int i=0; i<xSize; i++)
   {
      for(int j=0; j<ySize; j++)
      {
	 ///If an '@' token is found, reset the count for copyright since it is
	 /// not consecutive anymore.   
	 if(grid.at(i).at(j)=='@')
	 {
	    atCount++;
	    copyrightCount=0;
	 }
	 ///If a '©' token is found, reset the count for at since it is not
	 ///consecutive anymore.  
	 else if(grid.at(i).at(j)=='©')
	 {
	    copyrightCount++;
	    atCount=0;
	 }
      }

      ///If either count is at 4 then we have found four of a kind and a player
      ///has won so return true. 
      if(atCount==4||copyrightCount==4)
	 return true;

      ///Reset both counters since we've reached the end of the column with no
      ///match found.
      atCount=0;
      copyrightCount=0;
   }
   return false;
   

}

///Checks the entire grid to see if there is 4 of a kind in the right diagonal
///position, returns true if it finds 4 of a kind, false otherwise.  
bool ConnectFour::RightDiagonalCheck()
{
   ///atCount counts the number of '@' tokens in the diagonal line.
   ///copyrightCount counts the number of '©' tokens in the diagonal line.
   int atCount=0, copyrightCount=0;

   int j=xSize;
   ///j will the be horizontal movement, i will be the vertical movement. 
   for(int i=0; i<ySize; i++)
   {
      j--;
      ///If j has reached the end of the array, we haven't found four of a king
      /// so break out of the loop.
      if(j<0)
	 break;

      ///If an '@' token is found, reset the count for copyright since it is not
      ///consecutive anymore.
      if(grid.at(j).at(i)=='@')
      {
	 atCount++;
	 copyrightCount=0;
      }

      ///If a '©' token is found, reset the count for at since it is not
      ///consecutive anymore.
      else if(grid.at(j).at(i)=='©')
      {
	 copyrightCount++;
	 atCount=0;
      }

      ///If an empty space is found reset both counters since it is no longer a
      ///consecutive line
      else if(grid.at(j).at(i)==' ')
      {
	 copyrightCount=0;
	 atCount=0;
      }

      ///If either count is at 4 then we have found four of a kind and a player
      ///has won so return true.
      if(atCount==4||copyrightCount==4)
	 return true;
   }
   ///If no 4 of a kind has been found, return false.
   return false;
}

///Checks the entire grid to see if there is 4 of a kind in the left diagonal
///position, returns true if it finds 4 of a kind, false otherwise.  
bool ConnectFour::LeftDiagonalCheck()
{
   ///atCount counts the number of '@' tokens in the diagonal line.
   ///copyrightCount counts the number of '©' tokens in the diagonal line. 
   int atCount=0, copyrightCount=0;

   int j=-1;
   ///j will the be horizontal movement, i will be the vertical movement.

   for(int i=0; i<ySize; i++)
   {
      j++;
      ///If j has reached the end of the array, we haven't found four of a king
      /// so break out of the loop.    
      if(j>xSize-1)
	 break;

      ///If an '@' token is found, reset the count for copyright since it is not
      ///consecutive anymore.
      if((grid.at(j).at(i)=='@'))
      {
	 atCount++;
	 copyrightCount=0;
      }

      ///If a '©' token is found, reset the count for at since it is not
      ///consecutive anymore.  
      else if((grid.at(j).at(i)=='©'))
      {
	 copyrightCount++;
	 atCount=0;
      }

      ///If an empty space is found reset both counters since it is no longer a
      ///consecutive line
      else if(grid.at(j).at(i)==' ')
      {
	 copyrightCount=0;
	 atCount=0;
      }

      ///If either count is at 4 then we have found four of a kind and a player
      ///has won so return true.  
      if(atCount==4||copyrightCount==4)
	 return true;
   }
   return false;
}

///Function which checks if a column is full
bool ConnectFour::IsColumnFull(int x)
{
   int charCount=0;
   for(int i=0; i<ySize; i++)
   {
      if(grid.at(x).at(i)=='@'||grid.at(x).at(i)=='©')
	 charCount++;
   }
   ///If the column is full, return true, else return false.
   if(charCount==ySize)
      return true;
   else
      return false;
}

///Returns true if every space in the board has been filled with a character
bool ConnectFour::IsBoardFull(){
   int charCount=0;
   for(int i=0; i<xSize; i++)
   {
      for(int j=0; j<ySize; j++)
      {
	 if((grid.at(i).at(j)=='@')||grid.at(i).at(j)=='©')
	    charCount++;
      }
   }
   ///If the entire grid is full of characters, return true, else return false.
   if(charCount==xSize*ySize)
      return true;
   return false;   
}

//bool ConnectFour:: ValidCommand(char input)
//{
//   return true;
//}

//WAITING ON SCREEN FROM REID
// ConnectFour::void OutputGame(&screen)
// {

// }
