#pragma once
#include "Board.h"
#include <vector>
class CheckPositions
{
public:
	static bool checkRows(const Board& t_board, int t_row, int t_col,
		std::vector<std::array<std::string, 4>>& t_validLocations, char t_piece);
	static bool checkAbove(const Board& t_board, int t_row, int t_col,
		std::vector<std::array<std::string, 4>>& t_validLocations, char t_piece);
	static bool checkBelow(const Board& t_board, int t_row, int t_col,
		std::vector<std::array<std::string, 4>>& t_validLocations, char t_piece);
	static bool checkColumns(const Board& t_board, int t_row, int t_col,
		std::vector<std::array<std::string, 4>>& t_validLocations, char t_piece);
	static bool checkLeft(const Board& t_board, int t_row, int t_col,
		std::vector<std::array<std::string, 4>>& t_validLocations, char t_piece);
	static bool checkRight(const Board& t_board, int t_row, int t_col,
		std::vector<std::array<std::string, 4>>& t_validLocations, char t_piece);
	static bool checkFree(int t_row, int t_col, const Board& t_board, char t_piece);
};

