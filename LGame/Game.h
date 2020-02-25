#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "Renderer.h"
#include "Board.h"
#include <vector>
#include "SimpleAI.h"

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


	SimpleAI m_ai;

public:
	void run();
	void update();
	void pieceClear();
	void movePiece();
	bool checkVaildMove(std::vector<int> row1, std::vector<int> col1);
};

#endif