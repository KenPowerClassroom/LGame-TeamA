#include "SimpleAI.h"

bool SimpleAI::checkFree(int t_row, int t_col, const Board& t_board)
{
	if (t_row >= 0 && t_row < 4 && t_col >= 0 && t_col < 4)
	{
		return t_board.getCharacter(t_row, t_col) == '2' || t_board.getCharacter(t_row, t_col) == '-';
	}
	else
	{
		return false;
	}

}

void SimpleAI::setUpPositions(const Board& t_board)
{
	m_oldPositions = { "","","","" };
	m_newPositions = { "","","","" };
	m_validLocations.clear();

	int j = 0;
	int index = 0;
	for (int i = 0; i < 4; i++)
	{
		for (; j < 4; j++)
		{
			if (t_board.getCharacter(i, j) == '2')
			{
				m_oldPositions.at(index) = std::to_string(i) + std::to_string(j);
				if (index < 3)
				{
					index++;
				}
			}
		}
		j = 0;
	}

	m_newPositions = m_oldPositions;
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
	int count = 0;
	if (checkFree(t_row - 1, t_col, t_board) && checkFree(t_row - 2, t_col, t_board))
	{
		if (t_col > 0)
		{
			if (count < 4)
			{
				if (checkFree(t_row - 2, t_col - 1, t_board))
				{
					std::array<std::string, 4> position;

					position[0] = std::to_string(t_row) + std::to_string(t_col);
					position[1] = std::to_string(t_row - 1) + std::to_string(t_col);
					position[2] = std::to_string(t_row - 2) + std::to_string(t_col);
					position[3] = std::to_string(t_row - 2) + std::to_string(t_col - 1);
					m_validLocations.push_back(position);
				}
			}
		}
		if(t_col < 4)
		{
			if (checkFree(t_row - 2, t_col + 1, t_board))
			{
				std::array<std::string, 4> position;
				position[0] = std::to_string(t_row) + std::to_string(t_col);
				position[1] = std::to_string(t_row - 1) + std::to_string(t_col);
				position[2] = std::to_string(t_row - 2) + std::to_string(t_col);
				position[3] = std::to_string(t_row - 2) + std::to_string(t_col + 1);
				m_validLocations.push_back(position);
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
				std::array<std::string, 4> position;
				position[0] = std::to_string(t_row) + std::to_string(t_col);
				position[1] = std::to_string(t_row + 1) + std::to_string(t_col);
				position[2] = std::to_string(t_row + 2) + std::to_string(t_col);
				position[3] = std::to_string(t_row + 2) + std::to_string(t_col - 1);
				m_validLocations.push_back(position);
				
			}
		}
		if(t_col < 4)
		{
			if (checkFree(t_row + 2, t_col + 1, t_board))
			{
				std::array<std::string, 4> position;			
				position[0] = std::to_string(t_row) + std::to_string(t_col);
				position[1] = std::to_string(t_row + 1) + std::to_string(t_col);
				position[2] = std::to_string(t_row + 2) + std::to_string(t_col);
				position[3] = std::to_string(t_row + 2) + std::to_string(t_col + 1);
				m_validLocations.push_back(position);
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
	int count = 0;
	if (checkFree(t_row, t_col - 1, t_board) && checkFree(t_row, t_col - 2, t_board))
	{
		if (t_row > 0)
		{
			if (checkFree(t_row - 1, t_col - 2, t_board))
			{
				std::array<std::string, 4> position;
				position[0] = std::to_string(t_row) +
							std::to_string(t_col);
				position[1] = std::to_string(t_row) + std::to_string(t_col - 1);
				position[2] = std::to_string(t_row) + std::to_string(t_col - 2);
				position[3] = std::to_string(t_row - 1) + std::to_string(t_col - 2);
				m_validLocations.push_back(position);

			}
		}
		if(t_row < 4)
		{
			if (checkFree(t_row + 1, t_col - 2, t_board))
			{
				std::array<std::string, 4> position;
				position[0] = std::to_string(t_row) +
							std::to_string(t_col);
				position[1] = std::to_string(t_row) + std::to_string(t_col - 1);
				position[2] = std::to_string(t_row) + std::to_string(t_col - 2);
				position[3] = std::to_string(t_row + 1) + std::to_string(t_col - 2);
				m_validLocations.push_back(position);			
			}
		}
	}
	return false;
}

bool SimpleAI::checkRight(const Board& t_board, int t_row, int t_col)
{
	int count = 0;
	if (checkFree(t_row, t_col + 1, t_board) && checkFree(t_row, t_col + 2, t_board))
	{
		if (t_board.getCharacter(t_row, t_col + 1) == '2')
		{
			count++;
		}
		if (t_board.getCharacter(t_row, t_col + 2) == '2')
		{
			count++;
		}
		if (t_row > 0)
		{
			if (checkFree(t_row - 1, t_col + 2, t_board))
			{
				std::array<std::string, 4> position;
				position[0] = std::to_string(t_row) +
							std::to_string(t_col);
				position[1] = std::to_string(t_row) + std::to_string(t_col + 1);
				position[2] = std::to_string(t_row) + std::to_string(t_col + 2);
				position[3] = std::to_string(t_row - 1) + std::to_string(t_col + 2);
				m_validLocations.push_back(position);
			}
		}
		else
		{
			if (checkFree(t_row + 1, t_col + 2, t_board))
			{
				std::array<std::string, 4> position;
				position[0] = std::to_string(t_row) +
						std::to_string(t_col);
				position[1] = std::to_string(t_row) + std::to_string(t_col + 1);
				position[2] = std::to_string(t_row) + std::to_string(t_col + 2);
				position[3] = std::to_string(t_row + 1) + std::to_string(t_col + 2);
				m_validLocations.push_back(position);
			}
		}
	}
	return false;
}

bool SimpleAI::isEqual(std::array<std::string, 4> t_first, std::array<std::string, 4> t_second)
{
	for (int i = 0; i < 4; i++)
	{
		if (t_first.at(i) != t_second.at(i))
		{
			return false;
		}
	}
	return true;
}

std::array<std::string, 4> SimpleAI::movePiece(const Board & t_board)
{
	setUpPositions(t_board);

	for (int row = 0; row < 4; row++)
	{
		for (int column = 0; column < 4; column++)
		{
			if (checkFree(row, column, t_board))
			{
				checkRows(t_board, row, column);
				checkColumns(t_board, row, column);
			}
		}
	}

	if (!m_validLocations.empty())
	{
		int counter = 30; int count = 0; int random = 0;
		do
		{
			random = rand() % m_validLocations.size();
			count++;
		} while (isEqual(m_validLocations.at(random), m_oldPositions) && count < counter);
		for (int i = 0; i < 4; i++)
		{
			m_newPositions.at(i) = m_validLocations.at(random).at(i);
		}
	}
	return m_newPositions;
}

SimpleAI::SimpleAI()
{
	srand(1);
}
