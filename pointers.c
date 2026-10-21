#include <stdio.h>

int return_mul_val_fake() 
{
    return 3,5;
}

void return_mul_val(int *pN1, int *pN2) 
{
    *pN1 = 4;
    *pN2 = 44;
}

int main(int argc, char const *argv[])
{
    int n = 5;
    int *pN = &n;

    printf("Value: %i\n", n);
    // It will not be possible to fit in 32 bits.
    printf("Pointer as unsigned integer: %u\n", pN);
    //Now lets use 64 bit version.
    printf("Pointer as long long unsigned integer: %llu\n", pN);
    printf("Pointer as hexadecimal value: %p\n", pN);

    // Advantages of pointers
    // Reduce code.
    // Improves performance, strings, trees, arrays etc.
    // return multiple values from functions

    int a, b = return_mul_val_fake();
    printf("Returned multiple values: %i %i\n", a, b);

    int x = 9;
    int y = 9;
    printf("Before change: x:%i y:%i\n", x, y);
    return_mul_val(&x, &y);
    printf("After change: x:%i y:%i\n", x, y);

    return 0;
}
