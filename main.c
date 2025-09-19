#include <stdio.h>
#include <limits.h>
#include "compute_range.h"

/*
Write a program to determine the ranges of char, short, int, and long
variables, both signed and unsigned, by printing appropriate values
from standard headers and by direct computation. Harder if you compute
them: determine the ranges of the various floating-point types.
*/

void compute_data_type_ranges(){
    
    printf("Char: "); compute_srange(sizeof(char));
    printf("Unsigned Char: "); compute_urange(sizeof(unsigned char));
    printf("Signed Char: "); compute_srange(sizeof(signed char));

    printf("\nShort: "); compute_srange(sizeof(short));
    printf("Unsigned Short: "); compute_urange(sizeof(unsigned short));
    printf("Signed Short: "); compute_srange(sizeof(signed short));

    printf("\nInt: "); compute_srange(sizeof(int));
    printf("Unsigned Int: "); compute_urange(sizeof(unsigned int));
    printf("Signed Int: "); compute_srange(sizeof(signed int));

    printf("\nLong: "); compute_srange(sizeof(long));
    printf("Unsigned Long: "); compute_urange(sizeof(unsigned long));
    printf("Signed Long: "); compute_srange(sizeof(signed long));

    return;
}

int main(){

    // Trivial to just print the standard header values,
    // But its also extra work to compute the ranges manually.
    // Thank you <limit.h> for defining symbolic constants
    // for the ranges of these data types  
    
    // All unsigned data types are defined to have a minimum of 0.
    // Hence, no need for a UCHAR_MIN macro. (the limits.h even
    // explicitly says that the minimum is 0 for each unsigned
    // symbolic constant in a comment)

    printf("Printed via symbolic constants defined in <limit.h>\n\n");

    printf("Char: (%d) -> (%d)\n", CHAR_MIN, CHAR_MAX);
    printf("Unsigned Char: (%d) -> (%d)\n", 0, UCHAR_MAX);
    printf("Signed Char: (%d) -> (%d)\n\n", SCHAR_MIN, SCHAR_MAX);

    // Short is the same as signed short    
    printf("Short: (%d) -> (%d)\n", SHRT_MIN, SHRT_MAX);
    printf("Unsigned Short: (%d) -> (%d)\n", 0, USHRT_MAX);
    printf("Signed Short: (%d) -> (%d)\n\n", SHRT_MIN, SHRT_MAX);

    // Int is the same as signed int
    printf("Int: (%d) -> (%d)\n", INT_MIN, INT_MAX);
    printf("Unsigned Int: (%u) -> (%u)\n", 0, UINT_MAX);
    printf("Signed Int: (%d) -> (%d)\n\n", INT_MIN, INT_MAX);

    // Long is the same as unsigned long
    printf("Long: (%ld) -> (%ld)\n", LONG_MIN, LONG_MAX);
    printf("Unsigned Long: (%lu) -> (%lu)\n", 0, ULONG_MAX);
    printf("Signed Long: (%ld) -> (%ld)\n\n", LONG_MIN, LONG_MAX);

    printf("Printed via computation\n\n");

    // TODO: Compute data type ranges for char, short, int, long, and floats
    compute_data_type_ranges();

    return 0;
}

