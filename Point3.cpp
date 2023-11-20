//
// Created by ryousuke kaga on 2023/11/20.
//

#include "Point3.h"

Point3::Point3() {
    x = y = z = 0.0;
}

Point3::Point3(double x, double y, double z): x(x), y(y), z(z) {

}

Point3 Point3::operator+(const Vector3 &v) const {
    return {x+v.x, y+v.y, z*v.z};
}

Point3& Point3::operator+=(const Vector3 &v) {
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

Vector3 Point3::operator-(const Point3 &v) const {
    return {x-v.x, y-v.y, z-v.z};
}

Point3 Point3::operator-(const Vector3 &v) const {
    return {x-v.x, y-v.y, z-v.z};
}

Point3& Point3::operator-=(const Vector3 &v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}

double &Point3::operator[](size_t i) {
    return (&x)[i];
}

const double &Point3::operator[](size_t i) const {
    return (&x)[i];
}

Point3 operator*(const Point3& a, double b) {
    return {a.x*b, a.y*b, a.z*b};
}
Point3 operator*(double a, const Point3& b) {
    return {a*b.x, a*b.y, a*b.z};
}

Point3 min(const Point3& p1, const Point3& p2) {
    return {std::min(p1.x, p2.x), std::min(p1.y, p2.y), std::min(p1.z, p2.z)};
}
Point3 max(const Point3& p1, const Point3& p2) {
    return {std::max(p1.x, p2.x), std::max(p1.y, p2.y), std::max(p1.z, p2.z)};
}
Point3 floor(const Point3& p) {
    return {std::floor(p.x), std::floor(p.y), std::floor(p.z)};
}
Point3 ceil(const Point3& p) {
    return {std::ceil(p.x), std::ceil(p.y), std::ceil(p.z)};
}
Point3 abs(const Point3& p) {
    return {std::abs(p.x), std::abs(p.y), std::abs(p.z)};
}
Point3 permute(const Point3& p, int x, int y, int z) {
    return {p[x], p[y], p[z]};
}
double distance(const Point3& p1, const Point3& p2) {
    return (p1 - p2).length();
}

double distanceSquared(const Point3& p1, const Point3& p2) {
    return (p1 - p2).lengthSquared();
}

Point3 lerp(double t, const Point3& p1, const Point3& p2) {
    return (1-t) * p1 + t * p2;
}