/**
 * @author Tyler Siwy
 * CPSC 2720-Howard Cheng-Dungeon Dweller
 */

#include "MemoryMatch.h"

MemoryMatch::MemoryMatch()
{
	boardSize = 4;
	pairsOfCharsVector.resize(boardSize * boardSize / 2);
	pairsOfCharsVector.at(0) = '@';
	pairsOfCharsVector.at(1) = '#';
	pairsOfCharsVector.at(2) = '$';
	pairsOfCharsVector.at(3) = 'K';
	pairsOfCharsVector.at(4) = 'T';
	pairsOfCharsVector.at(5) = '&';
	pairsOfCharsVector.at(6) = 'R';
	pairsOfCharsVector.at(7) = 'G';

	matchVector.resize(boardSize);
	charTable.resize(boardSize);
	for (int i = 0; i < boardSize; i++)
	{
		charTable.at(i).resize(boardSize);
		matchVector.at(i).resize(boardSize);

		for (int j = 0; j < boardSize; j++)
		{
			matchVector.at(i).at(j) = 0;
			charTable.at(i).at(j) = ' ';
		}
	}
}

void MemoryMatch::RunGame(Character* player)
{
	if (player == NULL)
		throw std::invalid_argument("Player pointer passed to minigame is invalid");
	MemoryMenu MemoryMatchMenu;
	int inputX1, inputY1, inputX2, inputY2;
	BoardSetup();
	SaveBoardToScreen();
#ifdef __linux__
	system("clear");
#elif _WIN32
	std::cout << "\033[2J\033[H";
#endif
	PeekAtBoard(6);
	while (PuzzleEnd == false)
	{
#ifdef __linux__
		system("clear");
#elif _WIN32
		std::cout << "\033[2J\033[H";
#endif
		std::cout << MemoryMatchScreen;
		MemoryMatchMenu.OutputMenu();
		MemoryMatchMenu.HandleInput(std::cin);
		// Get input 1 - 4
		SetInputs(inputX1, inputY1, inputX2, inputY2, MemoryMatchMenu);
		if (CheckInput(inputX1, inputY1, inputX2, inputY2))
		{
			MovePiece(inputX1, inputY1, inputX2, inputY2);
			WinCheck();
		}
		else
			std::cout << "Invalid input, please try again!" << std::endl;
	}
}

void MemoryMatch::EndGamePrompt()
{
	std::string temp = "Congratulations adventurer! You've solved the puzzle!";
	temp += " +5 Stamina";
	std::cout << temp << std::endl;
	std::cout << MemoryMatchScreen;
	Puzzle::SecondDelay(6);
}

