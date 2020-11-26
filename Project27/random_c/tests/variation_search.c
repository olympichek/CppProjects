#include <stdio.h> // IO functions
#include <stdlib.h> // memory allocation functions
#include "common.h" // application types
#include "random.h" // random numbers generator

/**
 * Generates random numbers and writes them to file
 * @param n is amount of random numbers
 * @param filename is output file's name 
 * @return
 *   0 if success
 *   1 if file error
 *   2 if generator error
 */
int write_numbers(NType n, const char *filename) {
    FILE *fout = fopen(filename, "w"); // try to open file to write
    if (fout == NULL) 
        return 1; // checking file errors

    int error = my_srand(); // generator init
    if (error != 0)
        return 2; // checking generator errors

    for (NType i = 0; i < n; i++) {
        DType rd = my_rand_double_basic(); // get random double
        fprintf(fout, "%lf\n", rd); // write random double
    }

    fclose(fout); // close file
    return 0;
}

/**
 * Reads numbers from file and counts numbers in each interval
 * @param n is amount of random numbers
 * @param filename is input file's name
 * @param m is number of intervals
 * @param counts is array of counts of numbers in each interval
 * @return 0 if success, 1 if file error
 */
int count_numbers(NType n, char *filename, NType m,  NType *counts) {
    FILE *fin = fopen(filename, "r"); // try to open file to read
    if (fin == NULL)
        return 1; // checking file errors

    for (NType i = 0; i < n; i++) {
        DType rd;
        fscanf(fin, "%lf", &rd); // read number from file

        NType in = 0; // interval number
        while (( (1.0 / m) * in ) < rd) in++;
        // find interval in which the number lies
        
        counts[in - 1]++; 
        // increment count of numbers in this interval
    }

    fclose(fin); // close file
    return 0;
}

/**
 * Main function
 * @return 0 if success, 1 if error
 */
int main() {
    int error = 0; // variable for error codes

    NType n; // amount of random numbers
    printf("Enter number of random numbers:\n");
    scanf("%u", &n);

    char filename[BUFSIZ]; // file's name
    printf("Enter output file's name:\n");
    scanf("%s", filename);

    error = write_numbers(n, filename);
    // write random numbers to file
    
    if (error == 0) { // checking errors
        printf("Numbers written to file successfully.\n");
    }
    else if (error == 1) {
        printf("Unable to open or create file...\n");
        return 1;
    }
    else {
        printf("Unable to generate random numbers...\n");
        return 1;
    }

    NType m; // number of intervals
    printf("Enter number of intervals:\n");
    scanf("%u", &m);

    NType *counts = (NType*) calloc(m, sizeof(NType));
    // array of counts of numbers in each interval

    if (counts == NULL) { // checking memory errors
        printf("Unable to allocate memory...\n");
        return 1;
    }

    error = count_numbers(n, filename, m, counts);
    // count numbers in each interval

    if (error != 0) { // checking errors
        printf("Unable to read file...\n");
        return 1;
    }

    for (NType i = 0; i < m; i++) { 
        printf("Numbers in %u inerval: %u\n", (i + 1), counts[i]);
        // print counts of numbers in each interval
    }

    free(counts); // delete counts
    return 0;
}