#include "Random.h"

std::mt19937 Random::engine;

void Random::setSeed(unsigned int s) {
    engine.seed(s);
}