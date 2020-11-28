#include <stdio.h> // IO functions
#include "common.h" // application types
#include "random.h" // random numbers generator

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
    char input_file[BUFSIZ];
    printf("Enter input file's name:\n");
    scanf("%s", input_file);
    // prompt input file's name

    FILE *fin = fopen(input_file, "r");
    if (fin == NULL) { // checking errors
        printf("Unable to read file...\n");
        return;
    }
    else {
        printf("\n");
    }

    NType a, c, m, s0;
    fscanf(fin, "%u", &a);
    fscanf(fin, "%u", &c);
    fscanf(fin, "%u", &m);
    fscanf(fin, "%u", &s0);
    // read generator initialization parameters

    NType n1, n2, n3, n4;
    IType min1, max1;
    DType min2, max2;
    
    fscanf(fin, "%u", &n1);
    fscanf(fin, "%u", &n2);

    fscanf(fin, "%u", &n3);
    fscanf(fin, "%d", &min1);
    fscanf(fin, "%d", &max1);

    fscanf(fin, "%u", &n4);
    fscanf(fin, "%lf", &min2);
    fscanf(fin, "%lf", &max2);

    // read amounts and ranges

    fclose(fin); // close input file

    char output_file[BUFSIZ];
    printf("Enter output file's name:\n");
    scanf("%s", output_file);
    // prompt output file's name
    
    FILE *fout = fopen(output_file, "w");
    if (fout == NULL) { // checking errors
        printf("Unable to open or create file...\n");
        return;
    }
    else {
        printf("\n");
    }

    int error = my_srand_custom(a, c, m, s0);
    if (error != 0) {
        const char error_message[] = "a, c, m or s0 don't match conditions...\n";
        printf(error_message);
        fprintf(fout, error_message);
        return;
    }
    // checking wrong initialization arguments

    fprintf(fout, "%u random numbers: \n", n1);
    for (NType i = 0; i < n1; i++) {
        fprintf(fout, "%u\n", my_rand_int_basic());
    }
    // write random int numbers from 0 to m

    fprintf(fout, "\n");
    
    fprintf(fout, "%u random double numbers from 0 to 1: \n", n2);
    for (NType i = 0; i < n2; i++)
        fprintf(fout, "%lf\n", my_rand_double_basic());
    // write random double numbers from 0 to 1

    fprintf(fout, "\n");
    
    fprintf(fout, "%u random int numbers from %d to %d: \n", n3, min1, max1);
    for (NType i = 0; i < n3; i++)
        fprintf(fout, "%d\n", my_rand_int(min1, max1));
    // write random int numbers from min to max

    fprintf(fout, "\n");

    fprintf(fout, "%u random double numbers from %lf to %lf: \n", n4, min2, max2);
    for (NType i = 0; i < n4; i++)
        fprintf(fout, "%lf\n", my_rand_double(min2, max2));
    // write random double numbers from min to max

    fclose(fout); // close output file

    printf("Numbers written to file successfully.\n");
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

    int error;
    if (parameters_type == 1) { // custom a, c, m and s0
        NType a, c, m , s0;
        printf("Enter a, c, m and s0: ");
        scanf("%u %u %u %u", &a, &c, &m, &s0);
        // prompt a, c, m and s0
        error = my_srand_custom(a, c, m, s0);
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
            error = my_srand_basic(s0);
        }
        else if (s0_type == 2) { // time(NULL) as s0
            error = my_srand();
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

    if (error != 0) { // error checking
        printf("a, c, m or s0 don't match conditions...\n");
        return;
    }

    printf("\n");

    printf("Enter number of random integer numbers: ");
    NType c1;
    scanf("%u", &c1);
    printf("%u random integer numbers:\n", c1);
    for (NType i = 0; i < c1; i++)
        printf("%u\n", my_rand_int_basic());
    // write random int numbers from 0 to m

    printf("\n");

    printf("Enter number of random double numbers: ");
    NType c2;
    scanf("%u", &c2);
    printf("%u random double numbers:\n", c2);
    for (NType i = 0; i < c2; i++)
        printf("%lf\n", my_rand_double_basic());
    // write random double numbers from 0 to 1

    printf("\n");

    printf("Enter number of random integer numbers: ");
    NType c3;
    scanf("%u", &c3);
    printf("Enter minimal and maximal number: ");
    IType min1, max1;
    scanf("%d %d", &min1, &max1);
    printf("%u random integer numbers:\n", c3);
    for (NType i = 0; i < c3; i++)
        printf("%d\n", my_rand_int(min1, max1));
    // write random int numbers from min to max

    printf("\n");

    printf("Enter number of random double numbers: ");
    NType c4;
    scanf("%u", &c4);
    printf("Enter minimal and maximal number: ");
    DType min2, max2;
    scanf("%lf %lf", &min2, &max2);
    printf("%u random double numbers:\n", c4);
    for (NType i = 0; i < c4; i++)
        printf("%lf\n", my_rand_double(min2, max2));
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