#include <iostream> // base IO
#include <fstream> // file IO
#include "common.hpp" // application types
#include "random.hpp" // random numbers generator

/*
 * Input file example:
 *
 * 1103515245 12345 2147483648 123
 * 10
 * 11
 * 12 -10 15
 * 13 1.2 3.5
 *
 * First line: a, c, m and s0
 * Second line: generate 10 random integers from 0 to m
 * Third line: generate 11 random doubles from 0 to 1
 * Fourth line: generate 12 random integers from -10 to 15
 * Fifth line: generate 13 random doubles from 1.2 to 2.5
 *
 * Input file should be placed in
 * same folder as executable program
 */

/**
 * Test for random numbers generator
 * functions using file IO
 */
void file_io_tests() {
    std::string input_file;
    std::cout << "Enter input file's name:" << std::endl;
    std::cin >> input_file;
    // prompt input file's name

    std::ifstream fin(input_file);
    if (fin.fail()) {
       std::cout << "Unable to read file..." << std::endl;
       return;
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

    std::string output_file;
    std::cout << "Enter output file's name:" << std:: endl;
    std::cin >> output_file;
    // prompt output file's name
    
    std::ofstream fout(output_file);
    if (fout.fail()) {
        std::cout << "Unable to open or create file..." << std::endl;
        return;
    }
    else {
        std::cout << std::endl;
    }

    try {
        my::srand_custom(a, c, m, s0);
    }
    catch(std::invalid_argument &e) {
        std::cout << e.what() << std::endl;
        fout << e.what() << std::endl;
        return;
    }
    // checking wrong initialization arguments

    fout << n1 << " random numbers: " << std::endl;
    for (NType i = 0; i < n1; i++)
        fout << my::rand_int_basic() << std::endl;
    // write random int numbers from 0 to m

    fout << std::endl;
    
    fout << n2 << " random double numbers from 0 to 1: " << std::endl;
    for (NType i = 0; i < n2; i++)
        fout << my::rand_double_basic() << std::endl;
    // write random double numbers from 0 to 1

    fout << std::endl;
    
    fout << n3 << " random int numbers from " << min1 << " to " << max1 << ": " << std::endl;
    for (NType i = 0; i < n3; i++)
        fout << my::rand_int(min1, max1) << std::endl;
    // write random int numbers from min to max

    fout << std::endl;

    fout << n4 << " random double numbers from " << min2 << " to " << max2 << ": " << std::endl;
    for (NType i = 0; i < n4; i++)
        fout << my::rand_double(min2, max2) << std::endl;
    // write random double numbers from min to max

    fout.close(); // close output file

    std::cout << "Numbers written to file successfully." << std::endl;
}

/**
 * Test for random numbers generator
 * functions using command line IO
 */
void command_line_io_tests() {
    std::cout << "Do you want to set custom a, c and m or use default ones? (1 - custom, 2 - default): ";
    int parameters_type;
    std::cin >> parameters_type;
    // prompt parameters type

    try {
        if (parameters_type == 1) { // custom a, c, m and s0
            NType a, c, m , s0;
            std::cout << "Enter a, c, m and s0: ";
            std::cin >> a >> c >> m >> s0;
            // prompt a, c, m and s0
            my::srand_custom(a, c, m, s0);
        }
        else if (parameters_type == 2) { // default a, c and m
            std::cout << "Do you want to set custom s0 or use current time as s0? (1 - custom, 2 - time): ";
            int s0_type;
            std::cin >> s0_type;
            // prompt s0 type
            if (s0_type == 1) { // custom s0
                std::cout << "Enter s0: ";
                NType s0;
                std::cin >> s0;
                // prompt s0
                my::srand_basic(s0);
            }
            else if (s0_type == 2) { // time(NULL) as s0
                my::srand();
            }
            else {
                std::cout << "Wrong s0 type..." << std::endl;
                return;
            }
        }
        else {
            std::cout << "Wrong arguments type..." << std::endl;
            return;
        }
    }
    catch (std::invalid_argument &e) {
        std::cout << e.what() << std::endl;
        return;
    }

    std::cout << std::endl;

    std::cout << "Enter number of random integer numbers: ";
    NType c1;
    std::cin >> c1;
    std::cout << c1 << " random integer numbers:" << std::endl;
    for (NType i = 0; i < c1; i++)
        std::cout << my::rand_int_basic() << std::endl;
    // write random int numbers from 0 to m

    std::cout << std::endl;

    std::cout << "Enter number of random double numbers: ";
    NType c2;
    std::cin >> c2;
    std::cout << c2 << " random double numbers:" << std::endl;
    for (NType i = 0; i < c2; i++)
        std::cout << my::rand_double_basic() << std::endl;
    // write random double numbers from 0 to 1

    std::cout << std::endl;

    std::cout << "Enter number of random integer numbers: ";
    NType c3;
    std::cin >> c3;
    std::cout << "Enter minimal and maximal number: ";
    IType min1, max1;
    std::cin >> min1 >> max1;
    std::cout << c3 << " random integer numbers:" << std::endl;
    for (NType i = 0; i < c3; i++)
        std::cout << my::rand_int(min1, max1) << std::endl;
    // write random int numbers from min to max

    std::cout << std::endl;

    std::cout << "Enter number of random double numbers: ";
    NType c4;
    std::cin >> c4;
    std::cout << "Enter minimal and maximal number: ";
    DType min2, max2;
    std::cin >> min2 >> max2;
    std::cout << c4 << " random double numbers:" << std::endl;
    for (NType i = 0; i < c4; i++)
        std::cout << my::rand_double(min2, max2) << std::endl;
    // write random double numbers from min to max
}

/**
 * Main function
 * @return 0 if success, 1 if error
 */
int main() {
    std::ios_base::sync_with_stdio(false);
    // disable synchronization with stdio for higher speed

    std::cout << "Random numbers generator test" << std::endl << std::endl;

    std::cout << "Choose IO type (1 - file IO, 2 - command line IO): ";
    int io_type;
    std::cin >> io_type;
    // prompt IO type

    if (io_type == 1) { // file IO
        std::cout << std::endl;
        file_io_tests();
    }
    else if (io_type == 2) { // command line IO
        command_line_io_tests();
    }
    else {
        std::cout << "Wrong io type..." << std::endl;
    }

    return 0;
}