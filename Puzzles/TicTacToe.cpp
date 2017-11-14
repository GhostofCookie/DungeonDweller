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

void TicTacToe::BoardSetup()
{
   cout << "Board Setup" << endl;
   int gameBoardSize=15, leftBound=48, topBound=14;
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

  
bool TicTacToe::HorizontalCheck()
{
   cout << "Horizontal Check" << endl;
   return true;
}

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
	 if(xCount==4 || oCount==3)
	    return true;
      }
   }
   return false;
}
 
bool TicTacToe::RightDiagonalCheck()
{
}
 
bool TicTacToe::LeftDiagonalCheck()
{
}

void TicTacToe::SetOptionsInMenu()
{

}


void TicTacToe::MovePiece(int inputX, int inputY, char userPiece)
{
   int leftColumn=48, topRow=14;
   TicTacToeScreen.Set(inputY+topRow, inputX+leftColumn, userPiece);
}

bool ConnectFour::WinCheck()
{
   cout << "Win Check" << endl;
   if(VerticalCheck())//|| HorizontalCheck()||LeftDiagonalCheck())//||RightDiagonalCheck())
      return true;
   else
      return false;
}


void TicTacToe::AiMove()
{

}


void TicTacToe::RunGame(){
///currentPlayer keeps track of whos turn it is, if it's odd, it is the user,
   ///if it is even, it is the AI's turn.
   int currentPlayer=1;
   
   BoardSetup();
   //ConnectFourMenu connectFourGameMenu;
   //connectFourGameMenu.OutputMenu();

   cout << "Drop in column 1" << endl;
   MovePiece(1,1,'X');
   while(PuzzleEnd==false)
   {
      cout << TicTacToeScreen << endl;
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
	    //ResetGame();
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

// void TicTacToe::PromptUser(&screen)
// {

// }

//char TicTacToe::UserInput(Menu &menu)
//{
//  return 'c';
//}

//bool TicTacToe::ValidMove(char input)
//{
//   return true;
//}


//bool TicTacToe::ValidCommand(char input)
//{
//   return true;
//}

// void TicTacToe::OutputGame(&screen)
// {

// }
