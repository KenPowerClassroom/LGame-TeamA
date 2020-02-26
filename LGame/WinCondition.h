#pragma once
#include "CheckPositions.h"
#include "Board.h"
#include <array>
#include <string>
#include <vector>

class WinCondition
{
public:
	static bool hasLost(const Board & t_board, char t_piece);
};

