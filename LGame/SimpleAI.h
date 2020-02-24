#pragma once
#include <array>
#include <string>
#include <functional>
#include "Board.h"
class SimpleAI
{
private:
	std::array<std::string, 4> m_newPositions;
	void setUpPositions(const Board& t_board);
	bool checkRows(const Board& t_board, int t_row, int t_col);
	bool checkAbove(const Board& t_board, int t_row, int t_col);
	bool checkBelow(const Board& t_board, int t_row, int t_col);
	bool checkColumns(const Board& t_board, int t_row, int t_col);
	bool checkLeft(const Board& t_board, int t_row, int t_col);
	bool checkRight(const Board& t_board, int t_row, int t_col);
public:
	std::array<std::string, 4> movePiece(const Board & t_board);
};

