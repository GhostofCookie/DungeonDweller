//
// CodeCracker.h
//
/// \author Tyler Siwy
/// \date Oct 20, 2017
//
#include "CodeCracker.h"

///Constructor
CodeCracker::CodeCracker(){
   riddleCompletionCount = 0;
   numberOfRiddles = 0;
   correctPrompt = "That answer is correct!";
   incorrectPrompt = "Wrong! *The puzzler smacks you on the head with his staff* -1 Health"; 
}

///Deconstructor
CodeCracker::~CodeCracker()
{
}

void CodeCracker::EndGamePrompt(Character *player, RiddleMenu &menu)
{
   string temp="Puzzler: Well, off you go then! +5 Stamina, +10 Gold";
   //menu.SetQuery(temp);
   //menu.OutputMenu();
   cout << temp << endl;
   player->ChangeStamina(+5);
   player->ChangeGold(+10);
   SecondDelay(5);
}

///Method to run the game, serves as a 'main' for the mini-game, calling
///functions from private until the player has won.
void CodeCracker:: RunGame(Character *player)
{
   if(player==NULL)
      throw invalid_argument("Player pointer passed to minigame is invalid");
   int userInput, currentRiddle;
   RiddleMenu GameMenu;
   
   system("clear");
   ImportRiddles();

   InitialPrompt(GameMenu);

   PuzzleEnd = false;
   while(PuzzleEnd == false)
   {
      system("clear");
      currentRiddle = UnusedRandomRiddle();
      //SetRiddleInMenu(currentRiddle, GameMenu);
      cout << question.at(currentRiddle);
      //GameMenu.OutputMenu();
      GameMenu.HandleInput(cin);   
      userInput = GameMenu.GetInput();

      if(ValidAnswer(userInput, currentRiddle))
      {
	 MakeRiddleUsed(currentRiddle);
	 //GameMenu.SetQuery(correctPrompt);
	 //GameMenu.OutputMenu();
	 cout << correctPrompt << endl;
	 Puzzle::SecondDelay(3);
	 riddleCompletionCount++;
	 cout << "riddlecompcount:" << riddleCompletionCount << endl;
	 WinCheck();
      }
      else
      {
	 cout << incorrectPrompt << endl;
	 //GameMenu.SetQuery(incorrectPrompt);
	 //GameMenu.OutputMenu();
	 SecondDelay(3);
	 player->ChangeHealth(-5);
	 DeathCheck(player);
      }
   }
   if(player->GetHealth() != 0)
      EndGamePrompt(player, GameMenu);
}

///Checks to see if the user input is one of the accepted answers.
///\param[in] Input, an answer to the riddle in the form of the char.
///\param[in] riddleIndex, location of the puzzles answer in riddle vector 
bool CodeCracker::ValidAnswer(int input, int riddleIndex)
{
   if(input == answer.at(riddleIndex))
   {
      return true;
   }
   else
      return false;
}

///Checks if the riddle has already been used so that the player doesn't do
///the same one twice, returns true if it has been used already.
///\param[in] index, location of the riddle in the riddle vector 
bool CodeCracker::IsRiddleUsed(int index)
{
   if(usedRiddles.at(index) == true)
      return true;
   else
      return false;
}


///Checks if the player has successfully answered 3 riddles.
void CodeCracker::WinCheck()
{
   if(riddleCompletionCount == 3)
      PuzzleEnd = true;
}

///Outputs the initial message to the player
///\param[in] menu, the menu object to be set and then outputted.  
void CodeCracker::InitialPrompt(RiddleMenu &menu)
{
   string initialPrompt = "Puzzler: Stop! Who would pass through the Door of Death must answer me these question three, ere the other side he see.";
   //menu.SetQuery(initialPrompt);
   //menu.OutputMenu();
   cout << initialPrompt << endl;
   Puzzle::SecondDelay(6);
}

void CodeCracker::SetRiddleInMenu(int riddleIndex, RiddleMenu &menu)
{
   string riddleText = question.at(riddleIndex);
   menu.SetQuery(riddleText);

}

void CodeCracker::MakeRiddleUsed(int riddleIndex)
{
   usedRiddles.at(riddleIndex) = true;
}

///Picks one of the unused riddles randomly and returns its index
int CodeCracker::UnusedRandomRiddle()
{
   int randRiddle;
   bool validRiddleFound = false;
   while(validRiddleFound == false)
   {
      randRiddle = Puzzle::RandomNumber(numberOfRiddles);
      if(!IsRiddleUsed(randRiddle))
	 validRiddleFound = true;
   }
   return randRiddle;
}

///Checks if the player is now dead and ends the game if yes
///\param[in] player, a pointer to the players character passed from main. 
void CodeCracker::DeathCheck(Character *player)
{
   if(player->GetHealth() == 0)
   {
      cout << "You're dead Jim" << endl;
      SecondDelay(4);
      PuzzleEnd = true;
   }
}

///Imports riddles from a text file and stores them in the vector.
void CodeCracker::ImportRiddles()
{
   string line, questionString, questionFormat;
   int qAnswer = 0;

   ifstream in;
   in.open("../Puzzles/Riddles.txt");
   if(in)
   {
      in >> numberOfRiddles;
      std::getline(in,line);
      question.resize(numberOfRiddles);
      usedRiddles.resize(numberOfRiddles);
      answer.resize(numberOfRiddles);
      for(int i = 0; i < numberOfRiddles; i++)
      {
	 std::getline(in, questionString);
	 in >> qAnswer;
	 question.at(i) = questionString;
	 answer.at(i) = qAnswer;
	 usedRiddles.at(i) = false;
	 std::getline(in,line);
      }
      in.close();	
   }
   else
      throw invalid_argument("Riddles text file has failed to open");
}
