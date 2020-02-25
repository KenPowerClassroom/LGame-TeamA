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


	movePiece();
	
	if (!vaildPlay)
	{
		std::cout << "Quit? 1 - Yes: ";
		std::cin >> toQuit;
		if (toQuit == 1)
		{
			quit = true;
		}
	}	
}



void Game::movePiece()
{
	pieceClear();

	int help{ 0 };

	for (int i = 0; i < 4; i++)
	{

		int row{ -1 };
		char col{ -1 };
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
			if ((test == '(') || (test == ')') || (test == '2') || test == '1')
			{
				invalidMovement = true;
			}
		}

		if (row == pRow[i])
		{
			if (col == pCol[i])
			{
				help++;
			}
		}

		col = col - 65;
		row--;
		m_board.setCharacter(row, (int)col, '1');
		Renderer::drawBoard(std::cout, m_board);

		if (help < 3)
		{
			vaildPlay = false;
		}
		else
		{		
			vaildPlay = true;
		}
	}
	
}

void Game::pieceClear()
{
	int index = 0;

	for (int row = 0; row < 4; ++row)
	{
		for (int col = 0; col < 4; ++col)
		{
			if ('1' == m_board.getCharacter(row, col))
			{
				pRow[index] = row + 1;
				pCol[index] = col + 65;
				m_board.setCharacter(row, col, '-');
				index++;
				Renderer::drawBoard(std::cout, m_board);
			}
		}
	}
}