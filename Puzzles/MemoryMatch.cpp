//
///MemoryMatch.cpp
///\author Tyler Siwy
///CPSC 2720-Howard Cheng-Dungeon Dweller
//
#include "MemoryMatch.h"

///Default constructor for MemoryMatch, sets height to: 4 and width to: 4  
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
   for(int i = 0; i < boardSize; i++)
   {
      charTable.at(i).resize(boardSize);
      matchVector.at(i).resize(boardSize);

      for(int j=0; j < boardSize; j++)
      {
	 matchVector.at(i).at(j) = 0;
	 charTable.at(i).at(j) = ' ';
      }
   }   
}

//Deconstructor
MemoryMatch::~MemoryMatch()
{
}

///Method to run the game, serves as a 'main' for the mini-game, calling
///functions from private until the player has won.
///\param[in] player, pointer to the player, used to decrement health. 
void MemoryMatch::RunGame(Character *player)
{
   MemoryMenu MemoryMatchMenu;
   int inputX1, inputY1, inputX2, inputY2;
   BoardSetup();
   SaveBoardToScreen();
   system("clear");
   PeekAtBoard(6);
   while(PuzzleEnd ==false)
   {
      system("clear");
      cout << MemoryMatchScreen;
      MemoryMatchMenu.OutputMenu();
      MemoryMatchMenu.HandleInput(cin);
      ///Get input 1-4
      SetInputs(inputX1, inputY1, inputX2, inputY2, MemoryMatchMenu);
       if(CheckInput(inputX1, inputY1, inputX2, inputY2))
      {
	 MovePiece(inputX1, inputY1, inputX2, inputY2);
	 WinCheck();
      }
      else
	 cout << "Invalid input, please try again!" << endl;
   }   
}

///Outputs a conclusion message to the user and then shows the puzzle results
///for 6 seconds before ending the game.  
void MemoryMatch:: EndGamePrompt()
{
   cout << "Congratulations adventurer! You've solved the puzzle!" << endl;
   cout << MemoryMatchScreen;
   Puzzle::SecondDelay(6);
}

///Takes the char input given by the user and returns the associated index
///for its location within the vector as an int.
///\param[in]input, the character to convert to an integer index.  
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

///Setinputs assigns user input to the appropriate variables.
///\param[in]X1, the first x-coordinate to flip to the user.
///\param[in]Y1, the first y-coordinate to flip to the user.
///\param[in]X2, the second x-coordinate to flip to the user
///\param[in]Y2, the second y-coordinate to flip to the user.
///\param[in]menu, the menu object used for getting the input from the user.  
void MemoryMatch:: SetInputs(int &X1, int &Y1,int &X2,int &Y2,
			     MemoryMenu &menu)
{
   X1=ConvertCharToIndex(menu.GetCoordinates().x1);
   Y1=menu.GetCoordinates().y1 - 1;
   X2=ConvertCharToIndex(menu.GetCoordinates().x2);
   Y2=menu.GetCoordinates().y2 - 1;
}

///IsInputValid checks to see if the input in within the bounds of the
///gameboard. Returns true if its valid.
///\param[in]input, is checked to see if it is within the bounds of the game.  
bool MemoryMatch:: IsInputValid(int input)
{
   if(input > 3 || input < 0)
      return false;
   else
      return true;
}

///Checks to make sure all coordinates are within the bounds of the game
///board using IsInputValid helper function.
///\param[in]X1, the first x-coordinate to check.
///\param[in]Y1, the first y-coordinate to check.
///\param[in]X2, the second x-coordinate to check.
///\param[in]Y2, the second y-coordinate to check.   
bool MemoryMatch:: CheckInput(int x1, int y1, int x2, int y2)
{
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
   bool reSelect = true;
   
   ///Setting up the match-true/false value vector for win checking/error checking
   for(unsigned int i = 0; i < pairsOfCharsVector.size(); i++)
   {
      ///Try random pairs until the table has been filled in a random order
      while(reSelect == true)
      {
	 reSelect = false;
	 ///half of the area of the board since there are pairs so /2
	 randomPairIndex = RandomNumber(boardSize * boardSize / 2);
	 ///Chose a random pair from the table of possible pairs
	 randomPairToInsert = pairsOfCharsVector.at(randomPairIndex);
	 
	 ///If we haven't used any pair yet. Insert right away
	 if(usedPairs.empty())
	    reSelect = false;
         ///Else check if we have used it before, if yes, try another pair
	 else if(IsInUsedPairs(randomPairToInsert))
	    reSelect = true;	 
      }
      usedPairs.push_back(pairsOfCharsVector.at(randomPairIndex));
      RandomlyInsertIntoTable(pairsOfCharsVector.at(randomPairIndex));
      //If we havent inserted, try another value.
      reSelect = true;
   }
}

