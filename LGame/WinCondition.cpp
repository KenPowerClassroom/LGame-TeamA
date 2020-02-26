#include "WinCondition.h"

bool WinCondition::hasLost(const Board& t_board, char t_piece)
{
	std::vector<std::array<std::string, 4>> validLocations;
	validLocations.clear();

	for (int row = 0; row < 4; row++)
	{
		for (int column = 0; column < 4; column++)
		{
			if (CheckPositions::checkFree(row, column, t_board, t_piece))
			{
				CheckPositions::checkRows(t_board, row, column, validLocations, t_piece);
				CheckPositions::checkColumns(t_board, row, column, validLocations, t_piece);
			}
		}
	}

	if (validLocations.empty())
	{
		return true;
	}
	return false;
}
