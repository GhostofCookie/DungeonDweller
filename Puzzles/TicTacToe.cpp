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
