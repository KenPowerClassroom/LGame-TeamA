#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "Renderer.h"
#include "Board.h"
#include "SimpleAI.h"

class Game
{
	// variables
	bool quit{ false };

	Board m_board;

	SimpleAI m_ai;
public:
	void run();
	void update();

};

#endif