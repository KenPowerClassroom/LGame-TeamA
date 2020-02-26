#pragma once
#include "CheckPositions.h"
#include "Board.h"
#include <array>
#include <string>
#include <vector>

class WinCondition
{
private:
	std::vector<std::array<std::string, 4>> m_validLocations;
public:
	bool hasLost(const Board & t_board, char t_piece);
};

