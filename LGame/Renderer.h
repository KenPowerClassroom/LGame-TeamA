#ifndef RENDERER_H
#define RENDERER_H

#include <iostream>
#include <windows.h>   // WinApi header
#include "Board.h"

class Renderer
{

public:
	static void drawBoard(Board t_board);

private:
	static void changeTextColor(int t_color);
};

#endif