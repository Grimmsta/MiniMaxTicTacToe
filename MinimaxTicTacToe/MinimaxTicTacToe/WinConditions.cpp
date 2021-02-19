#include "WinConditions.h"

bool WinConditions::ColumnCrossed(char board[][SIDE])
{
	for (int i = 0; i < SIDE; i++)
	{
		if (board[0][i] == board[1][i] &&
			board[1][i] == board[2][i] &&
			board[0][i] != ' ')	{
			return true;
		}
	}

	return false;
}

bool WinConditions::RowCrossed(char board[][SIDE])
{
	for (int i = 0; i < SIDE; i++)
	{
		if (board[i][0] == board[i][1] &&
			board[i][1] == board[i][2] &&
			board[i][0] != ' ') {
			return true;
		}
	}

	return false;
}

bool WinConditions::DiagonalCrossed(char board[][SIDE])
{
	if (board[0][0] == board[1][1] &&
		board[1][1] == board[2][2] &&
		board[0][0] != ' ')	{
		return true;
	}

	if (board[0][2] == board[1][1] &&
		board[1][1] == board[2][0] &&
		board[0][2] != ' ')	{
		return true;
	}

	return false;
}

bool WinConditions::GameOver(char board[][SIDE])
{
	return RowCrossed(board) || ColumnCrossed(board) || DiagonalCrossed(board);
}