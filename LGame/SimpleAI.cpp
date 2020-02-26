#include "SimpleAI.h"

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

void SimpleAI::pickRandomPosition()
{
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
}

std::array<std::string, 4> SimpleAI::movePiece(const Board & t_board)
{
	setUpPositions(t_board);

	for (int row = 0; row < 4; row++)
	{
		for (int column = 0; column < 4; column++)
		{
			if (CheckPositions::checkFree(row,column,t_board,'2'))
			{
				CheckPositions::checkRows(t_board, row, column, m_validLocations,'2');
				CheckPositions::checkColumns(t_board, row, column, m_validLocations,'2');
			}
		}
	}

	pickRandomPosition();
	return m_newPositions;
}

SimpleAI::SimpleAI()
{
	srand(1);
}
