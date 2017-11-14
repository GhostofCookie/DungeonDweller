////////////////////////////////////////////////////////////////////////////////
///ConnectFour.cpp

#include "ConnectFour.h"

ConnectFour::ConnectFour()
{
   PuzzleEnd=false;
   ///Setting up the game vector 
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

void ConnectFour::SetOptionsInMenu()
{

}

void ConnectFour::BoardSetup()
{
   int horizontalBoardSize=15, verticalBoardSize=13, topBound=10, leftBound=43;
   for(int i=0; i<verticalBoardSize; i++)
   {
      for(int j=0; j<horizontalBoardSize; j++)
      {
	 ///If i is odd, fill the entire row with '-'
	 if(i%2==0)
	 {
	    ///topBound and leftBound should set the board centered inside
	    ///the screen object.
	    ConnectFourScreen.Set((topBound+i), (leftBound+j),'-');
	 }
	 ///If i is even, fill the row with squares to place tokens in later
	 else
	 {
	    if(j%2!=0)
	    {
	       ///topBound and leftBound should set the board centered inside
	       ///the screen object.  
	       ConnectFourScreen.Set((topBound+i),(leftBound+j),' ');
	    }
	    else
	    {
	       ///topBound and leftBound should set the board centered inside
	       ///the screen object.  
	       ConnectFourScreen.Set((topBound+i),(leftBound+j),'|');
	    }
	 }
      }
   }
}

bool ConnectFour:: ValidMove(int input)
{
   if(IsColumnFull(input))
      return false;
   else
      return true;
}

void ConnectFour::MovePiece(char userPiece, int column)
{
   int leftBound=42, bottomSlotHeight=21;;
   if(!IsColumnFull(column))
   {
      char currentSpot=' ';
      int height=ySize-1;
      while(currentSpot==' ')
      {
	 ///If there are no pieces here, keep moving down through the column
	 if(grid.at(column-1).at(height)==' ')
	 {
	    height--;
	 }
	 ///Else we have found a characters piece, place on top of it and break
	 if(grid.at(column-1).at(height)=='#' ||grid.at(column-1).at(height)=='@')
	 {
	    ///Height needs to be incremented since we want to place one space
	    ///above the char that we just found in the grid.
	    height++;
	    ///Set the char in the vector grid
	    grid.at(column-1).at(height)=userPiece;
	    ///Set the char in the screen
	    ///Height and column are multiplied by 2 since the actual vector has
	    /// 1/2 as many spots as the grid displayed on the screen does.
	    height*=2;
	    ConnectFourScreen.Set((bottomSlotHeight-height),(column*2+leftBound)
				  ,(userPiece));
	    ///Break the loop
	    currentSpot=userPiece;
	 }
	 ///If we have reached the bottom of the column and not found a piece, set
	 ///the piece at the bottom of the column and break.
	 if(height==0)
	 {
	    ///Set the char in the vector grid
	    grid.at(column-1).at(height)=userPiece;
	    ///Set the char in the screen
            ///Height and column are multiplied by 2 since the actual vector has
	    /// 1/2 as many spots as the grid displayed on the screen does.
	    ///Add 11 to the topBound to place it in the bottom slot in the grid.
	    ConnectFourScreen.Set((height*2+bottomSlotHeight),(column*2+leftBound)
				  ,(userPiece));
	    ///Break the loop
	    currentSpot=userPiece;
	 }
      }
   }else
      cout << "Column is full!" << endl;
}

void ConnectFour::RunGame()
{
   ///currentPlayer keeps track of whos turn it is, if it's odd, it is the user,
   ///if it is even, it is the AI's turn.
   int currentPlayer=1;
   
   BoardSetup();
   //ConnectFourMenu connectFourGameMenu;
   //connectFourGameMenu.OutputMenu();

   cout << "Drop in column 1" << endl;
   MovePiece('@',5);
   MovePiece('#',2);
   MovePiece('@',3);
   MovePiece('#',3);
   MovePiece('@',4);
   MovePiece('@',4);
   MovePiece('#',4);
   MovePiece('#',5);
   MovePiece('#',5);
   MovePiece('#',5);
   while(PuzzleEnd==false)
   {
      cout << ConnectFourScreen << endl;
      //connectFourMenu.OutputMenu();
      //connectFourMenu.HandleInput(cin);
      if(WinCheck())
      {
	 ///If currentPlayer is even, the AI has won, -1 player health, reset
	 ///the game for another round until the player has won.
	 if(currentPlayer%2==0)
	 {
	    cout << "The connect four champion has defeated you! Lose 1 health"
		 << " point." << endl;
	    //-1 Health
	    ResetGame();
	    cout << "Get ready to duel her again!" << endl;
	 }
	 else
	 {
	    cout << "Congratulations adventurer! You have defeated the champion"
		 << "! You are free to proceed into the next area!" << endl;
	    PuzzleEnd=true;
	 }
      }

      //Placed for testing
      PuzzleEnd=true;
      ///increment the player
      currentPlayer++;
   }
}

bool ConnectFour::WinCheck()
{
   cout << "Win Check" << endl;
   if(VerticalCheck() || HorizontalCheck() ||RightDiagonalCheck()||LeftDiagonalCheck())
      return true;
   else
      return false;
}

///Checks the entire grid to see if there is 4 of a kind in the vertical
///position, returns true if it finds 4 of a kind, false otherwise.  
bool ConnectFour::VerticalCheck()
{
   cout << "Vertical Check" << endl;
   ///atCount counts the number of '@' tokens in the line.
   ///copyrightCount counts the number of '#' tokens in the line.
   int atCount=0, poundCount=0;
   for(int i=0; i<xSize; i++)
   {
      for(int j=0; j<ySize; j++)
      { 
	 if(grid.at(i).at(j)=='@')
	 {
	    atCount++;
	    poundCount=0;
	 }
	 ///If a '#' token is found, reset the count for at since it is not
	 ///consecutive anymore.  
	 else if(grid.at(i).at(j)=='#')
	 {
	    poundCount++;
	    atCount=0;
	 }
	 ///If either count is at 4 then we have found four of a kind and a player
	 ///has won so return true. 
	 if(atCount==4 || poundCount==4)
	 {
	    cout << "VC TRUE" << endl;
	    return true;
	 }
      }	   
      ///Reset both counters since we've reached the end of the column with no
      ///match found.
      atCount=0;
      poundCount=0;
   }
   ///No matches found, return false
   cout << "VC FALSE" << endl;
   return false;
}

///Checks the entire grid to see if there is 4 of a kind in the horizontal
///position, returns true if it finds 4 of a kind, false otherwise.
bool ConnectFour::HorizontalCheck()
{
   cout << "Horizontal Check" << endl;
   ///atCount counts the number of '@' tokens in the line.
   ///copyrightCount counts the number of '©' tokens in the line. 
   int atCount=0, poundCount=0;
   for(int i=0; i<ySize; i++)
   {
      for(int j=0; j<xSize; j++)
      {
	 ///If an '@' token is found, reset the count for copyright since it is
	 /// not consecutive anymore.
	 if(grid.at(j).at(i)=='@')
	 {
	    atCount++;
	    poundCount=0;
	 }
	 ///If a '#' token is found, reset the count for at since it is not
	 ///consecutive anymore.
	 if(grid.at(j).at(i)=='#')
	 {
	    poundCount++;
	    atCount=0;
	 }
	 ///If either count is at 4 then we have found four of a kind and a player
	 ///has won so return true.                                               
	 if(atCount==4||poundCount==4)
	 {
	    cout << "HZ TRUE" << endl;
	    return true;
      }
   }
      ///Reset both counters since we've reached the end of the column with no
      ///match found.  
      atCount=0;
      poundCount=0;
   }
   cout << "HZ FALSE" << endl;
   return false;
}



///Checks the entire grid to see if there is 4 of a kind in the right diagonal
///position, returns true if it finds 4 of a kind, false otherwise.  
bool ConnectFour::RightDiagonalCheck()
{
   cout << "RDC" << endl;
   ///atCount counts the number of '@' tokens in the diagonal line.
   ///copyrightCount counts the number of '©' tokens in the diagonal line.
   int atCount=0, poundCount=0;

   ///j will the be horizontal movement, i will be the vertical movement. 
   for(int i=ySize; i>0; i--)
   {
      for(int j=xSize; j>0; j--)
      {
	 for(int k=0; k<=i && k<=j; k++)

	    ///If an '@' token is found, reset the count for copyright since it is not
	    ///consecutive anymore.
	    if(grid.at(j-k).at(i-k)=='@')
	    {
	       atCount++;
	       poundCount=0;
	    }

	 ///If a '#' token is found, reset the count for at since it is not
	 ///consecutive anymore.
	    else if(grid.at(j-k).at(i-k)=='#')
	    {
	       poundCount++;
	       atCount=0;
	    }

	 ///If an empty space is found reset both counters since it is no longer a
	 ///consecutive line
	    else if(grid.at(j-k).at(i-k)==' ')
	    {
	       poundCount=0;
	       atCount=0;
	    }
      
	 ///If either count is at 4 then we have found four of a kind and a player
	 ///has won so return true.
	 if(atCount==4||poundCount==4)
	    return true;
	 cout << "@:" << atCount << "    #:" << poundCount << endl;
      }
   }
///If no 4 of a kind has been found, return false.
   return false;
}

///Checks the entire grid to see if there is 4 of a kind in the left diagonal
///position, returns true if it finds 4 of a kind, false otherwise.  
bool ConnectFour::LeftDiagonalCheck()
{
   cout << "LDC" << endl;
   ///atCount counts the number of '@' tokens in the diagonal line.
   ///copyrightCount counts the number of '©' tokens in the diagonal line. 
   int atCount=0, poundCount=0;

   for(int i=ySize; i>0; i--)
   {
      for(int j=xSize; j>0; j++)
      {
	 for(int k=0; k<=i && k<=j; k++)
	 {
	    ///If an '@' token is found, reset the count for copyright since it is not
	    ///consecutive anymore.
	    if((grid.at(j-k).at(i+k)=='@'))
	    {
	       atCount++;
	       poundCount=0;
	    }

	    ///If a '#' token is found, reset the count for at since it is not
	    ///consecutive anymore.  
	    else if((grid.at(j-k).at(i+k)=='#'))
	    {
	       poundCount++;
	       atCount=0;
	    }

	    ///If an empty space is found reset both counters since it is no longer a
	    ///consecutive line
	    else if(grid.at(j-k).at(i+k)==' ')
	    {
	       poundCount=0;
	       atCount=0;
	    }
	    cout << "@:" << atCount << "    #:" << poundCount << endl;
	    ///If either count is at 4 then we have found four of a kind and a player
	    ///has won so return true.  
	    if(atCount==4||poundCount==4)
	       return true;
	 }
      }
   }
   return false;
   cout << "LDC FALSE" << endl;
}

///Function which checks if a column is full
bool ConnectFour::IsColumnFull(int input)
{
   ///Changing the value to -1 since vectors are zero relative
   int column=input-1;
   int charCount=0;
   for(int i=0; i<ySize; i++)
   {
      if(grid.at(column).at(i)=='@'||grid.at(column).at(i)=='#')
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
	 if((grid.at(i).at(j)=='@')||grid.at(i).at(j)=='#')
	    charCount++;
      }
   }
   ///If the entire grid is full of characters, return true, else return false.
   if(charCount==xSize*ySize)
      return true;
   return false;   
}

void ConnectFour::ResetGame()
{
   for(int i=0; i<xSize; i++)
   {
      ///Empty the board of all pieces and fill it with empty spaces.
      grid.at(i).clear();
      grid.at(i).resize(ySize);
      for(int j=0; j<ySize; j++)
      {
	 grid.at(i).at(j)=' ';
      }
   }
   
}

   
