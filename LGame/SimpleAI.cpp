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
	j = 0;
	index = 0;
	for (int i = 0; i < 4; i++)
	{
		for (; j < 4; j++)
		{
			newLocations = oldLocations;
			if (t_board.getCharacter(i, j) == '-' ||
				t_board.getCharacter(i,j) == '2')
			{
				newLocations.at(0) = std::to_string(i + 1) + std::to_string(j + 1);
				if (i - 1 > 0)
				{
					if (t_board.getCharacter(i - 1, j) == '-' ||
						t_board.getCharacter(i - 1, j) == '2')
					{
						newLocations.at(1) = std::to_string(i) + std::to_string(j + 1);
						if (i - 2 > 0)
						{
							if (t_board.getCharacter(i - 2, j) == '-' ||
								t_board.getCharacter(i - 2, j) == '2')
							{
								newLocations.at(2) = std::to_string(i - 2) + std::to_string(j + 1);
								if (j - 1 > 0)
								{
									if (t_board.getCharacter(i - 2, j - 1) == '-'
										||
										t_board.getCharacter(i - 2, j - 2) == '2')
									{
										newLocations.at(3) = std::to_string(i - 2) + std::to_string(j);
										return newLocations;
									}
								
								}
								else if (j + 1 < 4)
								{
									if (t_board.getCharacter(i - 2, j + 1) == '-' ||
										t_board.getCharacter(i - 2, j + 1) == '2')
									{
										newLocations.at(3) = std::to_string(i - 2) + std::to_string(j + 2);
										return newLocations;
									}									
								}
							}							
							newLocations = oldLocations;
					    }					
					}
				}
			}
		}
		newLocations = oldLocations;
	}
	
	return newLocations;
}
