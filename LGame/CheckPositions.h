#pragma once
#include "Board.h"
#include <vector>
class CheckPositions
{
public:
	static bool checkRows(const Board& t_board, int t_row, int t_col,
		std::vector<std::array<std::string, 4>>& t_validLocations, char t_piece);//check for any free spaces along the rows
	static bool checkAbove(const Board& t_board, int t_row, int t_col,
		std::vector<std::array<std::string, 4>>& t_validLocations, char t_piece);//checks above the current space
	static bool checkBelow(const Board& t_board, int t_row, int t_col,
		std::vector<std::array<std::string, 4>>& t_validLocations, char t_piece);//checks below the current space
	static bool checkColumns(const Board& t_board, int t_row, int t_col,
		std::vector<std::array<std::string, 4>>& t_validLocations, char t_piece);//check for any free spaces along the cols
	static bool checkLeft(const Board& t_board, int t_row, int t_col,
		std::vector<std::array<std::string, 4>>& t_validLocations, char t_piece);//checks to  the left of current space
	static bool checkRight(const Board& t_board, int t_row, int t_col,
		std::vector<std::array<std::string, 4>>& t_validLocations, char t_piece);//checks to the right of the current space
	static bool checkFree(int t_row, int t_col, const Board& t_board, char t_piece);//checks if the current space is free
};

