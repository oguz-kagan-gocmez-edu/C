#include <stdio.h>
#include <stdlib.h>

int gcd(int x, int y) 
{
    while (y != 0) 
    {
        int r = x % y;
        x = y;
        y = r;
    }
    return x;
}

int main(int argc, char const *argv[])
{
    if (argc != 3)
    {
        printf("Usage: ./function_gcd number1 number2\n");
    }
    
    int x = atoi(argv[1]);
    int y = atoi(argv[2]);

    printf("Greatest common divisor of x and y: %i\n", gcd(x, y));

    return 0;
}