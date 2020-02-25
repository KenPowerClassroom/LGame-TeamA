#include "Game.h"

void Game::run()
{
	m_board.initializeBoard();

	while (true)
	{
		if (quit)
		{
			break;
		}


		Renderer::drawBoard(std::cout, m_board);

		update();
	}
}

void Game::update()
{
	// update board with information
	int toQuit{ 0 };

	std::cout << "Quit? 1 - Yes: ";
	std::cin >> toQuit;

	std::array<std::string,4> location = m_ai.movePiece(m_board);
	m_board.moveLPiece(location, '2');

	if (toQuit == 1)
	{
		quit = true;
	}
}
