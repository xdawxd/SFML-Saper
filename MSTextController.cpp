#include <iostream>

#include "MSTextController.h"

MSTextController::MSTextController(MinesweeperBoard& board, MSBoardTextView& view):
playerBoard(board), playerView(view)
{
    height = board.getBoardHeight();
    width = board.getBoardWidth();
}

void MSTextController::play()
{
    // f or F - Flag
    // r or R - Reveal
    std::cout << "Specify the row, column and an action separated by a spacebar." << std::endl;
    while (true)
    {
        playerView.display();

        int row, col;
        char choice;

        std::cin >> row >> col >> choice;

        if ((char)tolower(choice) == 'r')
            playerBoard.revealField(row, col);

        else if ((char)tolower(choice) == 'f')
            playerBoard.toggleFlag(row, col);

        else if (choice == 'x')
            break;
    }
}