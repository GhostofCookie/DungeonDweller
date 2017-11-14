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
}

bool TicTacToe::VerticalCheck()
{
   cout << "Vertical Check" << endl;
   int xCount=0, oCount=0;
   for(int i=0; i<boardSize; i++)
   {
      for(int 
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

}

void TicTacToe::WinCheck()
{

}

void TicTacToe::AiMove()
{

}


void TicTacToe::RunGame(){

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
