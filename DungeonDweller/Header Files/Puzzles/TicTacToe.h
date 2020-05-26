/**
 * TicTacToe.h
 *
 * @author Tyler Siwy
 * @date Oct 20, 2017
 */

#pragma once

#include "Puzzle.h"
#include "TicTacToeMenu.h"
#include "Screen.h"
#include "DefaultImg.h"
#include <iostream>


 /** This class contains the mini-game/puzzle Tic Tac Toe */
class TicTacToe : public virtual Puzzle
{
public:
	/** Default constructor for TicTacToe, sets height to 3 and width to 3. */
	TicTacToe();

	/** Method to run the game, serves as a 'main' for the mini-game, calling
	 * functions from private until the player has won.
	 */
	virtual void RunGame(Character* player);

private:
	/** Checks the semantics of the user choice to make sure they aren't doing
	 * something that would break the game with their input.
	 * @param[in] inputX, the X-coordinate of the selection.
	 * @param[in] inputY, the Y-coordinate of the selection.
	 */
	bool ValidMove(int inputX, int inputY);

	/** Sets the board up for the beginning of the game, plastd::cing the grid */
	void BoardSetup();

	/** Displays the screen containing the gameboard
	 * @param[in] inputX, the X-coordinate of the selection.
	 * @param[in] inputY, the Y-coordinate of the selection.
	 */
	void MovePiece(int inputX, int inputY, char userPiece);

	/** Prompts the player and handles the end of the game appropriately.
	 * @param[in] currentPlayer, assigned to be human for new game.
	 * @param[in] menu, the menu used to output stuffs
	 * @param[in] player, a pointer to the player usd to modify stats
	 */
	void EndGamePrompt(int& currentPlayer, TicTacToeMenu menu, Character* player);

	/** Checks to see if there have been any 3 tokens in a row in the grid std::vector. */
	bool WinCheck();

	/** Checks if there is a tie, returns true if yes.
	 * @param[in] currentPlayer, a reference to which players turn it is
	 */
	bool TieGameCheck(int& currentPlayer);

	/** Performs the selection for the npc opponent.
	 * @param[in] AiPiece, which char to insert into the board
	 */
	void AiMove(char AiPiece);

	/** Checks the entire grid to see if there is 3 of a kind in a horizontal
	 * position, returns true if it finds 3 of a kind, false otherwise.
	 */
	bool HorizontalCheck();

	/** Checks the entire grid to see if there is 3 of a kind in a vertical
	 * position, returns true if it finds 3 of a kind, false otherwise.
	 */
	bool VerticalCheck();

	/** Checks the entire grid to see if there's 3 of a kind in a right diagonal
	 * position, returns true if it finds 3 of a kind, false otherwise.
	 */
	bool RightDiagonalCheck();

	/** Checks the entire grid to see if there is 3 of a kind in a left diagonal
	 * position, returns true if it finds 3 of a kind, false otherwise.
	 */
	bool LeftDiagonalCheck();

	/** Makes sure the input is within the bounds of the game
	 * @param[in]inputX, x-coordinate to check
	 * @param[in]inputY, y-coordinate to check
	 */
	bool IsInputValid(char inputX, int inputY);

	/** Checks to see if the int is within the bounds of the game
	* @param[in]input, the value to check
	*/
	bool IsIntInputValid(int input);

	/** Checks who's turn it is and sets CurrentPlayerChar to their
	 * correct char.
	 */
	void SetCurrentPlayersChar(int currentPlayer);

	/** Resets the game to the starting state
	 * @param[in]currentPlayer, an int to show whos turn it is
	 */
	void ResetGame(int& currentPlayer);

	/** Takes a char from the input and assigns it an appropriate int
	 * @param[in]input, a char to convert
	 */
	int ConvertCharCoordinateToIndex(char input);

	/** Vector to store the contents of the gameboard. */
	std::vector < std::vector < char > > gameBoard;

	/** Dimensions for the board. */
	int boardSize;

	char currentPlayerChar;

	/** returns true if character is filled, false otherwise. */
	bool IsSpotFilled(int inputX, int inputY);

	/** Returns true if every space in the board has been filled with a character. */
	bool IsBoardFull();

	/** Resets the game for another round in the event that the AI wins. */
	void ResetGame();

	/** TicTacToeScreen stores and outputs the contents of the game to the
	 * terminal.
	 */
	Screen TicTacToeScreen;

};
