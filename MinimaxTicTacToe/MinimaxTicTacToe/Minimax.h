#pragma once

#include "TicTacToeVariables.h"
class Minimax
{
public:
	int minimax(char board[][SIDE], int depth, bool isMax);

private:
	int Evaluate(char board[][SIDE]);
};