#include <iostream>

#include "board.hpp"

// проверяем, указывает ли 'position' на валидное место на доске
bool Board::validatePosition(const Position& position)
{
    if (position.col < 0 || position.col >= boardSize_)
    {
        return false;
    }

    if (position.row < 0 || position.row >= boardSize_)
    {
        return false;
    }

    return true;
}

// добавить фигуру на доску
bool Board::addFigure(std::unique_ptr<Figure>&& figure)
{
    Position pos = figure->getPosition();

    if (!validatePosition(pos))
    {
        return false;
    }

    bool result = false;

    if (board_[pos.row][pos.col] == '.')
    {
        board_[pos.row][pos.col] = figure->getSign();
        figures_.emplace_back(std::move(figure));
        result = true;
    }

    return result;
}

// передвинуть фигуру под указанным 'id' на случайно сгенерированную позицию
bool Board::moveFigureRandomly(int id)
{
    if (id >= figures_.size())
    {
        return false;
    }

    Position prevPosition = figures_[id]->getPosition();

    // фигура сама генерирует случайную позицию,
    // эта позиция валидна с точки зрения возможных ходов фигуры
    Position newPosition  = figures_[id]->generateRandomMove(boardSize_);

    if (!validatePosition(prevPosition) || !validatePosition(newPosition))
    {
        return false;
    }

    bool result = false;

    if (board_[newPosition.row][newPosition.col] == '.')
    {
        bool pathBlocked = false;
        for (int i = 0; i < figures_.size(); ++i)
        {
            if (id != i && figures_[id]->isPathBlockedByOtherFigure(newPosition, figures_[i]->getPosition()))
            {
                pathBlocked = true;
                break;
            }
        }

        if (!pathBlocked)
        {
            board_[prevPosition.row][prevPosition.col] = '.';
            board_[newPosition.row][newPosition.col] = figures_[id]->getSign();
            figures_[id]->setPosition(newPosition);
            std::cout << "Figure with id=" << id << " moved to position: " << figures_[id]->getPosition() << "\n";
            printBoard();
            result = true;
        }
    }

    return result;
}

// отрисовать текущее состояние доски
void Board::printBoard() const
{
    for (const auto& row : board_)
    {
        for (const auto& cell : row)
        {
            std::cout << cell << ' ';
        }
        std::cout << '\n';
    }

    std::cout << "-----------------\n";
}