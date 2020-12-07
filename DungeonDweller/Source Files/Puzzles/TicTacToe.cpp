/** @author Tyler Siwy
 * @date Oct 20, 2017
 */

#include "TicTacToe.h"

TicTacToe::TicTacToe()
{
	PuzzleEnd = false;
	// Setting up the game std::vector
	boardSize = 3;
	gameBoard.resize(boardSize);

	for (int i = 0; i < boardSize; i++)
	{
		for (int j = 0; j < boardSize; j++)
		{
			gameBoard.at(i).resize(boardSize);
			gameBoard.at(i).at(j) = ' ';
		}
	}
}

void TicTacToe::RunGame(Character* player)
{
	if (player == NULL)
		throw std::invalid_argument("Player pointer passed to minigame is invalid");
	// currentPlayer keeps track of whos turn it is, if it's odd, it is the user,
	// if it is even, it is the AI's turn.
	int currentPlayer = 1, inputX, inputY;
	BoardSetup();
	TicTacToeMenu ticTacToeGameMenu;
	while (PuzzleEnd == false)
	{
#ifdef __linux__
		system("clear");
#elif _WIN32
		std::cout << "\033[2J\033[H";
#endif
		std::cout << TicTacToeScreen << std::endl;
		SetCurrentPlayersChar(currentPlayer);
		if (currentPlayer % 2 == 0)
		{
			AiMove(currentPlayerChar);
			if (WinCheck() || TieGameCheck(currentPlayer))
				EndGamePrompt(currentPlayer, ticTacToeGameMenu, player);
			else
				currentPlayer++;
		}
		else
		{
			ticTacToeGameMenu.OutputMenu();
			ticTacToeGameMenu.HandleInput(std::cin);
			// X is taken as a, b, or c, Y is taken in as an integer.
			inputY = ticTacToeGameMenu.GetCoordinates().y - 1;
			inputX =
				ConvertCharCoordinateToIndex(ticTacToeGameMenu.GetCoordinates().x);
			if (IsInputValid(inputX, inputY) && !IsSpotFilled(inputX, inputY))
			{
				MovePiece(inputX, inputY, currentPlayerChar);
				if (WinCheck() || TieGameCheck(currentPlayer))
					EndGamePrompt(currentPlayer, ticTacToeGameMenu, player);
				else
					currentPlayer++;
			}
			else
			{
				ticTacToeGameMenu.SetQuery("Invalid coordinates, please try again!");
			}
		}
	}
}

void TicTacToe::BoardSetup()
{
	int gameBoardSize = 7, leftBound = 48, topBound = 14;
	for (int i = 0; i < gameBoardSize; i++)
	{
		for (int j = 0; j < gameBoardSize; j++)
		{
			// If i is odd, fill the row with '-'
			if (i % 2 == 0)
			{
				// topBoundand leftBound should set the board centered inside
				// the viewport object.
				TicTacToeScreen.Set(topBound + i, leftBound + j, '-');
			}
			else
			{
				if (j % 2 != 0)
				{
					// topBoundand leftBound should set the board centered inside
					// the viewport object.
					TicTacToeScreen.Set(topBound + i, leftBound + j, ' ');
				}
				else
				{
					// topBoundand leftBound should set the board centered inside
					// the viewport object.
					TicTacToeScreen.Set(topBound + i, leftBound + j, '|');
				}
			}
		}
	}
}

bool TicTacToe::HorizontalCheck()
{
	int xCount = 0, oCount = 0;
	for (int j = 0; j < boardSize; j++)
	{
		for (int i = 0; i < boardSize; i++)
		{
			if (gameBoard.at(i).at(j) == 'X')
			{
				xCount++;
				oCount = 0;
			}
			else if (gameBoard.at(i).at(j) == 'O')
			{
				oCount++;
				xCount = 0;
			}
			else
			{
				oCount = 0;
				xCount = 0;
			}
			if (xCount == 3 || oCount == 3)
				return true;
		}
		oCount = 0;
		xCount = 0;
	}
	return false;
}

bool TicTacToe::VerticalCheck()
{
	int xCount = 0, oCount = 0;
	for (int i = 0; i < boardSize; i++)
	{
		for (int j = 0; j < boardSize; j++)
		{
			if (gameBoard.at(i).at(j) == 'X')
			{
				xCount++;
				oCount = 0;
			}
			else if (gameBoard.at(i).at(j) == 'O')
			{
				oCount++;
				xCount = 0;
			}
			else
			{
				oCount = 0;
				xCount = 0;
			}
			if (xCount == 3 || oCount == 3)
				return true;
		}
		xCount = 0;
		oCount = 0;
	}
	return false;
}

bool TicTacToe::RightDiagonalCheck()
{
	int xCount = 0, oCount = 0, origin = 0;
	for (int i = 0; i < 3; i++)
	{
		if (gameBoard.at(origin + i).at(origin + i) == 'X')
		{
			xCount++;
			oCount = 0;
		}
		else if (gameBoard.at(origin + i).at(origin + i) == 'O')
		{
			oCount++;
			xCount = 0;
		}
		else
		{
			oCount = 0;
			xCount = 0;
		}
		if (xCount == 3 || oCount == 3)
			return true;
	}
	return false;
}

