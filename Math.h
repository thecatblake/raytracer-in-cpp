//
// Created by ryousuke kaga on 2023/11/20.
//

#ifndef RAYTRACER_IN_CPP_MATH_H
#define RAYTRACER_IN_CPP_MATH_H

#include <cstddef>
#include <limits>
#include <cmath>
#include <algorithm>

template <typename T>
inline bool similar(T x, T y, T eps = std::numeric_limits<T>::epsilon());

template <typename T>
inline T sign(T x);

template <typename T>
inline T min3(T x, T y, T z);

template <typename T>
inline T max3(T x, T y, T z);

template <typename T>
inline T minn(const T* x, size_t n);

template <typename T>
inline T maxn(const T* x, size_t n);

template <typename T>
inline T absmin(T x, T y);

template <typename T>
inline T absmax(T x, T y);

template <typename T>
inline T absminn(const T* x, size_t n);

template <typename T>
inline T absmaxn(const T* x, size_t n);

template <typename T>
inline size_t argmin2(T x, T y);

template <typename T>
inline size_t argmax2(T x, T y);

template <typename T>
inline size_t argmin3(T x, T y, T z);

template <typename T>
inline size_t argmax3(T x, T y, T z);

template <typename T>
inline T square(T x);

template <typename T>
inline T cubic(T x);

template <typename T>
inline T clamp(T val, T low, T high);

template <typename T>
inline T degreesToRadians(T angleInDegrees);

template <typename T>
inline T radiansToDegrees(T angleInRadians);

#endif //RAYTRACER_IN_CPP_MATH_H
