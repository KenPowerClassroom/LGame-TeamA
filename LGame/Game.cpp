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

	int error{ 0 };

	if (errorPlacement)
	{
		std::cout << "Invalid placement\n";
	}

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

			if ((col < 'A' || col > 'E'))
			{
				invalidMovement = true;
			}

			char test = m_board.getCharacter(row - 1, col - 65);
			if ((test == '(') || (test == ')') || (test == '2') || test == '1')
			{
				std::cout << "Invalid move piece is already there\n";
				invalidMovement = true;
			}
		}

		//checks if the previous l-piece placement is not the same
		if (row == pRow[i])
		{
			if (col == pCol[i])
			{
				error++;
			}
		}

		m_board.setCharacter(row - 1, (int)col - 65, '1');
		Renderer::drawBoard(std::cout, m_board);


		// just to display the error text
		if (error < 3)
		{
			vaildPlay = false;
			errorPlacement = false;
		}

		if (checkVaildMove(row, col))
		{
			 vaildPlay = true;
		}


	}

}

bool Game::checkVaildMove(int row, char col)
{
	std::vector<int> row1;
	std::vector<int> col1;

	//check for L Piece good shape 
	row1.push_back(row - 1);
	col1.push_back((int)col - 65);
	bool validLPiece = true;
	int changingInDirection = 0;
	if (row1.size() == 4)
	{
		for (unsigned int i = 2; row1.size(); i++)
		{
			bool horizontalLine = (row1.at(i - 2) == row1.at(i) && row1.at(i) == row1.at(i - 1)); // checks if the 3 input is horizonral
			bool verticalLine = (col1.at(i - 2) == col1.at(i) && col1.at(i) == col1.at(i - 1));// checks if the 3 input is horizonral
			if (!(horizontalLine || verticalLine))
			{
				changingInDirection++;
			}
		}
		validLPiece = changingInDirection == 1;
	}
	return validLPiece;
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