#include <iostream>

#include "MSBoardTextView.h"

MSBoardTextView::MSBoardTextView(MinesweeperBoard& board) : displayableBoard(board)
{
    height = board.getBoardHeight();
    width = board.getBoardWidth();
}

void MSBoardTextView::display()
{
    GameState state = displayableBoard.getGameState();

    std::cout << std::endl;
    for (int row = 0; row < height; ++row)
    {
        for (int col = 0; col < width; ++col)
        {
            char info = displayableBoard.getFieldInfo(row, col);

            if (info == 'F')
                std::cout << " ⛳ ";

            else if (info == 'x')
                std::cout << " 💥 ";

            else if (info == '_')
                std::cout << " 🔳 ";

            else if (info == '0')
                std::cout << " 🔲 ";

            else
                std::cout << " " << info << " ";
        }
        std::cout << std::endl;
    }

    if (state != RUNNING)
        state == FINISHED_WIN ? std::cout << "\nYOU WIN\n" : std::cout << "\nYOU LOSE\n";
}
