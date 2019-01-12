#include <stdio.h>

#include "matrix_multiplier.h"
#include "RAM_bitflip_test.h"

int main()
{
    for (int i = 0; i < 100; ++i) {
        printf("Running integer matrix multiplication\n");
        matrix_multiplier_integer(1000);
        printf("Running floating point matrix multiplcation\n");
        matrix_multiplier_floating(1000);
    }
}
