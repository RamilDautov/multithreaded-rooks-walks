#if !defined(_MULTITHREADED_ROOKS_STRATEGY_H_)
#define _MULTITHREADED_ROOKS_STRATEGY_H_

#include <memory>
#include <mutex>
#include <thread>

#include "strategy.hpp"
#include "rook.hpp"
#include "board.hpp"
#include "random.hpp"


class MultithreadedRooksStrategy final : public Strategy
{
public:
    MultithreadedRooksStrategy(int boardSize, int minNumRooks = 4, int maxNumRooks = 6);

    ~MultithreadedRooksStrategy() = default;

    void run() override;

    void rookThread(int id);

private:
    std::mutex mutex_;

    // время ожидания когда освободится путь
    // в миллисекундах
    int64_t timeout_{5000};

    // количество шагов для каждой ладьи
    int numMoves_{50};

    // количество ладей
    int numRooks_;

    RandomGenerator randGenerator_;

    std::vector<std::thread> threads_;
    std::unique_ptr<Board> board_;
};

#endif // _MULTITHREADED_ROOKS_STRATEGY_H_