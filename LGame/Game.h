#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "Renderer.h"
#include "Board.h"

class Game
{
	// variables
	bool quit{ false };

	Board m_board;
	int row{ -1 };
	char col{ -1 };

public:
	void run();
	void update();
};

#endif