#include <string>
#include <sstream>

#include "common.hpp"
#include "Quaternion.hpp"

Quaternion::Quaternion() = default;

Quaternion::Quaternion(DType a, DType b, DType c, DType d) {
    this->a = a;
    this->b = b;
    this->c = c;
    this->d = d;
};

std::string Quaternion::toString() const {
    std::stringstream s;
    s << this->a;
    if(this->b >= 0) 
        s << " + " << this->b << "i";
    else 
        s << " - " << -this->b << "i";
    if(this->c >= 0) 
        s << " + " << this->c << "j";
    else 
        s << " - " << -this->c << "j";
    if(this->d >= 0) 
        s << " + " << this->d << "k";
    else 
        s << " - " << -this->d << "k";
    return s.str();
}

Quaternion Quaternion::operator+(const Quaternion &other) const {
    Quaternion res;
    res.a = this->a + other.a;
    res.b = this->b + other.b;
    res.c = this->c + other.c;
    res.d = this->d + other.d;
    return res;
}

Quaternion& Quaternion::operator+=(const Quaternion &other) {
    *this = (*this) + other;
    return *this;
}

Quaternion Quaternion::operator-(const Quaternion &other) const {
    Quaternion res;
    res.a = this->a - other.a;
    res.b = this->b - other.b;
    res.c = this->c - other.c;
    res.d = this->d - other.d;
    return res;
}

Quaternion& Quaternion::operator-=(const Quaternion &other) {
    *this = (*this) - other;
    return *this;
}

Quaternion Quaternion::operator*(const Quaternion &other) const {
    Quaternion res(0.0, 0.0, 0.0, 0.0);
    res.a += this->a * other.a;
    res.a -= this->b * other.b;
    res.a -= this->c * other.c;
    res.a -= this->d * other.d;

    res.b += this->b * other.a;
    res.b += this->a * other.b;
    res.b += this->c * other.d;
    res.b -= this->d * other.c;

    res.c += this->a * other.c;
    res.c -= this->b * other.d;
    res.c += this->c * other.a;
    res.c += this->d * other.b;

    res.d += this->a * other.d;
    res.d += this->b * other.c;
    res.d -= this->c * other.b;
    res.d += this->d * other.a;
    return res;
}

Quaternion& Quaternion::operator*=(const Quaternion &other) {
    *this = (*this) * other;
    return *this;
}

Quaternion& Quaternion::inverse() {
    DType t = 0.0;
    t += this->a * this->a;
    t += this->b * this->b;
    t += this->c * this->c;
    t += this->d * this->d;
    this->a /= t;
    this->b /= -t;
    this->c /= -t;
    this->d /= -t;
    return *this;
}