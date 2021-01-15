#include <iostream>
#include <map>
#include "map.hpp"

int main() {
    std::map<int, int> stdmap {{1, 2}, {3, 4}};
    my::map<int, int>  mymap  {{1, 2}, {3, 4}};
    mymap.insert({5, 4});
    mymap[7] = 9;
    std::cout << "size: " << mymap.size() << std::endl;
    std::cout << mymap[7] << std::endl;
    std::cout << mymap[5] << std::endl;
    std::cout << stdmap[3] << std::endl;
    return 0;
}
