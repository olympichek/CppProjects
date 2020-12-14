#include <iostream>
#include <map>
#include "map.hpp"

int main() {
    std::map<int, int> stdmap {{1, 2}, {3, 4}};
    my::map<int, int> mymap {{1, 2}, {3, 4}, {5, 6}};
    mymap.insert({7, 8});
    std::cout << "size: " << mymap.size() << std::endl;
    std::cout << mymap.at(7) << std::endl;
    return 0;
}
