//
// code_cracker.h
//
/// \author Tyler Siwy
/// \date Oct 20, 2017
//
#include "CodeCracker.h"

CodeCracker::CodeCracker(){
      riddleCompletionCount=0;
   numberOfRiddles=0;
}

///Deconstructor
CodeCracker::~CodeCracker()
{
}

///Method to run the game, serves as a 'main' for the mini-game, calling
///functions from private until the player has won.
void CodeCracker:: RunGame(Character *player)
{
   int userInput;
   RiddleMenu GameMenu;
   cout << "Start" << endl;
   SetOptionsInMenu();
   ImportRiddles();

   int currentRiddle;
   while(PuzzleEnd==false)
   {
      cout << "Loop" << endl;
      currentRiddle=UnusedRandomRiddle();
///Do riddle output
      GameMenu.HandleInput(cin);
      userInput=GameMenu.GetInput();
      cout << "userInput:" << userInput << endl;
	
      if(ValidAnswer(userInput, currentRiddle))
      {
	 riddleCompletionCount++;
	 WinCheck();
      }
      else
      {
	 //Decrement health
	 DeathCheck();//************NEEDS TO BE IMPLEMENTED******************
      PuzzleEnd=true;//***********TO BE REMOVED**************
      }
   }
}

void CodeCracker::SetRiddleInMenu(int riddleIndex)
{
   cout << "riddle Index:" << riddleIndex << endl;
   string riddleText=question.at(riddleIndex);
   SetQuery(riddleText);

}


///Picks one of the unused riddles randomly and returns its index
int CodeCracker::UnusedRandomRiddle()
{
   int randRiddle, totalUsedRiddles=usedRiddles.size();
   bool validRiddleFound=false;
   while(validRiddleFound==false)
   {
      randRiddle=Puzzle::RandomNumber(numberOfRiddles);
      for(int i=0; i<totalUsedRiddles; i++)
      {
	 if(randRiddle==usedRiddles.at(i))
	    return false;
	 else
	    return true;
      }
   }
   return randRiddle;
}


///Checks the semantics of the user choice to make sure they aren't doing
///something that would break the game with their input.
///\param[in]input, has been checked for syntax by input method  
bool CodeCracker::ValidMove(char input)
{
   //if condition
   return false;
}


///Checks to see if the user input is one of the accepted answers.
///\param[in] Input, an answer to the riddle in the form of the char.
bool CodeCracker::ValidAnswer(int input, int riddleIndex)
{
  if(input==answer.at(riddleIndex))
   {
      return true;
   }
   else
      return false;
}

///Checks if the player has successfully answered 3 riddles.
void CodeCracker::WinCheck()
{
   if(riddleCompletionCount==3)
      PuzzleEnd=true;
}

void CodeCracker::DecrementPlayerHealth(int amountToDecrement)
{


}
///Checks if the player is now dead
void CodeCracker::DeathCheck()
{
}//Will need to take some kind of character variable/object

/// Displays the screen containing the gameboard
/// \param[in] CfScreen, the screen object used for displaying the mini-game 

void CodeCracker::SetOptionsInMenu()
{
}

///Imports riddles from a text file and stores them in the vector.
void CodeCracker::ImportRiddles()
{
   string line, questionString, questionFormat;
   char number;
   int qAnswer=0;

   ifstream in;
   in.open("Riddles.txt");

   if(in)
   {
      in >> numberOfRiddles;
      cout << "Number of Riddles: " << numberOfRiddles << endl;
      std::getline(in,line);
      question.resize(numberOfRiddles);
      format.resize(numberOfRiddles);
      answer.resize(numberOfRiddles);
      usedRiddles.resize(numberOfRiddles);
      for(int i=0; i<numberOfRiddles; i++)
      {
	 std::getline(in, questionString);
	 std::getline(in, questionFormat);
	 in >> qAnswer;
	 cout << "Question: " << questionString << endl;
	 cout << "Format: " << questionFormat << endl;
	 cout << "Answer: " << qAnswer << endl;
	 question.at(i)=questionString;
	 format.at(i)=questionFormat;
	 answer.at(i)=qAnswer;
	 std::getline(in,line);
      }
      in.close();	
   }
   else
      cout << "File failed to open" << endl;
}
