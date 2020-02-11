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
	SetConsoleTextAttribute(hConsole, 14); // change text color to yellow
	std::cout << "A B C D "; // output column letters
	SetConsoleTextAttribute(hConsole, 15); // change text color to white
	std::cout <<  "|" << std::endl;

	for (int row = 0; row < 4; ++row)
	{
		std::cout << "|";
		SetConsoleTextAttribute(hConsole, 14); // change text color to yellow
		std::cout << row + 1 << " "; // output row numbers
		SetConsoleTextAttribute(hConsole, 15); // change text color to white

		for (int col = 0; col < 4; ++col)
		{
			if (col == 3)
			{
				std::cout << t_board.getCharacter(row, col) << " |";
				std::cout << std::endl;
			}
			else
			{
				std::cout << t_board.getCharacter(row, col) << " ";
			}

			SetConsoleTextAttribute(hConsole, 15); // reset text color
		}
		
	}

	std::cout << "============" << std::endl;

}