int MemoryMatch::ConvertCharToIndex(char input)
{
	switch (input)
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

void MemoryMatch::SetInputs(int& X1, int& Y1, int& X2, int& Y2, MemoryMenu& menu)
{
	X1 = ConvertCharToIndex(menu.GetCoordinates().x1);
	Y1 = menu.GetCoordinates().y1 - 1;
	X2 = ConvertCharToIndex(menu.GetCoordinates().x2);
	Y2 = menu.GetCoordinates().y2 - 1;
}

bool MemoryMatch::IsInputValid(int input)
{
	if (input > 3 || input < 0)
		return false;
	else
		return true;
}

bool MemoryMatch::CheckInput(int x1, int y1, int x2, int y2)
{
	if (IsInputValid(x1) && IsInputValid(y1) && IsInputValid(x2) && IsInputValid(y2))
		return true;
	else
		return false;
}

void MemoryMatch::BoardSetup()
{
	std::cout << "Board Setup" << std::endl;
	int randomPairIndex;
	char randomPairToInsert;
	bool reSelect = true;

	// Setting up the match - true / false value std::vector for win checking / error checking
	for (unsigned int i = 0; i < pairsOfCharsVector.size(); i++)
	{
		// Try random std::pairs until the table has been filled in a random order
		while (reSelect == true)
		{
			reSelect = false;
			// half of the area of the board since there are std::pairs so / 2
			randomPairIndex = RandomNumber(boardSize * boardSize / 2);
			// Choose a random std::pair from the table of possible std::pairs
			randomPairToInsert = pairsOfCharsVector.at(randomPairIndex);

			// If we haven't used any std::pair yet. Insert right away
			if (usedPairs.empty())
				reSelect = false;
			// Else check if we have used it before, if yes, try another std::pair
			else if (IsInUsedPairs(randomPairToInsert))
				reSelect = true;
		}
		usedPairs.push_back(pairsOfCharsVector.at(randomPairIndex));
		RandomlyInsertIntoTable(pairsOfCharsVector.at(randomPairIndex));

		//If we havent inserted, try another value.
		reSelect = true;
	}
}

bool MemoryMatch::IsInUsedPairs(char symbol)
{
	int size = usedPairs.size();;
	for (int i = 0; i < size; i++)
	{
		if (symbol == usedPairs.at(i))
			return true;
	}
	return false;
}

void MemoryMatch::RandomlyInsertIntoTable(char symbol)
{
	int randomXCoordinate;
	int randomYCoordinate;
	bool insertSuccess = false;
	// Happens twice since it's a std::pair
	for (int i = 0; i < 2; i++)
	{
		// Keep repeating until an acceptable location is found, randomly.
		while (insertSuccess == false)
		{
			randomXCoordinate = Puzzle::RandomNumber(boardSize);
			randomYCoordinate = Puzzle::RandomNumber(boardSize);
			if (charTable.at(randomXCoordinate).at(randomYCoordinate) == ' ')
			{
				charTable.at(randomXCoordinate).at(randomYCoordinate) = symbol;
				insertSuccess = true;
			}
		}
		insertSuccess = false;
	}
}

void MemoryMatch::SaveBoardToScreen()
{
	// topBoundand leftBound should set the board centered inside
	// the viewport object.
	int screenBoardSize = 9, topBound = 11, leftBound = 45;
	for (int i = 0; i < screenBoardSize; i++)
	{
		for (int j = 0; j < screenBoardSize; j++)
		{
			// If i is odd, fill the entire row with '-'
			if (i % 2 == 0)
				MemoryMatchScreen.Set((topBound + i), (leftBound + j), '-');
			// If i is even, fill the row with squares to place tokens in later
			else
			{
				if (j % 2 != 0)
					MemoryMatchScreen.Set((topBound + i), (leftBound + j), ' ');
				else
					MemoryMatchScreen.Set((topBound + i), (leftBound + j), '|');
			}
		}
	}
}

bool MemoryMatch::ValidMove(int X1, int Y1, int X2, int Y2)
{
	if (matchVector.at(X1).at(Y1) == 1 || matchVector.at(X2).at(Y2) == 1)
		return false;
	else
		return true;
}

int MemoryMatch::RandomNumber(int n)
{
	// Returns 0 to n - 1
	n = rand() % n;
	return n;
}

bool MemoryMatch::IsOdd(int n)
{
	if (n % 2 == 0)
		return false;
	else
		return true;
}

bool MemoryMatch::IsCharAlreadyMatched(int inputX, int inputY)
{
	if (matchVector.at(inputX).at(inputY) == 1)
		return true;
	else
		return false;
}

void MemoryMatch::FlipTwoChars(int inputX, int inputY)
{
	int topBound = 11, leftBound = 45;
	char symbol;

	// Display the first symbol
	symbol = charTable.at(inputX).at(inputY);
	MemoryMatchScreen.Set(((inputY * 2) + 1 + topBound),
		((inputX * 2) + 1 + leftBound), symbol);
}

void MemoryMatch::PeekAtBoard(int lengthInSeconds)
{
	// top left coordinate of the game board on the viewport
	int topBound = 11, leftBound = 45;
	for (int i = 0; i < boardSize; i++)
	{
		for (int j = 0; j < boardSize; j++)
		{
			FlipTwoChars(i, j);
		}
	}

	// Output the game for three seconds
	std::cout << MemoryMatchScreen << std::endl;
	Puzzle::SecondDelay(lengthInSeconds);
#ifdef __linux__
	system("clear");
#elif _WIN32
	std::cout << "\033[2J\033[H";
#endif

	for (int i = 0; i < boardSize; i++)
	{
		for (int j = 0; j < boardSize; j++)
		{
			MemoryMatchScreen.Set(((j * 2) + 1 + topBound)
				, ((i * 2) + 1 + leftBound), ' ');
		}
	}
}

void MemoryMatch::Peek(int inputX1, int inputY1, int inputX2, int inputY2)
{
	// top left coordinate of the game board on the viewport
	int topBound = 11, leftBound = 45;

	// Flip the two selected chars, first check if they have been previously
	// matched, if so, do nothing to them.Otherwise, flip.
	if (!(IsCharAlreadyMatched(inputX1, inputY1)))
		FlipTwoChars(inputX1, inputY1);
	if (!(IsCharAlreadyMatched(inputX2, inputY2)))
		FlipTwoChars(inputX2, inputY2);

	// Output the game for three seconds
	std::cout << MemoryMatchScreen << std::endl;
	Puzzle::SecondDelay(3);

	// clear the firstand second symbol off of the viewport after 3 seconds, only
	// if they have not previously been matched
	if (!(IsCharAlreadyMatched(inputX1, inputY1)))
		MemoryMatchScreen.Set(((inputY1 * 2) + 1 + topBound)
			, ((inputX1 * 2) + 1 + leftBound), ' ');
	if (!(IsCharAlreadyMatched(inputX2, inputY2)))
		MemoryMatchScreen.Set(((inputY2 * 2) + 1 + topBound)
			, ((inputX2 * 2) + 1 + leftBound), ' ');
	// Output the game again now that it has been cleared of the users guess.
	std::cout << MemoryMatchScreen << std::endl;
}

void MemoryMatch::MovePiece(int inputX1, int inputY1, int inputX2, int inputY2)
{
	if (MatchCheck(inputX1, inputY1, inputX2, inputY2))
	{
		//Flip the two spots on the board
		FlipTwoChars(inputX1, inputY1);
		FlipTwoChars(inputX2, inputY2);

		//Set the two values to true to show that they have been matched.
		matchVector.at(inputX1).at(inputY1) = 1;
		matchVector.at(inputX2).at(inputY2) = 1;
	}
	else
		// Show the user the spots they tried for a brief period of time
		Peek(inputX1, inputY1, inputX2, inputY2);
}

bool MemoryMatch::MatchCheck(int inputX1, int inputY1, int inputX2, int inputY2)
{
	// If the two chars are the same.
	if (charTable.at(inputX1).at(inputY1) == charTable.at(inputX2).at(inputY2))
		return true;
	else
		return false;
}

void MemoryMatch::WinCheck()
{
	int trueCount = 0;
	for (int i = 0; i < boardSize; i++)
	{
		for (int j = 0; j < boardSize; j++)
		{
			if (matchVector.at(i).at(j) == 1)
				trueCount++;
		}
	}
	if (trueCount == boardSize * boardSize)
	{
		PuzzleEnd = true;
		EndGamePrompt();
	}
}
