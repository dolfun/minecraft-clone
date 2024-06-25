#ifndef VECXZ_H_INCLUDED
#define VECXZ_H_INCLUDED

#include <functional>
#include <glm/vec3.hpp>

struct vecXZ {
    int x, z;
};

bool operator ==(const vecXZ& left, const vecXZ& right) noexcept;

namespace std {
    template<> struct hash<vecXZ> {
        size_t operator()(const vecXZ& vect) const noexcept {
            std::hash<decltype(vect.x)> hasher;

            auto hash1 = hasher(vect.x);
            auto hash2 = hasher(vect.z);

            return std::hash<decltype(vect.x)>{}((hash1 ^ hash2) >> 2);
        }
    };
}

#endif
