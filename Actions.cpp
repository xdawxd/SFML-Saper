#include "Actions.h"

Actions::Actions(MinesweeperBoard& board, MSSFMLView& view) : board(board), view(view)
{
}

void Actions::addEvents(sf::Event& event) const
{
    int x = event.mouseButton.x;
    int y = event.mouseButton.y;

    if ((x >= 560 && x <= 760) && (y >= 120 && y <= 195))
    {
        board.setBoard();
        board.clearMoves();
        board.debugDisplay();
    }

    else if ((x >= 560 && x <= 760) && (y >= 240 && y <= 275))
    {
        board.setDifficulty(EASY);
        board.clearMoves();
        board.debugDisplay();
    }

    else if ((x >= 560 && x <= 760) && (y >= 320 && y <= 355))
    {
        board.setDifficulty(NORMAL);
        board.clearMoves();
        board.debugDisplay();
    }

    else if ((x >= 560 && x <= 760) && (y >= 400 && y <= 435))
    {
        board.setDifficulty(HARD);
        board.clearMoves();
        board.debugDisplay();
    }
}

void Actions::lmbPressed(sf::Event& event) const
{
    int row = event.mouseButton.y / 40 - 3;
    int col = event.mouseButton.x / 40 - 2;

    board.revealAmount();
    board.floodFill(row, col);
    board.revealField(row, col);
    board.countMoves();
}

void Actions::rmbPressed(sf::Event& event) const
{
    int row = event.mouseButton.y / 40 - 3;
    int col = event.mouseButton.x / 40 - 2;

	board.toggleFlag(row, col);
}
