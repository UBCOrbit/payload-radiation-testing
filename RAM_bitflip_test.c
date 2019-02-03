#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>

#define PAGE_SIZE 40960

void RAM_bitflip_test()
{
    /* get 10 pages of continuous memory (in RAM) */
    char *p = mmap(NULL, PAGE_SIZE, PROT_READ | PROT_WRITE,
                   MAP_ANONYMOUS | MAP_SHARED, -1, 0);

    /* Populate the pages with an initial pattern. */
    for (int i = 0; i < PAGE_SIZE; i++) {
        p[i] = i % 256;
    }

    /* zzzzzzz */
    /* 10 milliseconds */
    usleep(100000);
    /* beep beep beep beep */
    /* .... urgh, *HITS SNOOZE* */
    // usleep(100);
    /* beep bepp beep b-*CLNK**/
    // usleep(25);
    /* *gets up* */

    /* count the number of bit flips caused by radiation. */
    int flips = 0;
    int zeroToOneFlips = 0;
    for (int i = 0; i < PAGE_SIZE; i++) {
        /* !!! OMG Rads! !!!  */
        if (p[i] != i % 256) {
            /* now we count how many bits are different, and which way they flipped */
            char xor = p[i] ^ (i % 256);
            for (int j = 0; j < 8; j++) {
                /* check each bit of the xor */
                if (xor & (1 << j)) {
                    flips++;
                    /* if the bit in p[i] is 1, it means it has changed 0->1. */
                    if (p[i] & (1 << j)) {
                        zeroToOneFlips++;
                    }
                }
            }
        }
    }

    printf("++++\nRAM_bitflip_test\ntotal flips: %d\nzero->one flips: %d\n",
           flips, zeroToOneFlips);
}
