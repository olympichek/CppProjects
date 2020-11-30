#include <string> // std::string
#include <iostream> // base IO streams
#include <fstream> // file IO streams

#include "common.hpp" // application types
#include "random.hpp" // C++ version of random numbers generator
#include "random.h" // C version of random numbers generator

/**
 * Struct in which input data will be stored in
 */
struct input_data {
    NType a, c, m, s0; // generator init parameters
    NType n1, n2, n3, n4; // amounts
    IType min1, max1;
    DType min2, max2; // ranges
};

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
 * Reads input data from file
 * @param filename
 * @return input data
 * @throws std::ios_base::failure
 */
input_data input(const std::string &filename) {
    std::ifstream fin(filename);
    if (fin.fail())
        throw std::ios_base::failure("Unable to read file...");

    input_data data {};

    fin >> data.a >> data.c >> data.m >> data.s0;
    // read generator initialization parameters

    fin >> data.n1
        >> data.n2
        >> data.n3 >> data.min1 >> data.max1
        >> data.n4 >> data.min2 >> data.max2;
    // read amounts and ranges

    fin.close(); // close input file

    return data;
}

/**
 * Writes C output to file
 * @param data is input data
 * @param filename is output file's name
 * @throws std::ios_base::failure, std::invalid_argument
 */
void output_c(const input_data &data, const std::string &filename) {
    std::ofstream fout(filename);
    if (fout.fail())
        throw std::ios_base::failure("Unable to open or create file...");

    int error = my_srand_custom(data.a, data.c, data.m, data.s0);
    if (error != 0) {
        std::string message = "a, c, m or s0 don't match conditions...";
        fout << message << std::endl;
        throw std::invalid_argument(message);
    }
    // checking wrong initialization arguments

    fout << data.n1 << " random numbers: " << std::endl;
    for (NType i = 0; i < data.n1; i++)
        fout << my_rand_int_basic() << std::endl;
    // write random int numbers from 0 to m

    fout << std::endl;

    fout << data.n2 << " random double numbers from 0 to 1: " << std::endl;
    for (NType i = 0; i < data.n2; i++)
        fout << my_rand_double_basic() << std::endl;
    // write random double numbers from 0 to 1

    fout << std::endl;

    fout << data.n3 << " random int numbers from "
         << data.min1 << " to " << data.max1 << ": "
         << std::endl;

    for (NType i = 0; i < data.n3; i++)
        fout << my_rand_int(data.min1, data.max1) << std::endl;
    // write random int numbers from min to max

    fout << std::endl;

    fout << data.n4 << " random double numbers from "
         << data.min2 << " to " << data.max2 << ": "
         << std::endl;

    for (NType i = 0; i < data.n4; i++)
        fout << my_rand_double(data.min2, data.max2) << std::endl;
    // write random double numbers from min to max

    fout.close(); // close output file
}

/**
 * Writes C++ output to file
 * @param data is input data
 * @param filename is output file's name
 * @throws std::ios_base::failure, std::invalid_argument
 */
void output_cpp(const input_data &data, const std::string &filename) {
    std::ofstream fout(filename);
    if (fout.fail())
        throw std::ios_base::failure("Unable to open or create file...");

    try {
        my::srand_custom(data.a, data.c, data.m, data.s0);
    }
    catch(std::invalid_argument &e) {
        fout << e.what() << std::endl;
        throw e;
    }
    // checking wrong initialization arguments

    fout << data.n1 << " random numbers: " << std::endl;

    for (NType i = 0; i < data.n1; i++)
        fout << my::rand_int_basic() << std::endl;
    // write random int numbers from 0 to m

    fout << std::endl;

    fout << data.n2 << " random double numbers from 0 to 1: " << std::endl;

    for (NType i = 0; i < data.n2; i++)
        fout << my::rand_double_basic() << std::endl;
    // write random double numbers from 0 to 1

    fout << std::endl;

    fout << data.n3 << " random int numbers from "
         << data.min1 << " to " << data.max1 << ": "
         << std::endl;

    for (NType i = 0; i < data.n3; i++)
        fout << my::rand_int(data.min1, data.max1) << std::endl;
    // write random int numbers from min to max

    fout << std::endl;

    fout << data.n4 << " random double numbers from "
         << data.min2 << " to " << data.max2 << ": "
         << std::endl;

    for (NType i = 0; i < data.n4; i++)
        fout << my::rand_double(data.min2, data.max2) << std::endl;
    // write random double numbers from min to max

    fout.close(); // close output file
}
/**
 * Checks if C and C++ output files match
 * @param filename_c is C output file's name
 * @param filename_cpp is C++ output file's name
 * @return true if files match, otherwise false
 * @throws std::ios_base::failure
 */
bool compare_files(std::string &filename_c, std::string &filename_cpp) {
    std::ifstream fin_c(filename_c);
    std::string line_c;
    if (fin_c.fail())
        throw std::ios_base::failure("Unable to read file (C version)...");

    std::ifstream fin_cpp(filename_cpp);
    std::string line_cpp;
    if (fin_c.fail())
        throw std::ios_base::failure("Unable to read file (C++ version)...");

    while (std::getline(fin_c, line_c) && std::getline(fin_cpp, line_cpp)) {
       if (line_c != line_cpp) // compare files line by line
           return false; // return false if lines don't match
    }

    fin_c.close();
    fin_cpp.close();
    // close files

    return true;
}

/**
 * Main function
 * @return 0 if success, 1 if error
 */
int main() {
    std::ios_base::sync_with_stdio(false);
    // disable synchronization with stdio for higher speed

    std::string input_file;
    std::cout << "Enter input file's name:" << std::endl;
    std::cin >> input_file;
    // prompt input file's name

    input_data data {};
    try {
        data = input(input_file);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        return 1;
    }

    std::cout << std::endl;


    std::string output_file_c;
    std::cout << "Enter output file's name (C version):" << std:: endl;
    std::cin >> output_file_c;
    // prompt output file's name (C version)

    try {
        output_c(data, output_file_c);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        return 1;
    }

    std::cout << "Numbers written to file successfully." << std::endl;
    std::cout << std::endl;


    std::string output_file_cpp;
    std::cout << "Enter output file's name (C++ version):" << std:: endl;
    std::cin >> output_file_cpp;
    // prompt output file's name (C++ version)

    try {
        output_cpp(data, output_file_cpp);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        return 1;
    }

    std::cout << "Numbers written to file successfully." << std::endl;
    std::cout << std::endl;

    bool check;
    try {
        check = compare_files(output_file_c, output_file_cpp);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    if (check)
        std::cout << "Files' content matches!" << std::endl;
    else
        std::cout << "Files' content doesn't match..." << std::endl;


    return 0;
}