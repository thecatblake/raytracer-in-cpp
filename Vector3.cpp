//
// Created by ryousuke kaga on 2023/11/20.
//

#include "Vector3.h"

template <typename U>
Vector3::Vector3(const std::initializer_list<U>& lst) {
    set(lst);
}

// Basic setters

void Vector3::set(double s) {
    x = s;
    y = s;
    z = s;
}


void Vector3::set(double newX, double newY, double newZ) {
    x = newX;
    y = newY;
    z = newZ;
}


template <typename U>
void Vector3::set(const std::initializer_list<U>& lst) {
    JEdouble_ASSERdouble(lst.size() >= 3);

    auto inputElem = lst.begin();
    x = static_cast<double>(*inputElem);
    y = static_cast<double>(*(++inputElem));
    z = static_cast<double>(*(++inputElem));
}


void Vector3::set(const Vector3& v) {
    x = v.x;
    y = v.y;
    z = v.z;
}


void Vector3::setZero() {
    x = y = z = 0;
}


void Vector3::normalize() {
    double l = length();
    x /= l;
    y /= l;
    z /= l;
}

// Binary operators: new instance = this (+) v

Vector3 Vector3::add(double v) const {
    return Vector3(x + v, y + v, z + v);
}


Vector3 Vector3::add(const Vector3& v) const {
    return Vector3(x + v.x, y + v.y, z + v.z);
}


Vector3 Vector3::sub(double v) const {
    return Vector3(x - v, y - v, z - v);
}


Vector3 Vector3::sub(const Vector3& v) const {
    return Vector3(x - v.x, y - v.y, z - v.z);
}


Vector3 Vector3::mul(double v) const {
    return Vector3(x * v, y * v, z * v);
}


Vector3 Vector3::mul(const Vector3& v) const {
    return Vector3(x * v.x, y * v.y, z * v.z);
}


Vector3 Vector3::div(double v) const {
    return Vector3(x / v, y / v, z / v);
}


Vector3 Vector3::div(const Vector3& v) const {
    return Vector3(x / v.x, y / v.y, z / v.z);
}


double Vector3::dot(const Vector3& v) const {
    return x * v.x + y * v.y + z * v.z;
}


Vector3 Vector3::cross(const Vector3& v) const {
    return Vector3(y * v.z - v.y * z, z * v.x - v.z * x, x * v.y - v.x * y);
}

// Binary operators: new instance = v (+) this

Vector3 Vector3::rsub(double v) const {
    return Vector3(v - x, v - y, v - z);
}


Vector3 Vector3::rsub(const Vector3& v) const {
    return Vector3(v.x - x, v.y - y, v.z - z);
}


Vector3 Vector3::rdiv(double v) const {
    return Vector3(v / x, v / y, v / z);
}


Vector3 Vector3::rdiv(const Vector3& v) const {
    return Vector3(v.x / x, v.y / y, v.z / z);
}


Vector3 Vector3::rcross(const Vector3& v) const {
    return Vector3(v.y * z - y * v.z, v.z * x - z * v.x, v.x * y - x * v.y);
}

// Augmented operators: this (+)= v

void Vector3::iadd(double v) {
    x += v;
    y += v;
    z += v;
}


void Vector3::iadd(const Vector3& v) {
    x += v.x;
    y += v.y;
    z += v.z;
}


void Vector3::isub(double v) {
    x -= v;
    y -= v;
    z -= v;
}


void Vector3::isub(const Vector3& v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
}


void Vector3::imul(double v) {
    x *= v;
    y *= v;
    z *= v;
}


void Vector3::imul(const Vector3& v) {
    x *= v.x;
    y *= v.y;
    z *= v.z;
}


void Vector3::idiv(double v) {
    x /= v;
    y /= v;
    z /= v;
}


void Vector3::idiv(const Vector3& v) {
    x /= v.x;
    y /= v.y;
    z /= v.z;
}

// Basic getters

const double& Vector3::at(size_t i) const {

    return (&x)[i];
}


double& Vector3::at(size_t i) {

    return (&x)[i];
}


double Vector3::sum() const {
    return x + y + z;
}


double Vector3::avg() const {
    return (x + y + z) / 3;
}


