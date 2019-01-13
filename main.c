#include <stdio.h>

#include "matrix_multiplier.h"
#include "RAM_bitflip_test.h"

int main()
{
    printf("Running integer matrix multiplication\n");
    matrix_multiplier_integer(10);
    printf("Running floating point matrix multiplcation\n");
    matrix_multiplier_floating(10);

    RAM_bitflip_test();
}
