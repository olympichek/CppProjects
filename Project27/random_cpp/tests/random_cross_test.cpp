#include <string>
#include <iostream>
#include <fstream>

#include "common.hpp"
#include "random.hpp"

#include "random.h"

/**
 * Test for random numbers generator
 * functions using file IO
 */
int main() {
    // ---------------- START INPUT ----------------

    std::string input_file;
    std::cout << "Enter input file's name:" << std::endl;
    std::cin >> input_file;
    // prompt input file's name

    std::ifstream fin(input_file);
    if (fin.fail()) {
        std::cout << "Unable to read file..." << std::endl;
        return 1;
    }
    else {
        std::cout << std::endl;
    }

    NType a, c, m, s0;
    fin >> a >> c >> m >> s0;
    // read generator initialization parameters

    NType n1, n2, n3, n4;
    IType min1, max1;
    DType min2, max2;

    fin >> n1 >> n2;
    fin >> n3 >> min1 >> max1;
    fin >> n4 >> min2 >> max2;

    // read amounts and ranges

    fin.close(); // close input file

    // ---------------- END INPUT ----------------
    // ------------- START C++ OUTPUT ------------

    std::string output_file_cpp;
    std::cout << "Enter output file's name (C++ version):" << std:: endl;
    std::cin >> output_file_cpp;
    // prompt output file's name

    std::ofstream fout_cpp(output_file_cpp);
    if (fout_cpp.fail()) {
        std::cout << "Unable to open or create file..." << std::endl;
        return 1;
    }
    else {
        std::cout << std::endl;
    }

    try {
        my::srand_custom(a, c, m, s0);
    }
    catch(std::invalid_argument &e) {
        std::cout << e.what() << std::endl;
        fout_cpp << e.what() << std::endl;
        return 1;
    }
    // checking wrong initialization arguments

    fout_cpp << n1 << " random numbers: " << std::endl;
    for (NType i = 0; i < n1; i++)
        fout_cpp << my::rand_int_basic() << std::endl;
    // write random int numbers from 0 to m

    fout_cpp << std::endl;

    fout_cpp << n2 << " random double numbers from 0 to 1: " << std::endl;
    for (NType i = 0; i < n2; i++)
        fout_cpp << my::rand_double_basic() << std::endl;
    // write random double numbers from 0 to 1

    fout_cpp << std::endl;

    fout_cpp << n3 << " random int numbers from " << min1 << " to " << max1 << ": " << std::endl;
    for (NType i = 0; i < n3; i++)
        fout_cpp << my::rand_int(min1, max1) << std::endl;
    // write random int numbers from min to max

    fout_cpp << std::endl;

    fout_cpp << n4 << " random double numbers from " << min2 << " to " << max2 << ": " << std::endl;
    for (NType i = 0; i < n4; i++)
        fout_cpp << my::rand_double(min2, max2) << std::endl;
    // write random double numbers from min to max

    fout_cpp.close(); // close output file

    std::cout << "Numbers written to file successfully." << std::endl;

    // -------------- END C++ OUTPUT -------------
    // -------------- START C OUTPUT -------------

    std::string output_file_c;
    std::cout << "Enter output file's name (C version):" << std:: endl;
    std::cin >> output_file_c;
    // prompt output file's name

    std::ofstream fout_c(output_file_c);
    if (fout_c.fail()) {
        std::cout << "Unable to open or create file..." << std::endl;
        return 1;
    }
    else {
        std::cout << std::endl;
    }

    int error = my_srand_custom(a, c, m, s0);
    if (error != 0) {
        std::string message = "a, c, m or s0 don't match conditions...";
        std::cout << message << std::endl;
        fout_c << message << std::endl;
        return 1;
    }
    // checking wrong initialization arguments

    fout_c << n1 << " random numbers: " << std::endl;
    for (NType i = 0; i < n1; i++)
        fout_c << my_rand_int_basic() << std::endl;
    // write random int numbers from 0 to m

    fout_c << std::endl;

    fout_c << n2 << " random double numbers from 0 to 1: " << std::endl;
    for (NType i = 0; i < n2; i++)
        fout_c << my_rand_double_basic() << std::endl;
    // write random double numbers from 0 to 1

    fout_c << std::endl;

    fout_c << n3 << " random int numbers from " << min1 << " to " << max1 << ": " << std::endl;
    for (NType i = 0; i < n3; i++)
        fout_c << my_rand_int(min1, max1) << std::endl;
    // write random int numbers from min to max

    fout_c << std::endl;

    fout_c << n4 << " random double numbers from " << min2 << " to " << max2 << ": " << std::endl;
    for (NType i = 0; i < n4; i++)
        fout_c << my_rand_double(min2, max2) << std::endl;
    // write random double numbers from min to max

    fout_c.close(); // close output file

    std::cout << "Numbers written to file successfully." << std::endl;

    // --------------- END C OUTPUT --------------

    return 0;
}