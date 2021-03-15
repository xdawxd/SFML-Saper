#include "MinesweeperBoard.h"
#include <iostream>

MinesweeperBoard::MinesweeperBoard(int width, int height, GameMode mode)
{
    this->width = width;
    this->height = height;
    this->mode = mode;
    int numOfMines = 0;
    state = RUNNING;
    firstAction = false;

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

    board[width][height] = {};

    this->numOfMines = numOfMines;
    createRandomBoard();
}

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

void MinesweeperBoard::createRandomBoard()
{
    for (int mines = 0; mines < numOfMines; ++mines)
    {
        int randRow = rand() % height;
        int randCol = rand() % width;

        board[randRow][randCol].hasMine = true;
    }
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

int MinesweeperBoard::countMines(int row, int col) const
{
    int count = 0;

    if (getFieldInfo(row, col) == '#' ||
        !isRevealed(row, col))
        return -1;

    for (int i = -1; i <= 1; ++i)
    {
        for (int j = -1; j <= 1; ++j)
        {
<<<<<<< HEAD
            if (((row + i) >= 0 && (row + i) < height) &&
=======
            if (((row + i) >= 0 && (row + i) < height)&&
>>>>>>> 3fa5cdec306c91c3b780b1b1819e9f826d9692b7
                ((col +j) >=0 && (col + j) < width) &&
                board[row + i][col + j].hasMine)
                count++;
        }
    }
    return count;
}

bool MinesweeperBoard::hasFlag(int row, int col) const
{
    Field field = board[row][col];

    if (field.hasFlag)
        return true;

    if (getFieldInfo(row, col) == '#' ||
        isRevealed(row, col) ||
        !field.hasFlag)
        return false;
    return 0;
}

void MinesweeperBoard::toggleFlag(int row, int col)
{
    Field field = board[row][col];

    if (isRevealed(row, col))
        field.hasFlag = true;
    
    if (isRevealed(row, col) ||
        getFieldInfo(row, col) == '#' ||
        getGameState() != RUNNING)
        return;
}

void MinesweeperBoard::revealField(int row, int col)
{
    Field field = board[row][row];

    if (isRevealed(row, col) ||
        getFieldInfo(row, col) == '#'
        || getGameState() != RUNNING ||
        hasFlag(row, col))
        return;

    if (!isRevealed(row, col) && !field.hasMine)
        field.isRevealed = true;

    if (!isRevealed(row, col) && field.hasMine)
    {
        if (firstAction && mode != DEBUG)
        {
            int randRow = rand() % height;
            int randCol = rand() % width;

            board[row][col].hasMine = false;
            
<<<<<<< HEAD
            while (!board[randRow][randCol].hasMine && row != randRow && col != randCol)
=======
            while (!board[randRow][randCol].hasMine)
>>>>>>> 3fa5cdec306c91c3b780b1b1819e9f826d9692b7
            {
                board[randRow][randCol].hasMine = true;
                break;
            }
            firstAction = false;
        }
    }
}

bool MinesweeperBoard::isRevealed(int row, int col) const
{
    Field field = board[row][col];

    if (field.isRevealed)
        return true;
    return false;
}

GameState MinesweeperBoard::getGameState() const
{
    return state;
}

char MinesweeperBoard::getFieldInfo(int row, int col) const
{
    Field field = board[row][col];

    if (row < 0 || row >= height || col < 0 || col >= width) 
        return '#';

    if (!isRevealed(row, col) && hasFlag(row, col))
        return 'F';

    if (!isRevealed(row, col) || !hasFlag(row, col))
        return '_';

    if (isRevealed(row, col) && field.hasMine)
        return 'x';

    if (isRevealed(row, col) && countMines(row, col) > 1)
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