#include "SimpleAI.h"

/// <summary>
/// resets both the old positions and the new positions
/// it will then set up the old positions with the positions that the l piece is currently in
/// before it figures out where all of the valid moves are located
/// it stores the old locations so it can check that the l piece isn't going to go back to where it previously was
/// </summary>
/// <param name="t_board">takes in the board to find where the l piece is</param>
void SimpleAI::setUpPositions(const Board& t_board)
{
	m_oldPositions = { "","","","" };
	m_newPositions = { "","","","" };

	m_validLocations.clear();

	int index = 0;
	for (int row = 0; row < 4; row++)
	{
		for (int column = 0; column < 4; column++)
		{
			if (t_board.getCharacter(row, column) == c_PIECE)
			{
				m_oldPositions.at(index) = std::to_string(row) + std::to_string(column);
				if (index < 3)
				{
					index++;
				}
			}
		}
	}

	m_newPositions = m_oldPositions;
}

/// <summary>
/// tries to see if any of the valid locations that the AI has found is equal to the position that it started off at
/// if it is the same as the original position then it will erase this from the vector
/// </summary>
void SimpleAI::findOriginalPosition()
{
	for (int row = 0; row < m_validLocations.size(); row++)
	{
		if (m_validLocations.at(row) == m_oldPositions)
		{
			for (int column = 0; row < m_validLocations.at(row).size(); column++)
			{
				if (m_validLocations.at(row).at(column) != m_oldPositions.at(column))
				{
					continue;
				}
			}
			m_validLocations.erase(m_validLocations.begin() + row);
		}
	}
}

/// <summary>
/// picks a random position out of the positions that it found
/// only picks the position if the array has something in it
/// the ai should only be called if there is a valid move but it still checks if the vector is empty in case there
/// was an error
/// </summary>
void SimpleAI::pickRandomPosition()
{
	if (!m_validLocations.empty())
	{
		int random = 0;
		random = rand() % m_validLocations.size();

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
			if (CheckPositions::checkFree(row, column, t_board, c_PIECE))
			{
				CheckPositions::checkRows(t_board, row, column, m_validLocations, c_PIECE);
				CheckPositions::checkColumns(t_board, row, column, m_validLocations, c_PIECE);
			}
		}
	}

	pickRandomPosition();
	return m_newPositions;
}

SimpleAI::SimpleAI() : c_PIECE{ '2' }
{
	srand(time(NULL));
}

SimpleAI::SimpleAI(const char t_piece) : c_PIECE{ t_piece }
{
	srand(1);
}
