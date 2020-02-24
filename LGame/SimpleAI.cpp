#include "SimpleAI.h"

bool checkFree(int t_row, int t_col, const Board& t_board)
{
	return t_board.getCharacter(t_row, t_col) == '2' || t_board.getCharacter(t_row, t_col) == '-';
}

void SimpleAI::setUpPositions(const Board& t_board)
{
	std::array<std::string, 4> oldLocations = { "","","","" };
	m_newPositions = { "","","","" };

	int j = 0;
	int index = 0;
	for (int i = 0; i < 4; i++)
	{
		for (; j < 4; j++)
		{
			if (t_board.getCharacter(i, j) == '2')
			{
				oldLocations.at(index) = std::to_string(i + 1) + std::to_string(j + 1);
				if (index < 3)
				{
					index++;
				}
			}
		}
		j = 0;
	}

	m_newPositions = oldLocations;
}

bool SimpleAI::checkRows(const Board& t_board, int t_row, int t_col)
{
	if (t_row > 1)
	{		
		return checkAbove(t_board, t_row, t_col);	
	}
	else if (t_row < 2)
	{
		return checkBelow(t_board, t_row, t_col);
	}
	return false;
}

bool SimpleAI::checkAbove(const Board& t_board, int t_row, int t_col)
{
	if (checkFree(t_row - 1, t_col, t_board) && checkFree(t_row - 2, t_col, t_board))
	{
		if (t_col > 0)
		{
			if (checkFree(t_row - 2, t_col - 1, t_board))
			{
				m_newPositions[0] = std::to_string(t_row) + std::to_string(t_col);
				m_newPositions[1] = std::to_string(t_row - 1) + std::to_string(t_col);
				m_newPositions[2] = std::to_string(t_row - 2) + std::to_string(t_col);
				m_newPositions[3] = std::to_string(t_row - 2) + std::to_string(t_col - 1);
				return true;
			}
		}
		else
		{
			if (checkFree(t_row - 2, t_col + 1, t_board))
			{
				m_newPositions[0] = std::to_string(t_row) + std::to_string(t_col);
				m_newPositions[1] = std::to_string(t_row - 1) + std::to_string(t_col);
				m_newPositions[2] = std::to_string(t_row - 2) + std::to_string(t_col);
				m_newPositions[3] = std::to_string(t_row - 2) + std::to_string(t_col + 1);
				return true;
			}
		}
	}
	return false;
}

bool SimpleAI::checkBelow(const Board& t_board, int t_row, int t_col)
{
	if (checkFree(t_row + 1, t_col, t_board) && checkFree(t_row + 2, t_col, t_board))
	{
		if (t_col > 0)
		{
			if (checkFree(t_row + 2, t_col - 1, t_board))
			{
				m_newPositions[0] = std::to_string(t_row) + std::to_string(t_col);
				m_newPositions[1] = std::to_string(t_row + 1) + std::to_string(t_col);
				m_newPositions[2] = std::to_string(t_row + 2) + std::to_string(t_col);
				m_newPositions[3] = std::to_string(t_row + 2) + std::to_string(t_col - 1);
				return true;
			}
		}
		else
		{
			if (checkFree(t_row + 2, t_col + 1, t_board))
			{
				m_newPositions[0] = std::to_string(t_row) + std::to_string(t_col);
				m_newPositions[1] = std::to_string(t_row + 1) + std::to_string(t_col);
				m_newPositions[2] = std::to_string(t_row + 2) + std::to_string(t_col);
				m_newPositions[3] = std::to_string(t_row + 2) + std::to_string(t_col + 1);
				return true;
			}
		}
	}
	return false;
}

bool SimpleAI::checkColumns(const Board& t_board, int t_row, int t_col)
{
	if (t_col > 1)
	{
		checkLeft(t_board, t_row, t_col);
	}
	else if (t_col < 2)
	{
		checkRight(t_board, t_row, t_col);
	}
	return false;
}

bool SimpleAI::checkLeft(const Board& t_board, int t_row, int t_col)
{
	if (checkFree(t_row, t_col - 1, t_board) && checkFree(t_row, t_col - 2, t_board))
	{
		if (t_row > 0)
		{
			if (checkFree(t_row, t_col - 1, t_board))
			{
				m_newPositions[0] = std::to_string(t_row) +
					std::to_string(t_col);
				m_newPositions[1] = std::to_string(t_row) + std::to_string(t_col - 1);
				m_newPositions[2] = std::to_string(t_row) + std::to_string(t_col - 2);
				m_newPositions[3] = std::to_string(t_row - 1) + std::to_string(t_col - 2);
				return true;
			}
		}
		else
		{
			if (checkFree(t_row + 1, t_col - 2, t_board))
			{
				m_newPositions[0] = std::to_string(t_row) +
					std::to_string(t_col);
				m_newPositions[1] = std::to_string(t_row) + std::to_string(t_col - 1);
				m_newPositions[2] = std::to_string(t_row) + std::to_string(t_col - 2);
				m_newPositions[3] = std::to_string(t_row + 1) + std::to_string(t_col - 2);
				return true;
			}
		}
	}
	return false;
}

bool SimpleAI::checkRight(const Board& t_board, int t_row, int t_col)
{
	if (checkFree(t_row, t_col + 1, t_board) && checkFree(t_row, t_col + 2, t_board))
	{
		if (t_row > 0)
		{
			if (checkFree(t_row - 1, t_col + 2, t_board))
			{
				m_newPositions[0] = std::to_string(t_row) +
					std::to_string(t_col);
				m_newPositions[1] = std::to_string(t_row) + std::to_string(t_col + 1);
				m_newPositions[2] = std::to_string(t_row) + std::to_string(t_col + 2);
				m_newPositions[3] = std::to_string(t_row - 1) + std::to_string(t_col + 2);
				return true;
			}
		}
		else
		{
			if (checkFree(t_row + 1, t_col + 2, t_board))
			{
				m_newPositions[0] = std::to_string(t_row) +
					std::to_string(t_col);
				m_newPositions[1] = std::to_string(t_row) + std::to_string(t_col + 1);
				m_newPositions[2] = std::to_string(t_row) + std::to_string(t_col + 2);
				m_newPositions[3] = std::to_string(t_row + 1) + std::to_string(t_col + 2);
				return true;
			}
		}
	}
	return false;
}

std::array<std::string, 4> SimpleAI::movePiece(const Board & t_board)
{
	setUpPositions(t_board);

	for (int row = 0; row < 4; row++)
	{
		for (int column = 0; column < 4; column++)
		{
			if (checkFree(row , column, t_board))
			{
				if (checkRows(t_board, row, column))
				{
					break;
				}

				if (checkColumns(t_board, row, column))
				{
					break;
				}	
			}
		}
		return m_newPositions;
	}
}
