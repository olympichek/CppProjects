#include <cstdio>
#include "../headers/Quaternion.h"

int main() {
    Quaternion q1(1.0, 2.0, 3.0, 4.0);
    Quaternion q2(5.0, 6.0, 7.0, 8.0);
    Quaternion q3 = q1 + q2;
    Quaternion q4 = q2 - q1;
    q3.print();
    printf("\n");
    q4.print();
    return 0;
}