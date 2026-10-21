#include <stdio.h>
#include <stdlib.h>
int fib(int n) 
{
    if (n == 0) return 0;
    else if (n == 1) return 1;
    else return fib(n - 1) + fib(n - 2);
}

int main(int argc, char const *argv[])
{
    if (argc != 2) 
    {
        printf("Usage ./fibonacci seq\n");
        return 1;
    }
    int f = fib(atoi(argv[1]));
    printf("%i\n", f);
    return 0;
}
