#pragma once
#include <array>
#include <string>
#include <functional>
#include "Board.h"
#include <vector>


class SimpleAI
{
private:
	std::array<std::string, 4> m_newPositions;
	std::array<std::string, 4> m_oldPositions;
	std::vector<std::array<std::string, 4>> m_validLocations;
public:
	bool checkFree(int t_row, int t_col, const Board& t_board);
	void setUpPositions(const Board& t_board);
	bool checkRows(const Board& t_board, int t_row, int t_col);
	bool checkAbove(const Board& t_board, int t_row, int t_col);
	bool checkBelow(const Board& t_board, int t_row, int t_col);
	bool checkColumns(const Board& t_board, int t_row, int t_col);
	bool checkLeft(const Board& t_board, int t_row, int t_col);
	bool checkRight(const Board& t_board, int t_row, int t_col);
	std::string getPositions(int t_index) { return m_newPositions.at(t_index); }
	bool isEqual(std::array<std::string, 4> t_first, std::array<std::string, 4> t_second);
public:
	std::array<std::string, 4> movePiece(const Board & t_board);
	SimpleAI();
};

