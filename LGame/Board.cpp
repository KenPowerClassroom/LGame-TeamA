#include "Board.h"

void Board::initializeBoard()
{
	m_board[0][1] = '1';
	m_board[0][2] = '1';
	m_board[1][2] = '1';
	m_board[2][2] = '1';

	m_board[1][1] = '2';
	m_board[2][1] = '2';
	m_board[3][1] = '2';
	m_board[3][2] = '2';
}

const char Board::getCharacter(int t_row, int t_col) const
{
	return m_board[t_row][t_col];
}
