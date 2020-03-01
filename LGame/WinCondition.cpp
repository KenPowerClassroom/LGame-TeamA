#include "WinCondition.h"

/// <summary>
/// goes through the entire board and saves all of the valid locations that either the player or the ai can go to
/// depending on who's turn it is
/// if it goes through the entire baord and cannot find any valid moves for that piece then it will return true to say that
/// they have lost
/// otherwise if there is at least one valid move for them to do it will return false
/// </summary>
/// <param name="t_board"></param>
/// <param name="t_piece">either 1 or 2 for the player or the ai</param>
/// <returns>return true if they lsot</returns>
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
