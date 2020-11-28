#include <iostream> // base IO
#include <fstream> // file IO
#include <vector> // vector template
#include "common.hpp" // application types
#include "random.hpp" // random numbers generator

/**
 * Generates random numbers and writes them to file
 * @param n is amount of random numbers
 * @param filename is output file's name
 * @throws std::invalid_argument
 */
void write_numbers(NType n, const std::string &filename) {
    std::ofstream fout(filename); // try to open file to write

    try {
        my::srand(); // generator init
    } catch (std::invalid_argument &e) {
        throw e;
    }

    for (NType i = 0; i < n; i++) {
        DType rd = my::rand_double_basic(); // get random double
        fout << rd << std::endl; // write random double
    }

    fout.close(); // close file
}

/**
 * Reads numbers from file and counts numbers in each interval
 * @param n is amount of random numbers
 * @param filename is input file's name
 * @param m is number of intervals
 * @return array of counts of numbers in each interval
 */
std::vector<NType> count_numbers(NType n, const std::string &filename, NType m) {
    std::vector<NType> counts(m);
    // array of counts of numbers in each interval

    std::ifstream fin(filename); // try to open file to read

    for (NType i = 0; i < n; i++) {
        DType rd;
        fin >> rd; // read number from file

        NType in = 0; // interval number
        while (( (1.0 / m) * in ) < rd) in++;
        // find interval in which the number lies
        
        counts[in - 1]++;
        // increment count of numbers in this interval
    }

    fin.close(); // close file
    return counts;
}

/**
 * Main function
 * @return 0 if success, 1 if error
 */
int main() {
    std::ios_base::sync_with_stdio(false);
    // disable synchronization with stdio for higher speed

    NType n; // amount of random numbers
    std::cout << "Enter number of random numbers:" << std::endl;
    std::cin >> n;

    std::string filename; // file's name
    std::cout << "Enter output file's name:" << std::endl;
    std::cin >> filename;

    try {
        write_numbers(n, filename);
        // write random numbers to file
    } catch (std::invalid_argument &e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    
    std::cout << "Numbers written to file successfully." << std::endl;

    NType m; // number of intervals
    std::cout << "Enter number of intervals:" << std::endl;
    std::cin >> m;

    std::vector<NType> counts = count_numbers(n, filename, m);
    // count numbers in each interval

    for (NType i = 0; i < m; i++) { 
        std::cout << "Numbers in " << (i + 1) << " interval: " << counts[i] << std::endl;
        // print counts of numbers in each interval
    }

    return 0;
}