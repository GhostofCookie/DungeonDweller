//
// ConnectFour.cpp
//
/// \author Tyler Siwy
/// \date Nov 15, 2017
///

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


void ConnectFour::RunGame()
{
   ///currentPlayer keeps track of whos turn it is, if it's odd, it is the user,
   ///if it is even, it is the AI's turn.
   int currentPlayer=1, userInput;
   ConnectFourMenu connectFourGameMenu;  
   
   BoardSetup();
   while(PuzzleEnd==false)
   {
      cout << "CurrentPlayer:" << currentPlayer <<  endl;
      cout << ConnectFourScreen << endl;
      SetCurrentPlayerChar(currentPlayer);
      if(currentPlayer%2==0)
      {
	 PlayAI(currentPlayerChar);
      }
      else
      {	 
	 connectFourGameMenu.OutputMenu();
	 connectFourGameMenu.HandleInput(cin);
	 userInput=connectFourGameMenu.GetColumn();
	 cout << "userInput:" << userInput << endl;
	 
	 if(ValidMove(userInput))
	 {
	    MovePiece(currentPlayerChar, userInput);
	  
	 }
	 else
	    cout << "Invalid Move, please try again" << endl;
      }
      if(WinCheck() || TieGameCheck(currentPlayer))
	  EndGamePrompt(currentPlayer);
       else
	  currentPlayer++;
   }
}

void ConnectFour::MovePiece(char userPiece, int column)
{
   cout << "MOVE PIECE:" << column << endl;
   int leftBound=42, bottomSlotHeight=21;;
   char currentSpot=' ';
   int height=ySize-1;

   while(currentSpot==' ')
   {
      cout << "column " <<column-1 << " is height " <<grid.at(column-1).size() << "     Height subtracted is: " << height << endl;
      if(grid.at(column-1).at(ySize-height)!=' ')
      {
	 cout << "SET AT HIEGHT:" << ySize-height << endl;
	 height++;
	 grid.at(column-1).at(ySize-height)=userPiece;
	 height--;
	 ConnectFourScreen.Set((bottomSlotHeight-(height*2)),(column*2+leftBound), userPiece);
	 currentSpot=userPiece;//Loop break
      }
      else
      {
	 height--;
      }
      cout << "!!!!!!!!!!!" << endl;
      ///If we have reached the bottom of the column and not found a piece, set
      ///the piece at the bottom of the column and break.
      if(height==0 && (grid.at(column-1).at(ySize-1))==' ')
      {
	 cout << "SET AT ZERO" << endl;
	 grid.at(column-1).at(ySize-1)=userPiece;

         ///Set the char in the screen
	 ///Height and column are multiplied by 2 since the actual vector has
	 /// 1/2 as many spots as the grid displayed on the screen does.
	 ///Add 11 to the topBound to place it in the bottom slot in the grid.
	 ConnectFourScreen.Set((bottomSlotHeight+(height*2)),(column*2+leftBound),(userPiece));
	    ///Break the loop
	 currentSpot=userPiece;
      }
   }
   cout << "GRID" << endl;
   for(int i=0; i<ySize; i++)
   {
      for(int j=0; j<xSize; j++)
	 cout << grid.at(j).at(i);
      cout << endl;
   }      
}

///Performs the AI players move
void ConnectFour::PlayAI(char AiPiece)
{
   int columnChoice=Puzzle::RandomNumber(xSize);
   bool moveSuccessful=false;

   while(moveSuccessful==false)
   {
      if(columnChoice==0)
	 columnChoice++;
      if(IsColumnFull(columnChoice))
      {
	 columnChoice=Puzzle::RandomNumber(xSize);
      }
      else
      {
	 MovePiece(AiPiece, columnChoice);
	 moveSuccessful=true;
      }
   }

}

bool ConnectFour:: ValidMove(int input)
{
   if(IsColumnFull(input) || IsInputOutOfScope(input))
      return false;
   else
      return true;
}

void ConnectFour::SetOptionsInMenu()
{

}

bool ConnectFour::TieGameCheck(int &currentPlayerChar)
{
   if(IsBoardFull())
   {
      currentPlayerChar=-1;
      return true;
   }
   else
      return false;
}


///Sets up the board with the ui for the connect four game
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
bool ConnectFour:: IsInputOutOfScope(int input)
{
   if(input<=7 && input>0)
      return false;
   else
      return true;
}

void ConnectFour::SetCurrentPlayerChar(int currentPlayer)
{
   if(currentPlayer%2==0)
   {
      currentPlayerChar='@';
   }
   else
   {
      currentPlayerChar='#';
   }
}

