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

/// <summary>
/// finds where the l piece currently is and removes all of these pieces from the board
/// it then puts the l piece at the positions from the array
/// has to minus the ascii value of zero from the characters to get the int form to place them
/// at the correct position
/// </summary>
/// <param name="t_location"></param>
/// <param name="t_piece"></param>
void Board::moveLPiece(std::array<std::string, 4> t_location, char t_piece)
{
	for (int row = 0; row < c_NUM_SPACES; row++)
	{
		for (int col = 0; col < c_NUM_SPACES; col++)
		{
			if (getCharacter(row, col) == t_piece)
			{
				m_board[row][col] = '-';
			}
		}
	}
	for (int i = 0; i < c_NUM_SPACES; ++i)
	{
		std::string location = t_location.at(i);
		m_board[location[0] - c_ASCII_VALUE][location[1] - c_ASCII_VALUE] = t_piece;
	}
}
