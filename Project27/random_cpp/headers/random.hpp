#ifndef RANDOM_HPP
#define RANDOM_HPP

#include <cmath> // sqrt() function
#include <ctime> // time() function
#include "common.hpp" // application types

namespace my {
    /**
     * Initializes random numbers generator with all parametres defined by user
     * @param a0 is multiplier
     * @param c0 is increment
     * @param m0 is modulus
     * @param s0 is first number in a sequence
     * @throws std::invalid_argument
     */
    void srand_custom(NType a0, NType c0, NType m0, NType s0);

    /**
     * Initializes random numbers generator with constant a, c and m
     * but with s0 defined by user, like srand() function from stdlib.h
     * @param s0 is first number in a sequence
     * @throws std::invalid_argument
     */
    void srand_basic(NType s0);

    /**
     * Initializes random numbers generator with constant a, c and m
     * and with different s0 on each launch ( s0 = time(nullptr) )
     * @throws std::invalid_argument
     */
    void srand();

    /**
     * Generates random int from 0 to m,
     * as rand() function from stdlib.h
     * @return random int
     */
    NType rand_int_basic();

    /**
     * Generates random double from 0 to 1
     * @return random double
     */
    DType rand_double_basic();

    /**
     * Generates random int from min to max
     * @param min is minimal number
     * @param max is maximal number
     * @return random int
     */
    IType rand_int(IType min, IType max);

    /**
     * Generates random double from min to max
     * @param min is minimal number
     * @param max is maximal number
     * @return random double
     */
    DType rand_double(DType min, DType max);
}

#endif //RANDOM_HPP