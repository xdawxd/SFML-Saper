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
    std::cout << "--------------------------------------------------------------" << std::endl;
    std::cout << "Specify the row, column and an action separated by a spacebar." << std::endl;
    std::cout << "for example:" << std::endl;
    std::cout << "2 2 r - will reveal the filed at row = 2, column = 2" << std::endl;
    std::cout << "1 3 f - will place a flag at row = 1, column = 3" << std::endl;
    std::cout << "Not existing field will throw an error" << std::endl;
    std::cout << "--------------------------------------------------------------" << std::endl;
    while (true)
    {
        playerView.display();

        if (playerBoard.getGameState() != RUNNING)
            break;

        int row, col;
        char choice;

        std::cin >> row >> col >> choice;

        if (playerBoard.getFieldInfo(row, col) == '#')
            std::cout << "No such field" << std::endl;

        else if ((char)tolower(choice) == 'r')
            playerBoard.revealField(row, col);

        else if ((char)tolower(choice) == 'f')
            playerBoard.toggleFlag(row, col);
    }
}