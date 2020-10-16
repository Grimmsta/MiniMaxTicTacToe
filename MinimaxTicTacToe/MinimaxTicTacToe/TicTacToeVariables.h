#pragma once
#include <time.h>
#include <algorithm>
#include <conio.h>
#include <iostream>

#define COMPUTER 1
#define HUMAN 2

#define SIDE 3

#define COMPUTERMOVE 'O'
#define HUMANMOVE 'X'

struct Move
{
	int row, col;
};

class Game {
public:
	void ShowBoard();
	void Initialize(int moves[]);
	void DeclareWinner(int whoseTurn);
	void PlayGame(int whoseTurn);

	bool ColumnCrossed(char board[][SIDE]);
	bool RowCrossed(char board[][SIDE]);
	bool DiagonalCrossed(char board[][SIDE]);
	bool GameOver(char board[][SIDE]);

	int Evaluate(char board[][SIDE]);
	int Minimax(char board[][SIDE], int depth, bool isMax);

	Move BestMove(char board[][SIDE]);

	char board[SIDE][SIDE] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };
	int moves[SIDE * SIDE];
};