//
// Created by ryousuke kaga on 2023/11/20.
//

#include "Math.h"

template <typename T>
inline bool similar(T x, T y, T eps) {
    return (std::abs(x - y) <= eps);
}

template <typename T>
inline T sign(T x) {
    if (x >= 0) {
        return 1;
    } else {
        return -1;
    }
}

template <typename T>
inline T min3(T x, T y, T z) {
    return std::min(std::min(x, y), z);
}

template <typename T>
inline T max3(T x, T y, T z) {
    return std::max(std::max(x, y), z);
}

template <typename T>
inline T minn(const T* x, size_t n) {
    T m = x[0];
    for (size_t i = 1; i < n; i++) {
        m = std::min(m, x[i]);
    }
    return m;
}

template <typename T>
inline T maxn(const T* x, size_t n) {
    T m = x[0];
    for (size_t i = 1; i < n; i++) {
        m = std::max(m, x[i]);
    }
    return m;
}

template <typename T>
inline T absmin(T x, T y) {
    return (x*x < y*y) ? x : y;
}

template <typename T>
inline T absmax(T x, T y) {
    return (x*x > y*y) ? x : y;
}

template <typename T>
inline T absminn(const T* x, size_t n) {
    T m = x[0];
    for (size_t i = 1; i < n; i++) {
        m = absmin(m, x[i]);
    }
    return m;
}

template <typename T>
inline T absmaxn(const T* x, size_t n) {
    T m = x[0];
    for (size_t i = 1; i < n; i++) {
        m = absmax(m, x[i]);
    }
    return m;
}

template <typename T>
inline size_t argmin2(T x, T y) {
    return (x < y) ? 0 : 1;
}

template <typename T>
inline size_t argmax2(T x, T y) {
    return (x > y) ? 0 : 1;
}

template <typename T>
inline size_t argmin3(T x, T y, T z) {
    if (x < y) {
        return (x < z) ? 0 : 2;
    } else {
        return (y < z) ? 1 : 2;
    }
}

template <typename T>
inline size_t argmax3(T x, T y, T z) {
    if (x > y) {
        return (x > z) ? 0 : 2;
    } else {
        return (y > z) ? 1 : 2;
    }
}

template <typename T>
inline T square(T x) {
    return x * x;
}

template <typename T>
inline T cubic(T x) {
    return x * x * x;
}

template <typename T>
inline T clamp(T val, T low, T high) {
    if (val < low) {
        return low;
    } else if (val > high) {
        return high;
    } else {
        return val;
    }
}

template <typename T>
inline T degreesToRadians(T angleInDegrees) {
    return angleInDegrees * pi<T>() / 180;
}

template <typename T>
inline T radiansToDegrees(T angleInRadians) {
    return angleInRadians * 180 / pi<T>();
}

template<typename T>
inline void getBarycentric(
        T x,
        ssize_t iLow,
        ssize_t iHigh,
        ssize_t* i,
        T* f) {
    T s = std::floor(x);
    *i = static_cast<ssize_t>(s);

    ssize_t offset = -iLow;
    iLow += offset;
    iHigh += offset;

    if (iLow == iHigh) {
        *i = iLow;
        *f = 0;
    } else if (*i < iLow) {
        *i = iLow;
        *f = 0;
    } else if (*i > iHigh - 1) {
        *i = iHigh - 1;
        *f = 1;
    } else {
        *f = static_cast<T>(x - s);
    }

    *i -= offset;
}