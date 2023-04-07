#ifndef MATH_H
#define MATH_H

/**
 * @file Math.h
 * @brief Math functions.
 */
namespace Math {
    template <typename T> inline constexpr
    static int signum(T x) {
        return (T(0) < x) - (x < T(0));
    }
};

#endif 