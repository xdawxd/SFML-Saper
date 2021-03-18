#ifndef MSBOARDTEXTVIEW_H__
#define MSBOARDTEXTVIEW_H__

#include "MinesweeperBoard.h"

class MSBoardTextView
{
	int width;
	int height;
	GameState state;
	MinesweeperBoard& displayableBoard;

public:
	MSBoardTextView(MinesweeperBoard& board);

	void display();
};

#endif