///If currentPlayer is even, the AI has won, -1 player health, reset
///the game for another round until the player has won.
void ConnectFour::EndGamePrompt(int &currentPlayer)
{
   cout << ConnectFourScreen;
   if(currentPlayer%2==0)
   {
      cout << "The connect four champion has defeated you! Lose 1 health"
	   << " point." << endl;
      //-1 Health
      ResetGame(currentPlayer);
      cout << "Get ready to duel her again!" << endl;
   }
   else if(currentPlayer==-1)
   {
      cout << "There has been a tie, but unfortunately for you that doesn't"
	   << " count as a win! Try harder this time!" << endl;
      //-1 Health
      ResetGame(currentPlayer);
   }
   else
   {
      cout << "Congratulations adventurer! You have defeated the champion"
	   << "! You are free to proceed into the next area!" << endl;
      PuzzleEnd=true;
   }
}


bool ConnectFour::WinCheck()
{
   cout << "Win Check" << endl;
   if(VerticalCheck() || HorizontalCheck()||LeftDiagonalCheck()||RightDiagonalCheck())
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
	 else if(grid.at(j).at(i)=='#')
	 {
	    poundCount++;
	    atCount=0;
	 }
	 else if(grid.at(j).at(i)==' ')
	 {
	    poundCount=0;
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
   return false;
}

///Checks the entire grid to see if there is 4 of a kind in the left diagonal
///positions, returns true if it finds 4 of a kind, false otherwise.  
bool ConnectFour::LeftDiagonalCheck()
{
   cout << "LD Check" << endl;
   ///atCount counts the number of '@' tokens in the diagonal line.
   ///copyrightCount counts the number of '#' tokens in the diagonal line. 
   int atCount=0, poundCount=0;

   ///i is vertical movement, j is horizontal movement
   for(int i=0; i<3; i++)
   {
      for(int j=0; j<4; j++)
      {
	 for(int k=0; k<4; k++)
	 {
	    ///If an '@' token is found, reset the count for copyright since it is not
	    ///consecutive anymore.
	    if(grid.at(j+k).at(i+k)=='@')
	    {
	       atCount++;
	       poundCount=0;
	    }
	    ///If a '#' token is found, reset the count for at since it is not
	    ///consecutive anymore.
	    if(grid.at(j+k).at(i+k)=='#')
	    {
	       poundCount++;
	       atCount=0;
	    }
      	    ///If an empty space is found reset both counters since it is no longer a
	    ///consecutive line
	    if(grid.at(j+k).at(i+k)==' ')
	    {
	       poundCount=0;
	       atCount=0;
	    }
	    ///If either count is at 4 then we have found four of a kind and a player
	    ///has won so return true.  
	    if(atCount==4||poundCount==4)
	       return true;
	 }
      }
   }
   return false;
}

///Checks the entire grid to see if there is 4 of a kind in the right diagonal
///positions, returns true if it finds 4 of a kind, false otherwise.  
bool ConnectFour::RightDiagonalCheck()
{
   cout << "RD Check" << endl;
   ///atCount counts the number of '@' tokens in the diagonal line.
   ///copyrightCount counts the number of '#' tokens in the diagonal line.
   int atCount=0, poundCount=0;

   /// i will be the vertical movement, j will the be horizontal movement
   for(int i=0; i<3; i++)
   {
      for(int j=3; j<6; j++)
      {
	 for(int k=0; k<4; k++)
	 {
	    ///If an '@' token is found, reset the count for copyright since it is not
	    ///consecutive anymore.
	    if(grid.at(j-k).at(i+k)=='@')
	    { 
	       atCount++;
	       poundCount=0;
	    }
	    
	    ///If a '#' token is found, reset the count for at since it is not
	    ///consecutive anymore.
	    else if(grid.at(j-k).at(i+k)=='#')
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
	    
	    ///If either count is at 4 then we have found four of a kind and a player
	    ///has won so return true.
	    if(atCount==4||poundCount==4)
	       return true;
	 }
      }
   }
   cout << "END OF RD" << endl;
///If no 4 of a kind has been found, return false.
      return false;
}

///Function which checks if a column is full
bool ConnectFour::IsColumnFull(int input)
{
   for(int i=0; i<ySize-1; i++)
   {
      if(grid.at(input).at(i)==' ')
	 return false;
   }
   return true;
}

///Returns true if every space in the board has been filled with a character
bool ConnectFour::IsBoardFull(){
   int fullColumnCount=0;
   for(int i=0; i<xSize; i++)
   {
      if(IsColumnFull(i))
	    fullColumnCount++;
   }
   ///If the entire grid is full of characters, return true, else return false.
   if(fullColumnCount==xSize-1)
      return true;
   return false;   
}

void ConnectFour::ResetGame(int &currentPlayer)
{
   for(int i=0; i<xSize; i++)
   {
      for(int j=0; j<ySize; j++)
      {
	 grid.at(i).at(j)=' ';
      }
   }
   ConnectFourScreen.Erase();
   BoardSetup();
   currentPlayer=1;
}

   
