#include "PuzzleState.h"
#include "Hanoi.h"
#include "CodeCracker.h"
#include "TicTacToe.h"
#include "MemoryMatch.h"
#include "ConnectFour.h"

PuzzleState::PuzzleState(std::shared_ptr<Player> p, std::shared_ptr<Screen> scr)
{
	player = p;
	screen = scr;
}

void PuzzleState::Set()
{
	puzzles.push_back(new Hanoi());
	puzzles.push_back(new TicTacToe());
	puzzles.push_back(new ConnectFour());
	puzzles.push_back(new MemoryMatch());
	puzzles.push_back(new CodeCracker());
}

void PuzzleState::Get()
{
	random_shuffle(puzzles.begin(), puzzles.end());
	auto it = puzzles.begin();

	(*it)->RunGame(player.get());
	currState = States::EXPLORE;
}
