////////////////////////////////////////////////////////////////////////////////
///memory_match.cpp
///\author Tyler Siwy
///CPSC 2720-Howard Cheng-Dungeon Dweller
////////////////////////////////////////////////////////////////////////////////
#include "MemoryMatch.h"

MemoryMatch::MemoryMatch()
{
   boardSize=4;
   pairsOfCharsVector.resize(boardSize*boardSize/2);
   pairsOfCharsVector.at(0)='@';
   pairsOfCharsVector.at(1)='#';
   pairsOfCharsVector.at(2)='$';
   pairsOfCharsVector.at(3)='K';
   pairsOfCharsVector.at(4)='T';
   pairsOfCharsVector.at(5)='&';
   pairsOfCharsVector.at(6)='R';
   pairsOfCharsVector.at(7)='G';
   
   matchVector.resize(boardSize);
   charTable.resize(boardSize);
   for(int i=0; i<boardSize; i++)
   {
      charTable.at(i).resize(boardSize);
      matchVector.at(i).resize(boardSize);

      for(int j=0; j<boardSize; j++)
	 matchVector.at(i).at(j)=false;
   }
      
}

MemoryMatch::~MemoryMatch()
{

}

void MemoryMatch::RunGame()
{
   cout << "WELCOME TO MEMORY MATCH" << endl;
}

///Sets the board up for the beginning of the game, placing them in screen
void MemoryMatch::BoardSetup()
{
   ///Holds a memory of all pairs previously used
   std::vector<char>usedPairs(8);

   int randomPairIndex;
   char randomPairToInsert;
   bool reSelect=true;
   ///Setting up the match-true/false value vector for win checking/error checking
   for(unsigned int i=0; i<pairsOfCharsVector.size(); i++)
   {
      ///Try random pairs until the table has been filled in a random order
      while(reSelect==true)
      {
	 reSelect=false;
	 randomPairIndex=RandomNumber(boardSize*boardSize/2);
	 randomPairToInsert=pairsOfCharsVector.at(randomPairIndex);
      
	 for(unsigned int i=0; i<pairsOfCharsVector.size(); i++)
	 {
	    ///If we find any pair previously matched, try another random pair
	    if(randomPairToInsert==usedPairs.at(i))
	       reSelect=true;
	 }
      }
	 usedPairs.back()= pairsOfCharsVector.at(randomPairIndex);
	 RandomlyInsertIntoTable(pairsOfCharsVector.at(randomPairIndex));
   }
   
}

///Puts the values in the charTable into the screen in appropriate places among
///the game board
void MemoryMatch::SaveBoardToScreen()
{
   int screenBoardSize=9, topBound=11, leftBound=45;
   for(int i=0; i<screenBoardSize; i++)
   {
      for(int j=0; j<screenBoardSize; j++)
      {
	 ///If i is odd, fill the entire row with '-'
	 if(i%2==0)
	 {
	    ///topBound and leftBound should set the board centered inside
	    ///the screen object.
	    MemoryMatchScreen.Set((topBound+i), (leftBound+j),'-');
	 }
	 ///If i is even, fill the row with squares to place tokens in later
	 else
	 {
	    if(j%2!=0)
	    {
	       ///topBound and leftBound should set the board centered inside
	       ///the screen object.  
	       MemoryMatchScreen.Set((topBound+i),(leftBound+j),' ');
	    }
	    else
	    {
	       ///topBound and leftBound should set the board centered inside
	       ///the screen object.  
	       MemoryMatchScreen.Set((topBound+i),(leftBound+j),'|');
	    }
	 }
      }
   }
}

///randomly puts pairs into the table
void MemoryMatch::RandomlyInsertIntoTable(char symbol)
{
   int randomXCoordinate;
   int randomYCoordinate;
   bool insertSuccess=false;
   ///Happens twice since it's a pair
   for(int i=0; i<2; i++)
   {
      ///Keep repeating until an acceptable location is found, randomly.
      while(insertSuccess==false)
      {
	 randomXCoordinate=RandomNumber(boardSize-1);
	 randomYCoordinate=RandomNumber(boardSize-1);
	 if(charTable.at(randomXCoordinate).at(randomYCoordinate)==' ')
	 {
	    charTable.at(randomXCoordinate).at(randomYCoordinate)=symbol;
	    insertSuccess=true;
	 }
      }
   }
}

///Sends the menu class the options for the player to select.
void MemoryMatch::SetOptionsInMenu()
{
}

///Checks if the coordinates have been matched already, returns true if they are
///unmatched, false if they have previously been matched
bool MemoryMatch::ValidMove(int X1, int Y1, int X2, int Y2)
{
   if(matchVector.at(X1).at(Y1)==true || matchVector.at(X1).at(Y1)==true)
      return false;
   else
      return true;
}

///Causes a three second delay in the program process
void MemoryMatch::ThreeSecondDelay()
{
      usleep(3000000);
}

///Generates a random number between 0 and n-1
int MemoryMatch::RandomNumber(int n)
{
   ///Returns 0 to n-1
   n=rand()%n;
   return n;
}

///Flips two squares and outputs it for 3 seconds then flips it back.
void MemoryMatch::Peek(int inputX1, int inputY1, int inputX2, int inputY2)
{
  int topBound=12, leftBound=46;
   char symbol;
   symbol=charTable.at(inputX1).at(inputY1);
   MemoryMatchScreen.Set(inputX1, inputY1, symbol);
   
   symbol=charTable.at(inputX2).at(inputY2);
   MemoryMatchScreen.Set(inputX2, inputY2, symbol);
   cout << MemoryMatchScreen << endl; 
   ThreeSecondDelay();
   MemoryMatchScreen.Set(topBound+inputY1, leftBound+inputX1, ' ');
   MemoryMatchScreen.Set(topBound+inputY2, leftBound+inputX2, ' ');
   cout << MemoryMatchScreen << endl;
}

///Flips two cards and shows them to the user for a certain time, if they are
/// a match, it leaves them face-up, otherwise flip them back down.
///\param[in] inputX1, The X-Coordinate of the first card to flip
///\param[in] inputY1, The Y-Coordinate of the first card to flip
///\param[in] inputX2, The X-Coordinate of the second card to flip
///\param[in] inputY2, The Y-Coordinate of the second card to flip
void MemoryMatch::MovePiece(int inputX1, int inputY1, int inputX2, int inputY2)
{
    
}

///Checks if the two cards selected are a match, returns true if yes.
///\param[in] inputX1, The X-Coordinate of the first card to flip
///\param[in] inputY1, The Y-Coordinate of the first card to flip
///\param[in] inputX2, The X-Coordinate of the second card to flip
///\param[in] inputY2, The Y-Coordinate of the second card to flip 
bool MemoryMatch::MatchCheck(int inputX1, int inputY1, int inputX2, int inputY2)
{
   Peek(inputX1,inputY1,inputX2,inputY2);
   
   if(matchVector.at(inputX1).at(inputY1)==matchVector.at(inputX2).at(inputY2))
      return true;
   else
      return false;
}

///Checks the state of the int table to see if the player has won the game,
///returns true when they have completed the puzzle.
void MemoryMatch::WinCheck()
{
   for(int i=0; i<boardSize; i++)
   {
      for(int j=0; j<boardSize; j++)
      {
	 if(matchVector.at(i).at(j)==false)
	    PuzzleEnd=false;
	 else
	    PuzzleEnd=true;
      }
   }
}
