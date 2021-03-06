#ifndef BOARD_H
#define BOARD_H

#include <string.h>
#include <array>
class Board
{
	char m_board[4][4]
	{	{'-', '-', '-', '-'},
		{'-', '-', '-', '-'},
		{'-', '-', '-', '-'},
		{'-', '-', '-', '-'}
	};

	const int c_ASCII_VALUE = 48;
	const int c_NUM_SPACES = 4;
public:
	void initializeBoard();
	char setCharacter(int t_row, int t_col, char t_symbol);
	const char getCharacter(int t_row, int t_col) const;

	void moveLPiece(std::array<std::string, 4> t_location, char t_piece);
};

#endif