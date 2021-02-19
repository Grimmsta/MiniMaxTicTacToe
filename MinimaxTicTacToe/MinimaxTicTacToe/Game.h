#pragma once
#include "TicTacToeVariables.h"	
#include "Move.h"
#include <algorithm>
#include <conio.h>
#include <time.h>
#include <iostream>

class Game
{
public:
	void DrawBoard();
	void DeclareWinner(int whoseTurn);
	void PlayGame(int whoseTurn);

	Move BestMove(char board[][SIDE]);

	char board[SIDE][SIDE] = { {'1','2','3'},
						       {'4','5','6'},
						       {'7','8','9'}
	};
};