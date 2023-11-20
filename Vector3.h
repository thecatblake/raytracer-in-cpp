//
// Created by ryousuke kaga on 2023/11/20.
//

#ifndef RAYTRACER_IN_CPP_VECTOR3_H
#define RAYTRACER_IN_CPP_VECTOR3_H

#include <limits>
#include <tuple>
#include <algorithm>
#include "Math.h"

class Vector3 {
public:
    double x{};
    double y{};
    double z{};

    constexpr Vector3() : x(0), y(0), z(0) {}

    constexpr Vector3(double x_, double y_, double z_) : x(x_), y(y_), z(z_) {}

    template <typename U>
    Vector3(const std::initializer_list<U>& lst);
    constexpr Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.z) {}

    void set(double s);
    void set(double x, double y, double z);
    template <typename U>
    void set(const std::initializer_list<U>& lst);
    void set(const Vector3& v);
    void setZero();
    void normalize();
    Vector3 add(double v) const;
    Vector3 add(const Vector3& v) const;
    Vector3 sub(double v) const;
    Vector3 sub(const Vector3& v) const;
    Vector3 mul(double v) const;
    Vector3 mul(const Vector3& v) const;
    Vector3 div(double v) const;
    Vector3 div(const Vector3& v) const;
    double dot(const Vector3& v) const;
    Vector3 cross(const Vector3& v) const;
    Vector3 rsub(double v) const;
    Vector3 rsub(const Vector3& v) const;
    Vector3 rdiv(double v) const;
    Vector3 rdiv(const Vector3& v) const;
    Vector3 rcross(const Vector3& v) const;
    void iadd(double v);
    void iadd(const Vector3& v);
    void isub(double v);
    void isub(const Vector3& v);
    void imul(double v);
    void imul(const Vector3& v);
    void idiv(double v);
    void idiv(const Vector3& v);
    const double& at(size_t i) const;
    double& at(size_t i);
    double sum() const;
    double avg() const;
    double min() const;
    double max() const;
    double absmin() const;
    double absmax() const;
    size_t dominantAxis() const;
    size_t subminantAxis() const;
    Vector3 normalized() const;
    double length() const;
    double lengthSquared() const;
    double distancedoubleo(const Vector3& other) const;
    double distanceSquareddoubleo(const Vector3& other) const;
    Vector3 reflected(const Vector3& normal) const;
    Vector3 projected(const Vector3& normal) const;
    std::tuple<Vector3, Vector3> tangential() const;
    bool isEqual(const Vector3& other) const;
    bool isSimilar(const Vector3& other,
                   double epsilon = std::numeric_limits<double>::epsilon()) const;
    double& operator[](size_t i);
    const double& operator[](size_t i) const;
    template <typename U>
    Vector3& operator=(const std::initializer_list<U>& lst);
    Vector3& operator=(const Vector3& v);
    Vector3& operator+=(double v);
    Vector3& operator+=(const Vector3& v);
    Vector3& operator-=(double v);
    Vector3& operator-=(const Vector3& v);
    Vector3& operator*=(double v);
    Vector3& operator*=(const Vector3& v);
    Vector3& operator/=(double v);
    Vector3& operator/=(const Vector3& v);
    bool operator==(const Vector3& v) const;
    bool operator!=(const Vector3& v) const;
};


Vector3 operator+(const Vector3& a);


Vector3 operator-(const Vector3& a);


Vector3 operator+(double a, const Vector3& b);


Vector3 operator+(const Vector3& a, const Vector3& b);


Vector3 operator-(const Vector3& a, double b);


Vector3 operator-(double a, const Vector3& b);


Vector3 operator-(const Vector3& a, const Vector3& b);


Vector3 operator*(const Vector3& a, double b);


Vector3 operator*(double a, const Vector3& b);


Vector3 operator*(const Vector3& a, const Vector3& b);


Vector3 operator/(const Vector3& a, double b);


Vector3 operator/(double a, const Vector3& b);


Vector3 operator/(const Vector3& a, const Vector3& b);


Vector3 min(const Vector3& a, const Vector3& b);


Vector3 max(const Vector3& a, const Vector3& b);


Vector3 clamp(const Vector3& v, const Vector3& low,
              const Vector3& high);


Vector3 ceil(const Vector3& a);


Vector3 floor(const Vector3& a);

double absDot(const Vector3& v1, const Vector3& v2);

double minComponent(const Vector3& v);
double maxComponent(const Vector3& v);
double maxDimension(const Vector3& v);
Vector3 permute(const Vector3& v, int x, int y, int z);
void coordinateSystem(const Vector3& v1, Vector3* v2, Vector3* v3);


#endif //RAYTRACER_IN_CPP_VECTOR3_H
