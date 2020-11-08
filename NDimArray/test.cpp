#include <iostream>
#include "NDimArray.hpp"

int main() {
    unsigned d, *length;
    std::cout << "Enter number of dimensions: ";
    std::cin >> d;
    length = new unsigned[d];
    for(unsigned i = 0; i < d; i++) {
        std::cout << "Enter length by " << (i + 1) << " dimension: ";
        std::cin >> length[i];
    }
    NDimArray<int> arr(d, length);
    return 0;
}