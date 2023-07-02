#if !defined(_ROOK_H_)
#define _ROOK_H_

#include "figure.hpp"
#include "random.hpp"

class Rook final : public Figure
{
public:
    Rook(const Position&& position) : Figure('R', std::move(position)) {};

    Position generateRandomMove(int boardSize) override;

    bool isPathBlockedByOtherFigure(const Position& newPosition, const Position& otherFigurePos) const override;

private:
    RandomGenerator randGenerator_;
};

#endif // _ROOK_H_