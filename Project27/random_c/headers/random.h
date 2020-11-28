#ifndef RANDOM_H
#define RANDOM_H

#include <math.h> // sqrt() function
#include <time.h> // time() function
#include "common.h" // application types

/**
 * Initializes random numbers generator with all parametres defined by user
 * @param a0 is multiplier
 * @param c0 is increment
 * @param m0 is modulus
 * @param s0 is first number in a sequence
 * @return
 *   0 if success
 *   1 if wrong m
 *   2 if wrong a
 *   3 if wrong c
 *   4 if wrong s0
 */
int my_srand_custom(NType a0, NType c0, NType m0, NType s0);

/**
 * Initializes random numbers generator with constant a, c and m
 * but with s0 defined by user, like srand() function from stdlib.h
 * @param s0 is first number in a sequence
 * @return 0 if success
 */
int my_srand_basic(NType s0);

/**
 * Initializes random numbers generator with constant a, c and m
 * and with different s0 on each launch ( s0 = time(NULL) )
 * @return 0 if sucess
 */
int my_srand();

/**
 * Generates random int from 0 to m,
 * as rand() function from stdlib.h
 * @return random int
 */
NType my_rand_int_basic();

/**
 * Generates random double from 0 to 1
 * @return random double
 */
DType my_rand_double_basic();

/**
 * Generates random int from min to max
 * @param min is minimal number
 * @param max is maximal number
 * @return random int
 */
IType my_rand_int(IType min, IType max);

/**
 * Generates random double from min to max
 * @param min is minimal number
 * @param max is maximal number
 * @return random double
 */
DType my_rand_double(DType min, DType max);

#endif //RANDOM_H
