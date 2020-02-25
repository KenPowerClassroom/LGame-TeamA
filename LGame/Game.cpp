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

	pieceClear();
	for (int i = 0; i < 4; i++)
	{

		int row{ -1 };
		char col{ -1 };
		//bool inside{ true };

		bool invalidMovement = true;
		while (invalidMovement)
		{
			//Get input 
			std::cout << "Row: ";
			std::cin >> row;

			std::cout << "Col: ";
			std::cin >> col;

			//Check for validation
			invalidMovement = false;

			if (row < 0 || row > 5)
			{
				invalidMovement = true;
			}
			if (col < 'A' || col > 'D')
			{
				invalidMovement = true;
			}
			char test = m_board.getCharacter(row - 1, col - 65);
			if ((test == '(') || (test == ')') || (test == '2'))
			{
				invalidMovement = true;
			}
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

void Game::pieceClear()
{

	for (int row = 0; row < 4; ++row)
	{
		for (int col = 0; col < 4; ++col)
		{
			if ('1' == m_board.getCharacter(row, col))
				m_board.setCharacter(row, col, '-');
			Renderer::drawBoard(std::cout, m_board);
		}
	}
}
