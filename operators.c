//
// Created by Oguz Kagan Gocmez on 17.10.2026.
//

#include <stdio.h>

int main(int argc, char* argv[])
{
    int x = 6;
    int y = x++;

    printf("x = %i | y = %i\n", x, y);

    x = 6;
    y = ++x;
    printf("x = %i | y = %i", x, y);
    return 0;
}
