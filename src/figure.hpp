#if !defined(_FIGURE_H_)
#define _FIGURE_H_

#include <vector>
#include <iostream>

struct Position
{
    int row;
    int col;

    friend std::ostream& operator<< (std::ostream& os, const Position& pos)
    {
        os << "(" << pos.row << ", " << pos.col << ")";
        return os;
    }
};

class Figure
{
public:
    Figure(const char sign, const Position&& position) : sign_(sign), currentPosition_(position) {};

    virtual ~Figure() = default;

    virtual Position generateRandomMove(int boardSize) = 0;

    virtual bool isPathBlockedByOtherFigure(const Position& newPosition, const Position& otherFigurePos) const = 0;

    char getSign() const { return sign_; }
    
    Position getPosition() const { return currentPosition_; }
    void setPosition(const Position& newPosition) { currentPosition_ = newPosition; };

protected:
    // обозначение фигуры
    char sign_;

    // ее положение на доске
    Position currentPosition_;
};

#endif // _FIGURE_H_