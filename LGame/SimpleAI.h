#pragma once
#include <array>
#include <string>
#include "Board.h"
#include <vector>
#include "CheckPositions.h"

class SimpleAI
{
private:
	std::array<std::string, 4> m_newPositions;
	std::array<std::string, 4> m_oldPositions;
	std::vector<std::array<std::string, 4>> m_validLocations;
public:
	std::string getPositions(int t_index) { return m_newPositions.at(t_index); }
	bool isEqual(std::array<std::string, 4> t_first, std::array<std::string, 4> t_second);
	void pickRandomPosition();
	void setUpPositions(const Board& t_board);
public:
	std::array<std::string, 4> movePiece(const Board & t_board);
	SimpleAI();
};

