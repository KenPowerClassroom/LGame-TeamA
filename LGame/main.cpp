/// <summary>
/// L Game - Team A
/// Allexis Alvarico, Michal K, Jack Malone, Joshua Dunne
/// 
/// The purpose of this project is to attempt to re-create the L-Game.
/// The L game is a two-player game played on a board of 4x4 squares.
/// Each player takes a turn moving a 3x2 L piece to a new position.
/// Either player wins by trapping the other player, making it so they cannot move their L piece.
/// 
/// For a full description, see the research_report.md.
/// 
/// ---------------------------------------------------------
/// 
/// Date(s): 22/01/2020, 29/01/2020, 05/02/2020, 12/02/2020
/// Time Taken: 3hrs
/// Estimated Time: 20hrs
/// 
/// Known bugs:
/// 
/// 
/// 
/// 
/// 
/// </summary>


#include <iostream>
#include "Game.h"

int main()
{
	Game game;
	game.run();

	return 0;
}


//
//#include <iostream>
//#include <windows.h>   // WinApi header
//
//int main()
//{
//	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//	// you can loop k higher to see more color choices
//	for (int k = 1; k < 255; k++)
//	{
//		// pick the colorattribute k you want
//		SetConsoleTextAttribute(hConsole, k);
//		std::cout << k << " I want to be nice today!" << std::endl;
//	}
//}