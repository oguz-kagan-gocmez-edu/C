#include <stdio.h>
#include <stdlib.h>
int factorial(int n) 
{
    if (n == 0 || n == 1) return 1;
    else return n * factorial(n - 1);
}

int main(int argc, char const *argv[])
{
    if (argc != 2) 
    {
        printf("Usage ./recursion number\n");
        return 1;
    }
    int fac = factorial(atoi(argv[1]));
    printf("%i\n", fac);
    return 0;
}
