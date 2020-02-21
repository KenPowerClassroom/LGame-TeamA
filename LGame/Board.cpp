#include "Board.h"
#include <iostream>

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

	m_board[0][0] = '(';
	m_board[3][3] = ')';
}

char Board::setCharacter(int t_row, int t_col, char t_symbol)
{
	return m_board[t_row][t_col] = t_symbol;
}

const char Board::getCharacter(int t_row, int t_col) const
{
	return m_board[t_row][t_col];
}

