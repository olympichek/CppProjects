#include <math.h>
#include <time.h>
#include "common.h"

static NType a;
// sqrt(m) < a < m - sqrt(m)
// dividing a by 8, the remainder is 5

static NType c;
// c is odd number
// c/m ~= 0.5 - sqrt(3)/6

static NType m;
// m = 2 ^ k

static NType sn = 0;
// 0 <= s0 <= m - 1

// srand functions return:
// 0 if success
// 1 if wrong m
// 2 if wrong a
// 3 if wrong c
// 4 if wrong s0

// init with custom a, c, m and s0
int my_srand_custom(NType a0, NType c0, NType m0, NType s0) {
    if ( ((m0 & (m0 - 1)) != 0) || (m0 <= 4) ) // m = 2 ^ k
        return 1; // a exists only if m > 4
    
    DType sqrt_m0 = sqrt(m0);
    if ( ((a0 % 8) != 5) || (sqrt_m0 >= a0) || (a0 >= (m0 - sqrt_m0)) )
        return 2; // dividing a by 8, the remainder should be 5
    // sqrt(m) < a < m - sqrt(m)

    if ( (c0 % 2) != 1 )
        return 3; // c should be odd

    if ( s0 > (m0 - 1) ) 
        return 4; // 0 <= s0 <= m - 1

    a = a0, c = c0, m = m0, sn = s0;
    // if no errors, set a, c, m and s0

    return 0;
}

// init with constant a, c and m but with custom s0,
// like srand() function from stdlib.h
int my_srand_basic(NType s0) {
    const NType m0 = 1 << 31; // 2 ^ 31
    const NType a0 = 1103515245;
    const NType c0 = 12345;
    s0 = s0 % m0;
    int error = my_srand_custom(a0, c0 , m0, s0);
    return error;
}

// init with different s0 on each launch
int my_srand() {
    NType t = (NType) time(NULL);
    // time will be different on each launch

    NType s0 = t + (NType) sqrt(sn);
    // use sn from previous initialization

    int error = my_srand_basic( s0 );
    return error;
}

// random int from 0 to m,
// like stdlib.h rand() function
NType my_rand_int_basic() {
    sn = (a * sn + c) % m; // generate new sn
    return sn;
}

// random double from 0 to 1
DType my_rand_double_basic() {
    my_rand_int_basic(); // generate new sn
    return (sn + 1.0) / (m + 1.0); // return new rn
}

// random int from min to max
IType my_rand_int(IType min, IType max) {
    return min + (IType) ( (max - min) * my_rand_double_basic() );
}

// random double from min to max
DType my_rand_double(DType min, DType max) {
    return min + ( (max - min) * my_rand_double_basic() );
}