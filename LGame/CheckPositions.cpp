#include "CheckPositions.h"

/// <summary>
/// checks to see if there are any available spaces along the rows
/// it does this by checking either 2 spaces left or right of the currently free space to check if they are free
/// it will then check either below or above this piece depending on where it is  in the board, eg.
/// it can't check above a piece if it is already on the top row
/// </summary>
/// <param name="t_board">board to be checked</param>
/// <param name="t_row">current row</param>
/// <param name="t_col">current col</param>
/// <param name="t_validLocations">stores all of the valid locations to move to</param>
/// <param name="t_piece">ai or player</param>
/// <returns>returns true if it found somehwere, otherwise false</returns>
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

/// <summary>
/// checks for three free spaces vertically upwards and then check to the left or right of the final piece to 
/// see if there is a full l piece is available
/// also does checks before looking left or right to make sure that it wont be going outside the range of the 
/// board
/// </summary>
/// <param name="t_board">the board</param>
/// <param name="t_row">row of the current free piece</param>
/// <param name="t_col">column of the current free place</param>
/// <param name="t_validLocations">stores all of the locations that it was able to find</param>
/// <param name="t_piece">if it should be checking for the player or the ai</param>
/// <returns>true if it was able to check for pieces, otherwise false</returns>
bool CheckPositions::checkAbove(const Board& t_board, int t_row, int t_col,
	std::vector<std::array<std::string, 4>> & t_validLocations, char t_piece)
{
	int count = 0;
	if (t_row > 1)
	{
		if (checkFree(t_row - 1, t_col, t_board, t_piece) && checkFree(t_row - 2, t_col, t_board, t_piece))
		{
			if (t_col > 0)
			{
				if (count < 4)
				{
					if (checkFree(t_row - 2, t_col - 1, t_board, t_piece))
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
				if (checkFree(t_row - 2, t_col + 1, t_board, t_piece))
				{
					std::array<std::string, 4> position;
					position[0] = std::to_string(t_row) + std::to_string(t_col);
					position[1] = std::to_string(t_row - 1) + std::to_string(t_col);
					position[2] = std::to_string(t_row - 2) + std::to_string(t_col);
					position[3] = std::to_string(t_row - 2) + std::to_string(t_col + 1);
					t_validLocations.push_back(position);
				}
			}
			return true;
		}
		return true;
	}
	
	return false;
}
/// <summary>
/// checks for three free spaces vertically downwards and then check to the left or right of the final piece to 
/// see if there is a full l piece is available
/// also does checks before looking left or right to make sure that it wont be going outside the range of the 
/// board
/// </summary>
/// <param name="t_board">the board</param>
/// <param name="t_row">row of the current free piece</param>
/// <param name="t_col">column of the current free place</param>
/// <param name="t_validLocations">stores all of the locations that it was able to find</param>
/// <param name="t_piece">if it should be checking for the player or the ai</param>
/// <returns>true if it was able to check for pieces, otherwise false</returns>
bool CheckPositions::checkBelow(const Board& t_board, int t_row, int t_col,
	std::vector<std::array<std::string, 4>> & t_validLocations, char t_piece)
{
	if (t_row < 2)
	{
		if (checkFree(t_row + 1, t_col, t_board, t_piece) && checkFree(t_row + 2, t_col, t_board, t_piece))
		{
			if (t_col > 0)
			{
				if (checkFree(t_row + 2, t_col - 1, t_board, t_piece))
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
				if (checkFree(t_row + 2, t_col + 1, t_board, t_piece))
				{
					std::array<std::string, 4> position;
					position[0] = std::to_string(t_row) + std::to_string(t_col);
					position[1] = std::to_string(t_row + 1) + std::to_string(t_col);
					position[2] = std::to_string(t_row + 2) + std::to_string(t_col);
					position[3] = std::to_string(t_row + 2) + std::to_string(t_col + 1);
					t_validLocations.push_back(position);
				}
			}
			return true;
		}
		return true;
	}
	
	return false;
}

/// <summary>
/// checks to see if there are any available spaces along the rows
/// it does this by checking either 2 spaces left or right of the currently free space to check if they are free
/// it will then check either below or above this piece depending on where it is  in the board, eg.
/// it can't check above a piece if it is already on the top row
/// </summary>
/// <param name="t_board">board to be checked</param>
/// <param name="t_row">current row</param>
/// <param name="t_col">current col</param>
/// <param name="t_validLocations">stores all of the valid locations to move to</param>
/// <param name="t_piece">ai or player</param>
/// <returns>returns true if it found somehwere, otherwise false</returns>
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

/// <summary>
/// checks for three free spaces to the left and then check to the top or bottom of the final piece to 
/// see if there is a full l piece is available
/// also does checks before looking left or right to make sure that it wont be going outside the range of the 
/// board
/// </summary>
/// <param name="t_board">the board</param>
/// <param name="t_row">row of the current free piece</param>
/// <param name="t_col">column of the current free place</param>
/// <param name="t_validLocations">stores all of the locations that it was able to find</param>
/// <param name="t_piece">if it should be checking for the player or the ai</param>
/// <returns>true if it was able to check for pieces, otherwise false</returns>
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

/// <summary>
/// checks for three free spaces to the left and then check to the top or bottom of the final piece to 
/// see if there is a full l piece is available
/// also does checks before looking left or right to make sure that it wont be going outside the range of the 
/// board
/// </summary>
/// <param name="t_board">the board</param>
/// <param name="t_row">row of the current free piece</param>
/// <param name="t_col">column of the current free place</param>
/// <param name="t_validLocations">stores all of the locations that it was able to find</param>
/// <param name="t_piece">if it should be checking for the player or the ai</param>
/// <returns>true if it was able to check for pieces, otherwise false</returns>
bool CheckPositions::checkRight(const Board& t_board, int t_row, int t_col,
	std::vector<std::array<std::string, 4>> & t_validLocations, char t_piece)
{
	int count = 0;
	if (checkFree(t_row, t_col + 1, t_board,t_piece) && checkFree(t_row, t_col + 2, t_board,t_piece))
	{
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

/// <summary>
/// checks if a specific space in the board has anything in it or not
/// a space is defined as free if that piece is already in it or it is empty
/// also checks to make sure that the row and col are valid before checking
/// </summary>
/// <param name="t_row">current row</param>
/// <param name="t_col">current col</param>
/// <param name="t_board">board to be checked</param>
/// <param name="t_piece">ai or player</param>
/// <returns>true if free, otherwise false</returns>
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
