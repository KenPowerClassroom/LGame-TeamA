#pragma once
#include <array>
#include <string>
#include "Board.h"
class SimpleAI
{
private:
public:
	std::array<std::string, 4> movePiece(const Board & t_board);
};

