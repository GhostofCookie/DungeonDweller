//
// code_cracker.h
//
/// \author Tyler Siwy
/// \date Oct 20, 2017
//
#include "CodeCracker.h"

CodeCracker::CodeCracker(){
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

   int currentRiddle;
   while(PuzzleEnd==false)
   {
      //currentRiddle=

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
}

///Checks if the player is now dead
void CodeCracker::DeathCheck()
{
}//Will need to take some kind of character variable/object

/// Displays the screen containing the gameboard
/// \param[in] CfScreen, the screen object used for displaying the mini-game 
void CodeCracker::OutputGame(Screen &ccScreen)
{
}

void CodeCracker::SetOptionsInMenu()
{
}

///Imports riddles from a text file and stores them in the vector.
void CodeCracker::ImportRiddles()
{
   ifstream in;
   string line, questionString, questionFormat;
   int qAnswer;

   in.open("Riddles.txt");	
   if(in)
   {
      getline(in, line, '\n');
      numberOfRiddles=line[0];
      for(int i=0; i<numberOfRiddles; i++)
      {
	 if(line != "")
	 {
	    // get both the file and the ID
	    istringstream iss(line);
	    iss >> questionString >> questionFormat >> qAnswer;

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
