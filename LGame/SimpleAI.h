#pragma once
#include <array>
#include <string>
#include <functional>
#include "Board.h"
class SimpleAI
{
private:
	bool checkFreeSpace(int t_row, int t_col, const Board & t_board, std::array<std::string, 4> t_oldPositions);
	std::array<std::string, 4> m_newPositions;
public:
	std::array<std::string, 4> movePiece(const Board & t_board);
};

