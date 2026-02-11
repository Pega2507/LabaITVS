
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
using namespace std;

const int BOARD_SIZE = 30;


void InitBoard(bool board[BOARD_SIZE][BOARD_SIZE]);
void PrintCell(bool cell);
void PrintBoard(bool board[BOARD_SIZE][BOARD_SIZE]);
void UpdateBoard(bool board1[BOARD_SIZE][BOARD_SIZE], bool board2[BOARD_SIZE][BOARD_SIZE]);
void CheckIfAlive(bool board1[BOARD_SIZE][BOARD_SIZE], bool board2[BOARD_SIZE][BOARD_SIZE]);


int main()
{

	bool board1[BOARD_SIZE][BOARD_SIZE] = { 0 };
	bool board2[BOARD_SIZE][BOARD_SIZE] = { 0 };

	InitBoard(board1);
	//PrintBoard(board1);
	//cout << endl << endl;

	while (true) 
	{
		CheckIfAlive(board1, board2);
		UpdateBoard(board1, board2);
		PrintBoard(board1);
		Sleep(500);
		//system("pause");
		system("cls");
	}


}

// Functions declarations
/*******************************************/


//void InitBoard(bool board[BOARD_SIZE][BOARD_SIZE])
//{
//	board[4][2] = true;
//	board[4][3] = true;
//	board[4][4] = true;
//}
void InitBoard(bool board[BOARD_SIZE][BOARD_SIZE])
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			board[i][j] = (rand() % 3 == 0);	// ... % x - alive cell density
		}
	}
}

void PrintCell(bool cell)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	if (cell) // ==1, is alive
	{
		SetConsoleTextAttribute(hConsole,BACKGROUND_GREEN | BACKGROUND_INTENSITY);
	}
	else
	{
		SetConsoleTextAttribute(hConsole, 0);
	}

	cout << "  ";

	// color reset
	SetConsoleTextAttribute(hConsole,FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void PrintBoard(bool board[BOARD_SIZE][BOARD_SIZE])
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			PrintCell(board[i][j]);
		}
		cout << endl;
	}
}

void UpdateBoard(bool board1[BOARD_SIZE][BOARD_SIZE], bool board2[BOARD_SIZE][BOARD_SIZE])
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			board1[i][j] = board2[i][j];
		}
	}
}


void CheckIfAlive(bool board1[BOARD_SIZE][BOARD_SIZE], bool board2[BOARD_SIZE][BOARD_SIZE])
{
	for (int x = 0; x < BOARD_SIZE; x++)
	{
		for (int y = 0; y < BOARD_SIZE; y++)
		{
			int aliveNeighbours = 0; 

			for (int i = -1; i <= 1; i++)
			{
				for (int j = -1; j <= 1; j++)
				{
					if (i == 0 && j == 0) continue; // Skip the cell itself
					int neighbourX = x + i;
					int neighbourY = y + j;
					if (neighbourX >= 0 && neighbourX < BOARD_SIZE && neighbourY >= 0 && neighbourY < BOARD_SIZE)
					{
						if (board1[neighbourX][neighbourY]) aliveNeighbours++;
					}
				}
			}

			if ((aliveNeighbours == 2 || aliveNeighbours == 3) && board1[x][y] == true)
			{
				board2[x][y] = true;			// Cell lives on to the next generation
			}
			else if (aliveNeighbours == 3)
			{
				board2[x][y] = true; // Cell becomes alive if it has exactly 3 live neighbors
			}
			else
			{
				board2[x][y] = false; // Cell dies or remains dead
			}


		}
	}
}