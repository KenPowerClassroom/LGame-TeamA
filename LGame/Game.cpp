#include "Game.h"

void Game::run()
{
	Renderer::drawBoard(board);

	while (true)
	{
		if (quit)
		{
			break;
		}


		update();

		// ask renderer to draw the board
		Renderer::drawBoard(board);
		
	}
}

void Game::update()
{
	// update board with information
	int toQuit{ 0 };

	std::cout << "Quit? 1 - Yes: ";
	std::cin >> toQuit;

	if (toQuit == 1)
	{
		quit = true;
	}
}
