#include "flash_read_test.h"

#include <stdio.h>

#define FILE_SIZE 1024*1024

void flash_read_test()
{
    printf("flash_read_test\n");

    FILE *fp = fopen("read.file", "r");

    // read in pattern and test for changes
    int flips = 0;
    int zeroToOneFlips = 0;
    long size = FILE_SIZE;
    for (int i = 0; i < FILE_SIZE; i++) {
        int c = fgetc(fp);
        if (c == EOF) {
            size = ftell(fp);
            break;
        }
        if (c != i % 256) {
            /* now we count how many bits are different, and which way they flipped */
            char xor = c ^ (i % 256);
            for (int j = 0; j < 8; j++) {
                /* check each bit of the xor */
                if (xor & (1 << j)) {
                    flips++;
                    /* if the bit in c is 1, it means it has changed 0->1. */
                    if (c & (1 << j)) {
                        zeroToOneFlips++;
                    }
                }
            }
        }
    }

    fclose(fp);

    printf("total flips, %d\nzero to one flips, %d\nfile size, %ld\n", flips, zeroToOneFlips, size);
}
