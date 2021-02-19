#include "Minimax.h"
#include "WinConditions.h"
#include <algorithm>

int Minimax::minimax(char board[][SIDE], int depth, bool isMax)
{
	WinConditions winCon;

	int startScore = Evaluate(board);

	if (startScore == 10) {
		return startScore;
	}

	if (startScore == -10) {
		return startScore;
	}

	if (winCon.GameOver(board) == true) {
		return 0;
	}

	if (isMax)
	{
		int bestScore = -1000;
		for (int i = 0; i < SIDE; i++)
		{
			for (int j = 0; j < SIDE; j++)
			{
				if (board[i][j] != HUMANMOVE && board[i][j] != COMPUTERMOVE)
				{
					char num = board[i][j];
					board[i][j] = COMPUTERMOVE;
					int score = minimax(board, depth + 1, false);
					board[i][j] = num;
					bestScore = std::max(score, bestScore);
				}
			}
		}
		return bestScore;
	}
	else
	{
		int bestScore = 1000;

		for (int i = 0; i < SIDE; i++)
		{
			for (int j = 0; j < SIDE; j++)
			{
				if (board[i][j] != HUMANMOVE && board[i][j] != COMPUTERMOVE)
				{
					char num = board[i][j];
					board[i][j] = HUMANMOVE;
					int score = minimax(board, depth + 1, true);
					board[i][j] = num;
					bestScore = std::min(score, bestScore);
				}
			}
		}
		return bestScore;
	}

	return 0;
}

int Minimax::Evaluate(char board[][SIDE])
{
	for (int row = 0; row < 3; row++)
	{
		if (board[row][0] == board[row][1] && board[row][1] == board[row][2])
		{
			if (board[row][0] == HUMANMOVE)	{
				return -10;
			}
			else if (board[row][0] == COMPUTERMOVE)	{
				return +10;
			}
		}
	}

	for (int col = 0; col < 3; col++)
	{
		if (board[0][col] == board[1][col] && board[1][col] == board[2][col])
		{
			if (board[0][col] == HUMANMOVE)	{
				return -10;
			}
			else if (board[0][col] == COMPUTERMOVE)	{
				return +10;
			}
		}
	}

	if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
	{
		if (board[0][0] == HUMANMOVE) {
			return -10;
		}
		else if (board[0][0] == COMPUTERMOVE) {
			return +10;
		}
	}

	if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
	{
		if (board[0][2] == HUMANMOVE) {
			return -10;
		}
		else if (board[0][2] == COMPUTERMOVE) {
			return +10;
		}
	}

	return 0;
}