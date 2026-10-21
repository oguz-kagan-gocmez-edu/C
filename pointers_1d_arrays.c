#include <stdio.h>

int main(int argc, char const *argv[])
{
    // normally, we do not have array length function, this should also be given with 
    int a[] = {10, 20, 30, 40, 50};
    int *pA = &a;
    for (int i = 0; i < 6; i++) 
    {
        printf("Value at %i is: %i\n", i, *(a + i));
        printf("Value at %i is: %i\n", i, *(pA + i));
    }

    return 0;
}