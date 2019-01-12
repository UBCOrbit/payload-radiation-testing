#include <stdio.h>
#include <unistd.h>

#include "matrix_multiplier.h"

void matrix_multiply_integer(int num)
{
    int i, j, k;
    int a[10][10], b[10][10], result[10][10];

    /* rows and column for first matrix */
    int r1 = 10;
    int c1 = 10;

    /* rows and column for second matrix */
    int r2 = 10;
    int c2 = 10;

    /* matrices start with each entry = i+j */

    // Storing elements of first matrix.
    for (i = 0; i < r1; ++i)
        for (j = 0; j < c1; ++j)
            a[i][j] = (i + j + num);

    // Storing elements of second matrix.
    for (i = 0; i < r2; ++i)
        for (j = 0; j < c2; ++j)
            b[i][j] = (i + j - num);

    // Initializing all elements of result matrix to 0
    for (i = 0; i < r1; ++i)
        for (j = 0; j < c2; ++j)
            result[i][j] = 0;

    // Multiplying matrices a and b and
    // storing result in result matrix
    for (i = 0; i < r1; ++i)
        for (j = 0; j < c2; ++j)
            for (k = 0; k < c1; ++k)
                result[i][j] += a[i][k] * b[k][j];

    // Displaying the result
    printf("{");
    for (i = 0; i < r1; ++i) {
        printf("{ ");
        for (j = 0; j < c2; ++j) {
            printf("%d", result[i][j]);

            if (j != c2 - 1) {
                printf(",");
            }

            printf(" ");
        }

        if (i == r1 - 1) {
            printf("}}\n");
        } else {
            printf("}, ");
        }
    }
}

void matrix_multiply_floating(float num)
{
    int i, j, k;
    int a[10][10], b[10][10], result[10][10];

    /* rows and column for first matrix */
    int r1 = 10;
    int c1 = 10;

    /* rows and column for second matrix */
    int r2 = 10;
    int c2 = 10;

    /* matrices start with each entry = i+j */

    // Storing elements of first matrix.
    for (i = 0; i < r1; ++i)
        for (j = 0; j < c1; ++j)
            a[i][j] = (i + j) * num;

    // Storing elements of second matrix.
    for (i = 0; i < r2; ++i)
        for (j = 0; j < c2; ++j)
            b[i][j] = (i + j) / num;

    // Initializing all elements of result matrix to 0
    for (i = 0; i < r1; ++i)
        for (j = 0; j < c2; ++j)
            result[i][j] = 0;

    // Multiplying matrices a and b and
    // storing result in result matrix
    for (i = 0; i < r1; ++i)
        for (j = 0; j < c2; ++j)
            for (k = 0; k < c1; ++k)
                result[i][j] += a[i][k] * b[k][j];

    // Displaying the result
    printf("{");
    for (i = 0; i < r1; ++i) {
        printf("{ ");
        for (j = 0; j < c2; ++j) {
            printf("%d", result[i][j]);

            if (j != c2 - 1) {
                printf(",");
            }

            printf(" ");
        }

        if (i == r1 - 1) {
            printf("}}\n");
        } else {
            printf("}, ");
        }
    }
}

void matrix_multiplier_integer(int n)
{
    for (int i = 0; i < n; ++i)
        matrix_multiply_integer();
}

void matrix_multiplier_floating(int n)
{
    for (int i = 0; i < n; ++i)
        matrix_multiply_floating(i);
}
