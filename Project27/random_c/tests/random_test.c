#include <stdio.h> // IO functions
#include "common.h" // application types
#include "random.h" // random numbers generator

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
        fprintf(fout, "a, c, m or s0 don't match conditions...\n");
        return;
    }
    // checking wrong initialization arguments

    fprintf(fout, "%u random numbers: \n", n1);
    for(NType i = 0; i < n1; i++) {
        fprintf(fout, "%u\n", my_rand_int_basic());
    }
    // write random int numbers from 0 to m

    fprintf(fout, "\n");
    
    fprintf(fout, "%u random double numbers from 0 to 1: \n", n2);
    for(NType i = 0; i < n2; i++) {
        fprintf(fout, "%lf\n", my_rand_double_basic());
    }
    // write random double numbers from 0 to 1

    fprintf(fout, "\n");
    
    fprintf(fout, "%u random int numbers from %d to %d: \n", n3, min1, max1);
    for(NType i = 0; i < n3; i++) {
        fprintf(fout, "%d\n", my_rand_int(min1, max1));
    }
    // write random int numbers from min to max

    fprintf(fout, "\n");

    fprintf(fout, "%u random double numbers from %lf to %lf: \n", n4, min2, max2);
    for(NType i = 0; i < n4; i++) {
        fprintf(fout, "%lf\n", my_rand_double(min2, max2));
    }
    // write random double numbers from min to max

    fclose(fout); // close output file

    printf("Numbers written to file successfully.\n");
}

void command_line_io_tests() {

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
    if (io_type == 1) {
        printf("\n");
        file_io_tests();
    }
    else if (io_type == 2) {
        command_line_io_tests();
    }
    else {
        printf("Wrong io type...\n");
    }
    return 0;
}