#include <iostream>
#include <cstdint>
using namespace std;

int main() {
    uint64_t M, i, j;
    cout << "Enter M: ";
    cin >> M;
    for(i = 0; M == (M >> 1u)*2; i++) M >>= 1u;
    for(j = 0; M != 1; j++) M >>= 1u;
    cout << "left: " << i+j << endl;
    cout << "right: " << i << endl;
    return 0;
}