///Checks if a char is in the used pairs vector and returns true if its found
///\param[in]symbol, the symbol to be checked.  
bool MemoryMatch:: IsInUsedPairs(char symbol)
{
   int size = usedPairs.size();;
   for(int i = 0; i < size; i++)
   {
      if(symbol == usedPairs.at(i))
	 return true;
   }
   return false;
}

///randomly puts char into the table twice.
///\param[in]symbol, the symbol to be inserted into the screen  
void MemoryMatch::RandomlyInsertIntoTable(char symbol)
{
   int randomXCoordinate;
   int randomYCoordinate;
   bool insertSuccess=false;
   ///Happens twice since it's a pair
   for(int i = 0; i < 2; i++)
   {
      ///Keep repeating until an acceptable location is found, randomly.
      while(insertSuccess == false)
      {
	 randomXCoordinate = Puzzle::RandomNumber(boardSize);
	 randomYCoordinate = Puzzle::RandomNumber(boardSize);
	 if(charTable.at(randomXCoordinate).at(randomYCoordinate) == ' ')
	 {
	    charTable.at(randomXCoordinate).at(randomYCoordinate) = symbol;
	    insertSuccess = true;
	 }
      }
      insertSuccess = false;
   }
}

///Puts the values in the charTable into the screen in appropriate places among
///the game board
void MemoryMatch::SaveBoardToScreen()
{
   ///topBound and leftBound should set the board centered inside
   ///the screen object.
   int screenBoardSize = 9, topBound = 11, leftBound = 45;
   for(int i = 0; i < screenBoardSize; i++)
   {
      for(int j = 0; j < screenBoardSize; j++)
      {	 
	 ///If i is odd, fill the entire row with '-'
	 if(i %2 == 0)
	    MemoryMatchScreen.Set((topBound + i), (leftBound + j), '-');
         ///If i is even, fill the row with squares to place tokens in later
	 else
	 {
	    if(j %2 != 0)
	       MemoryMatchScreen.Set((topBound + i),(leftBound + j), ' ');
	    else
	       MemoryMatchScreen.Set((topBound + i),(leftBound + j), '|');
	 }
      }
   }
}

///Checks if the coordinates have been matched already using the membership
///table stored in the match vector, returns true if they are unmatched,
///false if they have previously been matched
///\param[in] inputX1, The X-Coordinate of the first card to check
///\param[in] inputY1, The Y-Coordinate of the first card to check
///\param[in] inputX2, The X-Coordinate of the second card to check
///\param[in] inputY2, The Y-Coordinate of the second card to check 
bool MemoryMatch::ValidMove(int X1, int Y1, int X2, int Y2)
{
   if(matchVector.at(X1).at(Y1)==1 || matchVector.at(X2).at(Y2)==1)
      return false;
   else
      return true;
}

///Generates a random number between 0 and n-1
///\param[in] n, the upper bound for the random number   
int MemoryMatch::RandomNumber(int n)
{
   ///Returns 0 to n-1
   n = rand ()% n;
   return n;
}

///Returns true if n is odd, false if even.
///\param[in]n, an integer n, checks if it is odd.  
bool MemoryMatch:: IsOdd(int n)
{
   if(n % 2 == 0)
      return false;
   else
      return true;
}

///Returns true if char has a true value in the matchVector, false otherwise
///\param[in] inputX, The X-Coordinate of the first card to check
///\param[in] inputY, The Y-Coordinate of the first card to check 
bool MemoryMatch:: IsCharAlreadyMatched(int inputX, int inputY)
{
   if(matchVector.at(inputX).at(inputY) == 1)
      return true;
   else
      return false;
}


///Flips the char stored at the inputted coordinates on chartable and sets them
///on the screen.
///\param[in] inputX, The X-Coordinate of the first card to flip
///\param[in] inputY, The Y-Coordinate of the first card to flip 
void MemoryMatch::FlipTwoChars(int inputX, int inputY)
{
   ///top left coordinate of the game board on the screen
   int topBound = 11, leftBound = 45;
   ///Symbol to be displayed
   char symbol;
   
   ///Display the first symbol
   symbol = charTable.at(inputX).at(inputY);
   MemoryMatchScreen.Set(((inputY * 2) + 1 + topBound),
			 ((inputX * 2) + 1 + leftBound), symbol);
}

