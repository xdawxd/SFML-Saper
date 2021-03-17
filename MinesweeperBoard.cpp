#include "MinesweeperBoard.h"
#include <iostream>

void MinesweeperBoard::createDebugBoard()
{
    for (int row = 0; row < height; ++row)
    {
        for (int col = 0; col < width; ++col)
        {
            if (row == col || row == 0 || (col == 0 && row % 2 == 0))
                board[row][col].hasMine = true;
        }
    }
}

void MinesweeperBoard::placeRandomMine()
{
    int randRow = rand() % height;
    int randCol = rand() % width;

    if (board[randRow][randCol].hasMine)
        placeRandomMine();
    else
        board[randRow][randCol].hasMine = true;
}

void MinesweeperBoard::createRandomBoard()
{
    for (int mines = 0; mines < numOfMines; ++mines)
        placeRandomMine();
}

MinesweeperBoard::MinesweeperBoard(int width, int height, GameMode mode)
{
    this->width = width;
    this->height = height;
    this->mode = mode;
    int numOfMines = 0;
    state = RUNNING;
    firstAction = true;

    for (int row = 0; row < height; ++row)
    {
        for (int col = 0; col < width; ++col)
        {
            board[row][col] = { 0, 0, 0 };
        }
    }

    switch (mode)
    {
    case EASY:
        numOfMines = width * height * 0.1;
        break;
    case NORMAL:
        numOfMines = width * height * 0.2;
        break;
    case HARD:
        numOfMines = width * height * 0.3;
        break;
    case DEBUG:
        createDebugBoard();
        break;
    }

    this->numOfMines = numOfMines;
    createRandomBoard();
}

int MinesweeperBoard::getBoardWidth() const
{
    return width;
}

int MinesweeperBoard::getBoardHeight() const
{
    return height;
}

int MinesweeperBoard::getMineCount() const
{
    return numOfMines;
}

int MinesweeperBoard::countMines(int boardRow, int boardCol) const
{
    int count = 0;

    if (getFieldInfo(boardRow, boardCol) == '#' ||
        !board[boardRow][boardCol].isRevealed)
        return -1;

    for (int row = -1; row <= 1; ++row)
    {
        for (int col = -1; col <= 1; ++col)
        {
            if (((boardRow + row) >= 0 && (boardRow + row) < height) &&
                ((boardCol + col) >= 0 && (boardCol + col) < width) &&
                board[boardRow + row][boardCol + col].hasMine)
                count++;
        }
    }
    return count;
}

bool MinesweeperBoard::hasFlag(int row, int col) const
{
    if (board[row][col].hasFlag)
        return true;

    if (getFieldInfo(row, col) == '#' ||
        board[row][col].isRevealed ||
        !board[row][col].hasFlag)
        return false;
    return 0;
}

void MinesweeperBoard::toggleFlag(int row, int col)
{
    if (board[row][col].isRevealed ||
        getFieldInfo(row, col) == '#' ||
        state != RUNNING)
        return;

    if (!board[row][col].isRevealed)
        board[row][col].hasFlag = true;
}

void MinesweeperBoard::revealField(int row, int col)
{
    if (board[row][col].isRevealed ||
        getFieldInfo(row, col) == '#'
        || state != RUNNING ||
        board[row][col].hasFlag)
        return;

    if (!board[row][col].isRevealed && !board[row][col].hasMine)
        board[row][col].isRevealed = true;

    if (!board[row][col].isRevealed && board[row][col].hasMine)
    {
        if (firstAction && mode != DEBUG)
        {
            board[row][col].hasMine = false;

            while (true)
            {
                int randRow = rand() % height;
                int randCol = rand() % width;

                if (!board[randRow][randCol].hasMine)
                {
                    board[randRow][randCol].hasMine = true;
                    break;
                }
            }
            board[row][col].isRevealed = true;
            firstAction = false;
        }
    }
}

bool MinesweeperBoard::isRevealed(int row, int col) const
{
    if (board[row][col].isRevealed)
        return true;
    return false;
}

GameState MinesweeperBoard::getGameState() const
{
    return state;
}

char MinesweeperBoard::getFieldInfo(int row, int col) const
{
    if (row < 0 || row >= height || col < 0 || col >= width)
        return '#';

    if (!board[row][col].isRevealed && board[row][col].hasFlag)
        return 'F';

    if (!board[row][col].isRevealed || !board[row][col].hasFlag)
        return '_';

    if (board[row][col].isRevealed && board[row][col].hasMine)
        return 'x';

    if (board[row][col].isRevealed && countMines(row, col) > 1)
        return countMines(row, col);
    return 0;
}

void MinesweeperBoard::debugDisplay() const
{
    for (int row = 0; row < height; ++row)
    {
        for (int col = 0; col < width; ++col)
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
