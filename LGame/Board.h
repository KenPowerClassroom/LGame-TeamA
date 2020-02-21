#ifndef BOARD_H
#define BOARD_H

#include <string.h>

class Board
{
	char m_board[4][4]
	{	{'-', '-', '-', '-'},
		{'-', '-', '-', '-'},
		{'-', '-', '-', '-'},
		{'-', '-', '-', '-'}
	};

public:
	void initializeBoard();
	char setCharacter(int t_row, int t_col, char t_symbol);
	const char getCharacter(int t_row, int t_col) const;
};

#endif