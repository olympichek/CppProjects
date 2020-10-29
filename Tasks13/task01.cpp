#include <iostream>
#include <cstdint>
using namespace std;

int main() {
    uint16_t n;
    cout << "Enter n: ";
    cin >> n;
    uint64_t res = 1u << n;
    cout << "res: " << res << endl;
    return 0;
}
