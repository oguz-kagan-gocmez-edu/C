//
// Created by Oguz Kagan Gocmez on 17.10.2026.
//
#include <stdio.h>

int main(int argc, char* argv[])
{
    int x = 128;
    int y = 256;

    printf("And result: %i\n", x & y);
    printf("Or result: %i\n", x | y);
    printf("Not result of x: %i\n", ~x);

    // bitwise left operation
    // x << n takes x and multiples with 2 to the power of n
    x = x << 1;
    printf("X value: %i\n", x);

    // bitwise right operation
    // x << n takes x and multiples with 2 to the power of minus n
    x = x >> 1;
    printf("X value: %i\n", x);

    return 0;
}
