//
// Created by Oguz Kagan Gocmez on 17.10.2026.
//
#include <stdio.h>

int find_max(int x, int y)
{
    return x > y ? x : y;
}

int main(int argc, char* argv[])
{
    int x = 4, y = 8;
    printf("Maximum of x and y is: %i\n", find_max(x, y));

    return 0;
}