double Vector3::min() const {
    return std::min(std::min(x, y), z);
}


double Vector3::max() const {
    return std::max(std::max(x, y), z);
}


double Vector3::absmin() const {
    return ::absmin(::absmin(x, y), z);
}


double Vector3::absmax() const {
    return ::absmax(::absmax(x, y), z);
}


size_t Vector3::dominantAxis() const {
    return (std::fabs(x) > std::fabs(y))
           ? ((std::fabs(x) > std::fabs(z)) ? 0 : 2)
           : ((std::fabs(y) > std::fabs(z)) ? 1 : 2);
}


size_t Vector3::subminantAxis() const {
    return (std::fabs(x) < std::fabs(y))
           ? ((std::fabs(x) < std::fabs(z)) ? 0 : 2)
           : ((std::fabs(y) < std::fabs(z)) ? 1 : 2);
}


Vector3 Vector3::normalized() const {
    double l = length();
    return Vector3(x / l, y / l, z / l);
}


double Vector3::length() const {
    return std::sqrt(x * x + y * y + z * z);
}


double Vector3::lengthSquared() const {
    return x * x + y * y + z * z;
}


double Vector3::distancedoubleo(const Vector3& other) const {
    return sub(other).length();
}


double Vector3::distanceSquareddoubleo(const Vector3& other) const {
    return sub(other).lengthSquared();
}


Vector3 Vector3::reflected(const Vector3& normal) const {
    // this - 2(this.n)n
    return sub(normal.mul(2 * dot(normal)));
}


Vector3 Vector3::projected(const Vector3& normal) const {
    // this - this.n n
    return sub(normal.mul(dot(normal)));
}


std::tuple<Vector3, Vector3> Vector3::tangential() const {
    Vector3 a =
            ((std::fabs(y) > 0 || std::fabs(z) > 0) ? Vector3(1, 0, 0)
                                                    : Vector3(0, 1, 0))
                    .cross(*this)
                    .normalized();
    Vector3 b = cross(a);
    return std::make_tuple(a, b);
}

bool Vector3::isEqual(const Vector3& other) const {
    return x == other.x && y == other.y && z == other.z;
}


bool Vector3::isSimilar(const Vector3& other, double epsilon) const {
    return (std::fabs(x - other.x) < epsilon) &&
           (std::fabs(y - other.y) < epsilon) &&
           (std::fabs(z - other.z) < epsilon);
}

// Operators

double& Vector3::operator[](size_t i) {

    return (&x)[i];
}


const double& Vector3::operator[](size_t i) const {

    return (&x)[i];
}


template <typename U>
Vector3& Vector3::operator=(const std::initializer_list<U>& lst) {
    set(lst);
    return (*this);
}


Vector3& Vector3::operator=(const Vector3& v) {
    set(v);
    return (*this);
}


Vector3& Vector3::operator+=(double v) {
    iadd(v);
    return (*this);
}


Vector3& Vector3::operator+=(const Vector3& v) {
    iadd(v);
    return (*this);
}


Vector3& Vector3::operator-=(double v) {
    isub(v);
    return (*this);
}


Vector3& Vector3::operator-=(const Vector3& v) {
    isub(v);
    return (*this);
}


Vector3& Vector3::operator*=(double v) {
    imul(v);
    return (*this);
}


Vector3& Vector3::operator*=(const Vector3& v) {
    imul(v);
    return (*this);
}


Vector3& Vector3::operator/=(double v) {
    idiv(v);
    return (*this);
}


Vector3& Vector3::operator/=(const Vector3& v) {
    idiv(v);
    return (*this);
}


bool Vector3::operator==(const Vector3& v) const {
    return isEqual(v);
}


bool Vector3::operator!=(const Vector3& v) const {
    return !isEqual(v);
}


Vector3 operator+(const Vector3& a) {
    return a;
}


Vector3 operator-(const Vector3& a) {
    return Vector3(-a.x, -a.y, -a.z);
}


Vector3 operator+(const Vector3& a, double b) {
    return a.add(b);
}


Vector3 operator+(double a, const Vector3& b) {
    return b.add(a);
}


Vector3 operator+(const Vector3& a, const Vector3& b) {
    return a.add(b);
}


