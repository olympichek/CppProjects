#include <iostream>
#include <algorithm>
#include "list.hpp"

int main() {
    my::list<int> list {1, 3, 5, 7, 9};

    list.pop_back();
    list.pop_top();
    list.push_top(2);
    list.push_back(8);

    std::cout << "list: " << list.to_string() << std::endl;
    std::cout << "size: " << list.size() << std::endl;
    std::cout << "empty: " << (list.empty() ? "yes" : "no") << std::endl;

    std::cout << "elements (from start to end): ";
    std::for_each(list.begin(), list.end(), [](auto &el) {
        std::cout << el << " ";
    });
    std::cout << std::endl;

    std::cout << "elements (from end to start): ";
    std::for_each(list.rbegin(), list.rend(), [](auto &el) {
        std::cout << el << " ";
    });
    std::cout << std::endl;

    return 0;
}
