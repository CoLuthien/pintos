#ifndef THREADS_FIXED_POINT_H
#define THREADS_FIXED_POINT_H
#include <stdint.h>

typedef int64_t fp_t;
#define F 17
#define Q 14
#define shift 1 << Q

#define int_to_fixed (num) ((fp_t) num * shift)
#define fixed_to_int_zero (num) ((fp_t) num / shift);

#define fixed_to_int_near (num) (num >= 0) ? (fp_t)((num + shift / 2 ) / shift)\
                                           : (fp_t)((num - shift / 2 ) / shift)

#define add (x, y) (fp_t) (x + y)
#define sub (x, y) (fp_t) (x - y)

#define add_int (x, y) (fp_t)(x + y * shift)
#define sub_int (x, y) (fp_t)(x - y * shift)
#define mult (x, y) (fp_t) ((fp_t) x * (y / shift))
#define mult_int (x, y) (fp_t)(x * y)
#define div (x, y) (fp_t) ((fp_t)x) * shift / y
#define div_int (x, y) (fp_t) x / y
#endif
