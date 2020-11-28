#include <cmath>
#include <ctime>
#include <stdexcept>
#include "common.hpp"

namespace my {
    static NType a;
    // sqrt(m) < a < m - sqrt(m)
    // dividing a by 8, the remainder is 5

    static NType c;
    // c is odd number
    // c/m ~= 0.5 - sqrt(3)/6

    static NType m;
    // m = 2 ^ k

    static NType sn;
    // 0 <= s0 <= m - 1

    // init with custom a, c, m and s0
    void srand_custom(NType a0, NType c0, NType m0, NType s0) {
        if ( ((m0 & (m0 - 1)) != 0) || (m0 <= 4) )
            throw std::invalid_argument("Parameter m doesn't match conditions...");
        // m = 2 ^ k
        // a exists only if m > 4

        DType sqrt_m0 = std::sqrt(m0);
        if (((a0 % 8) != 5) || (sqrt_m0 >= a0) || (a0 >= (m0 - sqrt_m0)) )
            throw std::invalid_argument("Parameter a doesn't match conditions...");
        // dividing a by 8, the remainder should be 5
        // sqrt(m) < a < m - sqrt(m)

        if ( (c0 % 2) != 1 )
            throw std::invalid_argument("Parameter c doesn't match conditions...");
        // c should be odd

        if ( s0 > (m0 - 1) )
            throw std::invalid_argument("Parameter s0 doesn't match conditions...");
        // 0 <= s0 <= m - 1

        a = a0, c = c0, m = m0, sn = s0;
        // if no errors, set a, c, m and s0
    }

    // init with constant a, c and m but with custom s0,
    // like srand() function from stdlib.h
    void srand_basic(NType s0) {
        const NType m0 = 1 << 31; // 2 ^ 31
        const NType a0 = 1103515245;
        const NType c0 = 12345;
        s0 = s0 % m0;
        srand_custom(a0, c0 , m0, s0);
    }

    // init with different s0 on each launch
    void srand() {
        auto t = static_cast<NType>( time(nullptr) );
        // time will be different on each launch

        NType s0 = t + static_cast<NType>( sqrt(sn) );
        // use sn from previous initialization

        srand_basic( s0 );
    }

    // Random int from 0 to m,
    // like stdlib.h rand() function
    NType rand_int_basic() {
        sn = (a * sn + c) % m; // generate new sn
        return sn;
    }

    // Random double from 0 to 1
    DType rand_double_basic() {
        rand_int_basic(); // generate new sn
        return (sn + 1.0) / (m + 1.0); // return new rn
    }

    // Random int from min to max
    IType rand_int(IType min, IType max) {
        return min + (IType) ( (max - min) * rand_double_basic() );
    }

    // Random double from min to max
    DType rand_double(DType min, DType max) {
        return min + ( (max - min) * rand_double_basic() );
    }
}
