#pragma once

#include "TicTacToeVariables.h"

class WinConditions
{
public:
	bool GameOver(char board[][SIDE]);
private:
	bool ColumnCrossed(char board[][SIDE]);
	bool RowCrossed(char board[][SIDE]);
	bool DiagonalCrossed(char board[][SIDE]);
};