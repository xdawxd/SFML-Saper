#include <iostream>

#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"

void intro()
{
    std::cout << "Dawid (----39)" << "\n";
    std::cout << "Grupa: Sroda 13:15 (MW)" << "\n" << "\n";
}

int main()
{
    intro();
    srand(time(nullptr));

    MinesweeperBoard board(5, 5, NORMAL);
    MSBoardTextView view(board);
    MSTextController ctrl(board, view);

    ctrl.play();
}
