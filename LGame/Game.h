#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "Renderer.h"
#include "Board.h"

class Game
{
	// variables
	bool quit{ false };
	bool vaildPlay{ true };
	bool errorPlacement{ false };
	Board m_board;
	int pRow[4]; // previous row
	char pCol[4]; // previous col



public:
	void run();
	void update();
	void pieceClear();
	void movePiece();

};

#endif