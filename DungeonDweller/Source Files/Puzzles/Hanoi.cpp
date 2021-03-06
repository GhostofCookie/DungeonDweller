/** @author Tyler Siwy
 * @date Oct 20, 2017
 *
 *       ===       (3)
 *     =======     (7)
 *   ===========   (11)
 * =============== (15)
 * viewport is 101x33
 */

#include "Hanoi.h"

Hanoi::Hanoi()
{
	BoardSetup();
	numberOfStacks = 3;
	maxStackHeight = 4;
	tower.resize(numberOfStacks);
	DiscSetup();
	endGamePrompt = "Congratulations you have completed the puzzle! +5 Stamina";
	PuzzleEnd = false;
}

void Hanoi::EndGamePrompt(Character* player)
{
	std::cout << endGamePrompt << std::endl;
	player->ChangeStamina(+5);
}

void Hanoi::RunGame(Character* player)
{
	if (player == NULL)
		throw std::invalid_argument("Player pointer passed to minigame is invalid");
	char input;
	SetOptionsInMenu();

	while (PuzzleEnd == false)
	{
#ifdef __linux__
		system("clear");
#elif _WIN32
		std::cout << "\033[2J\033[H";
#endif
		std::cout << HanoiScreen;
		HanoiGameMenu.OutputMenu();
		HanoiGameMenu.HandleInput(std::cin);
		input = HanoiGameMenu.GetOption();//returns a char
		LogicSwitch(input);
		WinCheck();
		EndGamePrompt(player);
	}
	//HanoiGameMenu.SetQuery(endGamePrompt);
	//HanoiGameMenu.OutputMenu();
	SecondDelay(5);
}

void Hanoi::DiscSetup()
{
	DefaultImg disc1(1, 3, '=');
	DefaultImg disc2(1, 7, '=');
	DefaultImg disc3(1, 11, '=');
	DefaultImg disc4(1, 15, '=');

	// Draw to the game viewport and then put the discs into the first stack to
	// start the game.
	int bottom = 15, leftPeg = 34;
	disc4.AlignCenter(HanoiScreen);
	disc4.ShiftLeft(leftPeg);
	disc4.ShiftDown(HanoiScreen, bottom);
	disc4.Draw(HanoiScreen);
	tower.at(0).push(disc4);
	bottom--;

	disc3.AlignCenter(HanoiScreen);
	disc3.ShiftLeft(leftPeg);
	disc3.ShiftDown(HanoiScreen, bottom);
	disc3.Draw(HanoiScreen);
	tower.at(0).push(disc3);
	bottom--;
	disc2.AlignCenter(HanoiScreen);
	disc2.ShiftLeft(leftPeg);
	disc2.ShiftDown(HanoiScreen, bottom);
	disc2.Draw(HanoiScreen);
	tower.at(0).push(disc2);
	bottom--;
	disc1.AlignCenter(HanoiScreen);
	disc1.ShiftLeft(leftPeg);
	disc1.ShiftDown(HanoiScreen, bottom);
	disc1.Draw(HanoiScreen);
	tower.at(0).push(disc1);
}

void Hanoi::PushDiscOnLeftStack(int bottom, DefaultImg disc) {
	int leftPeg = 34;
	disc.AlignCenter(HanoiScreen);
	disc.ShiftLeft(leftPeg);
	disc.ShiftDown(HanoiScreen, bottom);
	disc.Draw(HanoiScreen);
	tower.at(0).push(disc);
}

void Hanoi::BoardSetup()
{
	int leftDivider = 17, peg = 34, rightDivider = 16, bottom = 11;
	DefaultImg Divider1(31, 1, '|');
	Divider1.AlignCenter(HanoiScreen);
	Divider1.ShiftLeft(leftDivider);
	Divider1.Draw(HanoiScreen);

	DefaultImg Divider2(31, 1, '|');
	Divider2.AlignCenter(HanoiScreen);
	Divider2.ShiftRight(HanoiScreen, rightDivider);
	Divider2.Draw(HanoiScreen);

	DefaultImg Peg1(10, 1, '|');
	Peg1.AlignCenter(HanoiScreen);
	Peg1.ShiftLeft(peg);
	Peg1.ShiftDown(HanoiScreen, bottom);
	Peg1.Draw(HanoiScreen);

	DefaultImg Peg2(10, 1, '|');
	Peg2.AlignCenter(HanoiScreen);
	Peg2.ShiftDown(HanoiScreen, bottom);
	Peg2.Draw(HanoiScreen);

	DefaultImg Peg3(10, 1, '|');
	Peg3.AlignCenter(HanoiScreen);
	Peg3.ShiftRight(HanoiScreen, peg);
	Peg3.ShiftDown(HanoiScreen, bottom);
	Peg3.Draw(HanoiScreen);
}

void Hanoi::SetOptionsInMenu()
{
	std::string menuOption1 = "Move disc on peg 1 to peg 2"
		, menuOption2 = "Move disc on peg 2 to peg 1"
		, menuOption3 = "Move disc on peg 3 to peg 2"
		, menuOption4 = "Move disc on peg 1 to peg 3"
		, menuOption5 = "Move disc on peg 2 to peg 3"
		, menuOption6 = "Move disc on peg 3 to peg 1";

	HanoiGameMenu.AddOption('1', menuOption1);
	HanoiGameMenu.AddOption('2', menuOption2);
	HanoiGameMenu.AddOption('3', menuOption3);
	HanoiGameMenu.AddOption('4', menuOption4);
	HanoiGameMenu.AddOption('5', menuOption5);
	HanoiGameMenu.AddOption('6', menuOption6);
}

