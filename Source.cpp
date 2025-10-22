#include "Board.h"

int main()
{
	Board currentBoard;
	int turns = 0;
	//E for error
	char symbol = 'E';
	while (turns < 9)
	{
		currentBoard.printBoard();

		if (turns % 2)
		{
			std::cout << "Player 2-O choose 1-9\n";
			symbol = 'O';
		}
		else
		{
			std::cout << "Player 1-X choose 1-9\n";
			symbol = 'X';
		}
		int input;
	
		while (true)
		{
			std::cin >> input;
			currentBoard.setGridPos(input, symbol);
			if (input <= 9 && input >= 1)
			{
				break;
			}
			else 
			{
				std::cout << "I'm deeply disapointed in you... try again: " << std::endl;
			}
		}
		if (currentBoard.findWinner() != 'N')
		{
			if (currentBoard.findWinner() == 'X')
			{
				currentBoard.printBoard();
				std::cout << "PLAYER 1-X WON!!!\n";
				break;
			}
			if (currentBoard.findWinner() == 'X')
			{
				currentBoard.printBoard();
				std::cout << "PLAYER 2-O WON!!!\n";
				break;
			}
		}
		turns++;
	}
	if (turns > 8)
	{
		std::cout << "welp, that's a draw. try again! :)\n";
	}

	return 0;
}