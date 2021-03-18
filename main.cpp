#include <iostream>

#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"

void intro()
{
    std::cout << "Dawid (----39)" << "\n";
    std::cout << "Grupa: Sroda 13:15 (MW)" << "\n" << "\n";
}

int main()
{
    intro();
    srand(time(nullptr));

    MinesweeperBoard board(10, 10, DEBUG);
    MSBoardTextView view(board);

    //------------------------------------------------

    board.debugDisplay();

    //------------------------------------------------

    view.display();

    //------------------------------------------------

    board.revealField(1, 2);
    view.display();

    //------------------------------------------------

    board.revealField(1, 5);
    view.display();

    //------------------------------------------------

    board.revealField(3, 7);
    view.display();

    //------------------------------------------------

    board.revealField(0, 3);
    view.display();
}
