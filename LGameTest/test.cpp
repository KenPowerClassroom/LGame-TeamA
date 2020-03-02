#include "pch.h"
#include "..\\LGame\\Board.h"
#include "..\\LGame\\Renderer.h"
#include "..\\LGame\\Game.h"
#include "..\\LGame\\CheckPositions.h"
#include "..\\LGame\\WinCondition.h"
#include "..\\LGame\\SimpleAI.h"
#include <array>
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

TEST(FREESPACE, Free_Space_Test)
{
	Board board;

	board.initializeBoard();
	bool result = CheckPositions::checkFree(-1, 0, board, '2');


	EXPECT_EQ(result, false);
	result = (CheckPositions::checkFree(4, 0, board, '2'));
	EXPECT_EQ(result, false);
	EXPECT_TRUE(CheckPositions::checkFree(0, 0, board, '2'));
	EXPECT_TRUE(CheckPositions::checkFree(1, 1, board, '2'));
	EXPECT_TRUE(CheckPositions::checkFree(2, 1, board, '2'));
	EXPECT_TRUE(CheckPositions::checkFree(3, 1, board, '2'));
	EXPECT_TRUE(CheckPositions::checkFree(3, 2, board, '2'));
	EXPECT_FALSE(CheckPositions::checkFree(0, 1, board, '2'));
	EXPECT_FALSE(CheckPositions::checkFree(0, 2, board, '2'));
	EXPECT_FALSE(CheckPositions::checkFree(1, 2, board, '2'));
	EXPECT_FALSE(CheckPositions::checkFree(2, 2, board, '2'));


	EXPECT_FALSE(CheckPositions::checkFree(1, 1, board, '1'));
	EXPECT_FALSE(CheckPositions::checkFree(2, 1, board, '1'));
	EXPECT_FALSE(CheckPositions::checkFree(3, 1, board, '1'));
	EXPECT_FALSE(CheckPositions::checkFree(3, 2, board, '1'));
	EXPECT_TRUE(CheckPositions::checkFree(0, 1, board, '1'));
	EXPECT_TRUE(CheckPositions::checkFree(0, 2, board, '1'));
	EXPECT_TRUE(CheckPositions::checkFree(1, 2, board, '1'));
	EXPECT_TRUE(CheckPositions::checkFree(2, 2, board, '1'));
}

TEST(SETUPAI, Set_Up_New_Positions)
{
	SimpleAI ai;
	Board board;
	board.initializeBoard();
	ai.setUpPositions(board);
	std::array<std::string, 4> arr = { "11","21","31","32" };
	std::array<std::string, 4> arr2 = { ai.getPositions(0),ai.getPositions(1),ai.getPositions(2),ai.getPositions(3) };
	EXPECT_EQ(arr2, arr);
}

TEST(MOVEAI, Move_Ai_Piece)
{
	SimpleAI ai;
	Board board;
	board.initializeBoard();
	std::array<std::string, 4> arr2 = ai.movePiece(board);
	std::array<std::string, 4> arr = { "11","21","31","32" };
	EXPECT_NE(arr, arr2);
}

TEST(FREESPACE, Check_Rows)
{
	SimpleAI ai;
	Board board;
	std::vector<std::array<std::string, 4>>  validLocations;
	board.initializeBoard();
	bool result = CheckPositions::checkRows(board, 0, 0, validLocations, '2');

	EXPECT_EQ(validLocations.empty(), false);
}

TEST(FREESPACE, Check_Cols)
{
	SimpleAI ai;
	Board board;
	std::vector<std::array<std::string, 4>>  validLocations;
	board.initializeBoard();
	bool result = CheckPositions::checkColumns(board, 0, 0, validLocations, '2');

	EXPECT_EQ(validLocations.empty(), true);

	result = CheckPositions::checkColumns(board, 1, 3, validLocations, '2');
	EXPECT_EQ(validLocations.empty(), false);
}

TEST(WINCONDITION, Win_Condition_On_Setup)
{
	WinCondition winCondition;
	SimpleAI ai;
	Board board;
	std::vector<std::array<std::string, 4>>  validLocations;
	board.initializeBoard();

	bool result = winCondition.hasLost(board, '2');
	EXPECT_EQ(result, false);

	result = winCondition.hasLost(board, '1');
	EXPECT_EQ(result, false);
}