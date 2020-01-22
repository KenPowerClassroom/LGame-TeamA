#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "Renderer.h"
#include "Board.h"

class Game
{
	// variables
	bool quit{ false };

	Board board;


public:
	void run();
	void update();

};

#endif