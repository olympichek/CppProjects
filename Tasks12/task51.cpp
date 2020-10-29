#include <iostream>
#include <cmath>
using namespace std;

int sign(double x) {
    if(x > 0.0) return 1;
    if(x < 0.0) return -1;
    return 0;
}

double bisection(double xn, double xk, double eps, double f(double)) {
    if(f(xn) == 0.0) return xn;
    if(f(xk) == 0.0) return xk;
    double dx, xi;
    while((xk - xn) > eps) {
        dx = (xk - xn)/2.0;
        xi = xn + dx;
        if(sign(f(xn)) != sign(f(xi))) xk = xi;
        else xn = xi;
    }
    return xi;
}

int main() {
    double eps, xn = 2.0, xk = 5.0;
    cout << "Enter eps: "; cin >> eps;
    double res = bisection(xn, xk, eps, [](double x) {
        return tan(x) - x;
    });
    cout << "x = " << res << endl;
    return 0;
}