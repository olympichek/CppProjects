#include <iostream>
#include <climits>
using namespace std;

int main() {
    int a, b;
    cout << "Enter a and b: ";
    cin >> a >> b;
    cout << endl;
    if(a > INT_MAX - b) {
        cout << "Operation can cause type overflow.";
    }
    else {
        int res = a + b;
        cout << "a + b = " << res << endl;
    }
    return 0;
}
