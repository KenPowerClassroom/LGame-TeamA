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
		std::cout << t_board.getCharacter(0, index) << " " 
				  << t_board.getCharacter(1, index) << " " 
				  << t_board.getCharacter(2, index) << " " 
				  << t_board.getCharacter(3, index) << " |" << std::endl;
	}
	std::cout << "============" << std::endl;

}
