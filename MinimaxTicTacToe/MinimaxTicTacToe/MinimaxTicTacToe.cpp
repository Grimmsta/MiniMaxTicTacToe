#include <iostream>
#include "TicTacToeVariables.h"

void Game::ShowBoard() {
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

void Game::Initialize(int moves[]) {

	for (int i = 0; i < SIDE * SIDE; i++)
	{
		moves[i] = i;
	}
	return;
}

void Game::DeclareWinner(int whoseTurn)
{
	if (whoseTurn == COMPUTER)
	{
		printf("Computer won!");
	}
	else
	{
		printf("You won!");
	}
	return;
}

void Game::PlayGame(int whoseTurn)
{
	Initialize(moves);
	ShowBoard();
	int moveIndex = 0;

	while (GameOver(board) == false && moveIndex != SIDE * SIDE)
	{
		if (whoseTurn == COMPUTER)
		{
			Move bestMove = BestMove(board);
			board[bestMove.row][bestMove.col] = COMPUTERMOVE;
			system("cls");
			ShowBoard();
			printf("COMPUTER has put a %c in cell %d\n",
				COMPUTERMOVE, moves[moveIndex] + 1);
			moveIndex++;
			whoseTurn = HUMAN;
		}
		else if (whoseTurn == HUMAN)
		{
			int a;
			std::cin >> a;
			a--;
			if (a >= 0 && a <=8)
			{
				//TODO: Check that input is a number
				board[a / SIDE][a % SIDE] = HUMANMOVE;
				system("cls");
				ShowBoard();
				moveIndex++;
				whoseTurn = COMPUTER;
			}
			else
			{
				printf("Please chose a number between 1 and 9: ");
			}
		}
	}

	if (GameOver(board) == false && moveIndex == SIDE * SIDE)
	{
		printf("It's a tie!");
	}
	else
	{
		if (whoseTurn == COMPUTER)
			whoseTurn = HUMAN;
		else if (whoseTurn == HUMAN)
			whoseTurn = COMPUTER;

		DeclareWinner(whoseTurn);
	}
}

int Game::Evaluate(char b[][SIDE])
{
	for (int row = 0; row < 3; row++)
	{
		if (b[row][0] == b[row][1] && b[row][1] == b[row][2])
		{
			if (b[row][0] == HUMANMOVE)
			{
				return -10;
			}
			else if (b[row][0] == COMPUTERMOVE)
			{
				return +10;
			}
		}
	}

	for (int col = 0; col < 3; col++)
	{
		if (b[0][col] == b[1][col] && b[1][col] == b[2][col])
		{
			if (b[0][col] == HUMANMOVE)
			{
				return -10;
			}
			else if (b[0][col] == COMPUTERMOVE)
			{
				return +10;
			}
		}
	}

	if (b[0][0] == b[1][1] && b[1][1] == b[2][2])
	{
		if (b[0][0] == HUMANMOVE)
		{
			return -10;
		}
		else if (b[0][0] == COMPUTERMOVE)
		{
			return +10;
		}
	}

	if (b[0][2] == b[1][1] && b[1][1] == b[2][0])
	{
		if (b[0][2] == HUMANMOVE)
		{
			return -10;
		}
		else if (b[0][2] == COMPUTERMOVE)
		{
			return +10;
		}
	}

	return 0;
}

int Game::Minimax(char board[][SIDE], int depth, bool isMax)
{
	int startScore = Evaluate(board);

	if (startScore == 10)
	{
		return startScore;
	}

	if (startScore == -10)
	{
		return startScore;
	}

	if (GameOver(board) == true)
	{
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
					int score = Minimax(board, depth + 1, false);
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
					int score = Minimax(board, depth + 1, true);
					board[i][j] = num;
					bestScore = std::min(score, bestScore);
				}
			}
		}
		return bestScore;
	}

	return 0;
}

Move Game::BestMove(char board[][SIDE])
{
	int bestValue = -1000;
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
				int moveValue = Minimax(board, 0, false);
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

bool Game::ColumnCrossed(char board[][SIDE])
{
	for (int i = 0; i < SIDE; i++)
	{
		if (board[0][i] == board[1][i] &&
			board[1][i] == board[2][i] &&
			board[0][i] != ' ')
			return true;
	}
	return false;
}

bool Game::RowCrossed(char board[][SIDE])
{
	for (int i = 0; i < SIDE; i++)
	{
		if (board[i][0] == board[i][1] &&
			board[i][1] == board[i][2] &&
			board[i][0] != ' ')
			return true;
	}
	return false;
}

bool Game::DiagonalCrossed(char board[][SIDE])
{
	if (board[0][0] == board[1][1] &&
		board[1][1] == board[2][2] &&
		board[0][0] != ' ')
		return true;

	if (board[0][2] == board[1][1] &&
		board[1][1] == board[2][0] &&
		board[0][2] != ' ')
		return true;
	return false;
}

bool Game::GameOver(char board[][SIDE])
{
	return RowCrossed(board) || ColumnCrossed(board) || DiagonalCrossed(board);
}


int main()
{
	Game game;
	game.PlayGame(COMPUTER);
	return 0;
}
