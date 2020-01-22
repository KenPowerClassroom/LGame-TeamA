#include "Renderer.h"

/// <summary>
/// Render the board in full
/// </summary>
/// <param name="t_board"></param>
void Renderer::drawBoard(Board t_board)
{
	system("CLS");
	std::cout << "============" << std::endl;
	std::cout << "|  A B C D |" << std::endl;
	std::cout << "|1 " << t_board.m_board[0][0] << " " << t_board.m_board[0][1] << " " << t_board.m_board[0][2] << " " << t_board.m_board[0][3] << " |" << std::endl;
	std::cout << "|2 " << t_board.m_board[1][0] << " " << t_board.m_board[1][1] << " " << t_board.m_board[1][2] << " " << t_board.m_board[1][3] << " |" << std::endl;
	std::cout << "|3 " << t_board.m_board[2][0] << " " << t_board.m_board[2][1] << " " << t_board.m_board[2][2] << " " << t_board.m_board[2][3] << " |" << std::endl;
	std::cout << "|4 " << t_board.m_board[3][0] << " " << t_board.m_board[3][1] << " " << t_board.m_board[3][2] << " " << t_board.m_board[3][3] << " |" << std::endl;
	std::cout << "============" << std::endl;
}
