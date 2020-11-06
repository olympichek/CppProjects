#ifndef QUATERNION
#define QUATERNION

#include <string>
#include "common.hpp"

class Quaternion {
private:
    DType a;
    DType b;
    DType c;
    DType d;
    Quaternion();
public:
    Quaternion(DType a, DType b, DType c, DType d);
    std::string toString() const;

    Quaternion operator+(const Quaternion &other) const;
    Quaternion& operator+=(const Quaternion &other);
    Quaternion operator-(const Quaternion &other) const;
    Quaternion& operator-=(const Quaternion &other);
    Quaternion operator*(const Quaternion &other) const;
    Quaternion& operator*=(const Quaternion &other);
    Quaternion& inverse();
};

#endif //QUATERNION
