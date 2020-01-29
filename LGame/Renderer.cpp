#include "Renderer.h"

/// <summary>
/// Render the board in full
/// </summary>
/// <param name="t_board"></param>
void Renderer::drawBoard(Board t_board)
{
	system("CLS");

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 15);

	std::cout << "============" << std::endl;
	std::cout << "|  ";
	SetConsoleTextAttribute(hConsole, 14);
	std::cout << "A B C D ";
	SetConsoleTextAttribute(hConsole, 15);
	std::cout <<  "|" << std::endl;

	for (int index = 0; index < 4; ++index)
	{
		std::cout << "|";
		SetConsoleTextAttribute(hConsole, 14);
		std::cout << index + 1 << " ";
		SetConsoleTextAttribute(hConsole, 15);
		std::cout << t_board.m_board[index][0] << " " << t_board.m_board[index][1] << " " << t_board.m_board[index][2] << " " << t_board.m_board[index][3] << " |" << std::endl;
	}
	std::cout << "============" << std::endl;

}
