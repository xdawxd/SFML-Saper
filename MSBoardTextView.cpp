#include <iostream>

#include "MSBoardTextView.h"

MSBoardTextView::MSBoardTextView(MinesweeperBoard& board) : displayableBoard(board)
{
    height = board.getBoardHeight();
    width = board.getBoardWidth();
    state = board.getGameState();
}

void MSBoardTextView::display()
{
    std::cout << std::endl;
    for (int row = 0; row < height; ++row)
    {
        for (int col = 0; col < width; ++col)
        {
            if (displayableBoard.hasFlag(row, col))
                std::cout << " ⛳ ";

            else if (displayableBoard.hasMine(row, col) && displayableBoard.isRevealed(row, col))
            {
                std::cout << " 💥 ";
                state = FINISHED_LOSS;
            }

            else if (displayableBoard.isRevealed(row, col))
            {
                if (displayableBoard.countMines(row, col) == 0)
                    std::cout << " 🔲 ";
                else
                    std::cout << " " << displayableBoard.countMines(row, col) << " ";
            }

            else if (!displayableBoard.isRevealed(row, col))
                std::cout << " 🔳 ";
        }
        std::cout << std::endl;
    }

    if (state != RUNNING)
        state == FINISHED_WIN ? std::cout << "\nYOU WIN\n" : std::cout << "\nYOU LOSE\n";
}
