//
// code_cracker.h
//
/// \author Tyler Siwy
/// \date Oct 20, 2017
//
#include "CodeCracker.h"

CodeCracker::CodeCracker(){
   riddleCorrect=false;
   riddleCompletionCount=0;
   numberOfRiddles=0; //first char in the txt file
   question.resize(numberOfRiddles);
   question.resize(numberOfRiddles);
   question.resize(numberOfRiddles);
   for(int i=0; i<numberOfRiddles; i++)
   {
      ///Read in the riddle question string
      ///Read in the answer format
      ///Read in the anwer
   }
   
}

///Deconstructor
CodeCracker::~CodeCracker()
{
}

///Method to run the game, serves as a 'main' for the mini-game, calling
///functions from private until the player has won.
void CodeCracker:: RunGame()
{
   cout << "Start" << endl;
   SetOptionsInMenu();
   ImportRiddles();

   int currentRiddle;
   while(PuzzleEnd==false)
   {
      cout << "Loop" << endl;
      currentRiddle=Puzzle::RandomNumber(numberOfRiddles);
      ///Do riddle
      
      if(riddleCorrect==true)
      {
	 ///if riddle was completed successfully 
	 riddleCompletionCount++;
      }
      else
      {
	 ///Decrement player health
	 ///If player has died
	 ///PuzzleEnd=true;
	 ///
      }
      WinCheck();
      PuzzleEnd=true;
   }
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
bool CodeCracker::ValidAnswer(const char input)
{
   return false;
}
   
///Checks if the player has successfully answered 3 riddles.
void CodeCracker::WinCheck()
{
   if(riddleCompletionCount==3)
      PuzzleEnd=true;
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
   int qAnswer;

   ifstream in;
   in.open("Riddles.txt");	

   if(in)
   {
      in >> numberOfRiddles;
            cout << "Number of Riddles: " << numberOfRiddles << endl;
      for(int i=0; i<numberOfRiddles; i++)
      {
	 if(line != "")
	 {
	    getline(in, line, '\n');

	    cout << "Question:" << line << endl;
	    cout << "Format:" << questionFormat << endl;
	    cout << "Answer:" << qAnswer << endl;
	    question.at(i)=questionString;
	    format.at(i)=questionFormat;
	    answer.at(i)=qAnswer;

	 }
      }
      in.close();	
   }
   else
      cout << "File failed to open" << endl;
}
