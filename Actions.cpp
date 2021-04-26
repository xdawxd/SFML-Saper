#include "Actions.h"

Actions::Actions(MinesweeperBoard& board, sf::Event event, MSSFMLView& view) : board(board), event(event), view(view)
{
    row = event.mouseButton.y / 40 - 3;
    col = event.mouseButton.x / 40 - 2;
    x = event.mouseButton.x;
    y = event.mouseButton.y;
}

void Actions::addEvents() const
{
    if ((x >= 560 && x <= 760) && (y >= 120 && y <= 195))
    {
        board.setBoard();
        board.debugDisplay();
    }

    else if ((x >= 560 && x <= 760) && (y >= 240 && y <= 275))
    {
        board.setDifficulty(EASY);
        board.debugDisplay();
    }

    else if ((x >= 560 && x <= 760) && (y >= 320 && y <= 355))
    {
        board.setDifficulty(NORMAL);
        board.debugDisplay();
    }

    else if ((x >= 560 && x <= 760) && (y >= 400 && y <= 435))
    {
        board.setDifficulty(HARD);
        board.debugDisplay();
    }
}

void Actions::lmbPressed() const
{
    view.revealAmount();
    view.floodFill(row, col);
}

void Actions::rmbPressed() const
{
	board.toggleFlag(row, col);
}
