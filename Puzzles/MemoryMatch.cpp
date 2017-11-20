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
      {
	 matchVector.at(i).at(j)=false;
	 charTable.at(i).at(j)=' ';
      }
   }
      
}

MemoryMatch::~MemoryMatch()
{

}

void MemoryMatch::RunGame()
{
   cout << "Start" << endl;
   SetOptionsInMenu();
   BoardSetup();
   SaveBoardToScreen();
   while(PuzzleEnd==false)
   {
      cout << MemoryMatchScreen;
      //MemoryMatchMenu.OutputMenu();
      //MemoryMatchMenu.HandleInput(cin);
      MatchCheck(0,0,1,1);//Top left
      WinCheck();
      
      PuzzleEnd=true;//to be removed
   }
	   
}

///Sets the board up for the beginning of the game, placing them in screen
void MemoryMatch::BoardSetup()
{
   cout << "Board Setup" << endl << endl;
   int randomPairIndex;
   char randomPairToInsert;
   bool reSelect=true;
   ///Setting up the match-true/false value vector for win checking/error checking
   for(unsigned int i=0; i<pairsOfCharsVector.size(); i++)
   {
      cout << "i:" << i<< endl;
      ///Try random pairs until the table has been filled in a random order
      while(reSelect==true)
      {
	 reSelect=false;
	 ///half of the area of the board since there are pairs so /2
	 randomPairIndex=RandomNumber(boardSize*boardSize/2);
	 ///Chose a random pair from the table of possible pairs
	 randomPairToInsert=pairsOfCharsVector.at(randomPairIndex);
	 
	 ///If we haven't used any pair yet. Insert right away
	 if(usedPairs.empty())
	 {
	    cout << "Empty Vector" << endl;
	    reSelect=false;
	 }///Else check if we have used it before, if yes, try another pair
	 else if(IsInUsedPairs(randomPairToInsert))
	 {
	    reSelect=true;
	 }	 
      }
      usedPairs.push_back(pairsOfCharsVector.at(randomPairIndex));
      cout << endl << "symbol:" << pairsOfCharsVector.at(randomPairIndex) << "   ";

      RandomlyInsertIntoTable(pairsOfCharsVector.at(randomPairIndex));
      //If we inserted, try another value.
      reSelect=true;
   }
//Output the contents for development purposes 
   cout << endl << "1234" << endl;
   for(int i=0; i<charTable.size(); i++)
   {
        
      for(int j=0; j<charTable.at(i).size(); j++)
      {
	 cout << charTable.at(i).at(j);
      }
      cout << endl;
   }
    cout << "1234" << endl;
}

///Checks if the symbol has been used in the random board already
bool MemoryMatch:: IsInUsedPairs(char symbol)
{
   for(int i=0; i<usedPairs.size(); i++)
   {
      if(symbol==usedPairs.at(i))
      {
	 cout << "used";
	 return true;
      }
   }
   return false;
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
	 randomXCoordinate=Puzzle::RandomNumber(boardSize);
	 randomYCoordinate=Puzzle::RandomNumber(boardSize);
	 
	 cout << "Random X:" << randomXCoordinate << "  Random Y:" << randomYCoordinate << "    Symbol:"<< charTable.at(randomXCoordinate).at(randomYCoordinate)<<endl;													    
	 if(charTable.at(randomXCoordinate).at(randomYCoordinate)==' ')
	 {
	    charTable.at(randomXCoordinate).at(randomYCoordinate)=symbol;
	    insertSuccess=true;
	    cout << "insert Success" << endl;
	 }
      }
      insertSuccess=false;
   }
}

///Puts the values in the charTable into the screen in appropriate places among
///the game board
void MemoryMatch::SaveBoardToScreen()
{
   cout << "SaveBoardToScreen" << endl;
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

///Returns true if n is odd, false if even.
bool MemoryMatch:: IsOdd(int n)
{
   if(n%2==0)
      return false;
   else
      return true;
}

///Flips two squares and outputs it for 3 seconds then flips it back.
void MemoryMatch::Peek(int inputX1, int inputY1, int inputX2, int inputY2)
{
   int topBound=12, leftBound=46;
   char symbol;
   symbol=charTable.at(inputX1).at(inputY1);
   
   if(IsOdd(inputX1) && (!IsOdd(inputY1)))//X1 odd, Y1 even
      MemoryMatchScreen.Set(inputY1+topBound, inputX1+leftBound+1, symbol);
   if((!IsOdd(inputX1)) && IsOdd(inputY1))//X1 even, Y1 odd
      MemoryMatchScreen.Set(inputY1+topBound+1, inputX1+leftBound, symbol);
   if(IsOdd(inputX1) && IsOdd(inputY1))//both are odd
      MemoryMatchScreen.Set(inputY1+topBound+1, inputX1+leftBound+1, symbol);
   if((!IsOdd(inputX1)) && (!IsOdd(inputY1)))///both are even
      MemoryMatchScreen.Set(inputX1+topBound, inputY1+leftBound, symbol);
   
   symbol=charTable.at(inputX2).at(inputY2);
   
   if(IsOdd(inputX2) && (!IsOdd(inputY2)))//X1 odd, Y1 even
      MemoryMatchScreen.Set(inputY2+topBound, inputX2+leftBound+1, symbol);
   if((!IsOdd(inputX2)) && IsOdd(inputY2))//X1 even, Y1 odd
      MemoryMatchScreen.Set(inputY2+topBound+1, inputX2+leftBound, symbol);
   if(IsOdd(inputX2) && IsOdd(inputY2))//both are odd
      MemoryMatchScreen.Set(inputY2+topBound+1, inputX2+leftBound+1, symbol);
   if((!IsOdd(inputX2)) && (!IsOdd(inputY2)))///both are even
      MemoryMatchScreen.Set(inputX2+topBound, inputY2+leftBound, symbol);
   
   cout << MemoryMatchScreen << endl; 
   
   ThreeSecondDelay();
   
   if(IsOdd(inputX1) && (!IsOdd(inputY1)))//X1 odd, Y1 even
      MemoryMatchScreen.Set(inputY1+topBound, inputX1+leftBound+1, ' ');
   if((!IsOdd(inputX1)) && IsOdd(inputY1))//X1 even, Y1 odd
      MemoryMatchScreen.Set(inputY1+topBound+1, inputX1+leftBound, ' ');
   if(IsOdd(inputX1) && IsOdd(inputY1))//both are odd
      MemoryMatchScreen.Set(inputY1+topBound+1, inputX1+leftBound+1, ' ');
   if((!IsOdd(inputX1)) && (!IsOdd(inputY1)))///both are even
      MemoryMatchScreen.Set(inputX1+topBound, inputY1+leftBound, ' ');
   
   if(IsOdd(inputX2) && (!IsOdd(inputY2)))//X1 odd, Y1 even
      MemoryMatchScreen.Set(inputY2+topBound, inputX2+leftBound+1, ' ');
   if((!IsOdd(inputX2)) && IsOdd(inputY2))//X1 even, Y1 odd
      MemoryMatchScreen.Set(inputY2+topBound+1, inputX2+leftBound, ' ');
   if(IsOdd(inputX2) && IsOdd(inputY2))//both are odd
      MemoryMatchScreen.Set(inputY2+topBound+1, inputX2+leftBound+1, ' ');
   if((!IsOdd(inputX2)) && (!IsOdd(inputY2)))///both are even
      MemoryMatchScreen.Set(inputX2+topBound, inputY2+leftBound, ' ');
   
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
