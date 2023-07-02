#include "game_context.hpp"
#include "multithreaded_rooks_strategy.hpp"

int main()
{
    // задаем размер шахматной доски
    int boardSize = 8;

    // задаем контекст игры, выбирая стратегию
    GameContext context(
        std::make_unique<MultithreadedRooksStrategy>(boardSize)
    );

    // запускаем игру
    context.runGame();

    return 0;
}