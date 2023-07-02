#if !defined(_GAME_CONTEXT_H_)
#define _GAME_CONTEXT_H_

#include <iostream>
#include <memory>

#include "strategy.hpp"

class GameContext
{
public:
    explicit GameContext(std::unique_ptr<Strategy> &&strategy = {}) : strategy_(std::move(strategy))
    {
    }

    void setStrategy(std::unique_ptr<Strategy> &&strategy)
    {
        strategy_ = std::move(strategy);
    }

    void runGame() const
    {
        if (strategy_)
        {
            strategy_->run();
        }
        else
        {
            std::cout << "Context: Strategy isn't set\n";
        }
    }

private:
    std::unique_ptr<Strategy> strategy_;
};

#endif // _GAME_CONTEXT_H_