///Flips two squares and outputs it for the inputted amount of seconds and then
///flips them back over to hide them from the user.
///\param[in]lengthInSecond, the number of seconds you want to flip for   
void MemoryMatch::PeekAtBoard(int lengthInSeconds)
{
   ///top left coordinate of the game board on the screen
   int topBound = 11, leftBound = 45;
   for(int i = 0; i < boardSize; i++)
   {
      for(int j = 0; j < boardSize; j++)
      {
	 FlipTwoChars(i, j);
      }
   }
   ///Output the game for three seconds
   cout << MemoryMatchScreen << endl; 
   Puzzle::SecondDelay(lengthInSeconds);
   system("clear");
   
   for(int i = 0; i < boardSize; i++)
   {
      for(int j = 0; j < boardSize; j++)
      {
	 MemoryMatchScreen.Set(((j * 2) + 1 + topBound)
			       ,((i * 2) + 1 + leftBound), ' ');
      }
   }
}

///Flips two squares and outputs it for 3 seconds then flips it back.
///\param[in] inputX1, The X-Coordinate of the first card to flip
///\param[in] inputY1, The Y-Coordinate of the first card to flip
///\param[in] inputX2, The X-Coordinate of the second card to flip
///\param[in] inputY2, The Y-Coordinate of the second card to flip  
void MemoryMatch::Peek(int inputX1, int inputY1, int inputX2, int inputY2)
{
   ///top left coordinate of the game board on the screen
   int topBound = 11, leftBound = 45;

   ///Flip the two selected chars, first check if they have been previously
   ///matched, if so, do nothing to them. Otherwise, flip.
   if( !(IsCharAlreadyMatched(inputX1, inputY1)))
      FlipTwoChars(inputX1, inputY1);
   if( !(IsCharAlreadyMatched(inputX2, inputY2)))
      FlipTwoChars(inputX2, inputY2);

   ///Output the game for three seconds
   cout << MemoryMatchScreen << endl; 
   Puzzle::SecondDelay(3);

   ///clear the first and second symbol off of the screen after 3 seconds, only
   ///if they have not previously been matched
   if( !(IsCharAlreadyMatched(inputX1, inputY1)))
      MemoryMatchScreen.Set(((inputY1 * 2) + 1 + topBound)
			    , ((inputX1 * 2) + 1 + leftBound), ' ');
   if( !(IsCharAlreadyMatched(inputX2, inputY2)))
      MemoryMatchScreen.Set(((inputY2 * 2) + 1 + topBound)
			    , ((inputX2 * 2) + 1 + leftBound), ' ');
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
      //Flip the two spots on the board
      FlipTwoChars(inputX1, inputY1);
      FlipTwoChars(inputX2, inputY2);

      //Set the two values to true to show that they have been matched.
      matchVector.at(inputX1).at(inputY1) = 1;
      matchVector.at(inputX2).at(inputY2) = 1;
   }
   else
      ///Show the user the spots they tried for a brief period of time
      Peek(inputX1,inputY1,inputX2,inputY2);  
}

///Checks if the two cards selected are a match, returns true if yes.
///\param[in] inputX1, The X-Coordinate of the first card to flip
///\param[in] inputY1, The Y-Coordinate of the first card to flip
///\param[in] inputX2, The X-Coordinate of the second card to flip
///\param[in] inputY2, The Y-Coordinate of the second card to flip 
bool MemoryMatch::MatchCheck(int inputX1, int inputY1, int inputX2, int inputY2)
{
   ///If the two chars are the same.
   if(charTable.at(inputX1).at(inputY1) == charTable.at(inputX2).at(inputY2))
      return true;
   else
      return false;
}

///Checks the state of the int table to see if the player has won the game,
///returns true when they have completed the puzzle.
void MemoryMatch::WinCheck()
{
   int trueCount = 0;
   for(int i = 0; i < boardSize; i++)
   {
      for(int j = 0; j < boardSize; j++)
      {
	 if(matchVector.at(i).at(j) == 1)
	    trueCount++;
      }
   }
   if(trueCount == boardSize * boardSize)
   {
      PuzzleEnd = true;
      EndGamePrompt();
   }
}
