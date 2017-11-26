//
// TicTacToe.cpp
//
/// \author Tyler Siwy
/// \date Oct 20, 2017
//  
#include "TicTacToe.h"

TicTacToe::TicTacToe()
{
   PuzzleEnd=false;
   ///Setting up the game vector
   boardSize=3;
   gameBoard.resize(boardSize);

   for(int i=0; i<boardSize; i++)
   {
      for(int j=0; j<boardSize; j++)
      {
	 gameBoard.at(i).resize(boardSize);
	 gameBoard.at(i).at(j)=' ';
      }
   }
}

TicTacToe::~TicTacToe()
{

}

void TicTacToe::RunGame(Character *player){
///currentPlayer keeps track of whos turn it is, if it's odd, it is the user,
   ///if it is even, it is the AI's turn.
   int currentPlayer=1, inputX, inputY;
   BoardSetup();
   TicTacToeMenu ticTacToeGameMenu;
   while(PuzzleEnd==false)
   {
      system("clear");
      cout << TicTacToeScreen << endl;
      SetCurrentPlayersChar(currentPlayer);
      if(currentPlayer%2==0)
      {
	 AiMove(currentPlayerChar);
	 if(WinCheck() || TieGameCheck(currentPlayer))
	    EndGamePrompt(currentPlayer);
	 else
	    currentPlayer++;
      }
      else
      {
	 ticTacToeGameMenu.OutputMenu();
	 ticTacToeGameMenu.HandleInput(cin);
	 
	 ///X is taken as a,b, or c, Y is taken in as an integer.
	
	 inputY=ticTacToeGameMenu.GetCoordinates().y-1;
	 inputX=ConvertCharCoordinateToIndex(ticTacToeGameMenu.GetCoordinates().x);
	 cout << "InputX:" << inputX << "     inputY:" << inputY << "     currentPlayerChar:" << currentPlayerChar << endl;

	 if(IsInputValid(inputX, inputY) && !IsSpotFilled(inputX,inputY))
	 {	    
	    MovePiece(inputX, inputY, currentPlayerChar);
	    if(WinCheck() || TieGameCheck(currentPlayer))
	       EndGamePrompt(currentPlayer);
	    else
	       currentPlayer++;
	 }
	 else
	    cout << "Sorry that spot is already taken!" << endl;
      }
   }
}

///Sets up the board with the ui for the  TicTacToe game
void TicTacToe::BoardSetup()
{
   cout << "Board Setup" << endl;
   int gameBoardSize=7, leftBound=48, topBound=14;
   for(int i=0;i<gameBoardSize;i++)
   {
      for(int j=0; j<gameBoardSize; j++)
      {
	 ///If i is odd, fill the row with '-'
	 if(i%2==0)
	 {
	    ///topBound and leftBound should set the board centered inside
	    ///the screen object.  
	    TicTacToeScreen.Set(topBound+i, leftBound+j, '-');
	 }
	 else
	 {
	    if(j%2!=0)
	    {
	       ///topBound and leftBound should set the board centered inside
	       ///the screen object.  
	       TicTacToeScreen.Set(topBound+i, leftBound+j, ' ');
	    }
	    else
	    {
	       ///topBound and leftBound should set the board centered inside
	       ///the screen object.  
	       TicTacToeScreen.Set(topBound+i, leftBound+j, '|');
	    }
	 }
      }
   }
}

///Checks the entire grid to see if there is 3 of a kind in the horizontal
///position, returns true if it finds 3 of a kind, false otherwise.
bool TicTacToe::HorizontalCheck()
{
   cout << "Horizontal Check" << endl;
   int xCount=0, oCount=0;
   for(int j=0; j<boardSize; j++)
   {
      for(int i=0; i<boardSize; i++)
      {
	 if(gameBoard.at(i).at(j)=='X')
	 {
	    xCount++;
	    oCount=0;
	 }
	 else if(gameBoard.at(i).at(j)=='O')
	 {
	    oCount++;
	    xCount=0;
	 }
	 else
	 {
	    oCount=0;
	    xCount=0;
	 }
	 if(xCount==3 || oCount==3)
	    return true;
      }
      oCount=0;
      xCount=0;
   }
   return false;
}

///Checks the entire grid to see if there is 3 of a kind in the vertical
///position, returns true if it finds 3 of a kind, false otherwise.  
bool TicTacToe::VerticalCheck()
{
   cout << "Vertical Check" << endl;
   
   int xCount=0, oCount=0;
   
   for(int i=0; i<boardSize; i++)
   {
      for(int j=0; j<boardSize; j++)
      {
	 if(gameBoard.at(i).at(j)=='X')
	 {
	    xCount++;
	    oCount=0;
	 }
	 else if(gameBoard.at(i).at(j)=='O')
	 {
	    oCount++;
	    xCount=0;
	 }
	 else
	 {
	    cout << "else" << endl;
	    oCount=0;
	    xCount=0;
	 }
	 if(xCount==3 || oCount==3)
	 {
	    cout << "VertWin" << endl;
	    return true;
	 }
      }
      xCount=0;
      oCount=0;
   }
   return false;
}

///Checks the entire grid to see if there is 3 of a kind in the right diagonal
///position, returns true if it finds 3 of a kind, false otherwise.  
bool TicTacToe::RightDiagonalCheck()
{
   cout << "RightDiag" << endl;
   int xCount=0, oCount=0, origin=0;
   
   for(int i=0; i<3; i++)
   {
      if(gameBoard.at(origin+i).at(origin+i)=='X')
      {
	 xCount++;
	 oCount=0;
      }
      else if(gameBoard.at(origin+i).at(origin+i)=='O')
      {
	 oCount++;
	 xCount=0;
      }
      else
      {
	 cout << "else" << endl;
	 oCount=0;
	 xCount=0;
      }
      if(xCount==3 || oCount==3)
	 return true;
   }
   return false;
}