void Hanoi::WinCheck()
{
	// If the user has managed to successfully move all discs to the last peg
	// then its size should be 4.
	if (tower.at(2).size() == 4)
		PuzzleEnd = true;
}

void Hanoi::DrawDiscOnTargetStack(int sourceStack, int targetStack)
{
	int peg = 34, bottom = 15, targetHeight;
	switch (targetStack)
	{
	case 0:
		targetHeight = tower.at(targetStack).size();

		tower.at(sourceStack).top().AlignCenter(HanoiScreen);
		tower.at(sourceStack).top().ShiftLeft(peg);

		// Add the height of any discs stored on that stack
		tower.at(sourceStack).top().ShiftDown(HanoiScreen, bottom - targetHeight);
		tower.at(sourceStack).top().Draw(HanoiScreen);
		break;
	case 1:
		targetHeight = tower.at(targetStack).size();

		tower.at(sourceStack).top().AlignCenter(HanoiScreen);

		// Add the height of any discs stored on that stack
		tower.at(sourceStack).top().ShiftDown(HanoiScreen, bottom - targetHeight);
		tower.at(sourceStack).top().Draw(HanoiScreen);
		break;
	case 2:
		targetHeight = tower.at(targetStack).size();

		tower.at(sourceStack).top().AlignCenter(HanoiScreen);
		tower.at(sourceStack).top().ShiftRight(HanoiScreen, peg);

		// Add the height of any discs stored on that stack
		tower.at(sourceStack).top().ShiftDown(HanoiScreen, bottom - targetHeight);
		tower.at(sourceStack).top().Draw(HanoiScreen);
		break;
	}
}

bool Hanoi::ValidMove(const int targetStackTopSize, const int currentTopSize) const
{
	// If the disc on the current stack is smaller than the disc on the new stack
	// it is considered a valid move, so return true, otherwise return false.
	if (currentTopSize < targetStackTopSize || targetStackTopSize == 0)
		return true;
	else
		return false;
}

void Hanoi::MovePiece(int sourceTower, int targetTower)
{
	// targetStackTopSize is the size of the top disc on the target stack, used for a
	// comparison to see if the player is making a valid move.
	int targetStackTopSize;
	// If the target tower is empty, the target tower has a top disc
	// size of 0, otherwise find the size of the top discand set it to
	// newStackTop
	if (tower.at(targetTower).empty())
		targetStackTopSize = 0;
	else
		targetStackTopSize = tower.at(targetTower).top().GetCols();

	// Check if the move is a valid, if yes, move it overand pop it
	// from its old location.
	// currentDiscSize is the size of the disc which we are going to move
	int currentDiscSize;
	currentDiscSize = tower.at(sourceTower).top().GetCols();//get cols gives the width

	if (ValidMove(targetStackTopSize, currentDiscSize))
	{
		// Push the right size disc from the std::vector of discs based on the
		// size passed into WhichDiscFromSize, size is topOfStack
		ClearTopDisc(sourceTower);
		DrawDiscOnTargetStack(sourceTower, targetTower);
		tower.at(targetTower).push(tower.at(sourceTower).top());
		tower.at(sourceTower).pop();
		std::cout << HanoiScreen;
	}
}

void Hanoi::ClearTopDisc(int targetTower)
{
	int discWidth, centerOfScreen = 50, midPointInDisc, bottomStartPoint = 32
		, pegDistance = 34, startingPoint;
	discWidth = tower.at(targetTower).top().GetCols();

	switch (targetTower)
	{
	case 0:
		startingPoint = centerOfScreen - pegDistance;
		break;
	case 1:
		startingPoint = centerOfScreen;
		break;
	case 2:
		startingPoint = centerOfScreen + pegDistance;
		break;
	}
	midPointInDisc = discWidth / 2;
	bottomStartPoint -= tower.at(targetTower).size();

	// Start at 1 always so that the smallest discs get cleared since starting at
	// 0 wouldn't clear anything for the top disc.
	for (int i = 1; i < midPointInDisc + 1; i++)
	{
		HanoiScreen.Set(bottomStartPoint, startingPoint + i, ' ');
		HanoiScreen.Set(bottomStartPoint, startingPoint - i, ' ');
		HanoiScreen.Set(bottomStartPoint, startingPoint, '|');
	}
}

void Hanoi::EmptyPrompt()
{
	std::cout << "Disc is empty, please try again." << std::endl;
	SecondDelay(3);
}

void Hanoi::LogicSwitch(char userSelection)
{
	switch (userSelection)
	{
	case '1':
		// Move peg 1 to peg 2
		if (tower.at(0).empty())
			EmptyPrompt();
		else
			MovePiece(0, 1);//(source,target)
		break;
	case '2':
		// Move peg 2 to peg 1
		if (tower.at(1).empty())
			EmptyPrompt();
		else
			MovePiece(1, 0);
		break;
	case '3':
		// Move disk on peg 3 to peg 2
		if (tower.at(2).empty())
			EmptyPrompt();
		else
			MovePiece(2, 1);
		break;
	case '4':
		// Move peg 1 to peg 3
		if (tower.at(0).empty())
			EmptyPrompt();
		else
			MovePiece(0, 2);
		break;
	case '5':
		// Move peg 2 to peg 3
		if (tower.at(1).empty())
			EmptyPrompt();
		else
			MovePiece(1, 2);
		break;
	case '6':
		// Move peg 3 to peg 1
		if (tower.at(2).empty())
			EmptyPrompt();
		else
			MovePiece(2, 0);
		break;
	}
}
