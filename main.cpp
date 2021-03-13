#include <iostream>
#include <string>

void intro()
{
    std::cout << "Dawid (----39)" << "\n";
    std::cout << "Grupa: Sroda 13:15 (MW)" << "\n" << "\n";
}

struct Field
{
    bool hasMine;
    bool hasFlag;
    bool isRevealed;
};

class MinesweeperBoard
{
    Field board[100][100];    // 100-elementowa tablica, 100-elementowych tablic typu Field
    int width;                // rzeczywista szerokość planszy
    int height;               // rzeczywista wysokość planszy

public:
    MinesweeperBoard();
    void debug_display() const;
};

MinesweeperBoard::MinesweeperBoard()
{
    width = 5;
    height = 3;

    for(int col=0;col < height;++col)
    {
        for(int row=0;row < width; ++row)
        {
            board[row][col].hasMine = false;
            board[row][col].hasFlag = false;
            board[row][col].isRevealed = false;
        }
    }

    board[0][0].hasMine = 1;
    board[1][1].isRevealed = 1;
    board[2][0] = {.hasMine=1, .hasFlag=1};
}

void MinesweeperBoard::debug_display() const
{
    for(int col=0;col < height;++col)
    {
        for(int row=0;row < width; ++row)
        {
            std::string fld = "[]";

            board[row][col].hasMine == 1 ? fld.insert(1, "M") : fld.insert(1, ".");
            board[row][col].isRevealed == 1 ? fld.insert(2, "o") : fld.insert(2, ".");
            board[row][col].hasFlag == 1 ? fld.insert(3, "f") : fld.insert(3, ".");
            std::cout << fld;
        }
        std::cout << std::endl;
    }
}

int main()
{
    intro();

    MinesweeperBoard mb;

    mb.debug_display();
}