///Checks the entire grid to see if there is 3 of a kind in the left diagonal
///position, returns true if it finds 3 of a kind, false otherwise.  
bool TicTacToe::LeftDiagonalCheck()
{
   cout << "LeftDiag" << endl;
   int xCount=0, oCount=0, xOrigin=0, yOrigin=2;
   for(int i=0; i<3; i++)
   {
      if(gameBoard.at(xOrigin+i).at(yOrigin-i)=='X')
      {
	 xCount++;
	 oCount=0;
      }
      else if(gameBoard.at(xOrigin+i).at(yOrigin-i)=='O')
      {
	 oCount++;
	 xCount=0;
      }
      else
      {
	 oCount=0;
	 xCount=0;
      }
      if(xCount==3 || oCount==3)
	 return true;
   }
   return false;
}

void TicTacToe::SetOptionsInMenu()
{

}

bool TicTacToe::IsInputValid(char inputX, int inputY)
{
   if(IsIntInputValid(inputX)&&IsIntInputValid(inputY))
      return true;
   else
      return false;
}

bool TicTacToe::IsIntInputValid(int input)
{
   if(input>=0 && input<3)
      return true;
   else
      return false;
}

bool TicTacToe::IsSpotFilled(int inputX, int inputY)
{
   if(gameBoard.at(inputX).at(inputY)==' ')
      return false;
   else
      return true;
}

void TicTacToe::SetCurrentPlayersChar(int currentPlayer)
{
   if(currentPlayer%2!=0)
   {
      cout << "Set X" << endl;
      currentPlayerChar='X';
   }
   else
   {
      cout << "Set Y" << endl;
      currentPlayerChar='O';
   }
}

void TicTacToe::MovePiece(int inputX, int inputY, char userPiece)
{
   int leftColumn=49, topRow=15;
   gameBoard.at(inputX).at(inputY)=userPiece;
   TicTacToeScreen.Set(inputY*2+topRow, inputX*2+leftColumn, userPiece);
}

bool TicTacToe::WinCheck()
{
   cout << "Win Check" << endl;
   if(VerticalCheck()|| HorizontalCheck()||LeftDiagonalCheck()||RightDiagonalCheck())
      return true;
   else
      return false;
}

int TicTacToe::ConvertCharCoordinateToIndex(char input)
{
   switch(input)
   {
      case 'a': case 'A':
	 return 0;
	 break;
      case 'b': case 'B':
	 return 1;
	 break;
      case 'c': case 'C':
	 return 2;
	 break;
      default:
	 return -1;
   }
}

void TicTacToe::AiMove(char AiPiece)
{
   cout << "AI MOVE" << endl;
   int HorizontalMoveCoord, VerticalMoveCoord;
   HorizontalMoveCoord=Puzzle::RandomNumber(3);
   VerticalMoveCoord=Puzzle::RandomNumber(3);

   bool moveSuccessful=false;
   while(moveSuccessful==false)
   {
      if(gameBoard.at(HorizontalMoveCoord).at(VerticalMoveCoord)==' ')
      {
	 MovePiece(HorizontalMoveCoord, VerticalMoveCoord, AiPiece);
	 //gameBoard.at(HorizontalMoveCoord).at(VerticalMoveCoord)=AiPiece;
	 moveSuccessful=true;
      }
      else
      {
	 HorizontalMoveCoord=Puzzle::RandomNumber(3);
	 VerticalMoveCoord=Puzzle::RandomNumber(3);
      }
   }
}

void TicTacToe::EndGamePrompt(int &currentPlayer)
{
   ///If currentPlayer is even, the AI has won, -1 player health, reset
   ///the game for another round until the player has won.
   if(currentPlayer%2==0)
   {
      cout << TicTacToeScreen;
      cout << "The Tic Tac Toe champion has defeated you! Lose 1 health"
	   << " point." << endl;
      //-1 Health
      ResetGame(currentPlayer);
      cout << "Get ready to duel her again!" << endl;
   }
   else if(currentPlayer%2==-1)
   {
      cout << TicTacToeScreen << endl;
      cout << "Unfortunately there has been a tie, this counts as a loss in my"
	   << "books, so get ready to play again!" << endl;
      ResetGame(currentPlayer);
   }
   else
   {
      cout << TicTacToeScreen << endl;
      cout << "Congratulations adventurer! You have defeated the champion"
	   << "! You are free to proceed into the next area!" << endl;
      PuzzleEnd=true;
   }
}

bool TicTacToe::TieGameCheck(int &currentPlayer)
{
   for(int i=0; i<boardSize; i++)
   {
      for(int j=0; j<boardSize; j++)
      {
	 if(gameBoard.at(i).at(j)==' ');
	 {
	    cout << "TieCheck False" << endl;
	    return false;
	 }
      }
   }
   cout << "TieCheck true" << endl;
   currentPlayer=-1;
   return true;
}
   

void TicTacToe::ResetGame(int &currentPlayer)
{
   cout << "RESET GAME" << endl;
   for(int i=0; i<boardSize; i++)
   {
      for(int j=0; j<boardSize; j++)
      {
	 gameBoard.at(i).at(j)=' ';
      }
   }
   TicTacToeScreen.Erase();
   BoardSetup();
   currentPlayer=1;
}

