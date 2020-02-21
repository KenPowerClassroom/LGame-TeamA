#include "SimpleAI.h"

std::array<std::string, 4> SimpleAI::movePiece(const Board&  t_board)
{
	std::array<std::string, 4> oldLocations = { "","","","" };
	std::array<std::string, 4> newLocations = { "","","","" };
	int j = 0;
	int index = 0;
	for (int i = 0; i < 4; i++)
	{
		for (; j < 4; j++)
		{
			if (t_board.getCharacter(i, j) == '2')
			{
				oldLocations.at(index) = std::to_string(i + 1) + std::to_string(j + 1);
				if (index < 3)
				{
					index++;
				}
			}
		}
		j = 0;
	}
	newLocations = oldLocations;
	return newLocations;
}