bool TicTacToe::LeftDiagonalCheck()
{
	int xCount = 0, oCount = 0, xOrigin = 0, yOrigin = 2;
	for (int i = 0; i < 3; i++)
	{
		if (gameBoard.at(xOrigin + i).at(yOrigin - i) == 'X')
		{
			xCount++;
			oCount = 0;
		}
		else if (gameBoard.at(xOrigin + i).at(yOrigin - i) == 'O')
		{
			oCount++;
			xCount = 0;
		}
		else
		{
			oCount = 0;
			xCount = 0;
		}
		if (xCount == 3 || oCount == 3)
			return true;
	}
	return false;
}

bool TicTacToe::IsInputValid(char inputX, int inputY)
{
	if (IsIntInputValid(inputX) && IsIntInputValid(inputY))
		return true;
	else
		return false;
}

bool TicTacToe::IsIntInputValid(int input)
{
	if (input >= 0 && input < 3)
		return true;
	else
		return false;
}

bool TicTacToe::IsSpotFilled(int inputX, int inputY)
{
	if (gameBoard.at(inputX).at(inputY) == ' ')
		return false;
	else
		return true;
}

void TicTacToe::SetCurrentPlayersChar(int currentPlayer)
{
	if (currentPlayer % 2 != 0)
		currentPlayerChar = 'X';
	else
		currentPlayerChar = 'O';
}

void TicTacToe::MovePiece(int inputX, int inputY, char userPiece)
{
	int leftColumn = 49, topRow = 15;
	gameBoard.at(inputX).at(inputY) = userPiece;
	TicTacToeScreen.Set(inputY * 2 + topRow, inputX * 2 + leftColumn, userPiece);
}

bool TicTacToe::WinCheck()
{
	if (VerticalCheck() || HorizontalCheck()
		|| LeftDiagonalCheck() || RightDiagonalCheck())
		return true;
	else
		return false;
}

int TicTacToe::ConvertCharCoordinateToIndex(char input)
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
	default:
		return -1;
	}
}

void TicTacToe::AiMove(char AiPiece)
{
	int HorizontalMoveCoord, VerticalMoveCoord;
	HorizontalMoveCoord = Puzzle::RandomNumber(3);
	VerticalMoveCoord = Puzzle::RandomNumber(3);

	bool moveSuccessful = false;
	while (moveSuccessful == false)
	{
		if (gameBoard.at(HorizontalMoveCoord).at(VerticalMoveCoord) == ' ')
		{
			MovePiece(HorizontalMoveCoord, VerticalMoveCoord, AiPiece);
			moveSuccessful = true;
		}
		else
		{
			HorizontalMoveCoord = Puzzle::RandomNumber(3);
			VerticalMoveCoord = Puzzle::RandomNumber(3);
		}
	}
}

void TicTacToe::EndGamePrompt(int& currentPlayer, TicTacToeMenu menu, Character* player)
{
	// If currentPlayer is even, the AI has won, -1 player health, reset
	// the game for another round until the player has won.
	if (currentPlayer == -1)
	{
#ifdef __linux__
		system("clear");
#elif _WIN32
		std::cout << "\033[2J\033[H";
#endif
		std::cout << TicTacToeScreen << std::endl;
		menu.SetQuery("There has been a tie, so get ready to play again!");
		menu.OutputMenu();
		SecondDelay(4);
		ResetGame(currentPlayer);
	}
	if (currentPlayer % 2 == 0)
	{
#ifdef __linux__
		system("clear");
#elif _WIN32
		std::cout << "\033[2J\033[H";
#endif
		std::cout << TicTacToeScreen;
		menu.SetQuery("The Tic Tac Toe champion has defeated you! -5 HP.");
		menu.OutputMenu();
		SecondDelay(4);
		player->ChangeHealth(-5);
		ResetGame(currentPlayer);
		std::cout << "Get ready to duel her again!" << std::endl;
	}
	else
	{
		std::string temp = "Congratulations adventurer! You have defeated the champion!";
		temp += "+10 GP +5 Stamina.";
		std::cout << TicTacToeScreen << std::endl;
		menu.SetQuery(temp);
		menu.OutputMenu();
		SecondDelay(5);
		player->ChangeGold(10);
		player->ChangeStamina(5);
		PuzzleEnd = true;
	}
}

bool TicTacToe::TieGameCheck(int& currentPlayer)
{
	int count = 0;
	for (int i = 0; i < boardSize; i++)
	{
		for (int j = 0; j < boardSize; j++)
		{
			if (gameBoard.at(i).at(j) == 'O' || gameBoard.at(i).at(j) == 'X')
				count++;
		}
	}
	if (count == 9)
	{
		currentPlayer = -1;
		return true;
	}
	else
		return false;
}

void TicTacToe::ResetGame(int& currentPlayer)
{
	for (int i = 0; i < boardSize; i++)
	{
		for (int j = 0; j < boardSize; j++)
		{
			gameBoard.at(i).at(j) = ' ';
		}
	}
	TicTacToeScreen.Erase();
	BoardSetup();
	currentPlayer = 1;
}
