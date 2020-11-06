#ifndef QUATERNION_H
#define QUATERNION_H

#include "common.h"

class Quaternion {
private:
    DType a{};
    DType b{};
    DType c{};
    DType d{};
    Quaternion();
public:
    Quaternion(DType a, DType b, DType c, DType d);
    void print() const;
    Quaternion operator+(const Quaternion &other) const;
    Quaternion operator-(const Quaternion &other) const;
    Quaternion operator*(const Quaternion &other) const;
    Quaternion operator/(const Quaternion &other) const;
};

#endif //QUATERNION_H
