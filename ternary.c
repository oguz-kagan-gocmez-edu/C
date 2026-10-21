//
// Created by Oguz Kagan Gocmez on 17.10.2026.
//
#include <stdio.h>
#include <stdbool.h>

bool isEven(int a)
{
    return a % 2 == 0;
}

int main(int argc, char* argv[])
{
    int x = 1;

    int y = x ? x : 0;

    printf("x = %i | y = %i\n", x, y);

    x = 2;

    y = x ? x : 0;

    printf("x = %i | y = %i\n", x, y);

    x = 8;

    y = x ? x : 0;

    printf("x = %i | y = %i\n", x, y);

    printf("Is x even? %i\n", isEven(x));
    printf("Is y even? %i\n", isEven(y));
    return 0;
}
