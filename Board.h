#pragma once
#include <iostream>





class Board
{
public:
	Board();

	void printBoard(); 
	void setGridPos(int inputPos, char sym);
	char findWinner();

private:
	//helper
	char* findPos(int inputPos);
	char grid[3][3];

};