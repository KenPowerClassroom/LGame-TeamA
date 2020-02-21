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


	for (int i = 0; i < 4; i++)
	{
		std::cout << "Row: ";
		std::cin >> row;

		std::cout << "Col: ";
		std::cin >> col;

		while ((row < 0 || row > 5) || (col < 'A' || col > 'D'))
		{
			std::cout << "Re-enter: Row and Col\n";
			std::cout << "Row: ";
			std::cin >> row;

			std::cout << "Col: ";
			std::cin >> col;
		}

		col = col - 65;
		row--;

		m_board.setCharacter(row, (int)col, '1');

		Renderer::drawBoard(std::cout, m_board);
		
	}

	std::cout << "Quit? 1 - Yes: ";
	std::cin >> toQuit;

	if (toQuit == 1)
	{
		quit = true;
	}
}
