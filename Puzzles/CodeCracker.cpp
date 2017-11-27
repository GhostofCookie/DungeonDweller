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
   correctPrompt="That answer is correct!";
   incorrectPrompt="Wrong! *The puzzler smacks you on the head with his staff* -1 Health"; 
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
   system("clear");
   SetOptionsInMenu();
   ImportRiddles();
   InitialPrompt(GameMenu);
   int currentRiddle;
   PuzzleEnd=false;
   while(PuzzleEnd==false)
   {
      system("clear");
      currentRiddle=UnusedRandomRiddle();
      cout << "current Riddle: " << question.at(currentRiddle) << endl;
      SetRiddleInMenu(currentRiddle, GameMenu);
///Do riddle output
      GameMenu.OutputMenu();
      GameMenu.HandleInput(cin);
      userInput=GameMenu.GetInput();
      cout << "userInput:" << userInput << endl;
	
      if(ValidAnswer(userInput, currentRiddle))
      {
	 MakeRiddleUsed(currentRiddle);
	 cout << "correct" << endl;
	 GameMenu.SetQuery(correctPrompt);
	 GameMenu.OutputMenu();
	 Puzzle::SecondDelay(3);
	 riddleCompletionCount++;
	 cout << "Riddles Completed:" << riddleCompletionCount << endl;
	 WinCheck();
      }
      else
      {
	 GameMenu.SetQuery(incorrectPrompt);
	 GameMenu.OutputMenu();
	 SecondDelay(3);
	 player->ChangeHealth(-5);
	 DeathCheck(player);
      }
   }
}
void CodeCracker::InitialPrompt(RiddleMenu &menu)
{
   string initialPrompt= "Puzzler: Stop! Who would pass through the Door of Death must answer me these question three, ere the other side he see.";
   menu.SetQuery(initialPrompt);
   menu.OutputMenu();
   Puzzle::SecondDelay(6);
}

void CodeCracker::SetRiddleInMenu(int riddleIndex, RiddleMenu &menu)
{
   string riddleText=question.at(riddleIndex);
   menu.SetQuery(riddleText);

}

void CodeCracker::MakeRiddleUsed(int riddleIndex)
{
   usedRiddles.at(riddleIndex)=true;
}

///Picks one of the unused riddles randomly and returns its index
int CodeCracker::UnusedRandomRiddle()
{
   int randRiddle, totalUsedRiddles=usedRiddles.size();  
   bool validRiddleFound=false;
   while(validRiddleFound==false)
   {
      randRiddle=Puzzle::RandomNumber(numberOfRiddles);
      if(!IsRiddleUsed(randRiddle))
	 validRiddleFound=true;
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

bool CodeCracker::IsRiddleUsed(int index)
{
   if(usedRiddles.at(index)==true)
      return true;
   else
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

///Checks if the player is now dead
void CodeCracker::DeathCheck(Character *player)
{
   if(player->GetHealth()==0)
      PuzzleEnd=true;
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
      std::getline(in,line);
      question.resize(numberOfRiddles);
      usedRiddles.resize(numberOfRiddles);
      answer.resize(numberOfRiddles);
      for(int i=0; i<numberOfRiddles; i++)
      {
	 std::getline(in, questionString);
	 in >> qAnswer;
	 question.at(i)=questionString;
	 answer.at(i)=qAnswer;
	 usedRiddles.at(i)=false;
	 std::getline(in,line);
      }
      in.close();	
   }
   else
      cout << "File failed to open" << endl;
}
