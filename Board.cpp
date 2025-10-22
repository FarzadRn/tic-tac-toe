#include "Board.h"


Board::Board()
{
	for (int i = 0; i != 3; ++i)
	{
		for (int j = 0; j != 3; ++j)
		{
			grid[i][j] = ' ';
		}
	}
}

void Board::setGridPos(int inputPos, char sym)
{
	//-1 lets 1 to 9  | instead of 0 to 8
	*findPos(inputPos - 1) = sym;
}

void Board::printBoard()
{
	int everyOther = 0;
	for (int i = 0; i != 3; ++i)
	{
		for (int j = 0; j != 3; ++j)
		{
			std::cout << grid[i][j] << ' ';
			if (j != 2)
			{
				std::cout << char(219) << ' ';
			}
		}
		std::cout << '\n';
		if (i != 2)
		{
			for (int j = 0; j != 9; ++j)
			{
				std::cout << char(219);
			}
			std::cout << '\n';
		}
	}
}

char Board::findWinner()
{
	char threeInRow[3];
	//rows
	for (int i = 0; i != 3; ++i)
	{
		for (int j = 0; j != 3; ++j)
		{
			threeInRow[j] = grid[i][j];
		}
		if (threeInRow[0] == 'X' && threeInRow[1] == 'X' && threeInRow[2] == 'X')
		{
			return 'X';
		}
		if (threeInRow[0] == 'O' && threeInRow[1] == 'O' && threeInRow[2] == 'O')
		{
			return 'O';
		}
		//refresh threeInRow
		for (int i = 0; i != 3; ++i)
		{
			threeInRow[i] = ' ';
		}
	}

	//columns
	for (int i = 0; i != 3; ++i)
	{
		for (int j = 0; j != 0; ++j)
		{
			threeInRow[j] = grid[j][i];
		}
		if (threeInRow[0] == 'X' && threeInRow[1] == 'X' && threeInRow[2] == 'X')
		{
			return 'X';
		}
		if (threeInRow[0] == 'O' && threeInRow[1] == 'O' && threeInRow[2] == 'O')
		{
			return 'O';
		}
		//refresh threeInRow
		for (int i = 0; i != 3; ++i)
		{
			threeInRow[i] = ' ';
		}

	}

	//diagonals
	//left to right
	if (grid[0][0] == 'X' && grid[1][1] == 'X' && grid[2][2] == 'X')
	{
		return 'X';
	}
	if (grid[0][0] == 'O' && grid[1][1] == 'O' && grid[2][2] == 'O')
	{
		return 'O';
	}
	//right to left
	if (grid[0][2] == 'X' && grid[1][1] == 'X' && grid[2][0] == 'X')
	{
		return 'X';
	}
	if (grid[0][2] == 'O' && grid[1][1] == 'O' && grid[2][0] == 'O')
	{
		return 'O';
	}
	return 'N';
}

char* Board::findPos(int inputPos)
{
	if (inputPos < 0 && inputPos > 8)
	{
		std::cout << "wrong inputPos somehow\n";
	}
	else
	{
		return &grid[0][0] + inputPos;
	}
}