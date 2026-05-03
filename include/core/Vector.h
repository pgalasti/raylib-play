#ifndef GPLAY_VECTORS_H
#define GPLAY_VECTORS_H

#include <cmath>
#include <type_traits>

namespace GPlay::Core {

// Simple vector structs. Meant for game logic and not SIMD
template <typename T>
struct Vector2D {
  T x;
  T y;

  using FloatT = std::common_type_t<T, float>;

  FloatT length() const {
    return std::sqrt(static_cast<FloatT>(x * x + y * y));
  }

  Vector2D<FloatT> normalize() const {
    FloatT len = length();
    if (len == FloatT{0}) return {FloatT{0}, FloatT{0}};
    return {x / len, y / len};
  }
};

} // namespace GPlay::Core

#endif // GPLAY_VECTORS_H guard
