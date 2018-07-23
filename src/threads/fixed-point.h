#ifndef THREADS_FIXED_POINT_H
#define THREADS_FIXED_POINT_H
#include <stdint.h>

typedef int64_t fp_t;
#define F 17
#define Q 14
#define shift (1 << Q)

#define int_to_fixed(num) (shift * num)
#define fixed_to_int_zero(real) (real / shift)

#define fixed_to_int(real) (real >= 0) ? (((real) + (shift / 2)) / shift) \
                                           : (((real) - (shift / 2)) / shift)
    
#define add(x, y) (int) (x + y)
#define sub(x, y) (int) (x - y)

#define add_int(x, n) (int)(x + (n * shift))
#define sub_int(x, n) (int)(x - (n * shift))

#define mult(x, y) (int)(((fp_t)x) * y / shift)
#define mult_int(x, n) (x * n)

#define div(x, y) (int)(((fp_t)x) * shift / y)
#define div_int(x, n) (int)(fp_t)(x / n)
#endif
