#include "vecXZ.h"

bool operator ==(const vecXZ& left, const vecXZ& right) noexcept {
    return  (left.x == right.x) && (left.z == right.z);
}