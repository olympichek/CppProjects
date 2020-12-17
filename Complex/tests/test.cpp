#include <iostream>
#include <complex.hpp>

int main() {
    double a, b;
    std::cout << "Enter real and imagine part of first complex number: ";
    std::cin >> a >> b;
    my::complex<double> first(a, b);
    std::cout << "Enter real and imagine part of second complex number: ";
    std::cin >> a >> b;
    my::complex<double> second(a, b);
    std::cout << "First: "  << first  << std::endl;
    std::cout << "Second: " << second << std::endl;
    auto sum  = first + second;
    auto diff = first - second;
    auto prod = first * second;
    auto div  = first / second;
    std::cout << "First + second: " << sum  << std::endl;
    std::cout << "First - second: " << diff << std::endl;
    std::cout << "First * second: " << prod << std::endl;
    std::cout << "First / second: " << div  << std::endl;
    return 0;
}
