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

    printf("\n");

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

    printf("\n");

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
    for(NType i = 0; i < n1; i++) {
        fout << my::rand_int_basic() << std::endl;
    }
    // write random int numbers from 0 to m

    fout << std::endl;
    
    fout << n2 << " random double numbers from 0 to 1: " << std::endl;
    for(NType i = 0; i < n2; i++) {
        fout << my::rand_double_basic() << std::endl;
    }
    // write random double numbers from 0 to 1

    fout << std::endl;
    
    fout << n3 << " random int numbers from " << min1 << " to " << max1 << ": " << std::endl;
    for(NType i = 0; i < n3; i++) {
        fout << my::rand_int(min1, max1) << std::endl;
    }
    // write random int numbers from min to max

    fout << std::endl;

    fout << n4 << " random double numbers from " << min2 << " to " << max2 << ": " << std::endl;
    for(NType i = 0; i < n4; i++) {
        fout << my::rand_double(min2, max2) << std::endl;
    }
    // write random double numbers from min to max

    fout.close(); // close output file

    std::cout << "Numbers written to file successfully." << std::endl;
}

/**
 * Test for random numbers generator
 * functions using command line IO
 */
void command_line_io_tests() {
    printf("Do you want to set custom a, c and m or use default ones? (1 - custom, 2 - default): ");
    int parameters_type;
    scanf("%d", &parameters_type);
    // prompt parameters type

    if (parameters_type == 1) { // custom a, c, m and s0
        NType a, c, m , s0;
        printf("Enter a, c, m and s0: ");
        scanf("%u %u %u %u", &a, &c, &m, &s0);
        // prompt a, c, m and s0
        my::srand_custom(a, c, m, s0);
    }
    else if (parameters_type == 2) { // default a, c and m
        printf("Do you want to set custom s0 or use current time as s0? (1 - custom, 2 - time): ");
        int s0_type;
        scanf("%d", &s0_type);
        // prompt s0 type
        if (s0_type == 1) { // custom s0
            printf("Enter s0: ");
            NType s0;
            scanf("%u", &s0);
            // prompt s0
            my::srand_basic(s0);
        }
        else if (s0_type == 2) { // time(NULL) as s0
            my::srand();
        }
        else {
            printf("Wrong s0 type...\n");
            return;
        }
    }
    else {
        printf("Wrong arguments type...\n");
        return;
    }

    printf("\n");

    printf("Enter number of random integer numbers: ");
    NType c1;
    scanf("%u", &c1);
    printf("%u random integer numbers:\n", c1);
    for(NType i = 0; i < c1; i++)
        printf("%u\n", my::rand_int_basic());
    // write random int numbers from 0 to m

    printf("\n");

    printf("Enter number of random double numbers: ");
    NType c2;
    scanf("%u", &c2);
    printf("%u random double numbers:\n", c2);
    for(NType i = 0; i < c2; i++)
        printf("%lf\n", my::rand_double_basic());
    // write random double numbers from 0 to 1

    printf("\n");

    printf("Enter number of random integer numbers: ");
    NType c3;
    scanf("%u", &c3);
    printf("Enter minimal and maximal number: ");
    IType min1, max1;
    scanf("%d %d", &min1, &max1);
    printf("%u random integer numbers:\n", c3);
    for(NType i = 0; i < c3; i++)
        printf("%d\n", my::rand_int(min1, max1));
    // write random int numbers from min to max

    printf("\n");

    printf("Enter number of random double numbers: ");
    NType c4;
    scanf("%u", &c4);
    printf("Enter minimal and maximal number: ");
    DType min2, max2;
    scanf("%lf %lf", &min2, &max2);
    printf("%u random double numbers:\n", c4);
    for(NType i = 0; i < c4; i++)
        printf("%lf\n", my::rand_double(min2, max2));
    // write random double numbers from min to max
}

/**
 * Main function
 * @return 0 if success, 1 if error
 */
int main() {
    printf("Random numbers generator test\n\n");

    printf("Choose IO type (1 - file IO, 2 - command line IO): ");
    int io_type;
    scanf("%d", &io_type);
    // prompt IO type

    if (io_type == 1) { // file IO
        printf("\n");
        file_io_tests();
    }
    else if (io_type == 2) { // command line IO
        command_line_io_tests();
    }
    else {
        printf("Wrong io type...\n");
    }

    return 0;
}