#include <iostream>
#include "Quaternion.hpp"

int main() {
    Quaternion q1(10.0, 11.0, 12.0, 13.0);
    Quaternion q2(20.0, 21.0, 22.0, 23.0);
    Quaternion sumRes = q1 + q2;
    Quaternion diffRees = q1 - q2;
    Quaternion mulRes1 = q1 * q2;
    Quaternion mulRes2 = q2 * q1;
    std::cout << sumRes.toString() << std::endl;
    std::cout << diffRees.toString() << std::endl;
    std::cout << mulRes1.toString() << std::endl;
    std::cout << mulRes2.toString() << std::endl;
    std::cout << q2.inverse().toString() << std::endl;
    return 0;
}