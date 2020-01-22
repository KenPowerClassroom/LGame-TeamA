#ifndef RENDERER_H
#define RENDERER_H

#include <iostream>
#include <windows.h>   // WinApi header
#include "Board.h"

struct Renderer
{
	static void drawBoard(Board t_board);
};

#endif