Vector3 operator-(const Vector3& a, double b) {
    return a.sub(b);
}


Vector3 operator-(double a, const Vector3& b) {
    return b.rsub(a);
}


Vector3 operator-(const Vector3& a, const Vector3& b) {
    return a.sub(b);
}


Vector3 operator*(const Vector3& a, double b) {
    return a.mul(b);
}


Vector3 operator*(double a, const Vector3& b) {
    return b.mul(a);
}


Vector3 operator*(const Vector3& a, const Vector3& b) {
    return a.mul(b);
}


Vector3 operator/(const Vector3& a, double b) {
    return a.div(b);
}


Vector3 operator/(double a, const Vector3& b) {
    return b.rdiv(a);
}


Vector3 operator/(const Vector3& a, const Vector3& b) {
    return a.div(b);
}


Vector3 min(const Vector3& a, const Vector3& b) {
    return Vector3(std::min(a.x, b.x), std::min(a.y, b.y),
                   std::min(a.z, b.z));
}


Vector3 max(const Vector3& a, const Vector3& b) {
    return Vector3(std::max(a.x, b.x), std::max(a.y, b.y),
                   std::max(a.z, b.z));
}


Vector3 clamp(const Vector3& v, const Vector3& low,
              const Vector3& high) {
    return Vector3(clamp(v.x, low.x, high.x), clamp(v.y, low.y, high.y),
                   clamp(v.z, low.z, high.z));
}


Vector3 ceil(const Vector3& a) {
    return Vector3(std::ceil(a.x), std::ceil(a.y), std::ceil(a.z));
}


Vector3 floor(const Vector3& a) {
    return Vector3(std::floor(a.x), std::floor(a.y), std::floor(a.z));
}

// Extensions

Vector3 monotonicCatmullRom(const Vector3& v0, const Vector3& v1,
                            const Vector3& v2, const Vector3& v3,
                            double f) {
    static const double two = static_cast<double>(2);
    static const double three = static_cast<double>(3);

    Vector3 d1 = (v2 - v0) / two;
    Vector3 d2 = (v3 - v1) / two;
    Vector3 D1 = v2 - v1;

    if (std::fabs(D1.x) < std::numeric_limits<float>::epsilon() ||
        sign(D1.x) != sign(d1.x) || sign(D1.x) != sign(d2.x)) {
        d1.x = d2.x = 0;
    }

    if (std::fabs(D1.y) < std::numeric_limits<float>::epsilon() ||
        sign(D1.y) != sign(d1.y) || sign(D1.y) != sign(d2.y)) {
        d1.y = d2.y = 0;
    }

    if (std::fabs(D1.z) < std::numeric_limits<float>::epsilon() ||
        sign(D1.z) != sign(d1.z) || sign(D1.z) != sign(d2.z)) {
        d1.z = d2.z = 0;
    }

    Vector3 a3 = d1 + d2 - two * D1;
    Vector3 a2 = three * D1 - two * d1 - d2;
    Vector3 a1 = d1;
    Vector3 a0 = v1;

    return a3 * cubic(f) + a2 * square(f) + a1 * f + a0;
}

double absDot(const Vector3& v1, const Vector3& v2) {
    return std::abs(v1.dot(v2));
}

double minComponent(const Vector3& v) {
    return std::min(v.x, std::min(v.y, v.z));
}
double maxComponent(const Vector3& v) {
    return std::max(v.x, std::max(v.y, v.z));
}
double maxDimension(const Vector3& v) {
    return (v.x > v.y) ? ((v.x > v.z) ? 0 : 2) : ((v.y > v.z) ? 1 : 2);
}
Vector3 permute(const Vector3& v, int x, int y, int z) {
    return {v[x], v[y], v[z]};
}
void coordinateSystem(const Vector3& v1, Vector3* v2, Vector3* v3) {
    if(std::abs(v1.x) > std::abs(v1.y))
        *v2 = Vector3(-v1.y, 0, v1.x) / sqrt(v1.x * v1.x + v1.z * v1.z);
    else
        *v2 = Vector3(0, v1.z, -v1.y) / sqrt(v1.y * v1.y + v1.z * v1.z);

    *v3 = v1.cross(*v2);
}