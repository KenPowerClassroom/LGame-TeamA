#include "pch.h"
#include "..\LGame\Board.h"
#include "..\LGame\Renderer.h"
#include "..\\LGame\Game.h"
#include <iostream>
#include <sstream>

//TEST(TestCaseName, TestName) {
//  EXPECT_EQ(1, 1);
//  EXPECT_TRUE(true);
//}
TEST(BOARDCONTENT, Board_Contents_On_Construction_Empty)
{
	Board testBoard;

	for (size_t row = 0; row < 4; ++row)
	{
		for (size_t col = 0; col < 4; ++col)
		{
			EXPECT_EQ(testBoard.getCharacter(row, col), '-');
		}
	}
	
	EXPECT_TRUE(true);
}

TEST(BOARDCONTENT, Board_Contents_Initialize_Pieces)
{
	Board testBoard;
	testBoard.initializeBoard();

	std::string lineTest;

	for (size_t col = 0; col < 4; ++col)
	{
		lineTest += testBoard.getCharacter(0, col);
	}

	EXPECT_EQ(lineTest, "-11-");

	EXPECT_TRUE(true);

	lineTest = "";

	for (size_t col = 0; col < 4; ++col)
	{
		lineTest += testBoard.getCharacter(1, col);
	}

	EXPECT_EQ(lineTest, "-21-");

	EXPECT_TRUE(true);

	lineTest = "";

	for (size_t col = 0; col < 4; ++col)
	{
		lineTest += testBoard.getCharacter(2, col);
	}

	EXPECT_EQ(lineTest, "-21-");

	EXPECT_TRUE(true);

	lineTest = "";

	for (size_t col = 0; col < 4; ++col)
	{
		lineTest += testBoard.getCharacter(3, col);
	}

	EXPECT_EQ(lineTest, "-22-");

	EXPECT_TRUE(true);

	lineTest = "";
}
TEST(BOARDCONTENT, Screen_Output_Test_Uninitialised)	
{
	Board board;

	std::ostringstream test;

	Renderer::drawBoard(test, board);

	EXPECT_EQ(test.str(), "============\n|  A B C D |\n|1 - - - - |\n|2 - - - - |\n|3 - - - - |\n|4 - - - - |\n============\n");

	EXPECT_TRUE(true);
}

TEST(BOARDCONTENT, Screen_Output_Test_Initialised)
{
	Board board;

	board.initializeBoard();

	std::ostringstream test;

	Renderer::drawBoard(test, board);

	EXPECT_EQ(test.str(), "============\n|  A B C D |\n|1 - 1 1 - |\n|2 - 2 1 - |\n|3 - 2 1 - |\n|4 - 2 2 - |\n============\n");

	EXPECT_TRUE(true);
}

TEST(TURNORDER, Turn_Order_Test_Players_Turn)
{
	Game testGame;

	ASSERT_EQ(TurnOrder::PLAYER_TURN, testGame.getTurnOrder());

	EXPECT_TRUE(true);
}

TEST(TURNORDER, Turn_Order_Test_AIs_Turn)
{
	Game testGame;

	testGame.switchTurn();

	ASSERT_EQ(TurnOrder::AI_TURN, testGame.getTurnOrder());

	EXPECT_TRUE(true);
}