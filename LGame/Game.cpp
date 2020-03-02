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

			if (!WinCondition::hasLost(m_board, '1'))
			{
				movePiece(); // <- this

				switchTurn();
			}
			else
			{
				quit = true;
			}
			//movePiece(); // allows the player to move twice?
			moveNeutralPiece();
			//switchTurn(); // seem to skip A.I turn
		}

		// A.I does it's move with the L-Piece
		else if (m_currentTurn == TurnOrder::AI_TURN)
		{
			if (!WinCondition::hasLost(m_board, '1'))
			{
				std::array<std::string, 4> location = m_ai.movePiece(m_board);
				m_board.moveLPiece(location, '2');
				switchTurn();
			}
			else
			{
				quit = true;
			}
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
	int error{ 0 }; // checks if the 

	pieceClear(); // clears the player's piece

	//checks for validation
	std::vector<int> rowData; // stores player's row input 
	std::vector<int> colData; // stoees player's col input

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

			/// <summary>
			///this is a test
			/// </summary>
			//if (!std::cin.fail())
			//{
			//	std::cin.clear();
			//	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			//}

			std::cout << "Col: ";
			std::cin >> col;




			//Check for validation
			invalidMovement = false;

			//checks left and right
			if (row < 0 || row > 5)
			{
				invalidMovement = true;
			}

			//check if the player's input is capital
			if (col < 'A' || col > 'E')
			{
				invalidMovement = true;
			}


			// checks if other data is in place of 
			char test = m_board.getCharacter(row - 1, col - 65);
			if ((test == '(') || (test == ')') || (test == '2') || test == '1')
			{
				std::cout << "Invalid move piece is already there\n";
				invalidMovement = true;
			}



			// reverts back the data if its invalid
			if (invalidMovement)
			{
				//rowData.pop_back();
				//colData.pop_back();
			}
			else
			{
				//check for L Piece good shape 
				//rowData.push_back(row - 1);
				//colData.push_back((int)col - 65);
			}
		
			
			//check for L Piece good shape 
			rowData.push_back(row - 1);
			colData.push_back((int)col - 65);
			

		}

		//checks if the previous l-piece placement is not the same
		if (row == pRow[i])
		{
			if (col == pCol[i])
			{
				error++; // increment
			}
		}

		// just to display the error text
		if (error > 3)
		{
			gameOn = false;
			errorPlacement = false; // displays a error placement
		}
		else
		{
			errorPlacement = true; // does not display
		}

		//if (col > 'a' && col < 'e')
		//{
		//	col -= 32;
		//}


		m_board.setCharacter(row - 1, (int)col - 65, '1'); // set data to the grid
		Renderer::drawBoard(std::cout, m_board); // draw input
		std::cout << m_turn << std::endl << std::endl; // display who's turn it is

		gameOn = checkVaildMove(rowData, colData); // checks if the l-piece placement is correct
	}


}

bool Game::checkVaildMove(std::vector<int> row1, std::vector<int> col1)
{
	//check for L Piece good shape 

	int changingInDirection = 0; // variable for different placement
	if (row1.size() == 4) // <- if the size is this
	{
		for (unsigned int i = 2; i  < row1.size(); i++) // take two input before stareting the function
		{
			bool horizontalLine = (row1.at(i - 2) == row1.at(i) && row1.at(i) == row1.at(i - 1)); // checks if the horizontal line is straight on player's row data
			bool verticalLine = (col1.at(i - 2) == col1.at(i) && col1.at(i) == col1.at(i - 1)); // checks if the horizontal line is straight on player's col data
			if (!(horizontalLine || verticalLine))
			{
				changingInDirection++;
			}
		}
		validLPiece = changingInDirection == 1; // return
	}

	return validLPiece; // return
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


/// <summary>
/// allows the player to choose if they want to move a neutral piece, choose which one and
/// move the piece where the player inputs
/// </summary>
void Game::moveNeutralPiece()
{
	int row{ -1 };
	char col{ -1 };
	char neutralPiece{ '-' };
	bool repeat{ true };


	std::string choice{ "" };

	std::cout << "Move a neutral piece? 1 - Yes: ";
	std::cin >> choice;

	if (choice == "1")
	{
		while (repeat)
		{
			std::cout << "\nChoose piece: '(' or ')': ";
			std::cin >> neutralPiece;

			std::cout << "\nRow: ";
			std::cin >> row;

			std::cout << "Col: ";
			std::cin >> col;

			repeat = false;

			//checks if neutral piece is in the boundary regarding the row
			if (row < 1 || row > 4)
			{
				repeat = true;
				std::cout << "\ninvalid entry!" << std::endl;
			}

			//checks if neutral piece is in the boundary regarding the col and that the col input is capital
			if ((col < 'A') || (col > 'D'))
			{
				repeat = true;
				std::cout << "\ninvalid entry!" << std::endl;
			}

			// checks if neutral piece choice input is valid
			if ((neutralPiece != '(') && (neutralPiece != ')'))
			{
				repeat = true;
				std::cout << "\ninvalid entry!" << std::endl;
			}

			char testNeutralPiece = m_board.getCharacter(row - 1, (int)col - 65); // piece for testing only


			// checks if the new position of the neutral piece intersects with an L-Piece
			if ((testNeutralPiece == '1') || (testNeutralPiece == '2')
				|| (testNeutralPiece == '(') || (testNeutralPiece == ')'))
			{
				repeat = true;
				std::cout << "\ninvalid entry!" << std::endl;
			}
		}

		clearNeutralPiece(neutralPiece);
		m_board.setCharacter(row - 1, (int)col - 65, neutralPiece);
		Renderer::drawBoard(std::cout, m_board);
	}


}


/// <summary>
/// clears the previous neutral piece
/// </summary>
/// <param name="t_neutralPiece">char representing the chosen neutral piece</param>
void Game::clearNeutralPiece(char t_neutralPiece)
{
	for (int row = 0; row < 4; ++row)
	{
		for (int col = 0; col < 4; ++col)
		{
			if (t_neutralPiece == m_board.getCharacter(row, col))
			{
				m_board.setCharacter(row, col, '-');
				Renderer::drawBoard(std::cout, m_board);
				break;
			}
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
				std::cout << m_turn << std::endl << std::endl; // display who's turn it is
			}
		}
	}
}