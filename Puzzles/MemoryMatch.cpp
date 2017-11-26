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
	 matchVector.at(i).at(j)=0;
	 charTable.at(i).at(j)=' ';
      }
   }   
}

MemoryMatch::~MemoryMatch()
{

}

void MemoryMatch::RunGame(Character *player)
{
   MemoryMenu MemoryMatchMenu;
   cout << "Start" << endl;
   int inputX1, inputY1, inputX2, inputY2;
   SetOptionsInMenu();
   BoardSetup();
   SaveBoardToScreen();
   PeekAtBoard(6);
   while(PuzzleEnd==false)
   {
      system("clear");
      cout << MemoryMatchScreen;
      MemoryMatchMenu.OutputMenu();
      MemoryMatchMenu.HandleInput(cin);
      ///Get input 1-4
      SetInputs(inputX1, inputY1, inputX2, inputY2, MemoryMatchMenu);
      cout << "inputX1:" << inputX1 << "     inputY1:" << inputY1 << "     inputX2:" << inputX2 << "     inputY2:" << inputY2 << endl;
      if(CheckInput(inputX1, inputY1, inputX2, inputY2))
      {
	 MovePiece(inputX1,inputY1,inputX2,inputY2);//Top left
	 WinCheck();
      }
      else
	 cout << "Invalid input, please try again!" << endl;
   }   
}

void MemoryMatch:: EndGamePrompt()
{
   cout << "Congratulations adventurer! You've solved the puzzle!" << endl;
   cout << MemoryMatchScreen;
   SecondDelay(6);
}


int MemoryMatch:: ConvertCharToIndex(char input)
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
      case 'd': case 'D':
	 return 3;
	 break;
      default:
	 return -1;
	 break;
   }
}
   
void MemoryMatch:: SetInputs(int &X1, int &Y1,int &X2,int &Y2,
			     MemoryMenu &menu)
{
   X1=ConvertCharToIndex(menu.GetCoordinates().x1);
   Y1=menu.GetCoordinates().y1-1;
   X2=ConvertCharToIndex(menu.GetCoordinates().x2);
   Y2=menu.GetCoordinates().y2-1;
}

bool MemoryMatch:: IsInputValid(int input)
{
   if(input>3 || input<0)
      return false;
   else
      return true;
}

bool MemoryMatch:: CheckInput(int x1, int y1, int x2, int y2)
{
   //cout << "CHECK INPUTS: " << "x1:" << x1 << " y1:" << y1 << " x2:" << x2 << " y2:" << y2 << endl;
   if(IsInputValid(x1) && IsInputValid(y1) && IsInputValid(x2) && IsInputValid(y2))
      return true;
   else
      return false;
}

///Sets the board up for the beginning of the game, placing them in screen
void MemoryMatch::BoardSetup()
{
   cout << "Board Setup" << endl;
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
	 ///half of the area of the board since there are pairs so /2
	 randomPairIndex=RandomNumber(boardSize*boardSize/2);
	 ///Chose a random pair from the table of possible pairs
	 randomPairToInsert=pairsOfCharsVector.at(randomPairIndex);
	 
	 ///If we haven't used any pair yet. Insert right away
	 if(usedPairs.empty())
	    reSelect=false;
         ///Else check if we have used it before, if yes, try another pair
	 else if(IsInUsedPairs(randomPairToInsert))
	    reSelect=true;	 
      }
      usedPairs.push_back(pairsOfCharsVector.at(randomPairIndex));
      RandomlyInsertIntoTable(pairsOfCharsVector.at(randomPairIndex));
      //If we inserted, try another value.
      reSelect=true;
   }
}

