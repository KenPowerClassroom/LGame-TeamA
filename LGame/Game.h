#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "Renderer.h"
#include "Board.h"
#include <vector>
#include "SimpleAI.h"
#include "WinCondition.h"

/// /// <summary>
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
	bool gameOn{ true };
	bool errorPlacement{ false };
	bool validLPiece = true;
	Board m_board;
	int pRow[4]; // previous row
	char pCol[4]; // previous col

	TurnOrder m_currentTurn{ TurnOrder::PLAYER_TURN };
	std::string m_turn{ "Player's Turn" };

	SimpleAI m_ai;

public:
	void run();
	void update();
	void pieceClear();
	void movePiece();
	bool checkVaildMove(std::vector<int> row1, std::vector<int> col1);
	void switchTurn();
	TurnOrder getTurnOrder() { return m_currentTurn; }
};

#endif