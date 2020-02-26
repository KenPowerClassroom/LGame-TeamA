#include "CheckPositions.h"

bool CheckPositions::checkRows(const Board& t_board, int t_row, int t_col,
	std::vector<std::array<std::string, 4>> & t_validLocations, char t_piece)
{
	if (t_row > 1)
	{
		return checkAbove(t_board, t_row, t_col, t_validLocations,t_piece);
	}
	else if (t_row < 2)
	{
		return checkBelow(t_board, t_row, t_col, t_validLocations,t_piece);
	}
	return false;
}

bool CheckPositions::checkAbove(const Board& t_board, int t_row, int t_col,
	std::vector<std::array<std::string, 4>> & t_validLocations, char t_piece)
{
	int count = 0;
	if (checkFree(t_row - 1, t_col, t_board,t_piece) && checkFree(t_row - 2, t_col, t_board,t_piece))
	{
		if (t_col > 0)
		{
			if (count < 4)
			{
				if (checkFree(t_row - 2, t_col - 1, t_board,t_piece))
				{
					std::array<std::string, 4> position;

					position[0] = std::to_string(t_row) + std::to_string(t_col);
					position[1] = std::to_string(t_row - 1) + std::to_string(t_col);
					position[2] = std::to_string(t_row - 2) + std::to_string(t_col);
					position[3] = std::to_string(t_row - 2) + std::to_string(t_col - 1);
					t_validLocations.push_back(position);
				}
			}
		}
		if (t_col < 4)
		{
			if (checkFree(t_row - 2, t_col + 1, t_board,t_piece))
			{
				std::array<std::string, 4> position;
				position[0] = std::to_string(t_row) + std::to_string(t_col);
				position[1] = std::to_string(t_row - 1) + std::to_string(t_col);
				position[2] = std::to_string(t_row - 2) + std::to_string(t_col);
				position[3] = std::to_string(t_row - 2) + std::to_string(t_col + 1);
				t_validLocations.push_back(position);
			}
		}
	}
	return false;
}

bool CheckPositions::checkBelow(const Board& t_board, int t_row, int t_col,
	std::vector<std::array<std::string, 4>> & t_validLocations, char t_piece)
{
	if (checkFree(t_row + 1, t_col, t_board,t_piece) && checkFree(t_row + 2, t_col, t_board,t_piece))
	{
		if (t_col > 0)
		{
			if (checkFree(t_row + 2, t_col - 1, t_board,t_piece))
			{
				std::array<std::string, 4> position;
				position[0] = std::to_string(t_row) + std::to_string(t_col);
				position[1] = std::to_string(t_row + 1) + std::to_string(t_col);
				position[2] = std::to_string(t_row + 2) + std::to_string(t_col);
				position[3] = std::to_string(t_row + 2) + std::to_string(t_col - 1);
				t_validLocations.push_back(position);

			}
		}
		if (t_col < 4)
		{
			if (checkFree(t_row + 2, t_col + 1, t_board,t_piece))
			{
				std::array<std::string, 4> position;
				position[0] = std::to_string(t_row) + std::to_string(t_col);
				position[1] = std::to_string(t_row + 1) + std::to_string(t_col);
				position[2] = std::to_string(t_row + 2) + std::to_string(t_col);
				position[3] = std::to_string(t_row + 2) + std::to_string(t_col + 1);
				t_validLocations.push_back(position);
			}
		}
	}
	return false;
}

bool CheckPositions::checkColumns(const Board& t_board, int t_row, int t_col,
	std::vector<std::array<std::string, 4>> & t_validLocations, char t_piece)
{
	if (t_col > 1)
	{
		checkLeft(t_board, t_row, t_col, t_validLocations,t_piece);
	}
	else if (t_col < 2)
	{
		checkRight(t_board, t_row, t_col, t_validLocations,t_piece);
	}
	return false;
}

bool CheckPositions::checkLeft(const Board& t_board, int t_row, int t_col,
	std::vector<std::array<std::string, 4>> & t_validLocations, char t_piece)
{
	int count = 0;
	if (checkFree(t_row, t_col - 1, t_board,t_piece) && checkFree(t_row, t_col - 2, t_board,t_piece))
	{
		if (t_row > 0)
		{
			if (checkFree(t_row - 1, t_col - 2, t_board,t_piece))
			{
				std::array<std::string, 4> position;
				position[0] = std::to_string(t_row) +
					std::to_string(t_col);
				position[1] = std::to_string(t_row) + std::to_string(t_col - 1);
				position[2] = std::to_string(t_row) + std::to_string(t_col - 2);
				position[3] = std::to_string(t_row - 1) + std::to_string(t_col - 2);
				t_validLocations.push_back(position);

			}
		}
		if (t_row < 4)
		{
			if (checkFree(t_row + 1, t_col - 2, t_board,t_piece))
			{
				std::array<std::string, 4> position;
				position[0] = std::to_string(t_row) +
					std::to_string(t_col);
				position[1] = std::to_string(t_row) + std::to_string(t_col - 1);
				position[2] = std::to_string(t_row) + std::to_string(t_col - 2);
				position[3] = std::to_string(t_row + 1) + std::to_string(t_col - 2);
				t_validLocations.push_back(position);
			}
		}
	}
	return false;
}

bool CheckPositions::checkRight(const Board& t_board, int t_row, int t_col,
	std::vector<std::array<std::string, 4>> & t_validLocations, char t_piece)
{
	int count = 0;
	if (checkFree(t_row, t_col + 1, t_board,t_piece) && checkFree(t_row, t_col + 2, t_board,t_piece))
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
			if (checkFree(t_row - 1, t_col + 2, t_board,t_piece))
			{
				std::array<std::string, 4> position;
				position[0] = std::to_string(t_row) +
					std::to_string(t_col);
				position[1] = std::to_string(t_row) + std::to_string(t_col + 1);
				position[2] = std::to_string(t_row) + std::to_string(t_col + 2);
				position[3] = std::to_string(t_row - 1) + std::to_string(t_col + 2);
				t_validLocations.push_back(position);
			}
		}
		else
		{
			if (checkFree(t_row + 1, t_col + 2, t_board,t_piece))
			{
				std::array<std::string, 4> position;
				position[0] = std::to_string(t_row) +
					std::to_string(t_col);
				position[1] = std::to_string(t_row) + std::to_string(t_col + 1);
				position[2] = std::to_string(t_row) + std::to_string(t_col + 2);
				position[3] = std::to_string(t_row + 1) + std::to_string(t_col + 2);
				t_validLocations.push_back(position);
			}
		}
	}
	return false;
}

bool CheckPositions::checkFree(int t_row, int t_col, const Board& t_board, char t_piece)
{
	if (t_row >= 0 && t_row < 4 && t_col >= 0 && t_col < 4)
	{
		return t_board.getCharacter(t_row, t_col) == t_piece || t_board.getCharacter(t_row, t_col) == '-';
	}
	else
	{
		return false;
	}
}
