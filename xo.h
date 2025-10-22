#pragma once







class xo
{
public:
	xo();
	~xo();


	void printSymbol();
	void addTurn();

	int getTurn();

private: 
	struct boardInfo
	{
		const int pos[9] = { 1,2,3,4,5,6,7,8,9 };
		bool sym[9] = { 0 };
		bool type[9] = { 0 };
	};
	bool isX = true;
	int turn = 0;

};