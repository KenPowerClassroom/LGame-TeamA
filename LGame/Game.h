#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "Renderer.h"
#include "Board.h"

/// <summary>
/// enum class used for checking who's turn it is
/// </summary>
enum class TurnOrder
{
	PLAYER_TURN,
	AI_TURN
};

class Game
{
	// variables
	bool quit{ false };

	Board m_board;
	TurnOrder m_currentTurn{ TurnOrder::PLAYER_TURN };
	std::string m_turn{ "Player's Turn" };

public:
	void run();
	void update();
	void switchTurn();
	TurnOrder getTurnOrder() { return m_currentTurn; }

};

#endif