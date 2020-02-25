#include "Renderer.h"

/// <summary>
/// Render the board in full
/// </summary>
/// <param name="t_board"></param>
void Renderer::drawBoard(std::ostream& output, Board t_board)
{
	system("CLS");

	output << "============" << std::endl;
	output << "|  ";
	changeTextColor(14); // change text color to yellow
	output << "A B C D "; // output column letters
	changeTextColor(15); // change text color to white
	output <<  "|" << std::endl;

	for (int row = 0; row < 4; ++row)
	{
		output << "|";
		changeTextColor(14); // change text color to yellow
		output << row + 1 << " "; // output row numbers
		changeTextColor(15); // change text color to white

		for (int col = 0; col < 4; ++col)
		{
			if (t_board.getCharacter(row, col) == '1')
				changeTextColor(207);
			else if (t_board.getCharacter(row, col) == '2')
				changeTextColor(159);
			if ('(' == t_board.getCharacter(row, col) || ')' == t_board.getCharacter(row, col))
				changeTextColor(240);
			if ('-' == t_board.getCharacter(row, col))
				changeTextColor(15);



			output << t_board.getCharacter(row, col);
			changeTextColor(15); // reset color before finishing up line

			if (col == 3)
			{
				output << " |";
				output << std::endl;
			}
			else
			{
				output << " ";
			}


		}	
	}

	output << "============" << std::endl;

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
