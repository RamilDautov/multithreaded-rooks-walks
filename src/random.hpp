#if !defined(_RANDOM_GENERATOR_H_)
#define _RANDOM_GENERATOR_H_

#include <random>

class RandomGenerator
{
public:
    int generateRandomNumber(int min, int max)
    {
        static thread_local std::mt19937 engine;
        std::uniform_int_distribution<int> distribution(min, max);
        return distribution(engine);
    }
};

#endif // _RANDOM_GENERATOR_H_