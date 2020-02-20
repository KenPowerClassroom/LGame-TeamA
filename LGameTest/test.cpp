#include "pch.h"
#include "..\LGame\Board.h"
#include "..\LGame\Renderer.h"
#include <iostream>

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

	std::ostream& test{ std::cout };

	Renderer::drawBoard(test, board);

	EXPECT_TRUE(true);
}