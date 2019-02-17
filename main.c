#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "matrix_multiplier.h"
#include "RAM_bitflip_test.h"
#include "flash_write_test.h"
#include "flash_read_test.h"

int main()
{
    srand(time(NULL));

    while (1) {
        switch (rand() % 5) {
            case 0:
                matrix_multiplier_integer(10);
                break;
            case 1:
                matrix_multiplier_floating(10);
                break;
            case 2:
                RAM_bitflip_test();
                break;
            case 3:
                flash_write_test();
                break;
            case 4:
                flash_read_test();
                break;
        }
    }
}
