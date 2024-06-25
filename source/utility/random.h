#pragma once
#ifndef RANDOM_H_INCLUDED
#define RANDOM_H_INCLUDED

#include <random>

class Random {
public:
    static void setSeed(unsigned int s);

    template<typename T>
    static T intInRange(T low, T high) {
        static_assert(std::is_integral<T>::value, "Not integral type!");
        std::uniform_int_distribution<T> dist(low, high);
        return dist(engine);
    }

    Random(const Random& generator) = delete;
    Random operator=(const Random& generator) = delete;
    Random(Random&& generator);
    Random& operator=(Random&& generator);

private:
    static std::mt19937 engine;
};

#endif