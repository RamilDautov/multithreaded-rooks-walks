#if !defined(_BOARD_H_)
#define _BOARD_H_

#include <vector>
#include <memory>

#include "figure.hpp"

class Board
{
public:
    explicit Board(int boardSize) : boardSize_(boardSize)
    {
        board_ = std::vector<std::vector<char>>(boardSize, std::vector<char>(boardSize, '.'));
    }

    int getSize() const { return boardSize_; }

    bool addFigure(std::unique_ptr<Figure>&& figure);

    bool moveFigureRandomly(int id);

    void printBoard() const;

private:
    bool validatePosition(const Position& position);

private:
    int boardSize_;
    std::vector<std::vector<char>> board_;
    std::vector<std::unique_ptr<Figure>> figures_;
};

#endif // _BOARD_H_