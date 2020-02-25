#include "pch.h"
#include "..\LGame\Board.h"
#include "..\LGame\Renderer.h"
#include "..\LGame\SimpleAI.h"

#include <iostream>
#include <sstream>
#include <array>


TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}
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

TEST(FREESPACE, Free_Space_Test)
{
	SimpleAI ai;
	Board board;

	board.initializeBoard();
	bool result = ai.checkFree(-1, 0, board);

	EXPECT_EQ(result, false);
	result = (ai.checkFree(4, 0, board));
	EXPECT_EQ(result, false);
	EXPECT_TRUE(ai.checkFree(0, 0, board));
}

TEST(SETUPAI, Set_Up_New_Positions)
{
	SimpleAI ai;
	Board board;
	board.initializeBoard();
	ai.setUpPositions(board);
	std::array<std::string, 4> arr = { "11","21","31","32" };
	std::array<std::string, 4> arr2 = {ai.getPositions(0),ai.getPositions(1),ai.getPositions(2),ai.getPositions(3)};
	EXPECT_EQ(arr2, arr);
}


//bool checkBelow(const Board& t_board, int t_row, int t_col);
//bool checkColumns(const Board& t_board, int t_row, int t_col);
//bool checkLeft(const Board& t_board, int t_row, int t_col);
//bool checkRight(const Board& t_board, int t_row, int t_col);

TEST(FREESPACE, Check_Rows)
{
	SimpleAI ai;
	Board board;
	board.initializeBoard();
	bool result = ai.checkRows(board, 0, 0);
	EXPECT_EQ(result, true);
}

TEST(FREESPACE, Check_Above)
{
	SimpleAI ai;
	Board board;
	board.initializeBoard();
	bool result = ai.checkAbove(board, 0, 0);
	EXPECT_EQ(result, false);
	result = ai.checkAbove(board, 4, 0);
	EXPECT_EQ(result, true);
}