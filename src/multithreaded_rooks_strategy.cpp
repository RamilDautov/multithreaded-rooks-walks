#include <iostream>
#include "multithreaded_rooks_strategy.hpp"

MultithreadedRooksStrategy::MultithreadedRooksStrategy(
    int boardSize,
    int minNumRooks,
    int maxNumRooks
) : board_(std::make_unique<Board>(boardSize))
{
    // генерируем случайное количество ладей
    numRooks_ = randGenerator_.generateRandomNumber(minNumRooks, maxNumRooks);
    std::cout << "Number of rooks = " << numRooks_ << "\n";
}

void MultithreadedRooksStrategy::rookThread(int id)
{
    int move = 0;
    while (move < numMoves_)
    {
        auto startTime = std::chrono::steady_clock::now();
        int64_t elapsedTime = 0;

        bool figureMoved = false;

        // пока ладья не совершит ход или не истечет время ожидания
        while (!figureMoved && elapsedTime < timeout_)
        {
            {
                // критическая секция, блокируем доступ к доске
                std::lock_guard<std::mutex> lg{mutex_};
                figureMoved = board_->moveFigureRandomly(id);
            }

            elapsedTime =
                std::chrono::duration_cast<std::chrono::milliseconds>(
                    std::chrono::steady_clock::now() - startTime
                )
                .count()
                ;
        }

        if (figureMoved)
        {
            ++move;

            // пауза от 200 до 300 миллисекунд
            auto sleep_time = randGenerator_.generateRandomNumber(200, 300);
            std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time));
        }
    }
}

void MultithreadedRooksStrategy::run()
{
    int rooksCount = 0;

    int boardSize = board_->getSize();

    // расставляем ладьи на доске
    while (rooksCount < numRooks_)
    {
        int row = randGenerator_.generateRandomNumber(0, boardSize);
        int col = randGenerator_.generateRandomNumber(0, boardSize);

        if (board_->addFigure(std::make_unique<Rook>(Position{row, col})))
        {
            ++rooksCount;
        }
    }

    std::cout << "Starting positions of figures\n";

    board_->printBoard();

    std::cout << "Run threads...\n";

    for (int i = 0; i < numRooks_; ++i)
    {
        threads_.emplace_back(&MultithreadedRooksStrategy::rookThread, this, i);
    }

    for (auto& thread : threads_)
    {
        thread.join();
    }

    std::cout << "All threads stopped\n";
}