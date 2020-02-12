#include "Renderer.h"

/// <summary>
/// Render the board in full
/// </summary>
/// <param name="t_board"></param>
void Renderer::drawBoard(Board t_board)
{
	system("CLS");

	std::cout << "============" << std::endl;
	std::cout << "|  ";
	changeTextColor(14); // change text color to yellow
	std::cout << "A B C D "; // output column letters
	changeTextColor(15); // change text color to white
	std::cout <<  "|" << std::endl;

	for (int row = 0; row < 4; ++row)
	{
		std::cout << "|";
		changeTextColor(14); // change text color to yellow
		std::cout << row + 1 << " "; // output row numbers
		changeTextColor(15); // change text color to white

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

			changeTextColor(15); // reset text color
		}
		
	}

	std::cout << "============" << std::endl;

}

/// <summary>
/// Change color of CMD Text
/// Some useful colors to remember:
/// 14 = Yellow Text
/// 15 = White Text
/// 159 = Blue Background, White Text
/// 207 = Red Background, White Text
/// 240 = White Backgrund, Black Text
/// </summary>
/// <param name="t_color">Color of text to change</param>
void Renderer::changeTextColor(int t_color)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, t_color);
}
