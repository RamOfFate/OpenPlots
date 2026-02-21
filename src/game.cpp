#include <chrono>
#include <random>

namespace Game
{
    int rollDice()
    {
        const unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::default_random_engine engine(seed);
        std::uniform_int_distribution<int> distrib(1, 6);
        const int dice = distrib(engine);
        return dice;
    }
}
