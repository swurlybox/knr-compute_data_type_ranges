#include <stdio.h>
#include "compute_range.h"

// Notes
// Take any data type. It is a specific byte size to it.

// All signed data types have an interesting property in their signed rep.
// 0 11111111111111111 ... is the largest positive number (upper limit)
// 1 00000000000000000 ... is the smallest negative number (lower limit)
// 1st bit on the left can be interpreted as the sign bit
// and the succeeding bits are a measure of the value

// Unsigned data types are only ever non-negative
// their lower limit is 0 and their upper limit is all 1s

// As long as we know the size in bytes of the data type we're working
// with, and its qualifier, we can determine its upper and lower limits.

// One trick of being able to print the correct values (upper n lower lims)
// is to have enough breathing room to work with as many bits as possible.
// a.k.a we need the data type with the widest range, such that it can
// handle the data types with narrower ranges.

// For example, the number 8 in long data type, is the same as the number
// 8 in int data type when printed.


void compute_srange(int byte_size){

    // Widest data type is long long introduced in C99, but since our
    // largest data type to compute is long, we'll use that instead
    long bit_space = -1;
    int bit_shift = (byte_size * 8) - 1;
    long lower_lim = bit_space << bit_shift;
    long upper_lim = ~lower_lim;

    printf("(%ld) -> (%ld)\n", lower_lim, upper_lim);

    return;

}

void compute_urange(int byte_size){
    
    int bit_shift = (byte_size * 8);
    unsigned long lower_lim = 0;
    unsigned long upper_lim;
    
    if (bit_shift == (sizeof(long) * 8)){
        upper_lim = ~lower_lim;
    }
    else{
        // Algorithm below doesn't work for unsigned longs, hence edge case
        upper_lim = ~((~lower_lim) << bit_shift);
    }

    printf("(%lu) -> (%lu)\n", lower_lim, upper_lim);

    return;
    
}