///Checks if the symbol has been used in the random board already
bool MemoryMatch:: IsInUsedPairs(char symbol)
{
   for(int i=0; i<usedPairs.size(); i++)
   {
      if(symbol==usedPairs.at(i))
	 return true;
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
	 if(charTable.at(randomXCoordinate).at(randomYCoordinate)==' ')
	 {
	    charTable.at(randomXCoordinate).at(randomYCoordinate)=symbol;
	    insertSuccess=true;
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
   ///topBound and leftBound should set the board centered inside
   ///the screen object.
   int screenBoardSize=9, topBound=11, leftBound=45;
   for(int i=0; i<screenBoardSize; i++)
   {
      for(int j=0; j<screenBoardSize; j++)
      {	 
	 ///If i is odd, fill the entire row with '-'
	 if(i%2==0)
	    MemoryMatchScreen.Set((topBound+i), (leftBound+j),'-');

         ///If i is even, fill the row with squares to place tokens in later
	 else
	 {
	    if(j%2!=0)
	       MemoryMatchScreen.Set((topBound+i),(leftBound+j),' ');
	    else
	       MemoryMatchScreen.Set((topBound+i),(leftBound+j),'|');
	 }
      }
   }
}

///Sends the menu class the options for the player to select.
void MemoryMatch::SetOptionsInMenu()
{
   //MemoryMenu.AddOption('1', menuOption1, MovePiece);
   
}

///Checks if the coordinates have been matched already, returns true if they are
///unmatched, false if they have previously been matched
bool MemoryMatch::ValidMove(int X1, int Y1, int X2, int Y2)
{
   if(matchVector.at(X1).at(Y1)==1 || matchVector.at(X2).at(Y2)==1)
      return false;
   else
      return true;
}

///Causes a three second delay in the program process
void MemoryMatch::SecondDelay(int seconds)
{
      usleep(1000000*seconds);
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

///Returns true if char has a true value in the matchVector, false otherwise
bool MemoryMatch:: IsCharAlreadyMatched(int inputX, int inputY)
{
   if(matchVector.at(inputX).at(inputY)==1)
      return true;
   else
      return false;
}


///Flips the char stored at the inputted coordinates on chartable and sets them
///on the screen.
void MemoryMatch::FlipTwoChars(int inputX, int inputY)
{
   ///top left coordinate of the game board on the screen
   int topBound=11, leftBound=45;
   ///Symbol to be displayed
   char symbol;
   
   ///Display the first symbol
   symbol=charTable.at(inputX).at(inputY);
   MemoryMatchScreen.Set(((inputY*2)+1+topBound), ((inputX*2)+1+leftBound), symbol);
}
///Flips two squares and outputs it for 3 seconds then flips it back.
void MemoryMatch::PeekAtBoard(int lengthInSeconds)
{
   ///top left coordinate of the game board on the screen
   int topBound=11, leftBound=45;
   for(int i=0; i<boardSize; i++)
   {
      for(int j=0; j<boardSize; j++)
      {
	 FlipTwoChars(i, j);
      }
   }
   ///Output the game for three seconds
   cout << MemoryMatchScreen << endl; 
   SecondDelay(lengthInSeconds);
   system("clear");
   
   for(int i=0; i<boardSize; i++)
   {
      for(int j=0; j<boardSize; j++)
      {
	 MemoryMatchScreen.Set(((j*2)+1+topBound), ((i*2)+1+leftBound), ' ');
      }
   }
}

///Flips two squares and outputs it for 3 seconds then flips it back.
void MemoryMatch::Peek(int inputX1, int inputY1, int inputX2, int inputY2)
{
   ///top left coordinate of the game board on the screen
   int topBound=11, leftBound=45;

   ///Flip the two selected chars, first check if they have been previously
   ///matched, if so, do nothing to them. Otherwise, flip.
   if(!(IsCharAlreadyMatched(inputX1, inputY1)))
      FlipTwoChars(inputX1, inputY1);
   if(!(IsCharAlreadyMatched(inputX2, inputY2)))
      FlipTwoChars(inputX2, inputY2);

   ///Output the game for three seconds
   cout << MemoryMatchScreen << endl; 
   SecondDelay(3);

   ///clear the first and second symbol off of the screen after 3 seconds, only
   ///if they have not previously been matched
   if(!(IsCharAlreadyMatched(inputX1, inputY1)))
      MemoryMatchScreen.Set(((inputY1*2)+1+topBound), ((inputX1*2)+1+leftBound), ' ');
   if(!(IsCharAlreadyMatched(inputX2, inputY2)))
      MemoryMatchScreen.Set(((inputY2*2)+1+topBound), ((inputX2*2)+1+leftBound), ' ');

   ///Output the game again now that it has been cleared of the users guess.
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
   if(MatchCheck(inputX1, inputY1, inputX2, inputY2))
   {
      cout << "Match!" << endl;
      //Flip the two spots on the board
      FlipTwoChars(inputX1, inputY1);
      FlipTwoChars(inputX2, inputY2);

      //Set the two values to true to show that they have been matched.
      matchVector.at(inputX1).at(inputY1)=1;
      matchVector.at(inputX2).at(inputY2)=1;
   }
   else
   {
      cout << "Not a match!" << endl;
      ///Show the user the spots they tried for a brief period of time
      Peek(inputX1,inputY1,inputX2,inputY2);
   }     
}

///Checks if the two cards selected are a match, returns true if yes.
///\param[in] inputX1, The X-Coordinate of the first card to flip
///\param[in] inputY1, The Y-Coordinate of the first card to flip
///\param[in] inputX2, The X-Coordinate of the second card to flip
///\param[in] inputY2, The Y-Coordinate of the second card to flip 
bool MemoryMatch::MatchCheck(int inputX1, int inputY1, int inputX2, int inputY2)
{
   ///If the two chars are the same.
   cout << "input1:" << charTable.at(inputX1).at(inputY1) << "  input2:" << charTable.at(inputX2).at(inputY2) << endl;
   if(charTable.at(inputX1).at(inputY1)==charTable.at(inputX2).at(inputY2))
      return true;
   else
      return false;
}

///Checks the state of the int table to see if the player has won the game,
///returns true when they have completed the puzzle.
void MemoryMatch::WinCheck()
{
   int trueCount=0;
   for(int i=0; i<boardSize; i++)
   {
      for(int j=0; j<boardSize; j++)
      {
	 if(matchVector.at(i).at(j)==1)
	    trueCount++;
      }
   }
   if(trueCount==boardSize*boardSize)
   {
      PuzzleEnd=true;
      EndGamePrompt();
   }
}
