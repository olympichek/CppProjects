#include <cstdio>
#include "../headers/common.h"
#include "../headers/Quaternion.h"

Quaternion::Quaternion() = default;

Quaternion::Quaternion(DType a, DType b, DType c, DType d) {
    this->a = a;
    this->b = b;
    this->c = c;
    this->d = d;
};

void Quaternion::print() const {
    printf("%.lf", this->a);
    printf(" + ");
    printf("%.lf", this->b);
    printf("i");
    printf(" + ");
    printf("%.lf", this->c);
    printf("j");
    printf(" + ");
    printf("%.lf", this->d);
    printf("k");
}

Quaternion Quaternion::operator+(const Quaternion &other) const {
    Quaternion res;
    res.a = this->a + other.a;
    res.b = this->b + other.b;
    res.c = this->c + other.c;
    res.d = this->d + other.d;
    return res;
}

Quaternion Quaternion::operator-(const Quaternion &other) const {
    Quaternion res;
    res.a = this->a - other.a;
    res.b = this->b - other.b;
    res.c = this->c - other.c;
    res.d = this->d - other.d;
    return res;
}

Quaternion Quaternion::operator*(const Quaternion &other) const {
    //
}
