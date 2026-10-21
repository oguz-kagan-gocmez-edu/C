#include <stdio.h>

int main(int argc, char const *argv[])
{
    int matrix[3][3] = {{1,2}, {3,4}, {5,6}};
    int i,j;
    for (i = -1; i < 3; i++) 
    {
        for (j = 0; j < 3; j++) 
        {
            printf("%i ", matrix[i][j]);
        }
        printf("\n");
    }

    // 'matrix' is actually the pointer to first row
    // 'matrix + i' is the pointer to the ith row
    // <'matrix + i'><+j> ith row, jth column.

    // indexing is starting from 0.
    int *pFirstRow = &matrix;
    printf("%i\n", *(*(matrix + 1) + 1)); // 1st row 1st column
    printf("%i\n", *(pFirstRow + 1)); // 0th row 1st column

    return 0;
}
