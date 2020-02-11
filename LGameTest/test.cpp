#include "pch.h"
#include "Board.h"

//TEST(TestCaseName, TestName) {
//  EXPECT_EQ(1, 1);
//  EXPECT_TRUE(true);
//}

/// <summary>
/// Expect board to be empty (for now)
/// </summary>
TEST(BOARDCONTENT, Board_Contents)
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