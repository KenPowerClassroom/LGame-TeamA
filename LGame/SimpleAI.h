#pragma once
#include <array>
#include <string>
#include "Board.h"
#include <vector>
#include "CheckPositions.h"
#include <ctime>

class SimpleAI
{
private:
	std::array<std::string, 4> m_newPositions;//stores the new place for it to move to
	std::array<std::string, 4> m_oldPositions;//stores its previous position
	std::vector<std::array<std::string, 4>> m_validLocations;//stores all valid locations to move to
	const char c_PIECE;//stores what represents the ai on the board. Set up in the constructor. Default is character 2
public:
	std::string getPositions(int t_index) { return m_newPositions.at(t_index); }//used to get its current positions
	void pickRandomPosition();//picks a random position for it to go to from the valid locations
	void setUpPositions(const Board& t_board);//sets up the old locations then sets the new pos to the old pos
	void findOriginalPosition();//checks to see where it was from its last turn
public:
	std::array<std::string, 4> movePiece(const Board & t_board);//moves itself to a new position
	SimpleAI();
	SimpleAI(const char t_piece);
};

