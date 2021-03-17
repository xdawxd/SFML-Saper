#include "MinesweeperBoard.h"
#include <iostream>

void intro()
{
    std::cout << "Dawid (----39)" << "\n";
    std::cout << "Grupa: Sroda 13:15 (MW)" << "\n" << "\n";
}

int main()
{
    intro();
    srand(time(nullptr));

    MinesweeperBoard board(10, 10, HARD);

    board.debugDisplay();
}