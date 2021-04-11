#ifndef MSBOARDTEXTCONTROLLER_H__
#define MSBOARDTEXTCONTROLLER_H__

#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"

class MSTextController
{
    int height;
    int width;
    MinesweeperBoard& playerBoard;
    MSBoardTextView& playerView;

public:
	MSTextController(MinesweeperBoard& board, MSBoardTextView& view);
	void play();
};

#endif
