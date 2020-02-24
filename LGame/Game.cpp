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
		std::cout << m_turn << std::endl << std::endl;

		update();
	}
}

void Game::update()
{
	// update board with information
	int toQuit{ 0 };

	// allow player to move L-Piece and a neutral piece
	if (m_currentTurn == TurnOrder::PLAYER_TURN)
	{
		switchTurn();
	}

	// A.I does it's move with the L-Piece
	else if (m_currentTurn == TurnOrder::AI_TURN)
	{
		switchTurn();
	}


	std::cout << "Quit? 1 - Yes: ";
	std::cin >> toQuit;
	
	if (toQuit == 1)
	{
		quit = true;
	}
}

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
