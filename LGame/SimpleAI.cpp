#include "SimpleAI.h"

bool checkFree(int t_row, int t_col, const Board& t_board)
{
	return t_board.getCharacter(t_row, t_col) == '2' || t_board.getCharacter(t_row, t_col) == '-';
}

std::array<std::string, 4> SimpleAI::movePiece(const Board&  t_board)
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
	
	j = 0;
	for (int row = 0; row < 4; row++)
	{
		for (; j < 4; j++)
		{
			if (t_board.getCharacter(row, j) == '2' || t_board.getCharacter(row, j) == '-')
			{
				if (checkFreeSpace(row, j, t_board, oldLocations))
				{
					break;
				}
			}
		}
	}
	
	return m_newPositions;
}

bool SimpleAI::checkFreeSpace(int t_row, int t_col, const Board& t_board, std::array<std::string,4> t_oldPositions)
{
	std::array<std::string, 4> locations = t_oldPositions;
	locations.at(0) = std::to_string(t_row + 1) + std::to_string(t_col + 1);
	if (t_row > 1)
	{
		if(t_board.getCharacter(t_row - 1, t_col) == '2'
			|| t_board.getCharacter(t_row - 1, t_col) == '-')
		{
			if (t_row - 2 > 0)
			{
				if (t_board.getCharacter(t_row - 2, t_col) == '2'
					|| t_board.getCharacter(t_row - 2, t_col) == '-')
				{
					locations.at(1) = std::to_string(t_row) + std::to_string(t_col + 1);
					locations.at(2) = std::to_string(t_row - 1) + std::to_string(t_col + 1);
					if (t_board.getCharacter(t_row - 2, t_col - 1) == '2'
						|| t_board.getCharacter(t_row - 2, t_col - 1) == '-')
					{
						locations.at(3) = std::to_string(t_row - 1) + std::to_string(t_col);
					}
					else if (t_board.getCharacter(t_row - 2, t_col + 1) == '2' 
						|| t_board.getCharacter(t_row - 2, t_col + 1) == '-')
					{
						locations.at(3) = std::to_string(t_row - 1) + std::to_string(t_col + 1);
					}
				}
			}
		}
	}
	if (t_row < 2)
	{
		if (t_board.getCharacter(t_row + 1, t_col) == '2'
			|| t_board.getCharacter(t_row + 1, t_col) == '-')
		{
			if (t_row + 2 < 4)
			{
				if (t_board.getCharacter(t_row + 2, t_col) == '2' || t_board.getCharacter(t_row + 2, t_col) == '-')
				{
					locations.at(1) = std::to_string(t_row) + std::to_string(t_col + 1);
					locations.at(2) = std::to_string(t_row - 1) + std::to_string(t_col + 1);

					if (t_board.getCharacter(t_row + 2, t_col - 1) == '2' || t_board.getCharacter(t_row + 2, t_col - 1) == '-')
					{
						locations.at(3) = std::to_string(t_row - 1) + std::to_string(t_col);
					}
					else if (t_board.getCharacter(t_row + 2, t_col + 1) == '2'
						|| t_board.getCharacter(t_row + 2, t_col + 1) == '-')
					{
						locations.at(3) = std::to_string(t_row - 1) + std::to_string(t_col + 1);
					}
				}
			}
		}
	}
	if (t_col > 1)
	{
		if (t_board.getCharacter(t_row, t_col - 1) == '2' || t_board.getCharacter(t_row, t_col - 1) == '-')
		{
			if (t_col - 2 > 0)
			{
				if (t_board.getCharacter(t_row, t_col - 2) == '2' || t_board.getCharacter(t_row, t_col - 2) == '-')
				{
					locations.at(1) = std::to_string(t_row + 1) + std::to_string(t_col);
					locations.at(2) = std::to_string(t_row + 1) + std::to_string(t_col - 1);

					if (t_board.getCharacter(t_row - 1, t_col - 2) == '2' || t_board.getCharacter(t_row - 1, t_col - 2) == '-')
					{
						locations.at(3) = std::to_string(t_row) + std::to_string(t_col - 1);
					}
					else if (t_board.getCharacter(t_row + 1, t_col - 2) == '2'
						|| t_board.getCharacter(t_row + 1, t_col - 2) == '-')
					{
						locations.at(3) = std::to_string(t_row + 1) + std::to_string(t_col - 1);
					}
				}
			}
		}
	}
	if (t_col < 2)
	{
		if (t_board.getCharacter(t_row, t_col - 1) == '2' || t_board.getCharacter(t_row, t_col - 1) == '-')
		{
			if (t_col + 2 < 4)
			{
				if (t_board.getCharacter(t_row, t_col - 2) == '2' || t_board.getCharacter(t_row, t_col - 2) == '-')
				{
					locations.at(1) = std::to_string(t_row + 1) + std::to_string(t_col);
					locations.at(2) = std::to_string(t_row + 1) + std::to_string(t_col - 1);
				    if (t_board.getCharacter(t_row - 1, t_col - 2) == '2' || t_board.getCharacter(t_row - 1, t_col - 2) == '-')
					{
						locations.at(3) = std::to_string(t_row) + std::to_string(t_col - 1);
					}
					else if (t_board.getCharacter(t_row + 1, t_col - 2) == '2' 
						|| t_board.getCharacter(t_row + 1, t_col - 2) == '-')
					{
						locations.at(3) = std::to_string(t_row + 1) + std::to_string(t_col - 1);
					}
				}
			}
		}
	}
	for (int i = 0; i < 4; i++)
	{
		m_newPositions.at(i) = locations.at(i);
	}
	return locations == t_oldPositions;
}
