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
		std::cout << m_turn << std::endl << std::endl; // display who's turn it is

		update();
	}
}

void Game::update()
{
	// update board with information

	int toQuit{ 0 };

	if (gameOn)
	{
		// allow player to move L-Piece and a neutral piece
		if (m_currentTurn == TurnOrder::PLAYER_TURN)
		{
			/// <summary>
			/// had to temporarily comment this out, otherwise the program wouldn't run
			/// </summary>
			//std::array<std::string, 4> location = m_ai.movePiece(m_board);
			//m_board.moveLPiece(location, '2');

			movePiece();

			switchTurn();
		}

		// A.I does it's move with the L-Piece
		else if (m_currentTurn == TurnOrder::AI_TURN)
		{
			switchTurn();
		}
	}
	else
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
	int error{ 0 };

	pieceClear();

	std::vector<int> row1;
	std::vector<int> col1;

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

			//checks left and right
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
			//check for L Piece good shape 
			row1.push_back(row - 1);
			col1.push_back((int)col - 65);
		}

		//checks if the previous l-piece placement is not the same
		if (row == pRow[i])
		{
			if (col == pCol[i])
			{
				error++;
			}
		}

		// just to display the error text
		if (error > 3)
		{
			gameOn = false;
			errorPlacement = false;
		}
		else
		{
			errorPlacement = true;
		}





		gameOn = checkVaildMove(row1, col1);

		m_board.setCharacter(row - 1, (int)col - 65, '1');
		Renderer::drawBoard(std::cout, m_board);
		std::cout << m_turn << std::endl << std::endl; // display who's turn it is
	}


}

bool Game::checkVaildMove(std::vector<int> row1, std::vector<int> col1)
{
	//check for L Piece good shape 

	int changingInDirection = 0;
	if (row1.size() == 4)
	{
		for (unsigned int i = 2; i  < row1.size(); i++)
		{
			bool horizontalLine = (row1.at(i - 2) == row1.at(i) && row1.at(i) == row1.at(i - 1));
			bool verticalLine = (col1.at(i - 2) == col1.at(i) && col1.at(i) == col1.at(i - 1));
			if (!(horizontalLine || verticalLine))
			{
				changingInDirection++;
			}
		}
		validLPiece = changingInDirection == 1;
	}

	return validLPiece;
}

/// <summary>
/// function that changes the turn and updates the turn message accordingly
/// </summary>
void Game::switchTurn()
{
	if (m_currentTurn == TurnOrder::PLAYER_TURN)
	{
		m_currentTurn = TurnOrder::AI_TURN;
		m_turn = "AI's Turn";
	}

	else
	{
		m_currentTurn = TurnOrder::PLAYER_TURN;
		m_turn = "Player's Turn";
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
				std::cout << m_turn << std::endl << std::endl; // display who's turn it is
			}
		}
	}
}