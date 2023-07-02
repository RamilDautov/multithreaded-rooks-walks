#include "rook.hpp"

Position Rook::generateRandomMove(int boardSize)
{
    Position newPosition;
    bool validMove = false;

    while (!validMove)
    {
        int row = randGenerator_.generateRandomNumber(0, boardSize);
        int col = randGenerator_.generateRandomNumber(0, boardSize);
        
        newPosition = {row, col};
        if ((newPosition.row == currentPosition_.row) != (newPosition.col == currentPosition_.col))
        {
            validMove = true;
        }
    }

    return newPosition;
}

bool Rook::isPathBlockedByOtherFigure(const Position& newPosition, const Position& otherFigurePos) const
{
    bool blocked = false;

    // если ход по горизонтали
    if (currentPosition_.row == newPosition.row)
    {
        // другая фигура стоит на той же горизонтали, правее текущей ладьи
        if (currentPosition_.row == otherFigurePos.row && currentPosition_.col < otherFigurePos.col)
        {
            // путь заблокирован, если новая позиция правее другой фигуры или на той же вертикали
            blocked = newPosition.col >= otherFigurePos.col;
        }

        // другая фигура стоит на той же горизонтали, левее текущей ладьи 
        if (currentPosition_.row == otherFigurePos.row && currentPosition_.col > otherFigurePos.col)
        {
            // путь заблокирован, если новая позиция левее другой фигуры или на той же вертикали
            blocked = newPosition.col <= otherFigurePos.col;
        }
    }

    // если ход по вертикали
    if (currentPosition_.col == newPosition.col)
    {
        // другая фигура стоит на той же вертикали, ниже текущей ладьи
        if (currentPosition_.col == otherFigurePos.col && currentPosition_.row < otherFigurePos.row)
        {
            // путь заблокирован, если новая позиция ниже другой фигуры или на той же горизонтали
            blocked = newPosition.row >= otherFigurePos.row;
        }

        // другая фигура стоит на той же горизонтали, выше текущей ладьи
        if (currentPosition_.row == otherFigurePos.row && currentPosition_.row > otherFigurePos.row)
        {
            // путь заблокирован, если новая позиция выше другой фигуры или на той же горизонтали
            blocked = newPosition.row <= otherFigurePos.row;
        }
    }

    return blocked;
}