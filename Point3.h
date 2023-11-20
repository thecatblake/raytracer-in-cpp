//
// Created by ryousuke kaga on 2023/11/20.
//

#ifndef RAYTRACER_IN_CPP_POINT3_H
#define RAYTRACER_IN_CPP_POINT3_H


#include "Vector3.h"

class Point3 {
public:
    double x, y, z;

    Point3();
    Point3(double x, double y, double z);

    Point3 operator+(const Vector3& v) const;
    Point3& operator+=(const Vector3& v);
    Vector3 operator-(const Point3& v) const;
    Point3 operator-(const Vector3& v) const;
    Point3& operator-=(const Vector3& v);

    double& operator[](size_t i);
    const double& operator[](size_t i) const;
};

Point3 operator*(const Point3& a, double b);
Point3 operator*(double a, const Point3& b);

Point3 min(const Point3& p1, const Point3& p2);
Point3 max(const Point3& p1, const Point3& p2);
Point3 floor(const Point3& p);
Point3 ceil(const Point3& p);
Point3 abs(const Point3& p);
Point3 permute(const Point3& p, int x, int y, int z);

double distance(const Point3& p1, const Point3& p2);
double distanceSquared(const Point3& p1, const Point3& p2);
Point3 lerp(double t, const Point3& p1, const Point3& p2);

#endif //RAYTRACER_IN_CPP_POINT3_H
