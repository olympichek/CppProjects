#include <iostream>
#include <cstdint>
#include <bitset>
using namespace std;

uint32_t BitReverse(uint32_t n) {
    bitset<32> b = n;
    bitset<32> r = 0;
    for(int i = 31; i > -1; i--) {
        if(b[i] == 1) {
            for(int j = i; j > -1; j--)
                r[i-j] = b[j];
            break;
        }
    }
    return r.to_ulong();
}

int main() {
    uint32_t n, m;
    cout << "Enter n and m: ";
    cin >> n >> m;
    cout << "Results: " << endl;
    for(uint32_t i = n; i <= m; i++)
        cout << BitReverse(i) << endl;
    return 0;
}
