#include "Board.h"

const char Board::getCharacter(int t_row, int t_col) const
{
	return m_board[t_row][t_col];
}
