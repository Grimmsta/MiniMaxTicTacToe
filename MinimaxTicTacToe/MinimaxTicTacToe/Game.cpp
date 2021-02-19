#include <iostream>
#include "Game.h"
#include "TicTacToeVariables.h"
#include "Minimax.h"
#include "WinConditions.h"

void Game::DrawBoard() {
	std::cout << "\t\t\t" << "Tic-Tac-Toe\n\n";
	printf("Choose a cell numbered from 1 to 9 as below"
		" and play\n\n");

	for (int i = 0; i < SIDE; i++)
	{
		for (int j = 0; j < SIDE; j++)
		{
			std::cout << "| " << board[i][j] << " | ";
		}
		printf("\n------------------\n");

		std::cout << std::endl;
	}
	return;
}

void Game::DeclareWinner(int whoseTurn)
{
	if (whoseTurn == COMPUTER) {
		printf("Computer won!");
	}
	else {
		printf("You won!");
	}
	return;
}

void Game::PlayGame(int whoseTurn)
{
	DrawBoard();
	int moveIndex = 0;
	WinConditions winCond;

	while (winCond.GameOver(board) == false && moveIndex != SIDE * SIDE)
	{
		if (whoseTurn == COMPUTER)
		{
			Move bestMove = BestMove(board);
			board[bestMove.row][bestMove.col] = COMPUTERMOVE;
			system("cls");
			DrawBoard();
			moveIndex++;
			whoseTurn = HUMAN;
		}
		else if (whoseTurn == HUMAN)
		{
			int a;
			std::cin >> a;
			a--;

			if (a >= 0 && a <= 8)
			{
				if (board[a / SIDE][a % SIDE] != COMPUTERMOVE)
				{
					board[a / SIDE][a % SIDE] = HUMANMOVE;
					system("cls");
					DrawBoard();
					moveIndex++;
					whoseTurn = COMPUTER;
				}
				else {
					printf("That space is occupied\n");
				}
			}
			else {
				printf("Please chose a number between 1 and 9: ");
			}
		}
	}

	if (winCond.GameOver(board) == false && moveIndex == SIDE * SIDE) {
		printf("It's a tie!");
	}
	else
	{
		if (whoseTurn == COMPUTER) {
			whoseTurn = HUMAN;
		}
		else if (whoseTurn == HUMAN) {
			whoseTurn = COMPUTER;
		}

		DeclareWinner(whoseTurn);
	}
}

Move Game::BestMove(char board[][SIDE])
{
	int bestValue = -1000;
	Minimax mm;
	Move bestMove;
	
	bestMove.row = -1;
	bestMove.col = -1;

	for (int i = 0; i < SIDE; i++)
	{
		for (int j = 0; j < SIDE; j++)
		{
			if (board[i][j] != HUMANMOVE && board[i][j] != COMPUTERMOVE)
			{
				char num = board[i][j];
				board[i][j] = COMPUTERMOVE;
				int moveValue = mm.minimax(board, 0, false);
				board[i][j] = num;

				if (moveValue > bestValue)
				{
					bestValue = moveValue;
					bestMove.row = i;
					bestMove.col = j;
				}
			}
		}
	}

	return bestMove;
}